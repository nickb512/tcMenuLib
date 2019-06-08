/*
    The code in this file uses open source libraries provided by thecoderscorner

    DO NOT EDIT THIS FILE, IT WILL BE GENERATED EVERY TIME YOU USE THE UI DESIGNER
    INSTEAD EITHER PUT CODE IN YOUR SKETCH OR CREATE ANOTHER SOURCE FILE.

    All the variables you may need access to are marked extern in this file for easy
    use elsewhere.
 */

#include <tcMenu.h>
#include "remoteControlSerial_menu.h"

// Global variable declarations

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);
LiquidCrystalRenderer renderer(lcd, 16, 2);

// Global Menu Item declarations

const PROGMEM AnyMenuInfo minfoPushMe = { "Push Me", 6, 0xffff, 0, onPushMe };
ActionMenuItem menuPushMe(&minfoPushMe, NULL);
const char enumStrFood_0[] PROGMEM = "Pizza";
const char enumStrFood_1[] PROGMEM = "Pasta";
const char enumStrFood_2[] PROGMEM = "Salad";
const char* const enumStrFood[] PROGMEM  = { enumStrFood_0, enumStrFood_1, enumStrFood_2 };
const PROGMEM EnumMenuInfo minfoFood = { "Food", 5, 0xffff, 2, NO_CALLBACK, enumStrFood };
EnumMenuItem menuFood(&minfoFood, 0, &menuPushMe);
const PROGMEM TextMenuInfo minfoMyText = { "MyText", 4, 0xffff, 10, NO_CALLBACK };
TextMenuItem menuMyText(&minfoMyText, &menuFood);
const PROGMEM AnalogMenuInfo minfoA2Voltage = { "A2 Voltage", 3, 0xffff, 1024, NO_CALLBACK, 0, 200, "V" };
AnalogMenuItem menuA2Voltage(&minfoA2Voltage, 0, &menuMyText);
const PROGMEM AnalogMenuInfo minfoA1Voltage = { "A1 Voltage", 2, 0xffff, 1024, NO_CALLBACK, 0, 200, "V" };
AnalogMenuItem menuA1Voltage(&minfoA1Voltage, 0, &menuA2Voltage);
const PROGMEM AnalogMenuInfo minfoA0Voltage = { "A0 Voltage", 1, 0xffff, 1024, NO_CALLBACK, 0, 200, "V" };
AnalogMenuItem menuA0Voltage(&minfoA0Voltage, 0, &menuA1Voltage);
const PROGMEM ConnectorLocalInfo applicationInfo = { "Remote Ctrl", "f018e07a-f33f-42d2-b3a0-689a1bf6849c" };

// Set up code

void setupMenu() {
    lcd.begin(16, 2);
    lcd.configureBacklightPin(10);
    lcd.backlight();
    switches.initialise(ioUsingArduino(), true);
    menuMgr.initForEncoder(&renderer, &menuA0Voltage, ENCODER_PIN_A, ENCODER_PIN_B, ENCODER_PIN_OK);
    remoteServer.begin(&Serial, &applicationInfo);

    // Read only and local only function calls
    menuA0Voltage.setReadOnly(true);
    menuA1Voltage.setReadOnly(true);
    menuA2Voltage.setReadOnly(true);
}

