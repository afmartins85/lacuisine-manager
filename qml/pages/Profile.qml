import QtQuick 2.12
import Qt.labs.platform 1.0
import lacuisine.responsive.theme 1.0

ProfileForm {

    function exitedEditMode () {
        editMode = false;
        editButtom.visible = true
        editButtom.enabled = true
    }

    function enteredEditMode () {
        editMode = true;
        editButtom.visible = false
        editButtom.enabled = false
        restoreCompanyName = companyName.text
        restorCompanyLogo = logo.source
        console.log("CompanyLogo Url: " + restorCompanyLogo)
        console.log("CompanyName: " + restoreCompanyName)
    }

    companyLogo {
        Behavior on width {
            NumberAnimation { duration: 100 }
        }
        Behavior on height {
            NumberAnimation { duration: 100 }
        }
    }

    mouse.onClicked: {
        if (editMode === true) {
            openLogoDialog.open();
            isLoadedImage = true;
        }
    }
    mouse.onExited: {
        if (editMode === true) {
            companyLogo.width = AppTheme.normalRestaurantLogoWidth;
            companyLogo.height = AppTheme.normalRestaurantLogoHeight;
        }
    }
    mouse.onEntered: {
        if (editMode === true) {
            companyLogo.width = AppTheme.normalRestaurantLogoWidth + (AppTheme.normalRestaurantLogoWidth * 0.4);
            companyLogo.height = AppTheme.normalRestaurantLogoHeight + (AppTheme.normalRestaurantLogoHeight * 0.4);
        }
    }

    editButtom {
        onHoveredChanged: {
            if (editButtomHovered === false) {
                editButtomHovered = true;
                editButtom.opacity = 0.4;
            } else {
                editButtomHovered = false;
                editButtom.opacity = 1;
            }
        }
        onClicked: {
            enteredEditMode();
        }
    }

    editCancelButtom {
        onClicked: {
            exitedEditMode();
            companyName.text = restoreCompanyName
            logo.source = restorCompanyLogo
        }
    }

    editAcceptButtom {
        onClicked: {
            exitedEditMode();
        }
    }

    Component.onCompleted: {
        openLogoDialog.folder = StandardPaths.writableLocation(StandardPaths.DocumentsLocation);
    }
}



/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
##^##*/
