#include "sysinfo.h"
#include "loguru.hpp"
#include "simplecrypt.h"
#include <QCryptographicHash>
#include <QDebug>
#include <QString>

SysInfo::SysInfo(QObject *parent) : QObject(parent) {
  QSysInfo info;

  this->setBuildAbi(info.buildAbi());
  this->setCpuArch(info.currentCpuArchitecture());
  this->setKernelType(info.kernelType());
  this->setKernelVersion(info.kernelVersion());
  this->setHostName(info.machineHostName());
  this->setProductName(info.prettyProductName());
  this->setProductType(info.productType());
  this->setProductVersion(info.productVersion());

  // Generate a cypher with Sha256 to machine unique Id
  //  QByteArray cypher = QCryptographicHash::hash(info.machineUniqueId(), QCryptographicHash::Sha1);
  //  SimpleCrypt crypto(Q_UINT64_C(0x0c2ad4a4acb9f023));
  //  QString uniqueID = crypto.encryptToString(cypher);
  //  qDebug() << uniqueID;

  this->setUniqueID(QString::fromUtf8(info.machineUniqueId()));
}

SysInfo::SysInfo(const SysInfo &sysInfo) {
  this->setBuildAbi(sysInfo.buildAbi());
  this->setCpuArch(sysInfo.cpuArch());
  this->setKernelType(sysInfo.kernelType());
  this->setKernelVersion(sysInfo.kernelVersion());
  this->setHostName(sysInfo.hostName());
  this->setProductName(sysInfo.productName());
  this->setProductType(sysInfo.productType());
  this->setProductVersion(sysInfo.productVersion());
  this->setUniqueID(sysInfo.uniqueID());
}

/**
 * @brief SysInfo::setBuildAbi
 * @param buildAbi
 */
void SysInfo::setBuildAbi(QString buildAbi) {
  if (m_buildAbi == buildAbi) return;

  m_buildAbi = buildAbi;
  emit buildAbiChanged(m_buildAbi);
}

/**
 * @brief SysInfo::setCpuArch
 * @param cpuArch
 */
void SysInfo::setCpuArch(QString cpuArch) {
  if (m_cpuArch == cpuArch) return;

  m_cpuArch = cpuArch;
  emit cpuArchChanged(m_cpuArch);
}

/**
 * @brief SysInfo::setKernelType
 * @param kernelType
 */
void SysInfo::setKernelType(QString kernelType) {
  if (m_kernelType == kernelType) return;

  m_kernelType = kernelType;
  emit kernelTypeChanged(m_kernelType);
}

/**
 * @brief SysInfo::setName
 * @param kernelVersion
 */
void SysInfo::setKernelVersion(QString kernelVersion) {
  if (m_kernelVersion == kernelVersion) return;

  m_kernelVersion = kernelVersion;
  emit kernelVersionChanged(m_kernelVersion);
}

/**
 * @brief SysInfo::setHostName
 * @param hostName
 */
void SysInfo::setHostName(QString hostName) {
  if (m_hostName == hostName) return;

  m_hostName = hostName;
  emit hostNameChanged(m_hostName);
}

/**
 * @brief SysInfo::setProductName
 * @param productName
 */
void SysInfo::setProductName(QString productName) {
  if (m_productName == productName) return;

  m_productName = productName;
  emit productNameChanged(m_productName);
}

/**
 * @brief SysInfo::setProductType
 * @param productType
 */
void SysInfo::setProductType(QString productType) {
  if (m_productType == productType) return;

  m_productType = productType;
  emit productTypeChanged(m_productType);
}

/**
 * @brief SysInfo::setProductVersion
 * @param productVersion
 */
void SysInfo::setProductVersion(QString productVersion) {
  if (m_productVersion == productVersion) return;

  m_productVersion = productVersion;
  emit productVersionChanged(m_productVersion);
}

/**
 * @brief SysInfo::setUniqueID
 * @param uniqueID
 */
void SysInfo::setUniqueID(QString uniqueID) {
  if (m_uniqueID == uniqueID) return;

  m_uniqueID = uniqueID;
  emit uniqueIDChanged(m_uniqueID);
}

/**
 * @brief SysInfo::operator ==
 * @param sysInfo
 * @return
 */
bool SysInfo::operator==(const SysInfo &sysInfo) {
  if (this->m_uniqueID.compare(sysInfo.uniqueID())) {
    return false;
  }

  return true;
}

/**
 * @brief SysInfo::operator =
 * @param sysInfo
 * @return
 */
SysInfo &SysInfo::operator=(const SysInfo &sysInfo) {
  this->setBuildAbi(sysInfo.buildAbi());
  this->setCpuArch(sysInfo.cpuArch());
  this->setKernelType(sysInfo.kernelType());
  this->setKernelVersion(sysInfo.kernelVersion());
  this->setHostName(sysInfo.hostName());
  this->setProductName(sysInfo.productName());
  this->setProductType(sysInfo.productType());
  this->setProductVersion(sysInfo.productVersion());
  this->setUniqueID(sysInfo.uniqueID());

  return *this;
}

/**
 * @brief SysInfo::objectItSelf
 * @return
 */
SysInfo &SysInfo::objectItSelf() { return *this; }
