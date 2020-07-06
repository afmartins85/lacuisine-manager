#ifndef SOAPCLIENT_H
#define SOAPCLIENT_H

#include "gsoap/soapLacuisineBindingProxy.h"
#include "session.h"
#include "sysinfo.h"
#include <QObject>

class SoapClient : public QObject, public Session {
  Q_OBJECT

  Q_PROPERTY(QString userName READ userName NOTIFY sessionOpened)
  Q_PROPERTY(SysInfo *sysInfo READ sysInfo WRITE setSysInfo NOTIFY sysInfoChanged)
 public:
  explicit SoapClient(QObject *parent = nullptr);
  virtual ~SoapClient();

  SysInfo *sysInfo() const { return m_sysInfo; }
  QString userName() const { return this->sessionUser(); }
 public slots:
  //! Set the system information to use in authentication message
  void setSysInfo(SysInfo *sysInfo);
  //! Execute a open user session request
  Q_INVOKABLE bool openUserSession(QString login, QString password);
  //! Close user session request
  Q_INVOKABLE bool closeUserSession();

 signals:
  void sysInfoChanged(SysInfo *sysInfo);

  void sessionOpened(QString userName);

 private:
  LacuisineBindingProxy *m_soapClient;
  SysInfo *m_sysInfo;
  QString m_userName;
};

#endif  // SOAPCLIENT_H
