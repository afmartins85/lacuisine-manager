#include "unixsignalhandle.h"
#include "loguru.hpp"
#include <QObject>

bool g_isSigTrigged = false;
QMap<int, QString> UnixSignalHandle::sigMap{{1, "SIGHUP"},   {2, "SIGINT"},   {3, "SIGQUIT"},  {4, "SIGABRT"},
                                            {9, "SIGKILL"},  {10, "SIGBUS"},  {11, "SIGSEGV"}, {12, "SIGSYS"},
                                            {13, "SIGPIPE"}, {14, "SIGALRM"}, {15, "SIGTERM"}, {17, "SIGSTOP"}};

UnixSignalHandle::UnixSignalHandle(QObject *parent) : QThread(parent) {
  catchUnixSignals({SIGQUIT, SIGINT, SIGTERM, SIGSEGV, SIGHUP});
  connect(this, &UnixSignalHandle::finished, this, &UnixSignalHandle::deleteLater);
  this->start();
}

/**
 * @brief UnixSignalHandle::ignoreUnixSignals
 * @param ignoreSignals
 */
void UnixSignalHandle::ignoreUnixSignals(std::initializer_list<int> ignoreSignals) {
  // all these signals will be ignored.
  for (int sig : ignoreSignals) signal(sig, SIG_IGN);
}

/**
 * @brief UnixSignalHandle::catchUnixSignals
 * @param quitSignals
 */
void UnixSignalHandle::catchUnixSignals(std::initializer_list<int> quitSignals) {
  auto handler = [](int sig) -> void {
    QString sigString = sigMap.find(sig).value();
    // blocking and not aysnc-signal-safe func are valid
    LOG_F(INFO, "quit the application by signal(%d)(%s).\n", sig, sigString.toLatin1().data());
    g_isSigTrigged = true;
    while (1)
      ;
  };

  sigset_t blocking_mask;
  sigemptyset(&blocking_mask);
  for (auto sig : quitSignals) sigaddset(&blocking_mask, sig);

  struct sigaction sa;
  sa.sa_handler = handler;
  sa.sa_mask = blocking_mask;
  sa.sa_flags = 0;

  for (auto sig : quitSignals) sigaction(sig, &sa, nullptr);
}

void UnixSignalHandle::trigger(int sig) {
  QString sigString = sigMap.find(sig).value();
  // blocking and not aysnc-signal-safe func are valid
  LOG_F(INFO, "quit the application by signal(%d)(%s).\n", sig, sigString.toLatin1().data());
  emit sigTrigged(sig);
}

void UnixSignalHandle::run() {
  if (g_isSigTrigged == true) {
    LOG_F(WARNING, "UNIX SIGNAL RECEIVED!!!");
  }
}
