/*
    The code in this file uses open source libraries provided by thecoderscorner

    DO NOT EDIT THIS FILE, IT WILL BE GENERATED EVERY TIME YOU USE THE UI DESIGNER
    INSTEAD EITHER PUT CODE IN YOUR SKETCH OR CREATE ANOTHER SOURCE FILE.

    All the variables you may need access to are marked extern in this file for easy
    use elsewhere.
 */

#include <tcMenu.h>
#include "colorTftEthernet32_menu.h"

// Global variable declarations

AdaFruitGfxMenuRenderer renderer;
const char applicationName[] = "Turntable";
EthernetServer server(3333);

// Global Menu Item declarations

const FloatMenuInfo minfoVoltA1 = { "Volt A1", 9, 0xffff, 2, NO_CALLBACK };
FloatMenuItem menuVoltA1(&minfoVoltA1, NULL);
const FloatMenuInfo minfoVoltA0 = { "Volt A0", 8, 0xffff, 2, NO_CALLBACK };
FloatMenuItem menuVoltA0(&minfoVoltA0, &menuVoltA1);
const SubMenuInfo minfoStatus = { "Status", 7, 0xffff, 0, NO_CALLBACK };
BackMenuItem menuBackStatus(&menuVoltA0, (const AnyMenuInfo*)&minfoStatus);
SubMenuItem menuStatus(&minfoStatus, &menuBackStatus, NULL);
const BooleanMenuInfo minfoTempCheck = { "Temp Check", 13, 9, 1, NO_CALLBACK, NAMING_ON_OFF };
BooleanMenuItem menuTempCheck(&minfoTempCheck, false, NULL);
const BooleanMenuInfo minfoSCircuitProtect = { "S-Circuit Protect", 12, 8, 1, NO_CALLBACK, NAMING_ON_OFF };
BooleanMenuItem menuSCircuitProtect(&minfoSCircuitProtect, false, &menuTempCheck);
const SubMenuInfo minfoAdvanced = { "Advanced", 11, 0xffff, 0, NO_CALLBACK };
BackMenuItem menuBackAdvanced(&menuSCircuitProtect, (const AnyMenuInfo*)&minfoAdvanced);
SubMenuItem menuAdvanced(&minfoAdvanced, &menuBackAdvanced, NULL);
const AnyMenuInfo minfoSaveAll = { "Save all", 10, 0xffff, 0, onSaveRom };
ActionMenuItem menuSaveAll(&minfoSaveAll, &menuAdvanced);
const RemoteMenuInfo minfoRemote = { "Remote", 6, 0xffff, 0, NO_CALLBACK };
RemoteMenuItem menuRemote(&minfoRemote, remoteServer.getRemoteConnector(0), &menuSaveAll);
const BooleanMenuInfo minfoPwrDelay = { "Pwr Delay", 5, 0xffff, 1, NO_CALLBACK, NAMING_YES_NO };
BooleanMenuItem menuPwrDelay(&minfoPwrDelay, false, &menuRemote);
const SubMenuInfo minfoSettings = { "Settings", 4, 0xffff, 0, NO_CALLBACK };
BackMenuItem menuBackSettings(&menuPwrDelay, (const AnyMenuInfo*)&minfoSettings);
SubMenuItem menuSettings(&minfoSettings, &menuBackSettings, &menuStatus);
const char enumStrLimit_0[] = "Current";
const char enumStrLimit_1[] = "Voltage";
const char* const enumStrLimit[]  = { enumStrLimit_0, enumStrLimit_1 };
const EnumMenuInfo minfoLimit = { "Limit", 3, 6, 1, onLimitMode, enumStrLimit };
EnumMenuItem menuLimit(&minfoLimit, 0, &menuSettings);
const AnalogMenuInfo minfoCurrent = { "Current", 2, 4, 255, onCurrentChange, 0, 100, "A" };
AnalogMenuItem menuCurrent(&minfoCurrent, 0, &menuLimit);
const AnalogMenuInfo minfoVoltage = { "Voltage", 1, 2, 255, onVoltageChange, -128, 2, "V" };
AnalogMenuItem menuVoltage(&minfoVoltage, 0, &menuCurrent);

// Set up code

void setupMenu() {
    renderer.setGraphicsDevice(&gfx, &colorConfig);
    switches.initialise(io8574, true);
    menuMgr.initForEncoder(&renderer, &menuVoltage, ENCODER_PIN_A, ENCODER_PIN_B, ENCODER_PIN_OK);
    remoteServer.begin(&server, applicationName);
}

