/*
 * Angry Martlets
 *
 * Andrew Herriot
 * Undergraduate Directed Studies Project, Computer Science
 * University of Victoria, Canada
 *
 */

#include <iostream>
#include <GL/gl.h>
#include <Box2D/Box2D.h>

#include "Settings.h"
#include "Utilities.h"
#include "Graphics.h"
#include "Physics.h"
#include "ObjectDefinitions.h"

using namespace std;


//This function is called for each slice of time (60 times a second)
void mainLoop () {

	//Step through the physics simulation
	physicsStep();

	//Set up the graphics for this frame
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);

	//Get a linked list of our objects
	b2Body* node = getBodyList();

	while( node ) {

		// ...
		b2Body* nextNode = node->GetNext();

		//Fetch our own data that we pinned to the object
		ObjectData* data = (ObjectData*)node->GetUserData();

		//Check to see if the object should be deleted
		if ( data->isDead() ) {
			destroyBody(node);
			node = nextNode;
			continue;
		}

		//Get some information about the object, so we can draw it
		float32 angle = node->GetAngle();
		b2Vec2 position = node->GetPosition();
		float32 x = position.x;
		float32 y = position.y;

		//render the Object
		draw(x, y, angle, data->getWidth(), data->getHeight(), data->getTextureID());

		//Get the next node
		node = nextNode;
	}

	//Display the rendered image
	glutSwapBuffers();

}

int main(int argc, char* argv[]) {

	//Loads the settings for the graphics and physics from "data/Settings.txt"
	loadSettings();

	//Initializes the graphics and gui.
	initGraphics( argc, argv, mainLoop);

	//loads the textures
	loadTextures();

	//Initializes the physics
	initPhysics();

	//The loads the objects into the game world
	loadWorld(1);

	//Starts the main game loop
	glutMainLoop();

	return 0;
}
