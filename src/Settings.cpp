/*
 * Settings.cpp
 *
 *  This file retrieves and holds parameters for the physics and graphics,
 *  read from "data/Settings.txt"
 *
 */

#include "Settings.h"

Settings settings;

void loadSettings() {

	//open a file, parse it, and store the data
	ifstream file("data/Settings.txt");
	if ( file.is_open() ) {

		string line[7];
		int i = 0;

		while ( file.good() ) {
			getline( file, line[i]);
			if (line[i].length() != 0 && line[i].at(0) != '#') {
				i++;
			}
		}
		file.close();

		settings.windowWidth = atoi(line[0].c_str());
		settings.windowHeight = atoi(line[1].c_str());
		settings.windowPositionX = atoi(line[2].c_str());
		settings.windowPositionY = atoi(line[3].c_str());

		settings.timeStep = atof(line[4].c_str());
		settings.velocityIterations = atoi(line[5].c_str());
		settings.positionIterations = atoi(line[6].c_str());

	//If the file fails to open, use the following default settings
	} else {

		settings.windowWidth = 1280;
		settings.windowHeight = 720;
		settings.windowPositionX = 100;
		settings.windowPositionY = 100;

		settings.timeStep = 1.0 / 60.0;
		settings.velocityIterations = 10;
		settings.positionIterations = 10;
	}
}
