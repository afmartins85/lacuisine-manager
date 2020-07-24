#ifndef SITEFAPI_H
#define SITEFAPI_H

#include <QLibrary>
#include "clisitef.h"

#ifdef _WIN_BUILD
#include <windows.h>
#endif

class SitefAPI : public QObject {
  Q_OBJECT
 public:
  explicit SitefAPI(QObject *parent = 0);
  ~SitefAPI();

  QLibrary *clisitef;
  int setSitefInt(QString const &ipAddr, QString const &storeCode,
                  QString const &termNumber, short result);
  int openCardReader(void);
  int cardReaderAvailable(void);

 private:
  AbrePinPad openPinPad;
  VerificaPresencaPinPad checkPinPad;
  ConfiguraIntSiTefInterativo confSitefInt;
  IniciaFuncaoSiTefInterativo initSitefInt;
  ContinuaFuncaoSiTefInterativo resumeSitefInt;

 signals:

 public slots:
};

#endif  // SITEFAPI_H
