/*
 * tempSensor.h
 *
 *  Created on: Nov 7, 2012
 *      Author: christoph
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <cassert>

using namespace std;


class tempSensor {
private:
	string sensId;
	float lastTemp;
	float retTemp;
public:
	tempSensor();
	tempSensor(string sensId);
	virtual ~tempSensor();
	void setId(string sensId);
	float getTemp();
	float getLastTemp();
	void setLastTemp(float lastTempVal);
};

