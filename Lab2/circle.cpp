#include<stdio.h> 
#include<GL/glut.h> 
#include<math.h> 
#define pi 3.1415926535

void normal_circle (void)  
{ 
    glClear(GL_COLOR_BUFFER_BIT); 
    glBegin(GL_POINTS); 
    float x, y, i; 
      
    
    for ( i = 0; i < (2 * pi); i += 0.01) 
    { 
        
        x = 0.6 * cos(i); 
        y = 0.6 * sin(i); 

        glColor3f(0.0, 1.0, 0.0); 
          
        glVertex2f(x, y); 
    } 
    glEnd(); 
    glFlush(); 
} 

void filled_circle (void)  
{ 
    glClear(GL_COLOR_BUFFER_BIT); 
    glBegin(GL_LINES); 
    float x, y, i; 
      
   
    for ( i = 0; i < (2 * pi); i += 0.001) 
    { 
      
        x = 0.6 * cos(i); 
        y = 0.6 * sin(i); 

        glColor3f(0.0, 1.0, 0.0);
        glVertex2f(0.01,0.01);

        glColor3f(0.0, 1.0, 0.0);
        glVertex2f(x, y); 
    } 
    glEnd(); 
    glFlush(); 
} 
  
  
int main (int argc, char** argv) 
{ 
    glutInit(&argc, argv); 
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
      

    glutInitWindowSize(700, 700); 
    glutInitWindowPosition(200, 200); 
      
    glutCreateWindow("Circle Drawing"); 

      
    glutDisplayFunc(normal_circle);

    //glutDisplayFunc(filled_circle);
 
    glutMainLoop(); 
} 
