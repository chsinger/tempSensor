/*
 * tempSensor.cpp
 *
 *  Created on: Nov 7, 2012
 *      Author: tuxmux28 
 */

#include "tempSensor.h"

using namespace std;


tempSensor::tempSensor() {
	this->sensId = "";
	this->retTemp = 0.0;
	this->lastTemp = 0.0;
}

tempSensor::tempSensor(string id) {
	this->setId(id);
	this->lastTemp = 0.0;
	this->retTemp = 0.0;
}

void tempSensor::setId(string id) {
	this->sensId = id;
}

float tempSensor::getTemp() {
		char* path = new char[45];
		strcpy(path,"/sys/bus/w1/devices/");
		strcat(path,this->sensId.c_str());
		strcat(path,"/w1_slave");

		this->lastTemp = this->retTemp;
		ifstream fp;
		char line[60];
		char *tmpstring;
		int findYes = 0;
		int temp = 0;

		fp.open(path,ios::in);
		assert(!fp.fail());

		while (!fp.eof()) {
			fp >> line;
			if (strstr(line, "YES")) findYes++;
		}

		if  (findYes == 0) { 
			this->retTemp = this->lastTemp;
		}
		else {
			tmpstring = strtok(line, "=");
			tmpstring = strtok(NULL, "=");

			temp = atoi(tmpstring);

			this->retTemp = temp / 1000.000;
		}

		return this->retTemp;
}

float tempSensor::getLastTemp() {
	return this->lastTemp;
}

void tempSensor::setLastTemp(float lastTempVal) {
	this->lastTemp = lastTempVal;
}

tempSensor::~tempSensor() {
}


