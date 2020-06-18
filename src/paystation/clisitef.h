#ifndef CLISITEF_H
#define CLISITEF_H

#define CALLBACK __stdcall

typedef int (*type)(const char *);

typedef int (*ConfiguraIntSiTefInterativo)(char *pEnderecoIP, char *pCodigoLoja,
                                           char *pNumeroTerminal,
                                           short ConfiguraResultado);

typedef int (*IniciaFuncaoSiTefInterativo)(int Modalidade, char *pValor,
                                           char *pNumeroCuponFiscal,
                                           char *pDataFiscal, char *pHorario,
                                           char *pOperador, char *pRestricoes);

typedef int (*IniciaFuncaoAASiTefInterativo)(int Modalidade, char *pValor,
                                             char *pNumeroCuponFiscal,
                                             char *pDataFiscal, char *pHorario,
                                             char *pOperador, char *pRestricoes,
                                             char *pProdutos);

typedef int (*DesfazTransacaoSiTefInterativo)(char *pDadosDesfazimento);

typedef int (*FuncoesGerenciaisSiTefInterativo)(char *pNumeroCuponFiscal,
                                                char *pDataFiscal,
                                                char *pHorario,
                                                char *pOperador);

typedef int (*IniciaCancelamentoIdentificadoSiTefInterativo)(
    char *pNumeroCuponFiscal, char *pDataFiscal, char *pHorario,
    char *pOperador, char *pChaveTrnCancelamento);

typedef int (*CorrespondenteBancarioSiTefInterativo)(char *pNumeroCuponFiscal,
                                                     char *pDataFiscal,
                                                     char *pHorario,
                                                     char *pOperador,
                                                     char *pRestricoes);

typedef int (*ValidaCampoCodigoEmBarras)(char *pCodigoEmBarras, short *pTipo);

typedef void (*FinalizaTransacaoSiTefInterativo)(short Confirma,
                                                 char *pNumeroCuponFiscal,
                                                 char *pDataFiscal,
                                                 char *pHorario);

typedef void (*FinalizaTransacaoSiTefInterativoBonus)(
    short Confirma, char *pNumeroCuponFiscal, char *pDataFiscal, char *pHorario,
    char *pValorTotalCupon, char *pValorTotalBonus);

typedef int (*ContinuaFuncaoSiTefInterativo)(int *pProximoComando,
                                             unsigned long *pTipoCampo,
                                             unsigned short *pTamanhoMinimo,
                                             unsigned short *pTamanhoMaximo,
                                             char *pBuffer, int TamMaxBuffer,
                                             int ContinuaNavegacao);

typedef int (*EnviaRecebeSiTefDireto)(
    short RedeDestino, short FuncaoSiTef, short OffsetCartao, char *pDadosTx,
    short TamDadosTx, char *pDadosRx, short TamMaxDadosRx,
    short *pCodigoResposta, short TempoEsperaRx, char *pNumeroCupon,
    char *pDataFiscal, char *pHorario, char *pOperador, short TipoTransacao);

typedef int (*ForneceParametroEnviaRecebeSiTefDireto)(short IndiceParametro,
                                                      char *pParametro,
                                                      short ParametroCartao,
                                                      short Delimitador);
typedef void (*ForneceParametroEnviaRecebeSiTefDiretoA)(char *pResultado,
                                                        char *pIndiceParametro,
                                                        char *pParametro,
                                                        char *pParametroCartao,
                                                        char *pDelimitador);

typedef int (*LeCartaoInterativo)(char *pMsgDisplay);

typedef int (*LeCartaoDireto)(char *pMsgDisplay, char *pTrilha1,
                              char *pTrilha2);

// typedef int (*LeCartaoDiretoEx)(char *pMsgDisplay, char *pTrilha1,
//                                char *pTrilha2, unsigned short Timeout,
//                                short(__stdcall *pTestaCancelamento)(void));

typedef int (*LeSenhaDireto)(char *pChaveSeguranca, char *pSenha);

typedef int (*VerificaPresencaPinPad)(void);

typedef int (*SEObtemChaveSeguranca)(char *pChaveSeguranca, char *pCartao,
                                     char *pChaveAbertura, char *pResultado);

typedef int (*SEObtemSenhaCliente)(char *pSenhaAberta, char *pSenhaCapturada,
                                   char *pChaveSeguranca, char *pChaveAbertura,
                                   char *pResultado);

typedef int (*AbrePinPad)(void);
typedef int (*FechaPinPad)(void);
typedef int (*EscreveMensagemPinPad)(char *pMsgDisplay);
typedef int (*EscreveMensagemPermanentePinPad)(char *pMsgDisplay);
typedef int (*LeCampoPinPad)(char *pMsgDisplay, int TamMaximo, int eSenha,
                             char *pCampo);
typedef int (*LeTeclaPinPad)(void);
typedef int (*LeSimNaoPinPad)(char *pMsgDisplay);

typedef int (*IniciaFuncaoSiTefInterativoConsultaVidalink)(
    char *pCodigoAutorizacao, char *pCodigoProduto, char *pNumeroCuponFiscal,
    char *pDataFiscal, char *pHorario, char *pOperador);
typedef int (*InformaProdutoVendaVidalink)(short IndiceProduto,
                                           char *pCodigoProduto,
                                           short Quantidade, char *pValorVenda);
typedef int (*IniciaFuncaoSiTefInterativoVendaVidalink)(
    char *pCodigoAutorizacao, short NumeroProdutos, char *pNumeroCuponFiscal,
    char *pDataFiscal, char *pHorario, char *pOperador);
typedef int (*IniciaFuncaoSiTefInterativoCancelamentoVidalink)(
    short ParcialTotal, short NumeroProdutos, char *pNumeroCuponOriginal,
    char *pDataOriginal, char *pNumeroDocumentoOriginal,
    char *pIdentificacaoPdvOriginal, char *pCuponFiscal, char *pDataFiscal,
    char *pHorario, char *pOperador);

typedef int (*IniciaFuncaoSiTefInterativoConsultaPBM)(
    char *pCodigoAutorizacao, char *pCodigoProduto, char *pNumeroCuponFiscal,
    char *pDataFiscal, char *pHorario, char *pOperador,
    char *pParametrosAdicionais);

typedef int (*ConsultaParametrosSiTef)(int TipoConsulta, char *Reservado,
                                       char *Saida);
typedef int (*RegistraBonusOffLineSiTef)(char *ValorBonus, char *ValorCupom,
                                         char *NumeroCuponFiscal,
                                         char *DataFiscal, char *Horario,
                                         char *Operador, char *Supervisor);

typedef void (*FinalizaFuncaoSiTefInterativo)(short Confirma,
                                              char *pNumeroCuponFiscal,
                                              char *pDataFiscal,
                                              char *pHorario);

typedef int (*ObtemParametrosSiTef)(int TipoConsulta, char *pParamAdic);

#endif  // CLISITEF_H
