
#include "LacuisineBinding.nsmap"
#include "soapLacuisineBindingService.h"

int LacuisineBindingService::OpenUserSession(ns1__OpenUserSessionRequestType* /*ns1__OpenUserSessionRequest*/,
                                             ns1__OpenUserSessionResponseType& /*ns1__OpenUserSessionResponse*/) {
  return SOAP_OK;
};

int LacuisineBindingService::CloseUserSession(ns1__CloseUserSessionRequestType* /*ns1__CloseUserSessionRequest*/,
                                              ns1__CloseUserSessionResponseType& /*ns1__CloseUserSessionResponse*/) {
  return SOAP_OK;
}
