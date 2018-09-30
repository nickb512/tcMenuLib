/*
 * Copyright (c) 2018 https://www.thecoderscorner.com (Nutricherry LTD).
 * This product is licensed under an Apache license, see the LICENSE file in the top-level directory.
 */

/**
 * Serial remote capability plugin. This file is a plugin file and should not be directly edited,
 * it will be replaced each time the project is built. If you want to edit this file in place,
 * make sure to rename it first.
 */

#include "SerialTransport.h"
#include "tcMenu.h"

SerialTagValServer serialServer;

SerialTagValueTransport::SerialTagValueTransport() : TagValueTransport() {
	this->serialPort = NULL;
}

void SerialTagValueTransport::close() {
	currentField.msgType = UNKNOWN_MSG_TYPE;
	currentField.fieldType = FVAL_PROCESSING_AWAITINGMSG;
}

void SerialTagValServer::begin(Stream* portStream, const char* namePgm) {
	serPort.setStream(portStream);
	connector.setName(namePgm);
	taskManager.scheduleFixedRate(TICK_INTERVAL, []{serialServer.runLoop();}, TIME_MILLIS);
}

SerialTagValServer::SerialTagValServer() : connector(&serPort, 0) {
}

void SerialTagValServer::runLoop() {
	connector.tick();
}
