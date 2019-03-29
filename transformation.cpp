#include <GL/freeglut.h>
#include <GL/gl.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int factor[3][3] = { {0, 0, 0}, 
                         {0, 0, 0}, 
                         {0, 0, 0}
                       };
float factor1[3][3] = { {0, 0, 0}, 
                         {0, 0, 0}, 
                         {0, 0, 0}
                       };
int res[3][1] = {{0},{0},{0}};
float res1[3][1] = {{0},{0},{0}};


void multiply(int mat1[][3], int mat2[][1], int res[][1]) 
{ 
    int i, j, k; 
    for (i = 0; i < 3; i++) 
    { 
        for (j = 0; j < 1; j++) 
        { 
            res[i][j] = 0; 
            for (k = 0; k < 3; k++) 
                res[i][j] += mat1[i][k]*mat2[k][j]; 
        } 
    } 
} 

void multiply1(float mat1[][3], float mat2[][1], float res[][1]) 
{ 
    int i, j, k; 
    for (i = 0; i < 3; i++) 
    { 
        for (j = 0; j < 1; j++) 
        { 
            res[i][j] = 0; 
            for (k = 0; k < 3; k++) 
                res[i][j] += mat1[i][k]*mat2[k][j]; 
        } 
    } 
} 

void translation(int tx,int ty)
{
    
    factor[0][0] = 1;
    factor[1][1] = 1;
    factor[2][2] = 1;
    factor[0][2] = tx;
    factor[1][2] = ty;
     
}

void rotation(int angle1)
{
    float val = angle1*3.14/180;
    //float val = angle1;
    factor1[2][2] = 1;
    factor1[0][0] = cos(val);
    factor1[0][1] = -sin(val);
    factor1[1][0] = sin(val);
    factor1[1][1] = cos(val);

}

void scaling(int sx,int sy)
{
    factor[0][0] = sx;
    factor[1][1] = sy;
    factor[2][2] = 1;
    factor[0][2] = 0;
    factor[1][2] = 0;
}

void init()
{
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0,1920,0,1080);
}

  
void draw()
{
	//glClear only clears the colours on the screen
	
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POLYGON);
		//to give color to the polygon
		glColor3f(1.0,0.0,0.0);
		glVertex2i(100,100);
		glVertex2i(200,100);
		//glVertex2f(0.0,0.8);
		glVertex2i(200,200);
		glVertex2i(100,200);
		
	glEnd();

    int store[8] = {0,0,0,0,0,0,0,0};

    translation(25,25);
    int input1[3][1] = {{100},{100},{1}};
    int input2[3][1] = {{200},{100},{1}};
    int input3[3][1] = {{200},{200},{1}};
    int input4[3][1] = {{100},{200},{1}};
    

    multiply(factor,input1,res);
    store[0] = res[0][0];
    store[1] = res[1][0];

    multiply(factor,input2,res);
    store[2] = res[0][0];
    store[3] = res[1][0];

    multiply(factor,input3,res);
    store[4] = res[0][0];
    store[5] = res[1][0];

    multiply(factor,input4,res);
    store[6] = res[0][0];
    store[7] = res[1][0];

    glBegin(GL_POLYGON);
		//to give color to the polygon
		glColor3f(0,1.0,0.0);
		glVertex2i(store[0],store[1]);
		glVertex2i(store[2],store[3]);
		//glVertex2f(0.0,0.8);
		glVertex2i(store[4],store[5]);
		glVertex2i(store[6],store[7]);
		
	glEnd();


    //rotation


    rotation(30);
    float input5[3][1] = {{100},{100},{1}};
    float input6[3][1] = {{200},{100},{1}};
    float input7[3][1] = {{200},{200},{1}};
    float input8[3][1] = {{100},{200},{1}};
    
    float store1[8] = {0,0,0,0,0,0,0,0};

    multiply1(factor1,input5,res1);
    store1[0] = res1[0][0];
    store1[1] = res1[1][0];

    multiply1(factor1,input6,res1);
    store1[2] = res1[0][0];
    store1[3] = res1[1][0];

    multiply1(factor1,input7,res1);
    store1[4] = res1[0][0];
    store1[5] = res1[1][0];

    multiply1(factor1,input8,res1);
    store1[6] = res1[0][0];
    store1[7] = res1[1][0];

    glBegin(GL_POLYGON);
		//to give color to the polygon
		glColor3f(0,0.0,1.0);
		glVertex2f(store1[0],store1[1]);
		glVertex2f(store1[2],store1[3]);
		//glVertex2f(0.0,0.8);
		glVertex2f(store1[4],store1[5]);
		glVertex2f(store1[6],store1[7]);
		
	glEnd();

    


    scaling(2,2);
    int input9[3][1] = {{100},{100},{1}};
    int input10[3][1] = {{200},{100},{1}};
    int input11[3][1] = {{200},{200},{1}};
    int input12[3][1] = {{100},{200},{1}};
    

    multiply(factor,input9,res);
    store[0] = res[0][0];
    store[1] = res[1][0];

    multiply(factor,input10,res);
    store[2] = res[0][0];
    store[3] = res[1][0];

    multiply(factor,input11,res);
    store[4] = res[0][0];
    store[5] = res[1][0];

    multiply(factor,input12,res);
    store[6] = res[0][0];
    store[7] = res[1][0];

    glBegin(GL_POLYGON);
		//to give color to the polygon
		glColor3f(1.0,1.0,0.0);
		glVertex2i(store[0],store[1]);
		glVertex2i(store[2],store[3]);
		//glVertex2f(0.0,0.8);
		glVertex2i(store[4],store[5]);
		glVertex2i(store[6],store[7]);
		
	glEnd();


	//glFlush clears every buffer on the screen
	glFlush();
}

int main(int argc,char **argv)
{
	//initializing the glut library
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGBA|GLUT_SINGLE);
	glutInitWindowSize(1920,1080);
	glutInitWindowPosition(1,1);
	glutCreateWindow("opengl");
	
	init();
	glutDisplayFunc(draw);
	
	glutMainLoop();
	return 0;
	
} 

