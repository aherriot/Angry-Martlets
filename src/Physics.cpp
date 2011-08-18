/*
 * Physics.cpp
 *
 *  Handles all the physics and physical object construction and destruction
 */

#include "Physics.h"

using namespace std;

b2World* world;
b2BodyDef* bodyDef;
b2FixtureDef* fixtureDef;
b2PolygonShape* box;
b2CircleShape* circle;

int currentLevel;

void initPhysics() {

	b2Vec2 gravity;
	gravity.Set(0.0f, -20.0f);
	bool doSleep = true;
	world = new b2World(gravity, doSleep);

	b2ContactListener* listener = new ContactListener();
	world->SetContactListener(listener);


	bodyDef = new b2BodyDef();
	bodyDef->type = b2_dynamicBody;

	box = new b2PolygonShape();
	circle = new b2CircleShape();

	fixtureDef = new b2FixtureDef();
	fixtureDef->density = 1.0f;
	fixtureDef->restitution = 0.5f;

	//Seeds the random number generator with the current time
	//So that it produces different values if it is run at different times
	srand(time(0));

}


void loadLevel1() {

	//Create Rabbits
	createRabbit(12.5, -2.0);
	createRabbit(12.5, -9.0);


	//Create castle structure
	createWoodPlank(12.5, 2.5, 0.0);
	createWoodPlank(12.5, -3.5, 0.0);

	createWoodPlank(10.0, 0.0, PI/2);
	createWoodPlank(15.0, 0.0, PI/2);

	createWoodPlank(10.0, -7.5, PI/2);
	createWoodPlank(15.0, -7.5, PI/2);

	//Ground
	createStaticPlank(0, -11.0, 0.0);

}

void loadLevel2() {

	//Create Castle structure
	createWoodPlank(-1.0, -7.5, PI/2);
	createWoodPlank(6.01, -7.5, PI/2);
	createWoodPlank(2.5, -10.0, 0);

	createWoodPlank(9.0, -7.5, PI/2);
	createWoodPlank(16.0, -7.5, PI/2);
	createWoodPlank(12.5, -10.0, 0);

	createWoodPlank(7.5, -4.0, 0);
	createWoodPlank(7.5, -2.0, 0);

	createWoodPlank(2.0, -3.0, 0);
	createWoodPlank(13.0, -3.0, 0);

	createWoodPlank(5.5, 0.5, PI/2);
	createWoodPlank(9.5, 0.5, PI/2);

	createWoodPlank(7.5, 3.0, 0);

	//Create Rabbits
	createRabbit(7.5, -10.0);
	createRabbit(7.5, -0.25);

	createRabbit(2.5, -8.5);
	createRabbit(12.5, -8.5);

	//Ground
	createStaticPlank(0, -11.0, 0.0);

}


//Create your own level here!
void loadLevel3() {

	createRabbit(12.5, -8.5);
	createStaticPlank(0.0, -11.0, 0.0);
}


//load the specified level
void loadWorld(int level) {


	currentLevel = level;

	switch (currentLevel){
		case 1:
			loadLevel1();
			break;

		case 2:
			loadLevel2();
			break;

		case 3:
			loadLevel3();
			break;

		default:
			loadLevel1();
	}
}

//load the default level
void loadWorld() {
	loadWorld(currentLevel);
}

void deletePhysicsWorld() {
	delete world;
	delete bodyDef;
	delete fixtureDef;
	delete box;
	delete circle;

	initPhysics();
	//loadWorld(currentLevel);
}

//Simulates the physical world by one slice of time
void physicsStep() {

	world->Step( settings.timeStep,
			settings.velocityIterations, settings.positionIterations);
	world->ClearForces();
}

//Get a list of all the physical bodies in the world
b2Body* getBodyList() {
	return world->GetBodyList();
}

//Get a count of all the physical bodies
int32 getBodyCount() {
	return world->GetBodyCount();
}


//creates a square object
b2Body* createSquareObject(float32 x, float32 y, float32 rotation, float32 width, float32 height) {

	bodyDef->position.Set(x, y);
	bodyDef->angle = rotation;

	box->SetAsBox(width, height);
	fixtureDef->shape = box;

	b2Body* body = world->CreateBody(bodyDef);
	body->CreateFixture(fixtureDef);

	return body;

}

//creates a circular object
b2Body* createCircleObject(float32 x, float32 y, float32 radius) {

	bodyDef->position.Set(x, y);
	bodyDef->angle = 0;

	circle->m_radius = radius;
	fixtureDef->shape = circle;

	b2Body* body = world->CreateBody(bodyDef);
	body->CreateFixture(fixtureDef);

	return body;

}

// Create's a rectanglar object that is static ( Does not move but still collides ).
b2Body* createStaticObject(float32 x, float32 y, float32 rotation, float32 width, float32 height){

	bodyDef->position.Set(x, y);
	bodyDef->angle = rotation;
	bodyDef->type = b2_staticBody;

	box->SetAsBox(width, height);
	fixtureDef->shape = box;

	b2Body* body = world->CreateBody(bodyDef);
	body->CreateFixture(fixtureDef);

	bodyDef->type = b2_dynamicBody;

	return body;

}

void destroyBody( b2Body* body ) {
	ObjectData* data = (ObjectData*)body->GetUserData();
	delete data;

	world->DestroyBody(body);

	//cout << data->getHeight() << endl;
}
