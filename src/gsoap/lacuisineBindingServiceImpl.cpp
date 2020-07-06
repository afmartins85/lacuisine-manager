
#include "LacuisineBinding.nsmap"
#include "soapLacuisineBindingService.h"

int LacuisineBindingService::OpenUserSession(ns1__DataUserSessionType* /*ns1__DataUserSessionRequest*/,
                                             ns1__OpenUserSessionResponseType& /*ns1__OpenUserSessionResponse*/) {
  return SOAP_OK;
};

int LacuisineBindingService::CloseUserSession(ns1__DataUserSessionType* /*ns1__DataUserSessionRequest*/,
                                              ns1__CloseUserSessionResponseType& /*ns1__CloseUserSessionResponse*/) {
  return SOAP_OK;
}
