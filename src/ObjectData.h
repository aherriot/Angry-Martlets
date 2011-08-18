/*
 * UserData.h
 *
 *  This class represents data that is attached to each physical body
 *  which contains extra information.
 */

#ifndef OBJECT_DATA_H_
#define OBJECT_DATA_H_

#include <GL/gl.h>
#include <Box2D/Box2D.h>

#include "BMPLoader.h"
#include "Physics.h"

class ObjectData {

	private:
		b2Body* body;
		float32 width;
		float32 height;
		bool dead;

		GLuint textureID;
		int32 type;

	public:
		ObjectData(float32 width, float32 height, b2Body* body,
				GLuint textureID, int32 team);

		//Should the body be deleted?
		bool isDead();

		//Set the object to be deleted in the next game cycle.
		void die();

		float32 getWidth();
		float32 getHeight();
		GLuint getTextureID();
		int32 getType();
};


#endif /* OBJECT_DATA_H_ */
