//  ========================================================================
//
//
//  FILE NAME: userInteraction.cpp
//
//  ========================================================================


#include <iostream>
#include <fstream>
#include <GL/freeglut.h>
#include <GL/glut.h>
#include <GL/gl.h>

using namespace std;

//--Globals ---------------------------------------------------------------
int direction = 4; //Camera direction
float turn_angle = 10.0;  //Rotation angle for viewing
int positionz = 20;
int lookpointx = 0;
int lookpointy = 5;
int lookpointz = 0;

//--Draws a grid of lines on the floor plane -------------------------------
void drawFloor()
{
    bool flag = false;

    glBegin(GL_QUADS);
    glNormal3f(0, 1, 0);
    for(int x = -400; x <= 400; x += 20)
    {
        for(int z = -400; z <= 400; z += 20)
        {
            if(flag) glColor3f(0.6, 1.0, 0.8);
            else glColor3f(0.8, 1.0, 0.6);
            glVertex3f(x, 0, z);
            glVertex3f(x, 0, z+20);
            glVertex3f(x+20, 0, z+20);
            glVertex3f(x+20, 0, z);
            flag = !flag;
        }
    }
    glEnd();
}




//--Display: ---------------------------------------------------------------
//--This is the main display module containing function calls for generating
//--the scene.
void display()
{
    float lpos[4] = {10., 10., 10., 1.0};  //light's position

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0, 5, positionz, lookpointx, lookpointy, lookpointz, 0, 1, 0);
    glLightfv(GL_LIGHT0,GL_POSITION, lpos);   //Set light position

    //glRotatef(angle, 0.0, 1.0, 0.0);  //Rotate the scene about the y-axis

    glDisable(GL_LIGHTING);			//disabling lighting to draw the floor
    drawFloor();
    glEnable(GL_LIGHTING);


    glPushMatrix();
        glColor3f(1,0,0);
        glTranslatef(0,5,0);
        glutSolidTeapot(1.0);
    glPopMatrix();
    glPushMatrix();


    glFlush();
}

//------- Initialize OpenGL parameters -----------------------------------
void initialize()
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);	//Background colour

    glEnable(GL_LIGHTING);					//Enable OpenGL states
    glEnable(GL_LIGHT0);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_NORMALIZE);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-5.0, 5.0, -5.0, 5.0, 5.0, 1000.0);   //Camera Frustum
}

//------------ Special key event callback ---------------------------------
// To enable the use of left, right, up, and down arrow keys to rotate the scene
void special(int key, int x, int y)
{
    if (key == GLUT_KEY_LEFT) {
        lookpointx--;
        lookpointz--;
    } else if (key == GLUT_KEY_RIGHT) {
        lookpointx++;
        lookpointz++;
    }
    else if (key == GLUT_KEY_UP) {
        positionz--;
        //lookpointz--;
    }
    else if (key == GLUT_KEY_DOWN) {
        positionz++;
        //lookpointz++;
    }

    //can set maximums here (so the user can't leave the gallery)
    if (lookpointz > positionz) {       //can only turn 90deg max to the right
        lookpointz = positionz;
        lookpointx --;
    } else if (lookpointz < (positionz * -1)) {     //only turn 90deg to the left -DOESN'T APPEAR TO WORK.
        lookpointz = positionz * -1;
        lookpointx ++;
    }

    glutPostRedisplay();
}


//  ------- Main: Initialize glut window and register call backs -----------
int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_SINGLE | GLUT_DEPTH);
   glutInitWindowSize (600, 600);
   glutInitWindowPosition (10, 10);
   glutCreateWindow ("Ames Window");
   initialize();

   glutDisplayFunc(display);
   glutSpecialFunc(special);
   glutMainLoop();
   return 0;
}
