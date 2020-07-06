import QtQuick 2.4

LoginForm {

    function entry () {
        if (soapClient.openUserSession(userName.text, passwd.text) === true ) {
            stackView.push("Profile.qml");
            close();
        } else {
            loginErrorFlag = true;
        }
    }

    userName {
        onTextChanged: {
            loginErrorFlag = false
        }
        onAccepted: {
            entry();
        }
    }

    passwd {
        onTextChanged: {
            loginErrorFlag = false
        }
        onAccepted: {
            entry();
        }
    }

    submmit {
        onPressed: {
            entry();
        }
    }
}
