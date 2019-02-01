#include <GL/freeglut.h>
#include <GL/gl.h>
#include <bits/stdc++.h>

#define WIDTH 600
#define HEIGHT 600

using namespace std;

const double PI = 3.14159265358979323;

void drawChessBoard() {

    glClear(GL_COLOR_BUFFER_BIT);

    // Border
    glBegin(GL_POLYGON);
        //glColor3f(255.0/255, 170.0/255, 0.0/255);
        glVertex2f(1.0, 1.0);
        glVertex2f(1.0, -1.0);
        glVertex2f(-1.0, -1.0);
        glVertex2f(-1.0, 1.0);
    glEnd();

    // Squares
    for(int i=0; i<8; i++)
        for(int j=0; j<8; j++) {
            glBegin(GL_POLYGON);
                if((i+j)%2)
                    glColor3f(255.0/255, 255.0/255, 255.0/255); // white
                else
                    glColor3f(6.0/255, 6.0/255, 6.0/255); // Black

                glVertex2f(-1.0 + j*0.25,     1.0 - i*0.25);
                glVertex2f(-1.0 + (j+1)*0.25, 1.0 - i*0.25);
                glVertex2f(-1.0 + (j+1)*0.25, 1.0 - (i+1)*0.25);
                glVertex2f(-1.0 + j*0.25,     1.0 - (i+1)*0.25);
            glEnd();
        }
    
    glFlush();
}

int main(int argc, char **argv) {

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Chess Board");
    glutDisplayFunc(drawChessBoard);
    glutMainLoop();
}
