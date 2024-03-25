
//  ========================================================================
//
//
//  FILE NAME: amesWindow.cpp
//
//  ========================================================================


#include <iostream>
#include <fstream>
#include <cmath>
#include <GL/freeglut.h>
#include <GL/glut.h>
#include <GL/gl.h>
#include "loadBMP.h"


using namespace std;

//--Globals ---------------------------------------------------------------
float amesWindowSpin = 0.0; //Rotation of the Ames Window, about its own axis
GLuint txId[3]; //Texture IDs
float linesPosition = 0.0; //X Position of vertical lines for scanimation
float add_amount = 0.05;
//for camera movement in special character controls
float angle=0, look_x=0, look_z=0., eye_x=0, eye_z=10;

//for fish movement
float fishx = 20;
int fishAddAmount = 2;
int tailRotation = 0;
int fishRotation = 0;
//--------------------------------------------------------------------------------
void loadTexture()
{
    glGenTextures(3, txId);   //Get 2 texture IDs
    glBindTexture(GL_TEXTURE_2D, txId[0]);  //Use this texture name for the following OpenGL texture
    loadBMP("cube.bmp");
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);	// Linear Filtering
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glBindTexture(GL_TEXTURE_2D, txId[1]);  //Use this texture name for the following OpenGL texture
    loadBMP("spots.bmp");
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glBindTexture(GL_TEXTURE_2D, txId[2]);  //Use this texture name for the following OpenGL texture
    loadBMP("test6.bmp");
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);	// Linear Filtering
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

//    glBindTexture(GL_TEXTURE_2D, txId[3]);  //Use this texture name for the following OpenGL texture
//    loadBMP("Sun.bmp");
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);	// Linear Filtering
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
}


