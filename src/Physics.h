/*
 * Physics.h
 *
 *  Handles all the physics and physical object construction and destruction
 */

#ifndef PHYSICS_H_
#define PHYSICS_H_

#include <iostream>
#include <fstream>
#include <string>
#include <time.h>

#include <Box2D/Box2D.h>

#include "Settings.h"
#include "Utilities.h"
#include "ObjectData.h"
#include "BMPLoader.h"
#include "ContactListener.h"


void initPhysics();

//loads the specified level
void loadWorld(int level);

//loads the currently selected level
void loadWorld();

void deletePhysicsWorld();

//Simulates the physical world by one slice of time
void physicsStep();

//Get a list of all the physical bodies in the world
b2Body* getBodyList();

//Get a count of all the physical bodies
int32 getBodyCount();

b2Body* createSquareObject(float32 x, float32 y, float32 rotation, float32 width, float32 height);
b2Body* createCircleObject(float32 x, float32 y, float32 radius);

// Create's a rectanglar object that is static ( Does not move but still collides ).
b2Body* createStaticObject(float32 x, float32 y, float32 rotation, float32 width, float32 height);

void destroyBody( b2Body* body );


#endif /* PHYSICS_H_ */
