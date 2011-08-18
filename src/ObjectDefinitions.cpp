/*
 * ObjectDefinition.cpp
 *
 *  Created on: 2011-06-20
 *      Author: Andrew
 */

#include "ObjectDefinitions.h"


namespace {
	//When you update the list of textures, make sure you also
	//change the NUMBER_OF_TEXTURES constant.
	string textureName[] = {"Plank.bmp", "Rabbit.bmp", "Martlet.bmp"};
	#define NUMBER_OF_TEXTURES 3

	GLuint textureID[NUMBER_OF_TEXTURES];
}

//Loads the textures listed above into the video memory
void loadTextures() {

	glEnable(GL_TEXTURE_2D);

	glGenTextures(NUMBER_OF_TEXTURES, textureID);

	BMPClass* img = new BMPClass();

	for( int i = 0; i < NUMBER_OF_TEXTURES; i++) {

		glBindTexture(GL_TEXTURE_2D, textureID[i]);

		BMPLoad("images/" + textureName[i], img);

		//glTexImage2D(GL_TEXTURE_2D,0,3,img->width,img->height,0,GL_RGB,GL_UNSIGNED_BYTE,img->bytes);
		glTexImage2D(GL_TEXTURE_2D,0,4,img->width,img->height,0,GL_RGBA,GL_UNSIGNED_BYTE,img->transparencyBytes);


		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
	}

	delete img;

}

b2Body* createWoodPlank(float32 x, float32 y, float32 rotation) {

	b2Body* plank = createSquareObject( x, y, rotation, 3.0, 0.5);

	plank->SetUserData(new ObjectData(3.0, 0.5, plank, textureID[0], WOOD));

	return plank;
}

b2Body* createRabbit(float32 x, float32 y) {

	b2Body* rabbit = createCircleObject(x, y, 1.0);

	rabbit->SetUserData( new ObjectData(1.0, 1.0, rabbit, textureID[1], RABBIT) );

	return rabbit;
}

b2Body* createMartlet(b2Vec2 position, b2Vec2 impulse) {

	b2Body* martlet = createCircleObject(position.x, position.y, 0.75);

	martlet->SetUserData( new ObjectData(0.8, 0.8, martlet, textureID[2], MARTLET) );

	martlet->ApplyLinearImpulse(impulse, martlet->GetPosition());

	return martlet;
}


//This object is rectangular and does not move when something collides with it
b2Body* createStaticPlank(float32 x, float32 y, float32 rotation) {

	b2Body* plank = createStaticObject( x, y, rotation, 20.0, 0.5);

	plank->SetUserData(new ObjectData(20.0, 0.5, plank, textureID[0], GROUND));

	return plank;
}