//--Draws a character model constructed using GLUT objects ------------------
void drawWindow()
{
    glPolygonMode( GL_FRONT_AND_BACK, GL_LINE ); //wireframe/outlined quads
    glLineWidth(2);


    glPushMatrix();//    glBindTexture(GL_TEXTURE_2D, txId[1]);  //Use this texture name for the following OpenGL texture
        glColor3f(1,1,0); //colour for outlines

        glBegin(GL_QUADS);
           glVertex3f(0, -4, 0);  //main outline
           glVertex3f(21.4, -7.6, 0);
           glVertex3f(21.4, 7.6, 0);
           glVertex3f(0, 4, 0);
                          //side piece
           glVertex3f(21.4, -7.6, 0);
           glVertex3f(23, -7, 0);
           glVertex3f(23, 7, 0);
           glVertex3f(21.4, 7.6, 0);
                         //(0,1)

           glVertex3f(0.8, 0.3, 0);
           glVertex3f(5.1, 0.5, 0);
           glVertex3f(5.1, 3.8, 0);
           glVertex3f(0.8, 3, 0);
                          //Interior vertical
                 //(0,1)
           glVertex3f(0.8, 0.4, 0);
           glVertex3f(1.6, 0.4, 0);
           glVertex3f(1.6, 2.6, 0);
           glVertex3f(0.8, 3, 0);
                       //Interior horizontal
                  //(0,1)
           glVertex3f(1.6, 2.6, 0);
           glVertex3f(5.1, 3.2, 0);
           glVertex3f(5.1, 3.8, 0);
           glVertex3f(0.8, 3, 0);
                        //(0,0)

           glVertex3f(0.8, -3.1, 0);
           glVertex3f(5.1, -3.8, 0);
           glVertex3f(5.1, -0.5, 0);
           glVertex3f(0.8, -0.4, 0);
                         //vertical
                 //(0,0)
           glVertex3f(0.8, -3.1, 0);
           glVertex3f(1.6, -2.6, 0);
           glVertex3f(1.6, -0.4, 0);
           glVertex3f(0.8, -0.4, 0);
                        //horizontal
                 //(0,0)
            glVertex3f(0.8, -3.1, 0);
            glVertex3f(5.1, -3.8, 0);
            glVertex3f(5.1, -3.1, 0);//
            glVertex3f(1.6, -2.6, 0);
                        //(1,1)
           glVertex3f(6.1, 0.5, 0);
           glVertex3f(11.8, 0.6, 0);
           glVertex3f(11.8, 4.8, 0);
           glVertex3f(6.1, 4, 0);
                        //Interior vertical
                 //(1,1)
           glVertex3f(6.1, 0.5, 0);
           glVertex3f(7.2, 0.5, 0);
           glVertex3f(7.2, 3.5, 0);
           glVertex3f(6.1, 4, 0);
                       //Interior horizontal
                  //(1,1)
           glVertex3f(7.2, 3.5, 0);
           glVertex3f(11.8, 4, 0);
           glVertex3f(11.8, 4.8, 0);
           glVertex3f(6.1, 4, 0);
                        //(1,0)

           glVertex3f(6.1, -4, 0);
           glVertex3f(11.8, -4.8, 0);
           glVertex3f(11.8, -0.5, 0);
           glVertex3f(6.1, -0.4, 0);
                         //vertical
            //(1,0)
           glVertex3f(6.1, -4, 0);
           glVertex3f(7.2, -3.5, 0);//
           glVertex3f(7.2, -0.4, 0);
           glVertex3f(6.1, -0.4, 0);

                       //horizontal
                  //(1,0)
            glVertex3f(6.1, -4, 0);
            glVertex3f(11.8, -4.8, 0);
            glVertex3f(11.8, -4, 0);
            glVertex3f(7.2, -3.5, 0);//
                        //(2,1)

            glVertex3f(13, 0.6, 0);
            glVertex3f(19.9, 0.8, 0);
            glVertex3f(19.9, 5.9, 0);
            glVertex3f(13, 4.9, 0);
                         //Interior vertical
                  //(2,1)
            glVertex3f(13, 0.6, 0);
            glVertex3f(14.2, 0.6, 0);//
            glVertex3f(14.2, 4.3, 0);
            glVertex3f(13, 4.9, 0);
                      //Interior horizontal
                  //(2,1)
            glVertex3f(14.2, 4.3, 0);
            glVertex3f(19.9, 5, 0);
            glVertex3f(19.9, 5.9, 0);
            glVertex3f(13, 4.9, 0);
                       //(2,0)
            glVertex3f(13, -4.9, 0);
            glVertex3f(19.9, -5.9, 0);
            glVertex3f(19.9, -0.8, 0);
            glVertex3f(13, -0.6, 0);

                   //vertical
                 //(2,0)
            glVertex3f(13, -4.9, 0);
            glVertex3f(14.2, -4.3, 0);
            glVertex3f(14.2, -0.6, 0);
            glVertex3f(13, -0.6, 0);

                        //horizontal
                 //(2,0)
            glVertex3f(13, -4.9, 0);
            glVertex3f(19.9, -5.9, 0);
            glVertex3f(19.9, -5, 0);
            glVertex3f(14.2, -4.3, 0);

       glEnd();
    glPopMatrix();

    glPushMatrix();
        //Colour fills -'shadow red'
        glPolygonMode( GL_FRONT_AND_BACK, GL_FILL );
        glColor3f(1,0,0);

        glBegin(GL_QUADS);
                      //side piece colour fill
           glVertex3f(21.4, -7.6, 0);
           glVertex3f(23, -7, 0);
           glVertex3f(23, 7, 0);
           glVertex3f(21.4, 7.6, 0);

                       //Interior vertical colour fill
                  //(0,1)
           glVertex3f(0.8, 0.4, 0);
           glVertex3f(1.6, 0.4, 0);
           glVertex3f(1.6, 2.6, 0);
           glVertex3f(0.8, 3, 0);


                         //Interior horizontal colour fill
                  //(0,1)
           glVertex3f(1.6, 2.6, 0);
           glVertex3f(5.1, 3.2, 0);
           glVertex3f(5.1, 3.8, 0);
           glVertex3f(0.8, 3, 0);


                       //Interior vertical colour fill
                 //(0,0)
           glVertex3f(0.8, -3.1, 0);
           glVertex3f(1.6, -2.6, 0);
           glVertex3f(1.6, -0.4, 0);
           glVertex3f(0.8, -0.4, 0);


                        //Interior horizontal colour fill
        glBegin(GL_QUADS);                  //(0,0)
            glVertex3f(0.8, -3.1, 0);
            glVertex3f(5.1, -3.8, 0);
            glVertex3f(5.1, -3.1, 0);//
            glVertex3f(1.6, -2.6, 0);


                       //Interior vertical colour fill
                //(1,1)
           glVertex3f(6.1, 0.5, 0);
           glVertex3f(7.2, 0.5, 0);
           glVertex3f(7.2, 3.5, 0);
           glVertex3f(6.1, 4, 0);


                       //Interior horizontal colour fill
                //(1,1)
           glVertex3f(7.2, 3.5, 0);
           glVertex3f(11.8, 4, 0);
           glVertex3f(11.8, 4.8, 0);
           glVertex3f(6.1, 4, 0);


                         //Interior vertical colour fill
                   //(1,0)
           glVertex3f(6.1, -4, 0);
           glVertex3f(7.2, -3.5, 0);//
           glVertex3f(7.2, -0.4, 0);
           glVertex3f(6.1, -0.4, 0);


                      //Interior horizontal colour fill
                 //(1,0)
            glVertex3f(6.1, -4, 0);
            glVertex3f(11.8, -4.8, 0);
            glVertex3f(11.8, -4, 0);
            glVertex3f(7.2, -3.5, 0);//


                         //Interior vertical colour fill
             //(2,1)
            glVertex3f(13, 0.6, 0);
            glVertex3f(14.2, 0.6, 0);//
            glVertex3f(14.2, 4.3, 0);
            glVertex3f(13, 4.9, 0);
                           //Interior horizontal colour fill
                          //(2,1)
            glVertex3f(14.2, 4.3, 0);
            glVertex3f(19.9, 5, 0);
            glVertex3f(19.9, 5.9, 0);
            glVertex3f(13, 4.9, 0);
                           //Interior vertical colour fill
                     //(2,0)
            glVertex3f(13, -4.9, 0);
            glVertex3f(14.2, -4.3, 0);
            glVertex3f(14.2, -0.6, 0);
            glVertex3f(13, -0.6, 0);
                         //Interior horizontal colour fill
                     //(2,0)
            glVertex3f(13, -4.9, 0);
            glVertex3f(19.9, -5.9, 0);
            glVertex3f(19.9, -5, 0);
            glVertex3f(14.2, -4.3, 0);
         glEnd();
        glPopMatrix();

    glPushMatrix();
        //Colour fills
        glColor3f(1,1,0);

        glBegin(GL_QUADS);
     //horzizontal #3
           glVertex3f(0, -4, 0);
           glVertex3f(21.4, -7.6, 0);
           glVertex3f(21.4, -5.9, 0);
           glVertex3f(0, -3, 0);

 //horzizontal #1
           glVertex3f(0, 2.9, 0);
           glVertex3f(21.4, 6, 0);
           glVertex3f(21.4, 7.6, 0);
           glVertex3f(0, 4, 0);
//horzizontal #2
           glVertex3f(0, -0.4, 0);
           glVertex3f(21.4, -0.7, 0);
           glVertex3f(21.4, 0.8, 0);
           glVertex3f(0, 0.3, 0);
//vertical #1
           glVertex3f(0, -4, 0);
           glVertex3f(0.8, -4.1, 0);
           glVertex3f(0.8, 4.1, 0);
           glVertex3f(0, 4, 0);
 //vertical #2
           glVertex3f(5.1, -4, 0);
           glVertex3f(6.2, -4, 0);
           glVertex3f(6.2, 4, 0);
           glVertex3f(5.1, 4, 0);
  //vertical #3
           glVertex3f(11.8, -5, 0);
           glVertex3f(13, -5, 0);
           glVertex3f(13, 5, 0);
           glVertex3f(11.8, 5, 0);
  //vertical #4
           glVertex3f(19.9, -7.4, 0);
           glVertex3f(21.4, -7.6, 0);
           glVertex3f(21.4, 7.6, 0);
           glVertex3f(19.9, 7.4, 0);
        glEnd();
    glPopMatrix();

}


