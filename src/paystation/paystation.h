#ifndef PAYSTATION_H
#define PAYSTATION_H

#include <QObject>
#include <QString>
#include "clisitef.h"
#include "sitefapi.h"

class PayStation : public QObject
{
    Q_OBJECT
    Q_PROPERTY(float cost READ cost WRITE setCost)
public:
    explicit PayStation(QObject *parent = 0);

    SitefAPI *clisitef;
    float cost () const;
    void setCost (const float &);
    void sale (int type, float price, QString const &fiscNumber, QString const &usr, QString const &restriction);

private:
    float m_cost;
    bool m_cardCredit;
    bool m_cardDebit;


    bool checkPinPad (void);
    int readField(char *pMensagem, char *pCampo);
    int collectData(int comando, unsigned long tipoCampo, char* pDadosComando);
    int result (unsigned long TipoCampo, char *pResultado);
    int LeCampo (short TamMinimo, short TamMaximo, char *pMensagem, char *pCampo);
    void delay(int secs);


signals:

public slots:

};

#endif // PAYSTATION_H
