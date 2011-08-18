/*
 * Utilities.cpp
 *
 *  This file includes a few constants and functions
 *  that have no other real place to be defined.
 */

#include "Utilities.h"


float32 randFloat(float32 min, float32 max) {

	float32 result = rand() / (float)RAND_MAX;

	return result * (max - min) + min;

}

int32 randInt(int32 min, int32 max) {

	return rand() % (max - min + 1) + min;
}