void drawVertLine()
{
    //Will need to adjust width in respect to the background image
    glBegin(GL_QUADS);
        glVertex3f(0, 0, 0);
        glVertex3f(0.3, 0, 0);
        glVertex3f(0.3, 15, 0);
        glVertex3f(0, 15, 0);
    glEnd();
}

//-- Draws scanimaton object
void drawScanimation()
{
    //Background Image -cat
    glPushMatrix();
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, txId[0]);
        glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
        glColor3f(1,1,1);
        glBegin(GL_QUADS);
            glTexCoord2f(0., 0.);
            glVertex3f(0, 0, 0);
            glTexCoord2f(1., 0.);
            glVertex3f(20, 0, 0);
            glTexCoord2f(1., 1.);
            glVertex3f(20, 15, 0);
            glTexCoord2f(0., 1.);
            glVertex3f(0, 15, 0);
        glEnd();
        glDisable(GL_TEXTURE_2D);
    glPopMatrix();

    //Vertical Lines
    glPushMatrix();
        glTranslatef(linesPosition, 0, 1); //Movement of vertical lines
        glColor3f(0,0,0);
        for (int i=1; i<40; i++) {
            drawVertLine();
            glTranslatef(0.4,0,0);
        }
    glPopMatrix();
}


void drawTeleport()
{
    glColor3f(0,1,0);
    glPushMatrix();
        GLUquadric *q;
        q = gluNewQuadric();
        gluCylinder(q, 10, 0, 15, 30, 5);
        gluQuadricDrawStyle(q, GLU_FILL);
    glPopMatrix();
}


