/*
 * Settings.h
 *
 *  This file retrieves and holds parameters for the physics and graphics,
 *  read from "data/Settings.txt"
 *
 */

#ifndef SETTINGS_H_
#define SETTINGS_H_

#include <iostream>
#include <fstream>
#include <string>

#include <Box2D/Box2D.h>
#include <GL/gl.h>

#include "BMPLoader.h"
#include "ObjectDefinitions.h"

using namespace std;

struct Settings {

	int32 windowWidth;
	int32 windowHeight;
	int32 windowPositionX;
	int32 windowPositionY;

	float32 timeStep;
	int32 velocityIterations;
	int32 positionIterations;

};

extern Settings settings;

void loadSettings();


#endif /* SETTINGS_H_ */
