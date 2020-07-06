#ifndef UNIXSIGNALHANDLE_H
#define UNIXSIGNALHANDLE_H

#include <QMap>
#include <QThread>
#include <initializer_list>
#include <signal.h>
#include <unistd.h>

class UnixSignalHandle : public QThread {
  Q_OBJECT

  Q_PROPERTY(int sig READ sig NOTIFY sigTrigged)
 public:
  explicit UnixSignalHandle(QObject *parent = nullptr);

  void run() override;
  //!
  Q_INVOKABLE void catchUnixSignals(std::initializer_list<int> quitSignals);
  //!
  Q_INVOKABLE void ignoreUnixSignals(std::initializer_list<int> ignoreSignals);
  //!
  int sig() const { return m_sig; }

  void trigger(int sig);
 signals:
  void sigTrigged(int sig);

 public slots:

 private:
  int m_sig;
  static QMap<int, QString> sigMap;
};

#endif  // UNIXSIGNALHANDLE_H