void drawFish()
{
    glColor3f(1,0,1);
    glPushMatrix();     //body
        glScalef(5,3,5);
        glutSolidOctahedron();
    glPopMatrix();
    glPushMatrix();     //tail
    glTranslatef(-4,0,0);
        glRotatef(tailRotation,0,1,0);
        glTranslatef(-2,0,0);
        glScalef(2,2,0.3);
        glutSolidOctahedron();
    glPopMatrix();
    glPushMatrix();     //eye #1
        glColor3f(1,1,1);
        glTranslatef(3,0.8,1);
        glScalef(0.5,0.5,0.5);
        glutSolidSphere(2,20,20);
    glPopMatrix();
    glPushMatrix();     //eye #2
        glColor3f(1,1,1);
        glTranslatef(3,0.8,-1);
        glScalef(0.5,0.5,0.5);
        glutSolidSphere(2,20,20);
    glPopMatrix();
    glPushMatrix();     //pupil #1
        glColor3f(0,0,0);
        glTranslatef(3.5,1,1.8);
        glScalef(0.2,0.2,0.2);
        glutSolidSphere(2,20,20);
    glPopMatrix();
    glPushMatrix();     //pupil #2
        glColor3f(0,0,0);
        glTranslatef(3.5,1,-1.8);
        glScalef(0.2,0.2,0.2);
        glutSolidSphere(2,20,20);
    glPopMatrix();

}


void drawWallArt1()
{
    glPushMatrix();
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, txId[1]);
        glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
        glColor3f(1,1,1); //PLACEHOLDER FOR IMAGE
        glBegin(GL_QUADS);
            glTexCoord2f(0., 0.);
            glVertex3f(0, 0, 0);
            glTexCoord2f(1., 0.);
            glVertex3f(50, 0, 0);
            glTexCoord2f(1., 1.);
            glVertex3f(50, 50, 0);
            glTexCoord2f(0., 1.);
            glVertex3f(0, 50, 0);
        glEnd();
        glDisable(GL_TEXTURE_2D);
    glPopMatrix();
}


void drawWallArt2()
{
    glPushMatrix();
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, txId[2]);
        glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
        glColor3f(1,1,1);
        glBegin(GL_QUADS);
            glTexCoord2f(0., 0.);
            glVertex3f(0, 0, 0);
            glTexCoord2f(1., 0.);
            glVertex3f(50, 0, 0);
            glTexCoord2f(1., 1.);
            glVertex3f(50, 50, 0);
            glTexCoord2f(0., 1.);
            glVertex3f(0, 50, 0);
        glEnd();
        glDisable(GL_TEXTURE_2D);
    glPopMatrix();
}

