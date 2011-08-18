/*
 * ContactListener.h
 *
 *  The functions of this class are called whenever two physical
 *  objects collide with each other.
 */

#ifndef CONTACT_LISTENER_H_
#define CONTACT_LISTENER_H_

#include <iostream>

#include <Box2D/Box2D.h>

#include "Utilities.h"
#include "ObjectData.h"

class ContactListener : public b2ContactListener {

	public:

		//Called after the collision has been resolved.
		void PostSolve(b2Contact* contact, const b2ContactImpulse* impulse);


};


#endif /* CONTACT_LISTENER_H_ */
