#ifndef SESSION_H
#define SESSION_H

#include "gsoap/soapLacuisineBindingProxy.h"
#include <QString>

class Session

{
 public:
  explicit Session();

  //! Return the user name of session
  QString sessionUser() const;
  //! Set the user name of session
  void setSessionUser(const QString &sessionUser);
  //! Return the full name of the session owner
  QString sessionFullName() const;
  //! Set the full name of the session owner
  void setSessionFullName(const QString &sessionFullName);
  //! Return the profile of user
  ns2__ProfileEnum getSessionProfile() const;
  //! Set the profile of user
  void setSessionProfile(const ns2__ProfileEnum &value);
  //! Return the challenge for the data encode/decode
  int getSessionChallenge() const;
  //! Set the challenge for the data encode/decode
  void setSessionChallenge(int value);
  //! Clean the user data session
  bool cleanSessionData();
  //! Return the password of user
  QString getSessionPassword() const;
  //! Set the password of user
  void setSessionPassword(const QString &password);

 private:
  QString m_user;
  QString m_fullName;
  QString m_password;
  ns2__ProfileEnum m_profile;
  int m_challenge;
};

#endif  // SESSION_H
