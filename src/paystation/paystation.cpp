#include <QDebug>
#include <QLibrary>
#include <QTime>
#include <stdlib.h>
#include "paystation.h"
#include "clisitef.h"

PayStation::PayStation(QObject *parent) :
    QObject(parent)
{

//    clisitef = new SitefAPI();

//    clisitef->setSitefInt("192.168.0.232", "00000000", "SW000001", 0);

}

float PayStation::cost() const
{
    return m_cost;
}

void PayStation::setCost(const float &n)
{
    m_cost = n;
    qDebug() << "Inserindo: R$ " << m_cost << "reais";

    if (clisitef->cardReaderAvailable()) {
        qDebug("PinPad encontrado");
    } else {
        qDebug("PinPad não encontrado");
        return;
    }

    if (!clisitef->openCardReader()) {
        qDebug("Efetuando a venda");
        sale(3, m_cost, "12345", "OPERADOR", "");
    }
}

void PayStation::sale(int type, float price, const QString &fiscNumber, const QString &user, const QString &restriction)
{
    QDate date;

    qDebug() << "Tipo de Operação: " << type;
    qDebug() << "Hora atual: " << date.currentDate().toJulianDay();
    qDebug() << "Número fiscal: " << fiscNumber;
    qDebug() << "Hora atual: " << user;
    qDebug() << "Restrição: " << restriction;

}

//void PayStation::sale()
//{
//    int comando = 0;
//    int resultado = 0;
//    unsigned long tipoCampo = 0;
//    unsigned short tamanhoMinimo = 0;
//    unsigned short tamanhoMaximo = 0;
//    char buffer [20 * 1024 + 1];

//    char Restricoes [2048 + 1];

//    *Restricoes = '\0';

//    IniciaFuncaoSiTefInterativo initSitefInt = (IniciaFuncaoSiTefInterativo) clisitef->resolve("IniciaFuncaoSiTefInterativo");
//    FinalizaFuncaoSiTefInterativo endSitefInt = (FinalizaFuncaoSiTefInterativo) clisitef->resolve("FinalizaFuncaoSiTefInterativo");
//    ContinuaFuncaoSiTefInterativo resumeSitefInt = (ContinuaFuncaoSiTefInterativo) clisitef->resolve("ContinuaFuncaoSiTefInterativo");

//    int ret = initSitefInt(3, (char*)"250,00", (char*)"12345", (char*)"20150113", (char*)"115400", (char*)"OPERADOR",Restricoes);

//    if (ret != 10000) {
//        return;
//    }

//    while (1) {

//        ret = resumeSitefInt (&comando, &tipoCampo, &tamanhoMinimo, &tamanhoMaximo,  buffer, 20100, resultado);
//        if (ret != 10000) {
//            break;
//        }

//        if (comando == 0)
//        {
//           resultado = result(tipoCampo, buffer);
//        } else {
//           resultado = collectData(comando, tipoCampo, buffer);
//        }
//    }

//    endSitefInt(1, (char*)"12345",  (char*)"20150113", (char*)"115400");
//}

/**
 * @brief PayStation::checkPinPad
 * @return
 */
bool PayStation::checkPinPad(void)
{
    int ret = 0;
//    VerificaPresencaPinPad checkPin = (VerificaPresencaPinPad) clisitef->resolve("VerificaPresencaPinPad");

//    ret = checkPin();
    qDebug() << "Resultado da operação: " << ret;
    if (!ret) {
        return true;
    } else if (ret < 0) {
        qDebug("Biblioteca de acesso ao PinPad não encontrada.");
    }

    return false;
}

/**
 * @brief PayStation::collectData
 * @param comando
 * @param tipoCampo
 * @param pDadosComando
 * @param pCampo
 * @return
 */
int PayStation::collectData(int comando, unsigned long tipoCampo, char* pDadosComando)
{
    static int nVezes;

    if (comando != 23)
    {
        nVezes = 0;
    }

    switch (comando)
    {
        case 1:
        case 2:
        case 3:
        case 4:

            qDebug() << "Mensagem Visor: [" << pDadosComando << "]";
            return 0;

        case 11:
        case 12:
        case 13:
        case 14:
            qDebug() << "Apaga Visor: [" << pDadosComando << "]";
            return 0;

        case 37:
            qDebug() << "Coleta confirmacao no PinPad: [" << pDadosComando << "]";
            return 0;

        case 20:
            qDebug() << "Coleta Sim/Nao: [" << pDadosComando << "]";
            return 0;

        case 21:
            qDebug() << "Menu: [" << pDadosComando << "]";
            return 0;

        case 22:
            qDebug() << "Obtem qualquer tecla: [" << pDadosComando << "]";
            return 0;

        case 23:
            delay(1);
            if (nVezes++ > 30)
            {
                return -1;
            }

            return 0;

        case 30:
        case 31:
        case 32:
        case 33:
        case 34:
        case 35:
        case 38:
            qDebug() << "nComando: [" << comando << "]\nTipoCampo: [" << tipoCampo << "]";
            return 0;
    }

    return -1;
}

int PayStation::result (unsigned long TipoCampo, char *pResultado)
{


    char Retorno [5 + 1];
    switch (TipoCampo)
    {
        case 1:
            qDebug() << "Finalizacao: [" << pResultado << "]";
            return -1;

        case 2:
            qDebug() << "Finalizacao: [" << pResultado << "]";
            memset(pResultado, 0, 20100);
            break;

        case 105:
            qDebug () << "\nTipoCampo= " << TipoCampo << "Conteudo= " << pResultado;
            break;

        case 121:
            qDebug() << "Comprovante Cliente:\n" << pResultado;
            break;

        case 122:
            qDebug() << "Comprovante Estabelecimento:\n" << pResultado;
            break;

        case 131:
          qDebug() << "Rede destino:" << pResultado;
          LeCampo (0, sizeof (Retorno) - 1, "Retorno RecebeResultado (enter = 0)?:", Retorno);
          return (atoi (Retorno));

        case 132:
          qDebug() << "Tipo Cartao:" << pResultado;
          LeCampo (0, sizeof (Retorno) - 1, "Retorno RecebeResultado (enter = 0)?:", Retorno);
          return (atoi (Retorno));

        case 136:
            qDebug () << "\nTipoCampo= " << TipoCampo << "Conteudo= " << pResultado;
            break;

        default:
            qDebug () << "\nTipoCampo= " << TipoCampo << "Conteudo= " << pResultado;
            break;
    }

    return (0);
}

int PayStation::LeCampo (short TamMinimo, short TamMaximo, char *pMensagem, char *pCampo)
{
//    for (int i = 0; i < sizeof (pCampo); i++)
//    {
//        pCampo[i] = 0;
//    }

//    pCampo[0] = 0x35;
//    pCampo[1] = 0x34;
//    pCampo[2] = 0x37;
//    pCampo[4] = 0;

//    qDebug("LE CAMPO");

    return 0;
}

int PayStation::readField(char *pMensagem, char *pCampo)
{
    return 0;
}

void PayStation::delay(int secs)
{
    QTime dieTime= QTime::currentTime().addSecs(secs);
    while( QTime::currentTime() < dieTime );
}
