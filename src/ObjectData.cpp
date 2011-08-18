/*
 * ObjectData.cpp
 *
 *  This class represents data that is attached to each physical body
 *  which contains extra information.
 *
 */

#include "ObjectData.h"

ObjectData::ObjectData(float32 width, float32 height, b2Body* body, GLuint textureID, int32 type) {

	this->body = body;
	this->width = width;
	this->height = height;
	dead = false;
	this->textureID = textureID;
	this->type = type;
}

//Should the body be deleted?
bool ObjectData::isDead() {
	return dead;
}

//Set the object to be deleted in the next game cycle.
void ObjectData::die() {
	dead = true;
}

float ObjectData::getWidth() {
	return width;
}

float ObjectData::getHeight() {
	return height;
}

GLuint ObjectData::getTextureID() {
	return textureID;
}

int32 ObjectData::getType() {
	return type;
}
