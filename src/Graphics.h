/*
 * Graphics.h
 *
 *  This class handles all the graphics, and interface details for the project
 */

#ifndef GRAPHICS_H_
#define GRAPHICS_H_

#include <iostream>

#include <GL/gl.h>
#include <GL/glext.h>
#include <GL/glui.h>
#include <Box2D/Box2D.h>

#include "Settings.h"
#include "Utilities.h"
#include "Physics.h"
#include "BMPLoader.h"

//Initializes all the graphics parameters
void initGraphics(int argc, char* argv[], void (* simulationFunction)(void));

//Draws the given object onto the screen
void draw (float32 x, float32 y, float32 angle, float32 wifth, float32 height, GLuint textureID);

#endif /* GRAPHICS_H_ */
