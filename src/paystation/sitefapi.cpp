#include <QDebug>
#include <QLibrary>
#include <QTime>
#include <QString>
#include <stdlib.h>

//#include "clisitef.h"
#include "sitefapi.h"

SitefAPI::SitefAPI(QObject *parent) :
    QObject(parent)
{

    clisitef = new QLibrary("c:/Projects/la-cuisini/lib/win/clisitef32I");
    bool load = clisitef->load();
    if( load == false ) {
        qDebug() << "Biblioteca não carregada!";
    } else {
        qDebug("Lib CLISitef encontrada, resolvendo simbolos.\n");
        confSitefInt = (ConfiguraIntSiTefInterativo) clisitef->resolve("ConfiguraIntSiTefInterativo");
        openPinPad = (AbrePinPad) clisitef->resolve("AbrePinPad");
        initSitefInt = (IniciaFuncaoSiTefInterativo) clisitef->resolve("IniciaFuncaoSiTefInterativo");
        resumeSitefInt = (ContinuaFuncaoSiTefInterativo) clisitef->resolve("ContinuaFuncaoSiTefInterativo");
        checkPinPad = (VerificaPresencaPinPad) clisitef->resolve("VerificaPresencaPinPad");
    }
}

SitefAPI::~SitefAPI() {}


/**
 * @brief SitefAPI::setSitefInt
 * @param ipAddr
 * @param storeCode
 * @param termNumber
 * @param result
 * @return
 */
int SitefAPI::setSitefInt(const QString &ipAddr, const QString &storeCode, const QString &termNumber, short result)
{

    qDebug() << "IP do servidor: " << ipAddr;
    qDebug() << "Código da Loja: " << storeCode;
    qDebug() << "Número do terminal: " << termNumber;

    int ret = confSitefInt(ipAddr.toLatin1().data(), storeCode.toLatin1().data(),
                           termNumber.toLatin1().data(), result);

    qDebug() << "Resultado da configuracao: " << ret;

    return 0;
}

/**
 * @brief SitefAPI::openCardReader
 * @return
 */
int SitefAPI::openCardReader(void) { return openPinPad(); }

/**
 * @brief SitefAPI::cardReaderAvailable
 * @return
 */
int SitefAPI::cardReaderAvailable(void) { return checkPinPad(); }

