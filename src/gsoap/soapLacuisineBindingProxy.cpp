/* soapLacuisineBindingProxy.cpp
   Generated by gSOAP 2.8.103 for lacuisine.h

gSOAP XML Web services tools
Copyright (C) 2000-2020, Robert van Engelen, Genivia Inc. All Rights Reserved.
The soapcpp2 tool and its generated software are released under the GPL.
This program is released under the GPL with the additional exemption that
compiling, linking, and/or using OpenSSL is allowed.
--------------------------------------------------------------------------------
A commercial use license is available from Genivia Inc., contact@genivia.com
--------------------------------------------------------------------------------
*/

#include "soapLacuisineBindingProxy.h"

LacuisineBindingProxy::LacuisineBindingProxy()
{	this->soap = soap_new();
	this->soap_own = true;
	LacuisineBindingProxy_init(SOAP_IO_DEFAULT, SOAP_IO_DEFAULT);
}

LacuisineBindingProxy::LacuisineBindingProxy(const LacuisineBindingProxy& rhs)
{	this->soap = rhs.soap;
	this->soap_own = false;
	this->soap_endpoint = rhs.soap_endpoint;
}

LacuisineBindingProxy::LacuisineBindingProxy(struct soap *_soap)
{	this->soap = _soap;
	this->soap_own = false;
	LacuisineBindingProxy_init(_soap->imode, _soap->omode);
}

LacuisineBindingProxy::LacuisineBindingProxy(struct soap *_soap, const char *soap_endpoint_url)
{	this->soap = _soap;
	this->soap_own = false;
	LacuisineBindingProxy_init(_soap->imode, _soap->omode);
	soap_endpoint = soap_endpoint_url;
}

LacuisineBindingProxy::LacuisineBindingProxy(const char *soap_endpoint_url)
{	this->soap = soap_new();
	this->soap_own = true;
	LacuisineBindingProxy_init(SOAP_IO_DEFAULT, SOAP_IO_DEFAULT);
	soap_endpoint = soap_endpoint_url;
}

LacuisineBindingProxy::LacuisineBindingProxy(soap_mode iomode)
{	this->soap = soap_new();
	this->soap_own = true;
	LacuisineBindingProxy_init(iomode, iomode);
}

LacuisineBindingProxy::LacuisineBindingProxy(const char *soap_endpoint_url, soap_mode iomode)
{	this->soap = soap_new();
	this->soap_own = true;
	LacuisineBindingProxy_init(iomode, iomode);
	soap_endpoint = soap_endpoint_url;
}

LacuisineBindingProxy::LacuisineBindingProxy(soap_mode imode, soap_mode omode)
{	this->soap = soap_new();
	this->soap_own = true;
	LacuisineBindingProxy_init(imode, omode);
}

LacuisineBindingProxy::~LacuisineBindingProxy()
{	if (this->soap_own)
	{	this->destroy();
		soap_free(this->soap);
	}
}

void LacuisineBindingProxy::LacuisineBindingProxy_init(soap_mode imode, soap_mode omode)
{	soap_imode(this->soap, imode);
	soap_omode(this->soap, omode);
	soap_endpoint = NULL;
	static const struct Namespace namespaces[] = {
        { "SOAP-ENV", "http://www.w3.org/2003/05/soap-envelope", "http://schemas.xmlsoap.org/soap/envelope/", NULL },
        { "SOAP-ENC", "http://www.w3.org/2003/05/soap-encoding", "http://schemas.xmlsoap.org/soap/encoding/", NULL },
        { "xsi", "http://www.w3.org/2001/XMLSchema-instance", "http://www.w3.org/*/XMLSchema-instance", NULL },
        { "xsd", "http://www.w3.org/2001/XMLSchema", "http://www.w3.org/*/XMLSchema", NULL },
        { "ns2", "http://truetechsystems.com.br/lacuisine/common/v1/", NULL, NULL },
        { "ns1", "http://truetechsystems.com.br/lacuisine/hmi/v1/", NULL, NULL },
        { NULL, NULL, NULL, NULL}
    };
	soap_set_namespaces(this->soap, namespaces);
}