void drawWalls()
{
    glColor3f(0,0,1);
    glBegin(GL_QUADS);
        glVertex3f(-100,0,-100);
        glVertex3f(100,0,-100);
        glVertex3f(100,100,-100);
        glVertex3f(-100,100,-100);

        glVertex3f(-100,0,100);
        glVertex3f(100,0,100);
        glVertex3f(100,100,100);
        glVertex3f(-100,100,100);

        glVertex3f(100,0,-100);
        glVertex3f(100,0,100);
        glVertex3f(100,100,100);
        glVertex3f(100,100,-100);

        glVertex3f(-100,0,100);
        glVertex3f(-100,0,-100);
        glVertex3f(-100,100,-100);
        glVertex3f(-100,100,100);
    glEnd();
}

void drawRoof()
{
    glColor3f(1,1,0);
    glBegin(GL_QUADS);
        glVertex3f(-100,100,100);
        glVertex3f(100,100,100);
        glVertex3f(100,100,-100);
        glVertex3f(-100,100,-100);
    glEnd();
}

//--Draws a chequered pattern on the floor plane -------------------------------
void drawFloor()
{
    bool flag = false;
    glBegin(GL_QUADS);
    glNormal3f(0, 1, 0);
    for(int x = -100; x <= 100; x += 20)
    {
        for(int z = -100; z <= 100; z += 20)
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
    float lpos[4] = {0., 50., 10., 1.0};  //light's position

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(eye_x, 10, eye_z, look_x, 10, look_z, 0, 1, 0);
    glLightfv(GL_LIGHT0,GL_POSITION, lpos);   //Set light position

    //test Spotlight
//    float light1_pos[4] = {eye_x, 40.0, eye_z, 1.0 };
//    float light1_dir[3] = { look_x-eye_x, 0, look_z-eye_z };
    float light1_pos[4] = { 0.0, 20.0, 60.0, 1.0 };
    float light1_dir[3] = { 0.0, 20.0, -60.0 };
    glLightfv(GL_LIGHT1, GL_POSITION, light1_pos);
    glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, light1_dir);



    //Gallery
    drawFloor();

    drawWalls();
    drawRoof();
    glPushMatrix();
        glTranslatef(30,15,99.9);
        drawWallArt1();
    glPopMatrix();
    glPushMatrix();
        glTranslatef(-80,15,99.9);
        drawWallArt2();
    glPopMatrix();





    //Ames Window
    glPushMatrix();

        glTranslatef(0,20,-60);	 //Translate the Ames window to its position in the gallery

        glPushMatrix();
            glTranslatef(10, 0, 0.0);
            glRotatef(amesWindowSpin, 0, -1, 0);       //Rotate about the y-axis
            glTranslatef(-10, 0, 0.0);	 //Translate the Ames window to the origin (along x-axis by -10 units from where the draw window function puts it)
            glScalef(1.5,1.5,1.5);
            drawWindow();
        glPopMatrix();
    glPopMatrix();


    //Scanimation
    glPushMatrix();
        glTranslatef(-99,8,25); //translate the whole scanimation to its position in the gallery
        glRotatef(90,0,1,0);
        glScalef(3,3,3);
        drawScanimation();
    glPopMatrix();


    //Fish animation
    glPushMatrix();
        glTranslatef(50,40,30); //translate the whole animation to its position in the gallery
        glRotatef(fishRotation,0.3,1,0); //turn fish animation
        glScalef(0.8,0.8,0.8);
        //Fish
        glPushMatrix();
            glTranslatef(fishx,0,0);
            glTranslatef(-50,0,0);

            float light2_pos[4] = { 0.0, 0.0, 0.0, 1.0 };
            float light2_dir[3] = { 0.0, -40.0, 0.0 };
            glLightfv(GL_LIGHT2, GL_POSITION, light1_pos);
            glLightfv(GL_LIGHT2, GL_SPOT_DIRECTION, light1_dir);
            drawFish();
        glPopMatrix();

        //Teleport 1
        glPushMatrix();
            glRotatef(90,0,1,0);
            drawTeleport();
        glPopMatrix();

        //Teleport 2
        glPushMatrix();
            glTranslatef(-45,0,0);
            glRotatef(-90,0,1,0);
            drawTeleport();
        glPopMatrix();

    glPopMatrix();

    glFlush();
}


