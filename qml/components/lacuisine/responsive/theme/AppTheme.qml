/******************************************************************************

Copyright (C) 2015 Burkhard Stubert, Embedded Use (DBA), Germany
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and/or other materials provided with the distribution.
    * Neither the name of Embedded Use (DBA) nor the
      names of its contributors may be used to endorse or promote products
      derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL BURKHARD STUBERT, EMBEDDED USE (DBA), BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

******************************************************************************/

pragma Singleton
import QtQuick 2.0

QtObject
{
    id: root

    readonly property real refScreenWidth: 1600
    readonly property real refScreenHeight: 1200

    //Raspi
//    readonly property real screenWidth: 640
//    readonly property real screenHeight: 480

    //Desktop
    readonly property real screenWidth: 1600
    readonly property real screenHeight: 1200

    function hscale(size) {
        return Math.round(size * (screenWidth / refScreenWidth))
    }

    function vscale(size) {
        return Math.round(size * (screenHeight / refScreenHeight))
    }

    function tscale(size) {
        return Math.round((hscale(size) + vscale(size)) / 2)
    }

    readonly property real screenLeftMargin: hscale(16)
    readonly property real screenRightMargin: screenLeftMargin
    readonly property real statusBarHeight: vscale(79)
    readonly property real mainPageHeight: vscale(599)
    readonly property real appToolBarHeight: vscale(120)
    readonly property real dividerSize: 1

    readonly property int textSizeNormal: tscale(42)
    readonly property int textSizeSmall: tscale(32)
    readonly property int textSizeVerySmall: tscale(24)
    readonly property int textSizeExtraSmall: tscale(18)
    readonly property int textSizeUltraSmall: tscale(10)
    readonly property int textSize_12: tscale(12)

    readonly property color textColorNormal: "#ffec8b" // lightgoldenrod 1
    readonly property color textColorSmall: "#cdbe70" // lightgoldenrod 3
    readonly property color textColorSelected: "#7FFF00" // chartreuse

    readonly property real leftTabButtonWidth: hscale(319)
    readonly property real leftTabButtonHeight: vscale(99)
    readonly property real toolButtonWidth: hscale(191)
    readonly property real toolButtonHeight: vscale(99)
    readonly property int buttonBorderWidth: 2

    //Get Started Buttons
    readonly property real getStartedWidth: AppTheme.hscale(256)
    readonly property real getStartedHeight: AppTheme.vscale(174)

    //SelectItemPanel
    readonly property real selectItemWidth: hscale(600)
    readonly property real selectItemHeight: vscale(522)
    //ToolBar Size Button
    readonly property real toolBarButtonWidth: hscale(100)
    readonly property real toolBarButtonHeight: vscale(58)
    //ToolBar Size List
    readonly property real toolBarListWidth: hscale(600)
    //ToolBar Height
    readonly property real toolBarHeight: vscale(58)
    // Small Restaurant Logo
    readonly property real smallRestaurantLogoWidth: hscale(44)
    readonly property real smallRestaurantLogoHeight: vscale(44)
    // Normal Restaurant Logo
    readonly property real normalRestaurantLogoWidth: hscale(144)
    readonly property real normalRestaurantLogoHeight: vscale(144)
    // Normal TrueTech Logo
    readonly property real normalTipoGrLogoWidth: hscale(44)
    readonly property real normalTipoGrLogoHeight: vscale(31)
    // Normal Tipographic Logo
    readonly property real normalTthLogoWidth: hscale(58)
    readonly property real normalTthLogoHeight: vscale(20)
    // Drawer Buttons
    readonly property real drawerButtonsHeight: vscale(60)
    // Drawer Component Closed
    readonly property real drawerClosedWidth: hscale(60)
    readonly property real drawerClosedHeight: vscale(522)
    // Drawer Component Opened
    readonly property real drawerOpenedWidth: hscale(200)
    readonly property real drawerOpenedHeight: vscale(402)
    // Item Delegate
    readonly property real offsetScroolBarWidth: hscale(25)
    readonly property real itemExpandedWidth: hscale(735)
    readonly property real itemWidth: hscale(594)
    readonly property real itemHeight: vscale(86)
    // Small Dish Illustration
    readonly property real dishIllustrationSmallWidth: hscale(113)
    readonly property real dishIllustrationSmallHeight: vscale(61)
    // ScrollBar Size
    readonly property real scrollItemWidth: hscale(23)
    readonly property real scrollItemHeight: vscale(452)
    readonly property real scrollLineCntIndicatorSmallWidh: hscale(6)
    readonly property real scrollLineCntIndicatorNormalWidn: hscale(12)
    // Total Cost
    readonly property real squareCostWidth: hscale(100)
    readonly property real squareCostHeight: vscale(58)

    readonly property int columnSpacing_2: tscale(2)
    readonly property int columnSpacing_3: tscale(3)
    readonly property int columnSpacing_5: tscale(5)
    readonly property int columnSpacing_10: tscale(10)
    readonly property int columnSpacing_15: tscale(15)
    readonly property int columnSpacing_20: tscale(20)
    readonly property int columnSpacing_25: tscale(25)
    readonly property int columnSpacing_30: tscale(30)
}