LacuisineBindingProxy *LacuisineBindingProxy::copy()
{	LacuisineBindingProxy *dup = SOAP_NEW_UNMANAGED(LacuisineBindingProxy);
	if (dup)
	{	soap_done(dup->soap);
		soap_copy_context(dup->soap, this->soap);
	}
	return dup;
}

LacuisineBindingProxy& LacuisineBindingProxy::operator=(const LacuisineBindingProxy& rhs)
{	if (this->soap != rhs.soap)
	{	if (this->soap_own)
			soap_free(this->soap);
		this->soap = rhs.soap;
		this->soap_own = false;
		this->soap_endpoint = rhs.soap_endpoint;
	}
	return *this;
}

void LacuisineBindingProxy::destroy()
{	soap_destroy(this->soap);
	soap_end(this->soap);
}

void LacuisineBindingProxy::reset()
{	this->destroy();
	soap_done(this->soap);
	soap_initialize(this->soap);
	LacuisineBindingProxy_init(SOAP_IO_DEFAULT, SOAP_IO_DEFAULT);
}

void LacuisineBindingProxy::soap_noheader()
{	this->soap->header = NULL;
}

::SOAP_ENV__Header *LacuisineBindingProxy::soap_header()
{	return this->soap->header;
}

::SOAP_ENV__Fault *LacuisineBindingProxy::soap_fault()
{	return this->soap->fault;
}

const char *LacuisineBindingProxy::soap_fault_subcode()
{	return ::soap_fault_subcode(this->soap);
}

const char *LacuisineBindingProxy::soap_fault_string()
{	return ::soap_fault_string(this->soap);
}

const char *LacuisineBindingProxy::soap_fault_detail()
{	return ::soap_fault_detail(this->soap);
}

int LacuisineBindingProxy::soap_close_socket()
{	return ::soap_closesock(this->soap);
}

int LacuisineBindingProxy::soap_force_close_socket()
{	return ::soap_force_closesock(this->soap);
}

void LacuisineBindingProxy::soap_print_fault(FILE *fd)
{	::soap_print_fault(this->soap, fd);
}

#ifndef WITH_LEAN
#ifndef WITH_COMPAT
void LacuisineBindingProxy::soap_stream_fault(std::ostream& os)
{	::soap_stream_fault(this->soap, os);
}
#endif

char *LacuisineBindingProxy::soap_sprint_fault(char *buf, size_t len)
{	return ::soap_sprint_fault(this->soap, buf, len);
}
#endif

int LacuisineBindingProxy::send_AccessAuthentication(const char *soap_endpoint_url, const char *soap_action, ns1__AccessAuthenticationRequestType *ns1__AccessAuthenticationRequest)
{
	struct __ns1__AccessAuthentication soap_tmp___ns1__AccessAuthentication;
	if (soap_endpoint_url != NULL)
		soap_endpoint = soap_endpoint_url;
	if (soap_endpoint == NULL)
		soap_endpoint = "http://localhost:9090/zzz";
	if (soap_action == NULL)
		soap_action = "tns:AccessAuthentication";
	soap_tmp___ns1__AccessAuthentication.ns1__AccessAuthenticationRequest = ns1__AccessAuthenticationRequest;
	soap_begin(soap);
	soap->encodingStyle = NULL; /* use SOAP literal style */
	soap_serializeheader(soap);
	soap_serialize___ns1__AccessAuthentication(soap, &soap_tmp___ns1__AccessAuthentication);
	if (soap_begin_count(soap))
		return soap->error;
	if ((soap->mode & SOAP_IO_LENGTH))
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put___ns1__AccessAuthentication(soap, &soap_tmp___ns1__AccessAuthentication, "-ns1:AccessAuthentication", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put___ns1__AccessAuthentication(soap, &soap_tmp___ns1__AccessAuthentication, "-ns1:AccessAuthentication", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	return SOAP_OK;
}

int LacuisineBindingProxy::recv_AccessAuthentication(ns1__AccessAuthenticationResponseType &ns1__AccessAuthenticationResponse)
{
	ns1__AccessAuthenticationResponse.soap_default(soap);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	ns1__AccessAuthenticationResponse.soap_get(soap, "ns1:AccessAuthenticationResponse", NULL);
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}
/* End of client proxy code */