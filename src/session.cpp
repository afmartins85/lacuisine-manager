#include "session.h"

Session::Session() {}

/**
 * @brief Session::sessionUser
 * @return
 */
QString Session::sessionUser() const { return m_user; }

/**
 * @brief Session::setSessionUser
 * @param user
 */
void Session::setSessionUser(const QString &user) { m_user = user; }

/**
 * @brief Session::sessionFullName
 * @return
 */
QString Session::sessionFullName() const { return m_fullName; }

/**
 * @brief Session::setSessionFullName
 * @param fullName
 */
void Session::setSessionFullName(const QString &fullName) { m_fullName = fullName; }

/**
 * @brief Session::getSessionProfile
 * @return
 */
ns2__ProfileEnum Session::getSessionProfile() const { return m_profile; }

/**
 * @brief Session::setSessionProfile
 * @param value
 */
void Session::setSessionProfile(const ns2__ProfileEnum &value) { m_profile = value; }

/**
 * @brief Session::getSessionChallenge
 * @return
 */
int Session::getSessionChallenge() const { return m_challenge; }

/**
 * @brief Session::setSessionChallenge
 * @param value
 */
void Session::setSessionChallenge(int value) { m_challenge = value; }

/**
 * @brief Session::cleanSessionData
 * @return
 */
bool Session::cleanSessionData() {
  this->m_user.clear();
  this->m_password.clear();
  this->m_fullName.clear();
  this->m_profile = ns2__ProfileEnum__ProfileUnknown;
  this->m_challenge = 0;

  return true;
}

/**
 * @brief Session::getSessionPassword
 * @return
 */
QString Session::getSessionPassword() const { return m_password; }

/**
 * @brief Session::setSessionPassword
 * @param password
 */
void Session::setSessionPassword(const QString &password) { m_password = password; }
