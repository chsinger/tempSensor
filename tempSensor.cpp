/*
 * tempSensor.cpp
 *
 *  Created on: Nov 7, 2012
 *      Author: christoph
 */

#include "tempSensor.h"

using namespace std;


tempSensor::tempSensor() {
	sensId = "";
}

tempSensor::tempSensor(string id) {
	this->setId(id);
}

void tempSensor::setId(string id) {
	this->sensId = id;
}

float tempSensor::getTemp() {
		char* path = new char[45];
		strcpy(path,"/sys/bus/w1/devices/");
		strcat(path,this->sensId.c_str());
		strcat(path,"/w1_slave");

		ifstream fp;
		char line[60];
		char *tmpstring;
		int temp = 0;
		float retTemp = 0;

		fp.open(path,ios::in);
		assert(!fp.fail());

		while (!fp.eof()) {
			fp >> line;
		}

		tmpstring = strtok(line, "=");
		tmpstring = strtok(NULL, "=");

		temp = atoi(tmpstring);

		retTemp = temp / 1000.000;

		if ( retTemp < -30 || retTemp > 100 ) {
			retTemp = 0;
		}

		return retTemp;
}

tempSensor::~tempSensor() {
}


