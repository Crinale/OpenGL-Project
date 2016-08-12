#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <math.h>
#include <stdio.h>
using namespace std;
float xPosition = 0; 
float xRotation = 0; 
float xRotationR = 0;
float yPosition = 5; 
float yRotation = 0; 
float yRotationR;
float zPosition = 20; 
GLuint tex;
GLfloat busX = 0.0, busZ = 0.0;
GLuint busAction = 0;
GLuint busTime = 0;



//TEXTURE LOAD
GLuint BmpTexture(const char* filename,int wrap,int width,int height)
{
    GLuint texture;
    char* data;
    FILE* file;
    //CBitmap image(filename);
    //open texture data
    file = fopen(filename,"rb"); //read as binary file
    if (file==NULL)
        return 0; //exit if file doesn't exist
        
    //allocate RGB for each pixel into data
    data = (char*)malloc(width*height*3);
    
    //read file into data
    fread(data,width*height*3,1,file);
    fclose(file);

    //texture name
    glGenTextures(1,&texture);

    //select the texture we're using
    glBindTexture(GL_TEXTURE_2D,texture);

    glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_MODULATE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);   //specify minificaton filtering
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);   //specify magnificaton filtering

    //mipmap
    glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR_MIPMAP_NEAREST);
    glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR );
       
    //repeat or clamp textures
    if (wrap) {
        glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T,GL_REPEAT);
    }else{
        glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_CLAMP);
        glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_CLAMP);      
    }
    
    //mipmap
    gluBuild2DMipmaps(GL_TEXTURE_2D,GL_RGB,width,height,GL_RGB,GL_UNSIGNED_BYTE,data);

    free( data );

    return texture; 
 glBindTexture(GL_TEXTURE_2D, 0);
}
void reshape ( int width, int height ) {

    // define the viewport transformation 
    glViewport(0,0,width,height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity(); //camera reset
    gluPerspective(45.0,1.0,1.0,100.0);
    glMatrixMode(GL_MODELVIEW);
}
void camera(){
    glRotatef(xRotation,1.0,0.0,0.0);  //x axis
    glRotatef(yRotation,0.0,1.0,0.0);  //y axis
    glTranslated(-xPosition,-yPosition,-zPosition); //translating the screen
}

void display () {

    // clear window 
    glClearColor (0.0,0.0,0.0,1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    // draw scene 
    glPushMatrix();
    camera();

//glRotatef(360,0,1,0);//tool for camera to check if im putting in coordinates right
    

    // Warehouse 1
glEnable(GL_TEXTURE_2D);
    tex = BmpTexture("texture/brick.bmp",1,200,150);
    glBindTexture(GL_TEXTURE_2D,tex);
glBegin(GL_POLYGON);
glColor3f(1.0f,0.0f,0.0f);
glTexCoord2f(0.0f,0.0f);glVertex3f(0.0,0.0,25.0);
glTexCoord2f(0.0f,1.0f);glVertex3f(3.0,0.0,25.0);
glTexCoord2f(1.0f,1.0f);glVertex3f(3.0,3.0,25.0);
glTexCoord2f(0.5f,1.5f);glVertex3f(1.5,4.5,25.0);
glTexCoord2f(1.0f,0.0f);glVertex3f(0.0,3.0,25.0);
glEnd ();
glDisable(GL_TEXTURE_2D);

glEnable(GL_TEXTURE_2D);
    tex = BmpTexture("texture/brick.bmp",1,200,150);
    glBindTexture(GL_TEXTURE_2D,tex);
glBegin(GL_POLYGON);
glColor3f(1.0f,0.0f,0.0f);
glTexCoord2f(0.0f,0.0f);glVertex3f(0.0,0.0,35.0);
glTexCoord2f(0.0f,1.0f);glVertex3f(3.0,0.0,35.0);
glTexCoord2f(1.0f,1.0f);glVertex3f(3.0,3.0,35.0);
glTexCoord2f(0.5f,1.5f);glVertex3f(1.5,4.5,35.0);
glTexCoord2f(1.0f,0.0f);glVertex3f(0.0,3.0,35.0);
glEnd(); 
glDisable(GL_TEXTURE_2D);
 
glEnable(GL_TEXTURE_2D);
    tex = BmpTexture("texture/brick.bmp",1,200,150);
    glBindTexture(GL_TEXTURE_2D,tex);
glBegin(GL_QUADS);
glColor3f(1.0f,0.0f,0.0f); 
glTexCoord2f(0.0f,0.0f);glVertex3f(0.0,3.0,25.0);
glTexCoord2f(1.0f,0.0f);glVertex3f(0.0,3.0,35.0);
glTexCoord2f(1.0f,1.0f);glVertex3f(0.0,0.0,35.0);
glTexCoord2f(0.0f,1.0f);glVertex3f(0.0,0.0,25.0);
glEnd(); 
glDisable(GL_TEXTURE_2D);

 glEnable(GL_TEXTURE_2D);
    tex = BmpTexture("texture/brick.bmp",1,200,150);
    glBindTexture(GL_TEXTURE_2D,tex);
glBegin(GL_QUADS);
glColor3f(1.0f,0.0f,0.0f);  
glTexCoord2f(0.0f,0.0f);glVertex3f(1.5,4.5,25.0);
glTexCoord2f(1.0f,0.0f);glVertex3f(1.5,4.5,35.0);
glTexCoord2f(1.0f,1.0f);glVertex3f(0.0,3.0,35.0);
glTexCoord2f(0.0f,1.0f);glVertex3f(0.0,3.0,25.0);
glEnd(); 
glDisable(GL_TEXTURE_2D);

glEnable(GL_TEXTURE_2D);
    tex = BmpTexture("texture/brick.bmp",1,200,150);
    glBindTexture(GL_TEXTURE_2D,tex);
glBegin(GL_QUADS);
glColor3f(1.0f,0.0f,0.0f);  
glTexCoord2f(0.0f,0.0f);glVertex3f(3.0,3.0,25.0);
glTexCoord2f(1.0f,0.0f);glVertex3f(3.0,3.0,35.0);
glTexCoord2f(1.0f,1.0f);glVertex3f(3.0,0.0,35.0);
glTexCoord2f(0.0f,1.0f);glVertex3f(3.0,0.0,25.0);
glEnd(); 
 glDisable(GL_TEXTURE_2D);

glEnable(GL_TEXTURE_2D);
    tex = BmpTexture("texture/brick.bmp",1,200,150);
    glBindTexture(GL_TEXTURE_2D,tex);
glBegin(GL_QUADS);
glColor3f(1.0f,0.0f,0.0f); 
glTexCoord2f(0.0f,0.0f);glVertex3f(1.5,4.5,35.0);
glTexCoord2f(1.0f,0.0f);glVertex3f(1.5,4.5,25.0);
glTexCoord2f(1.0f,1.0f);glVertex3f(3.0,3.0,25.0);
glTexCoord2f(0.0f,1.0f);glVertex3f(3.0,3.0,35.0);
glEnd(); 
glDisable(GL_TEXTURE_2D);

//Warehouse 2

glEnable(GL_TEXTURE_2D);
    tex = BmpTexture("texture/brick.bmp",1,200,150);
    glBindTexture(GL_TEXTURE_2D,tex);
glBegin(GL_POLYGON);
glColor3f(1.0f,0.0f,0.0f);
glTexCoord2f(0.0f,0.0f);glVertex3f(7.0,0.0,25.0);
glTexCoord2f(0.0f,1.0f);glVertex3f(10.0,0.0,25.0);
glTexCoord2f(1.0f,1.0f);glVertex3f(10.0,3.0,25.0);
glTexCoord2f(0.5f,1.5f);glVertex3f(8.5,4.5,25.0);
glTexCoord2f(1.0f,0.0f);glVertex3f(7.0,3.0,25.0);
glEnd ();
glDisable(GL_TEXTURE_2D);

glEnable(GL_TEXTURE_2D);
    tex = BmpTexture("texture/brick.bmp",1,200,150);
    glBindTexture(GL_TEXTURE_2D,tex);
glBegin(GL_POLYGON);
glColor3f(1.0f,0.0f,0.0f);
glTexCoord2f(0.0f,0.0f);glVertex3f(7.0,0.0,35.0);
glTexCoord2f(0.0f,1.0f);glTexCoord2f(0.0f,0.0f);glVertex3f(10.0,0.0,35.0);
glTexCoord2f(1.0f,1.0f);glVertex3f(10.0,3.0,35.0);
glTexCoord2f(0.5f,1.5f);glVertex3f(8.5,4.5,35.0);
glTexCoord2f(1.0f,0.0f);glVertex3f(7.0,3.0,35.0);
glEnd(); 
glDisable(GL_TEXTURE_2D);
 
glEnable(GL_TEXTURE_2D);
    tex = BmpTexture("texture/brick.bmp",1,200,150);
    glBindTexture(GL_TEXTURE_2D,tex);
glBegin(GL_QUADS);
glColor3f(1.0f,0.0f,0.0f); 
glTexCoord2f(0.0f,0.0f);glVertex3f(7.0,3.0,25.0);
glTexCoord2f(1.0f,0.0f);glVertex3f(7.0,3.0,35.0);
glTexCoord2f(1.0f,1.0f);glVertex3f(7.0,0.0,35.0);
glTexCoord2f(0.0f,1.0f);glVertex3f(7.0,0.0,25.0);
glEnd(); 
glDisable(GL_TEXTURE_2D);

 glEnable(GL_TEXTURE_2D);
    tex = BmpTexture("texture/brick.bmp",1,200,150);
    glBindTexture(GL_TEXTURE_2D,tex);
glBegin(GL_QUADS);
glColor3f(1.0f,0.0f,0.0f);  
glTexCoord2f(0.0f,0.0f);glVertex3f(8.5,4.5,25.0);
glTexCoord2f(1.0f,0.0f);glVertex3f(8.5,4.5,35.0);
glTexCoord2f(1.0f,1.0f);glVertex3f(7.0,3.0,35.0);
glTexCoord2f(0.0f,1.0f);glVertex3f(7.0,3.0,25.0);
glEnd(); 
glDisable(GL_TEXTURE_2D);

glEnable(GL_TEXTURE_2D);
    tex = BmpTexture("texture/brick.bmp",1,200,150);
    glBindTexture(GL_TEXTURE_2D,tex);
glBegin(GL_QUADS);
glColor3f(1.0f,0.0f,0.0f);  
glTexCoord2f(0.0f,0.0f);glVertex3f(10.0,3.0,25.0);
glTexCoord2f(1.0f,0.0f);glVertex3f(10.0,3.0,35.0);
glTexCoord2f(1.0f,1.0f);glVertex3f(10.0,0.0,35.0);
glTexCoord2f(0.0f,1.0f);glVertex3f(10.0,0.0,25.0);
glEnd(); 
glDisable(GL_TEXTURE_2D);
 
glEnable(GL_TEXTURE_2D);
    tex = BmpTexture("texture/brick.bmp",1,200,150);
    glBindTexture(GL_TEXTURE_2D,tex);
glBegin(GL_QUADS);
glColor3f(1.0f,0.0f,0.0f); 
glTexCoord2f(0.0f,0.0f);glVertex3f(8.5,4.5,35.0);
glTexCoord2f(1.0f,0.0f);glVertex3f(8.5,4.5,25.0);
glTexCoord2f(1.0f,1.0f);glVertex3f(10.0,3.0,25.0);
glTexCoord2f(0.0f,1.0f);glVertex3f(10.0,3.0,35.0);
glEnd(); 
glDisable(GL_TEXTURE_2D);

//Bus

glEnable(GL_TEXTURE_2D);
    tex = BmpTexture("texture/frontback.bmp",1,200,100);
    glBindTexture(GL_TEXTURE_2D,tex);
glBegin(GL_QUADS);//Back
glColor3f(1.0f,1.0f,1.0f); 
glTexCoord2f(0.0f,0.0f);glVertex3f(-busX-10.0,0.0,-busZ+49.0);
glTexCoord2f(0.0f,1.0f);glVertex3f(-busX-10.0,1.0,-busZ+49.0);
glTexCoord2f(1.0f,1.0f);glVertex3f(-busX-11.0,1.0,-busZ+49.0);
glTexCoord2f(1.0f,0.0f);glVertex3f(-busX-11.0,0.0,-busZ+49.0);
glEnd(); 
glDisable(GL_TEXTURE_2D);

glEnable(GL_TEXTURE_2D);
    tex = BmpTexture("texture/frontback.bmp",1,200,100);
    glBindTexture(GL_TEXTURE_2D,tex);
glBegin(GL_QUADS);//Front
glColor3f(1.0f,1.0f,1.0f);  
glTexCoord2f(0.0f,0.0f);glVertex3f(-busX-10.0,0.0,-busZ+46.0);
glTexCoord2f(0.0f,1.0f);glVertex3f(-busX-10.0,1.0,-busZ+46.0);
glTexCoord2f(1.0f,1.0f);glVertex3f(-busX-11.0,1.0,-busZ+46.0);
glTexCoord2f(1.0f,0.0f);glVertex3f(-busX-11.0,0.0,-busZ+46.0);
glEnd(); 
glDisable(GL_TEXTURE_2D);

glEnable(GL_TEXTURE_2D);
    tex = BmpTexture("texture/carside.bmp",1,200,100);
    glBindTexture(GL_TEXTURE_2D,tex);
glBegin(GL_QUADS);//right
glColor3f(1.0f,1.0f,1.0f);  
glTexCoord2f(1.0f,0.0f);glVertex3f(-busX-10.0,0.0,-busZ+49.0);
glTexCoord2f(0.0f,0.0f);glVertex3f(-busX-10.0,0.0,-busZ+46.0);
glTexCoord2f(0.0f,1.0f);glVertex3f(-busX-10.0,1.0,-busZ+46.0);
glTexCoord2f(1.0f,1.0f);glVertex3f(-busX-10.0,1.0,-busZ+49.0);
glEnd(); 
glDisable(GL_TEXTURE_2D);
 
 glEnable(GL_TEXTURE_2D);
    tex = BmpTexture("texture/carside.bmp",1,200,100);
    glBindTexture(GL_TEXTURE_2D,tex);
glBegin(GL_QUADS);//left
glColor3f(1.0f,1.0f,1.0f); 
glTexCoord2f(1.0f,0.0f);glVertex3f(-busX-11.0,0.0,-busZ+49.0);
glTexCoord2f(0.0f,0.0f);glVertex3f(-busX-11.0,0.0,-busZ+46.0);
glTexCoord2f(0.0f,1.0f);glVertex3f(-busX-11.0,1.0,-busZ+46.0);
glTexCoord2f(1.0f,1.0f);glVertex3f(-busX-11.0,1.0,-busZ+49.0);
glEnd();
glDisable(GL_TEXTURE_2D);

 glEnable(GL_TEXTURE_2D);
    tex = BmpTexture("texture/top.bmp",1,200,100);
    glBindTexture(GL_TEXTURE_2D,tex);
glBegin(GL_QUADS);//top
glColor3f(1.0f,1.0f,1.0f); 
glTexCoord2f(0.0f,0.0f);glVertex3f(-busX-10.0,1.0,-busZ+49.0);
glTexCoord2f(0.0f,1.0f);glVertex3f(-busX-10.0,1.0,-busZ+46.0);
glTexCoord2f(1.0f,1.0f);glVertex3f(-busX-11.0,1.0,-busZ+46.0);
glTexCoord2f(0.0f,1.0f);glVertex3f(-busX-11.0,1.0,-busZ+49.0);
glEnd();
glDisable(GL_TEXTURE_2D);

switch(busAction){
        case 0:
            busTime = 0;
            break;
        case 15:
            busTime = 1;
            break;
        case 30:
            busTime = 2;
            break;
        case 45:
            busX = 0;
            busZ = 0;
            busTime = 0;
            busAction = 0;
    }
    switch(busTime){
        case 0:
            busAction++;
            busZ+=5;
            break;
        case 1:
            busAction++;
            busX-=2.5;
            break;
        case 2:
            busAction++;
            busZ-=5;
            break;
    }

//Building
glEnable(GL_TEXTURE_2D);
    tex = BmpTexture("texture/office.bmp",1,200,133);
    glBindTexture(GL_TEXTURE_2D,tex);
glBegin(GL_QUADS);//Front
glColor3f(1.0f,1.0f,1.0f); 
glTexCoord2f(1.0f,1.0f);glVertex3f(0.0,0.0,-37.0);
glTexCoord2f(0.0f,1.0f);glVertex3f(0.0,20.0,-37.0);
glTexCoord2f(0.0f,0.0f);glVertex3f(20.0,20.0,-37.0);
glTexCoord2f(1.0f,0.0f);glVertex3f(20.0,0.0,-37.0);
glEnd(); 
glDisable(GL_TEXTURE_2D);

glEnable(GL_TEXTURE_2D);
    tex = BmpTexture("texture/office.bmp",1,200,133);
    glBindTexture(GL_TEXTURE_2D,tex);
glBegin(GL_QUADS);//back
glColor3f(1.0f,1.0f,1.0f);  
glTexCoord2f(1.0f,1.0f);glVertex3f(0.0,0.0,-49.0);
glTexCoord2f(0.0f,1.0f);glVertex3f(0.0,20.0,-49.0);
glTexCoord2f(0.0f,0.0f);glVertex3f(20.0,20.0,-49.0);
glTexCoord2f(1.0f,0.0f);glVertex3f(20.0,0.0,-49.0);
glEnd(); 
glDisable(GL_TEXTURE_2D);

glEnable(GL_TEXTURE_2D);
    tex = BmpTexture("texture/office.bmp",1,200,133);
    glBindTexture(GL_TEXTURE_2D,tex);
glBegin(GL_QUADS);//left
glColor3f(1.0f,1.0f,1.0f);  
glTexCoord2f(1.0f,1.0f);glVertex3f(0.0,0.0,-37.0);
glTexCoord2f(1.0f,0.0f);glVertex3f(0.0,0.0,-49.0);
glTexCoord2f(0.0f,0.0f);glVertex3f(0.0,20.0,-49.0);
glTexCoord2f(0.0f,1.0f);glVertex3f(0.0,20.0,-37.0);
glEnd(); 
glDisable(GL_TEXTURE_2D);
 
 glEnable(GL_TEXTURE_2D);
    tex = BmpTexture("texture/office.bmp",1,200,133);
    glBindTexture(GL_TEXTURE_2D,tex);
glBegin(GL_QUADS);//right
glColor3f(1.0f,1.0f,1.0f); 
glTexCoord2f(0.0f,0.0f);glVertex3f(20.0,0.0,0-37.0);
glTexCoord2f(1.0f,0.0f);glVertex3f(20.0,20.0,-37.0);
glTexCoord2f(1.0f,1.0f);glVertex3f(20.0,20.0,-49.0);
glTexCoord2f(0.0f,1.0f);glVertex3f(20.0,0.0,-49.0);
glEnd();
glDisable(GL_TEXTURE_2D);

glBegin(GL_QUADS);//top
glColor3f(0.0f,0.0f,0.0f); 
glVertex3f(0.0,20.0,-37.0);
glVertex3f(0.0,20.0,-49.0);
glVertex3f(20.0,20.0,-49.0);
glVertex3f(20.0,20.0,-37.0);
glEnd();


//Land
 glEnable(GL_TEXTURE_2D);
  tex = BmpTexture("texture/citystreet.bmp",1,500,375);
glBegin(GL_QUADS);
glColor3f(1.0f,1.0f,1.0f); 
glTexCoord2f(0.0f,0.0f);glVertex3f(-50.0,0.0,-50.0);
glTexCoord2f(0.0f,1.0f);glVertex3f(-50.0,0.0,50.0);
glTexCoord2f(1.0f,1.0f);glVertex3f(50.0,0.0,50.0);
glTexCoord2f(1.0f,0.0f);glVertex3f(50.0,0.0,-50.0);
glEnd();
glDisable(GL_TEXTURE_2D);


//middle Building
 glEnable(GL_TEXTURE_2D);
  tex = BmpTexture("texture/hotel.bmp",1,200,150);
glBegin(GL_QUADS);//Front
glColor3f(1.0f,1.0f,1.0f); 
glTexCoord2f(0.0f,0.0f);glVertex3f(0.0,0.0,0.0);
glTexCoord2f(0.0f,1.0f);glVertex3f(0.0,10.0,0.0);
glTexCoord2f(1.0f,1.0f);glVertex3f(20.0,10.0,0.0);
glTexCoord2f(1.0f,0.0f);glVertex3f(20.0,0.0,0.0);
glEnd(); 
glDisable(GL_TEXTURE_2D);

 glEnable(GL_TEXTURE_2D);
  tex = BmpTexture("texture/hotel.bmp",1,200,150);
glBegin(GL_QUADS);//back
glColor3f(1.0f,1.0f,1.0f);  
glTexCoord2f(0.0f,0.0f);glVertex3f(0.0,0.0,-10.0);
glTexCoord2f(0.0f,1.0f);glVertex3f(0.0,10.0,-10.0);
glTexCoord2f(1.0f,1.0f);glVertex3f(20.0,10.0,-10.0);
glTexCoord2f(1.0f,0.0f);glVertex3f(20.0,0.0,-10.0);
glEnd(); 
glDisable(GL_TEXTURE_2D);


 glEnable(GL_TEXTURE_2D);
  tex = BmpTexture("texture/hotel.bmp",1,200,150);
glBegin(GL_QUADS);//left
glColor3f(1.0f,1.0f,1.0f);  
glTexCoord2f(1.0f,0.0f);glVertex3f(0.0,0.0,0.0);
glTexCoord2f(0.0f,0.0f);glVertex3f(0.0,0.0,-10.0);
glTexCoord2f(0.0f,1.0f);glVertex3f(0.0,10.0,-10.0);
glTexCoord2f(1.0f,1.0f);glVertex3f(0.0,10.0,0.0);
glEnd(); 
glDisable(GL_TEXTURE_2D);
 
  glEnable(GL_TEXTURE_2D);
  tex = BmpTexture("texture/hotel.bmp",1,200,150);
glBegin(GL_QUADS);//right
glColor3f(1.0f,1.0f,1.0f); 
glTexCoord2f(0.0f,0.0f);glVertex3f(20.0,0.0,0.0);
glTexCoord2f(0.0f,1.0f);glVertex3f(20.0,10.0,0.0);
glTexCoord2f(1.0f,1.0f);glVertex3f(20.0,10.0,-10.0);
glTexCoord2f(1.0f,0.0f);glVertex3f(20.0,0.0,-10.0);
glEnd();
glDisable(GL_TEXTURE_2D);

glBegin(GL_QUADS);//top
glColor3f(0.0f,0.0f,0.0f); 
glVertex3f(0.0,10.0,0.0);
glVertex3f(0.0,10.0,-10.0);
glVertex3f(20.0,10.0,-10.0);
glVertex3f(20.0,10.0,0.0);
glEnd();
glDisable(GL_TEXTURE_2D);


//Skybox
    glEnable(GL_TEXTURE_2D);
    tex = BmpTexture("texture/lol.bmp",1,100,100);
    glBindTexture(GL_TEXTURE_2D,tex);
glBegin(GL_QUADS);
glColor3f(1.0f,1.0f,1.0f); 
glTexCoord2f(1.0f,1.0f);glVertex3f(50.0,50.0,-50.0);
glTexCoord2f(0.0f,1.0f);glVertex3f(50.0,50.0,50.0);
glTexCoord2f(0.0f,0.0f);glVertex3f(50.0,-50.0,50.0);
glTexCoord2f(1.0f,0.0f);glVertex3f(50.0,-50.0,-50.0);
glEnd(); 
glDisable(GL_TEXTURE_2D);

glEnable(GL_TEXTURE_2D);
 tex = BmpTexture("texture/lol.bmp",1,100,100);
glBegin(GL_QUADS);
glColor3f(1.0f,1.0f,1.0f);  
glTexCoord2f(1.0f,1.0f);glVertex3f(-50.0,50.0,50.0);
glTexCoord2f(0.0f,1.0f);glVertex3f(50.0,50.0,50.0);
glTexCoord2f(0.0f,0.0f);glVertex3f(50.0,-50.0,50.0);
glTexCoord2f(1.0f,0.0f);glVertex3f(-50.0,-50.0,50.0);
glEnd(); 
glDisable(GL_TEXTURE_2D);

    glEnable(GL_TEXTURE_2D);
 tex = BmpTexture("texture/lol.bmp",1,100,100);
glBegin(GL_QUADS);
glNormal3f(1.0f,0.0f,0.0f);
glColor3f(1.0f,1.0f,1.0f);  
glTexCoord2f(1.0f,1.0f);glVertex3f(-50.0,50.0,-50.0);
glTexCoord2f(0.0f,1.0f);glVertex3f(-50.0,50.0,50.0);
glTexCoord2f(0.0f,0.0f);glVertex3f(-50.0,-50.0,50.0);
glTexCoord2f(1.0f,0.0f);glVertex3f(-50.0,-50.0,-50.0);
glEnd(); 
glDisable(GL_TEXTURE_2D);

    glEnable(GL_TEXTURE_2D);
  tex = BmpTexture("texture/lol.bmp",1,100,100);
glBegin(GL_QUADS);
glColor3f(1.0f,1.0f,1.0f);   
glTexCoord2f(1.0f,1.0f);glVertex3f(-50.0,50.0,-50.0);
glTexCoord2f(0.0f,1.0f);glVertex3f(50.0,50.0,-50.0);
glTexCoord2f(0.0f,0.0f);glVertex3f(50.0,-50.0,-50.0);
glTexCoord2f(1.0f,0.0f);glVertex3f(-50.0,-50.0,-50.0);
glEnd();
glDisable(GL_TEXTURE_2D);

    glEnable(GL_TEXTURE_2D);
tex = BmpTexture("texture/lol.bmp",1,100,100);
glBegin(GL_QUADS);
glColor3f(1.0f,1.0f,1.0f); 
glTexCoord2f(1.0f,1.0f);glVertex3f(-50.0,50.0,50.0);
glTexCoord2f(0.0f,1.0f);glVertex3f(50.0,50.0,50.0);
glTexCoord2f(0.0f,0.0f);glVertex3f(50.0,50.0,-50.0);
glTexCoord2f(1.0f,0.0f);glVertex3f(-50.0,50.0,-50.0);
glEnd();
glDisable(GL_TEXTURE_2D);

    glEnable(GL_TEXTURE_2D);
 tex = BmpTexture("texture/lol.bmp",1,100,100);
glBegin(GL_QUADS);
glColor3f(1.0f,1.0f,1.0f); 
glTexCoord2f(1.0f,1.0f);glVertex3f(-50.0,-50.0,50.0);
glTexCoord2f(0.0f,1.0f);glVertex3f(50.0,-50.0,50.0);
glTexCoord2f(0.0f,0.0f);glVertex3f(50.0,-50.0,-50.0);
glTexCoord2f(1.0f,0.0f);glVertex3f(-50.0,-50.0,-50.0);
glEnd();
glDisable(GL_TEXTURE_2D);

    glPopMatrix();
glutSwapBuffers();
    // flush drawing routines to the window 
    glFlush();

}



void keyFunction(unsigned char key, int x, int y){
    switch(key){

        case 'w':
            yRotationR = (yRotation / 180 * 3.14159f);
            xRotationR = (xRotation / 180 * 3.14159f); 
            xPosition += float(sin(yRotationR)) ;
            zPosition -= float(cos(yRotationR)) ;
            yPosition -= float(sin(xRotationR)) ;
            break;
        case 's':
            yRotationR = (yRotation / 180 * 3.14159f);
            xRotationR = (xRotation / 180 * 3.14159f); 
            xPosition -= float(sin(yRotationR));
            zPosition += float(cos(yRotationR)) ;
            yPosition += float(sin(xRotationR));
            break;
        case 'a':
            yRotation -= 2;
            if(yRotation < -360)
                yRotation += 360;
            break;
        case 'd':
            yRotation += 2;
            if(yRotation > 360)
                yRotation -= 360;
            break;
        case 'c':
            xRotation += 1;
            if (xRotation > 360)
                xRotation -= 360;
            break;
        case 'e':
            xRotation -= 1;
            if (xRotation < -360)
                xRotation += 360;
            break;

        
    }
}
int main ( int argc, char **argv ) {

    // initialize GLUT, using any commandline parameters passed to the 
    //   program 
    glutInit(&argc,argv);

    // setup the size, position, and display mode for new windows 
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(0,0);
    

    // create and set up a window 
    glutCreateWindow("CITY!");
   glutKeyboardUpFunc(keyFunction); 
    glutDisplayFunc(display);
    glutIdleFunc(display);
    glutReshapeFunc(reshape);

    //set up depth-buffering 
    glEnable(GL_DEPTH_TEST);

    // tell GLUT to wait for events 
    glutMainLoop();
}