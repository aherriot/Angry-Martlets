/*
 * ObjectDefinition.h
 *
 *  This file contain constructors for each type of object for Angry Martlets,
 *  and it also loads the textures for each one.
 */

#ifndef OBJECT_DEFINITIONS_H_
#define OBJECT_DEFINITIONS_H_

#include <iostream>
#include <string>

#include <GL/GL.h>
#include <Box2D/Box2D.h>

#include "BMPLoader.h"
#include "Physics.h"

using namespace std;

//Loads the textures listed above into the video memory
void loadTextures();

b2Body* createWoodPlank(float32 x, float32 y, float32 rotation);

b2Body* createRabbit(float32 x, float32 y);

b2Body* createMartlet(b2Vec2 position, b2Vec2 impulse);

//This object is rectangular and does not move when something collides with it
b2Body* createStaticPlank(float32 x, float32 y, float32 rotation);



#endif /* OBJECT_DEFINITIONS_H_ */
