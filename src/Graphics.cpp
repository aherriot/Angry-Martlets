/*
 * Graphics.cpp
 *
 *  This class handles all the graphics, and interface details for the project
 *
 */

#include "Graphics.h"



using namespace std;

namespace {

	int32 mainWindow;
	float32 viewZoom = 1.0f;
	b2Vec2 viewCenter(0.0f, 0.0f);
	GLUI* gui;

}

//Called when the window is resized
void reshapeFunction(int w, int h) {


	int tx, ty, tw, th;
	GLUI_Master.get_viewport_area( &tx, &ty, &tw, &th );
	glViewport( tx, ty, tw, th );

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	float32 ratio = float32(tw) / float32(th);

	b2Vec2 extents(ratio * 12.5f, 12.5f);
	extents *= viewZoom;

	b2Vec2 lower = viewCenter - extents;
	b2Vec2 upper = viewCenter + extents;

	// L/R/B/T
	gluOrtho2D(lower.x, upper.x, lower.y, upper.y);

	settings.windowHeight = h;
	settings.windowWidth = w;

	gui->check_subwindow_position();

}

//Called when the GUI dropdown menu is changed
void loadScenario(GLUI_Control * listBox) {

	deletePhysicsWorld();
	loadWorld( listBox->get_int_val() + 1);

}

void resetLevel( int x ) {
	deletePhysicsWorld();
	loadWorld();
}

// This is used to control the frame rate (60Hz).
void timer(int)
{
	glutSetWindow(mainWindow);
	glutPostRedisplay();
	glutTimerFunc((int)(1000*settings.timeStep), timer, 0);
}

//Called whenever a mouse action is performed
void mouseFunction(int button, int state, int x, int y) {

	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		//cout << x << " " << y << endl;
		createMartlet( b2Vec2(-20.0, -9.0), b2Vec2(x/(float)settings.windowWidth*60.0,
				(settings.windowHeight - y)/(float)settings.windowHeight*60.0));
	}


}


//Initializes all the graphics parameters
void initGraphics (int argc, char* argv[], void (*simulationFunc)(void)) {

	glutInit(&argc, argv);
	glutInitDisplayMode( GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH );

	glutInitWindowPosition( settings.windowPositionX, settings.windowPositionY );
	glutInitWindowSize( settings.windowWidth, settings.windowHeight );

	mainWindow = glutCreateWindow( "Angry Martlets" );

	glutMouseFunc(mouseFunction);
	glutDisplayFunc(simulationFunc);
	glutReshapeFunc(reshapeFunction);
	glutIdleFunc(NULL);

	//Creates a side panel with buttons on the left of the main window
	gui = GLUI_Master.create_glui_subwindow( mainWindow, GLUI_SUBWINDOW_RIGHT);

	gui->add_statictext("Menu Options");

	GLUI_Listbox* list = gui->add_listbox("Scenario ", 0, 0, loadScenario);
	list->add_item(0, "Level 1");
	list->add_item(1, "Level 2");
	list->add_item(2, "Level 3");

	gui->add_button("Reset", 0, resetLevel);
	gui->add_button("Quit", 0, exit);

	gui->set_main_gfx_window( mainWindow );



	glutTimerFunc((int)(1000*settings.timeStep), timer, 0);

	//Sets the transparency rendering for openGL
	glEnable( GL_BLEND );
	glBlendFunc(GL_ONE_MINUS_SRC_ALPHA, GL_ONE);

}


//Draws the given object onto the screen
void draw (float32 x, float32 y, float32 angle, float32 width, float32 height, GLuint textureID)
{

	//Reset
	glLoadIdentity();

	//Move to offset
	glTranslatef( x, y, 0 );

	// Rotate The Quad On The x axis
	glRotatef(angle * RAD_2_DEG,0.0f,0.0f,1.0f);

	//Select the texture to use
	glBindTexture(GL_TEXTURE_2D, textureID);

	//Start quad
	glBegin( GL_QUADS );

		//Draw square
		glTexCoord2d(0,0); glVertex2f( -width, -height );
		glTexCoord2d(1,0); glVertex2f( width, -height );
		glTexCoord2d(1,1); glVertex2f( width, height );
		glTexCoord2d(0,1); glVertex2f( -width, height );

	//End quad
	glEnd();


}
