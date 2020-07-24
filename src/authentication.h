#ifndef AUTHENTICATION_H
#define AUTHENTICATION_H

#include <QDebug>
#include <QQuickItem>

class Authentication : public QQuickItem {
  Q_OBJECT

 public:
  explicit Authentication(QQuickItem *parent = 0);
  ~Authentication();

  QByteArray genMD5(QString passwd);
  QString md5ToString(const QByteArray &array);
  //! Encrypt data user
  static QString genCipher(const QString &data, int k);

 public slots:

 private:
  bool m_isAcvive;
};

#endif  // AUTHENTICATION_H
