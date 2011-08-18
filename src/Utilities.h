/*
 * Utilities.h
 *
 *    This file includes a few constants and functions
 *  that have no other real place to be defined.
 *
 */

#ifndef UTILITIES_H_
#define UTILITIES_H_

#include <Box2D/Box2D.h>

const float32 PI = 3.1415926535897932384626433832795;
const float32 RAD_2_DEG = 57.295779513082320876798154814114;
const float32 DEG_2_RAD = 0.017453292519943295769236907684883;

//Constants for the differentObjectData->type values
const int32 WOOD = 0;
const int32 RABBIT = 1;
const int32 MARTLET = 2;
const int32 GROUND = 3;

float32 randFloat(float32 min, float32 max);

int32 randInt(int32 min, int32 max);

#endif /* UTILITIES_H_ */
