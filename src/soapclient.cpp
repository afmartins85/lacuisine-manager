#include "soapclient.h"
#include "authentication.h"
#include "cacertdefinitions.h"
#include "loguru.hpp"
#include "qutilitytools.h"
#include "simplecrypt.h"
#include <QCryptographicHash>
#include <QDebug>

SoapClient::SoapClient(QObject *parent) : QObject(parent) {
  this->m_soapClient = new LacuisineBindingProxy("https://138.68.29.14:9090");
  soap_ssl_init();

  if (soap_ssl_client_context(this->m_soapClient->soap, SOAP_SSL_DEFAULT, clientPEM, passwd, cacert, NULL, NULL)) {
    LOG_F(ERROR, "SOAP Client Fail: %s", this->m_soapClient->soap_fault_string());
    exit(1);
  }

  LOG_F(INFO, "SOAP Client Started with successfully!!");
}

SoapClient::~SoapClient() {
  LOG_F(INFO, "SOAPClient DESTRUCTOR");
  this->closeUserSession();
  delete this->m_soapClient;
}

/**
 * @brief SoapClient::setSysInfo
 * @param sysInfo
 */
void SoapClient::setSysInfo(SysInfo *sysInfo) {
  if (m_sysInfo == sysInfo) return;

  m_sysInfo = sysInfo;
  LOG_F(INFO, "cpuArch: %s", this->m_sysInfo->cpuArch().toLatin1().data());
  LOG_F(INFO, "buildAbi: %s", this->m_sysInfo->buildAbi().toLatin1().data());
  LOG_F(INFO, "hostName: %s", this->m_sysInfo->hostName().toLatin1().data());
  LOG_F(INFO, "uniqueID: %s", this->m_sysInfo->uniqueID().toLatin1().data());
  LOG_F(INFO, "kernelType: %s", this->m_sysInfo->kernelType().toLatin1().data());
  LOG_F(INFO, "productName: %s", this->m_sysInfo->productName().toLatin1().data());
  LOG_F(INFO, "productType: %s", this->m_sysInfo->productType().toLatin1().data());
  LOG_F(INFO, "productVersion: %s", this->m_sysInfo->productVersion().toLatin1().data());
  emit sysInfoChanged(m_sysInfo);
}

/**
 * @brief SoapClient::openUserSession
 * @param login
 * @param password
 * @return
 */
bool SoapClient::openUserSession(QString login, QString password) {
  Authentication auth;
  QString passMD5 = auth.md5ToString(auth.genMD5(password));

  ns1__OpenUserSessionRequestType request;
  ns1__OpenUserSessionResponseType response;

  request.userName = login.toLatin1().data();
  request.passwd = passMD5.toLatin1().data();

  // Generate a cypher with Sha256 to machine unique Id
  QString uniqueID = Authentication::genCipher(m_sysInfo->uniqueID(), static_cast<int>(0xec78ff296a50bb7a));
  request.deviceId = uniqueID.toLatin1().data();

  LOG_SCOPE_F(INFO, "OpenUserSession");
  LOG_F(INFO, "User Name: %s", request.userName.c_str());
  LOG_F(INFO, "MD5: %s", request.passwd.c_str());
  LOG_F(INFO, "with crypto Device Id: %s", request.deviceId.c_str());

  if (this->m_soapClient->OpenUserSession(&request, response) != SOAP_OK) {
    LOG_F(WARNING, "SOAP Client Fail: %s", this->m_soapClient->soap_fault_string());
    return false;
  }

  if ((response.success) == true && (response.response == ns2__SessionEnum::ns2__SessionEnum__SessionOk)) {
    LOG_F(INFO, "Session opened for %s", response.userDataSession->fullName.c_str());
    LOG_F(INFO, "Challenge received %d", response.userDataSession->challenge);
    LOG_F(INFO, "User profile %d", response.userDataSession->profileType);
    this->setSessionUser(login);
    this->setSessionPassword(password);
    this->setSessionFullName(QString(response.userDataSession->fullName.c_str()));
    this->setSessionProfile(response.userDataSession->profileType);
    this->setSessionChallenge(response.userDataSession->challenge);
    emit sessionOpened(this->sessionUser());
    return true;
  }

  return false;
}

/**
 * @brief SoapClient::closeUserSession
 * @return
 */
bool SoapClient::closeUserSession() {
  Authentication auth;
  ns1__CloseUserSessionRequestType request;
  ns1__CloseUserSessionResponseType response;
  QString eKey = auth.md5ToString(auth.genMD5(this->getSessionPassword()));
  QString uniqueID = Authentication::genCipher(m_sysInfo->uniqueID(), this->getSessionChallenge());

  if (this->sessionUser().isEmpty() == true) {
    LOG_F(INFO, "No session is opened!");
    return true;
  }

  request.userName = this->sessionUser().toLatin1().data();
  request.passwd = eKey.toLatin1().data();
  request.deviceId = uniqueID.toLatin1().data();

  LOG_SCOPE_F(INFO, "CloseUserSession");
  LOG_F(INFO, "User Name: %s", request.userName.c_str());
  LOG_F(INFO, "Key: %s", request.passwd.c_str());
  LOG_F(INFO, "Device Id: %s", request.deviceId.c_str());

  if (this->m_soapClient->CloseUserSession(&request, response) != SOAP_OK) {
    LOG_F(WARNING, "SOAP Client Fail: %s", this->m_soapClient->soap_fault_string());
    return false;
  }

  if ((response.success == false) || (response.response != ns2__SessionEnum__SessionIsSuccessfullyClosed)) {
    return false;
  }

  this->cleanSessionData();

  return true;
}