//------- Initialize OpenGL parameters -----------------------------------
void initialize()
{
    loadTexture();
    float white[] = { 1, 1, 1, 1 };
    float magenta[] = { 1, 0, 1, 1 };

    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);	//Background colour

    glEnable(GL_LIGHTING);					//Enable OpenGL states
    glEnable(GL_LIGHT0);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_NORMALIZE);
    glEnable(GL_TEXTURE_2D);

    //Setting a second light source - a spotlight on the ames window
    glEnable(GL_LIGHT1);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, white);
    glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, 40);
    glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, 10);


    //Setting a third light source - a spotlight on the ames window
    glEnable(GL_LIGHT2);
    glLightfv(GL_LIGHT2, GL_DIFFUSE, magenta);
    glLightf(GL_LIGHT2, GL_SPOT_CUTOFF, 60);
    glLightf(GL_LIGHT2, GL_SPOT_EXPONENT, 10);


    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(50.0, 1.0, 10.0, 1000.0);  //Camera Frustum
}

//------------ Special key event callback ---------------------------------
// To enable the use of left, right, up, and down arrow keys to rotate the scene
void special(int key, int x, int y)
{
    if(key == GLUT_KEY_LEFT) angle -= 0.1;  //Change direction
    else if(key == GLUT_KEY_RIGHT) angle += 0.1;
    //Move backward
    else if(key == GLUT_KEY_DOWN)
    {
        eye_x -= 2*sin(angle);
        eye_z += 2*cos(angle);
    }
    //Move forward
    else if(key == GLUT_KEY_UP)
    {
        eye_x += 2*sin(angle);
        eye_z -= 2*cos(angle);
    }

    look_x = eye_x + 5*sin(angle);
    look_z = eye_z - 5*cos(angle);

    glutPostRedisplay();

}


//------------ Keyboard event callback ---------------------------------
// To enable the use of 0,1,2,3 keys to orient the camera position and view point at the gallery and at each AAO
void keyboard(unsigned char key, int x, int y)
{

    //Gallery View
    if(key == '0')
    {
        look_x = -90;
        look_z = 90;
        eye_x  = 85;
        eye_z = -85;
    }

    //AAO-1 Ames Window
    if(key == '1')
    {
        look_x = 0;
        look_z = 0;
        eye_x  = 0;
        eye_z = 90;
    }
    //AAO-2 Scanimation
    else if(key == '2')
    {
        look_x = -99;
        look_z = -3;
        eye_x  = 0;
        eye_z = -3;
    }

    //AAO-3 Teleporting Fish
    else if(key == '3')
    {
        look_x = 99;
        look_z = 30;
        eye_x  = -50;
        eye_z = 30;
    }

    //View of Static Optical Illusion 1
    else if(key == '8')
    {
        look_x = 50;
        look_z = 99;
        eye_x  = 50;
        eye_z = -30;
    }

    //View of Static Optical Illusion 2
    else if(key == '9')
    {
        look_x = -50;
        look_z = 99;
        eye_x  = -50;
        eye_z = -30;
    }

    glutPostRedisplay();
}

//  -------------------- Timer Function ------------------------------------
void timer(int value)
{
    amesWindowSpin += 1;
    if(amesWindowSpin > 360) amesWindowSpin = 0;

    //moves the lines for the scanimation
    if(linesPosition > 16){
        add_amount *= -1;
    } else if(linesPosition < -11) {
        add_amount *= -1;
    }
    linesPosition += add_amount;

    //Moves the fish to its vanishing point
    fishx += 0.5;
    if(fishx > 55) fishx = 0;

    //changes the rotation of the fish's tail
    if(tailRotation > 35){
        fishAddAmount *= -1;
    } else if(tailRotation < -35) {
        fishAddAmount *= -1;
    }
    tailRotation += fishAddAmount;

    //send the fish round in circles
    fishRotation += 1;
    if(fishRotation > 360) fishRotation = 0;



    glutTimerFunc(50, timer, value);
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
   glutTimerFunc(50, timer, 0);
   glutSpecialFunc(special);
   glutKeyboardFunc(keyboard);
   glutMainLoop();
   return 0;
}
