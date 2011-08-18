/*
 * ContactListener.cpp
 *
 *  The functions of this class are called whenever two physical
 *  objects collide with each other.
 */

#include "ContactListener.h"

using namespace std;

//After the collision has been resolved.
void ContactListener::PostSolve(b2Contact* contact, const b2ContactImpulse* impulse) {

	//Determine the maximum amount of impulse that occurred in the collision resolution
	float32 maxImpulse = 0;
	for ( int i = 0; i < contact->GetManifold()->pointCount; i++) {
		if ( impulse->normalImpulses[i] > maxImpulse ) {
			maxImpulse = impulse->normalImpulses[i];
		}
	}

	//If the max impulse is greater than a threshold,
	//check to see if it was a rabbit, and kill it.
	//In other words, the rabbit has been hit hard enough to die.
	if ( maxImpulse > 30.0 ) {

		ObjectData* data = (ObjectData*)(contact->GetFixtureA()->GetBody()->GetUserData());

		if ( data->getType() == RABBIT ) {
			data->die();
		}

		data = (ObjectData*)(contact->GetFixtureB()->GetBody()->GetUserData());

		if ( data->getType() == RABBIT ) {
			data->die();
		}
	}

}
