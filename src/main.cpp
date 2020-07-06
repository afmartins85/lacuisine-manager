/****************************************************************************
**
** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/legal
**
** This file is part of the Qt Quick Controls module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** You may use this file under the terms of the BSD license as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of Digia Plc and its Subsidiary(-ies) nor the names
**     of its contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include "gsoap/soapLacuisineBindingProxy.h"
#include "loguru.hpp"
#include "paystation/paystation.h"
#include "soapclient.h"
#include "sysinfo.h"
#include "unixsignalhandle.h"
#include <QGuiApplication>
#include <QQmlComponent>
#include <QQmlContext>
#include <QQmlEngine>
#include <QQmlFileSelector>
#include <QQuickStyle>
#include <QQuickView>
#include <QSettings>
#include <QtQml/QQmlApplicationEngine>

int main(int argc, char *argv[]) {
  QGuiApplication::setOrganizationName("TrueTech Systems");
  QGuiApplication::setOrganizationDomain("truetechsystems.com.br");
  QGuiApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

  QGuiApplication app(argc, argv);

  // Starting the log supervisor
  loguru::init(argc, argv);

  qmlRegisterType<PayStation>("LaCuisine", 1, 0, "PayStation");
  qmlRegisterType<SysInfo>("LaCuisine", 1, 0, "SysInfo");
  qmlRegisterType<SoapClient>("LaCuisine", 1, 0, "SoapClient");
  qmlRegisterType<UnixSignalHandle>("LaCuisine", 1, 0, "UnixSignalHandle");

  QIcon::setThemeName("lacuisine");

  QSettings settings;
  QString style = QQuickStyle::name();
  if (!style.isEmpty()) {
    settings.setValue("style", style);
  } else {
    QQuickStyle::setStyle(settings.value("style").toString());
  }

  LacuisineBindingProxy testProxy("https://138.68.29.14:9090");

  soap_ssl_init();
  if (soap_ssl_client_context(testProxy.soap, SOAP_SSL_DEFAULT, "/usr/local/share/ca-certificates/lacuisine/client.pem",
                              "ZIWw3HND$yG6naizADpF", "/usr/local/share/ca-certificates/lacuisine/cacert.pem", NULL,
                              NULL)) {
    testProxy.soap_print_fault(stderr);
    exit(1);
  }

  QQmlApplicationEngine engine;
  engine.rootContext()->setContextProperty("availableStyles", QQuickStyle::availableStyles());
  engine.addImportPath(":/qml");
  engine.addImportPath(":/qml/components");
  engine.addImportPath(":/qml/pages");
  engine.load(QUrl(QStringLiteral("qrc:/qml/lacuisine.qml")));

  return app.exec();
}
