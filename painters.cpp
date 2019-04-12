#include<GL/freeglut.h>
#include<GL/gl.h>
#include<math.h>

void draw (void) {
    glClear(GL_COLOR_BUFFER_BIT);

    // Background
    glBegin(GL_POLYGON);
        glColor3f(0.527, 0.804, 1);
        glVertex2f(-1, -1);
        glVertex2f(1, -1);
        glVertex2f(1, 1);
        glVertex2f(-1, 1);
    glEnd();

    // Ground
    glBegin(GL_POLYGON);
        glColor3f(0, 1, 0);
        glVertex2f(-1, -1);
        glVertex2f(1, -1);
        glVertex2f(1, 0);
        glVertex2f(-1, 0);
    glEnd();

    // House: Pentagon
    glBegin(GL_POLYGON);
        glColor3f(0.1, 0.3, 0.5);
        glVertex2f(0.0, 0.0);
        glVertex2f(0.5, 0.0);
        glVertex2f(0.5, 0.5);
        glVertex2f(0.25, 0.8);
        glVertex2f(0.0, 0.5);
    glEnd();

    // House: Line
    glBegin(GL_LINES);
        glColor3f(0.0, 0.0, 1.0);
        glVertex2f(0.0, 0.5);
        glVertex2f(0.5, 0.5);
    glEnd();

    // House: Door
    glBegin(GL_POLYGON);
        glColor3f(0.2, 0.4, 0.6);
        glVertex2f(0.16, 0.0);
        glVertex2f(0.32, 0.0);
        glVertex2f(0.32, 0.32);
        glVertex2f(0.16, 0.32);
    glEnd();

    // Sun
    float radius = 0.15, cx=-0.7, cy=0.8;
    for(float i = 0; i <= 360; i+=0.1) {
        glBegin(GL_LINES);
            glColor3f(1,1,0);    
            float x = radius * sin(i*3.14/180.0);
            float y = radius * cos(i*3.14/180.0);
            glVertex2f(cx+0.0,cy+0.0);
            glVertex2f(cx+x,cy+y);
        glEnd();
    }

    // Car: Body
    glBegin(GL_POLYGON);
        glColor3f(0.5, 0.5, 0.5);
        glVertex2f(-0.7, -0.6);
        glVertex2f(0.25, -0.6);
        glVertex2f(0.25, -0.2);
        glVertex2f(-0.7, -0.2);
    glEnd();

    // Car: Front
    glBegin(GL_POLYGON);
        glColor3f(0.5, 0.5, 0.5);
        glVertex2f(-0.9, -0.6);
        glVertex2f(0.25, -0.6);
        glVertex2f(-0.1, -0.3);
        glVertex2f(-0.9, -0.45);
    glEnd();

    // Car: Wheels
    radius = 0.12, cx=-0.5, cy=-0.63;
    for(float i = 0; i <= 360; i+=0.1) {
        glBegin(GL_LINES);
            glColor3f(0,0,0);    
            float x = radius * sin(i*3.14/180.0);
            float y = radius * cos(i*3.14/180.0);
            glVertex2f(cx+0.0,cy+0.0);
            glVertex2f(cx+x,cy+y);
        glEnd();
    }
    radius = 0.12, cx=0.01, cy=-0.63;
    for(float i = 0; i <= 360; i+=0.1) {
        glBegin(GL_LINES);
            glColor3f(0,0,0);    
            float x = radius * sin(i*3.14/180.0);
            float y = radius * cos(i*3.14/180.0);
            glVertex2f(cx+0.0,cy+0.0);
            glVertex2f(cx+x,cy+y);
        glEnd();
    }

    // Bird
    radius = 0.12, cx=-0.4, cy=0.4;
    for(float i = 0; i <= 360; i+=0.1) {
        glBegin(GL_LINES);
            glColor3f(0,0.39,0);    
            float x = (radius+0.02) * sin(i*3.14/180.0);
            float y = radius * cos(i*3.14/180.0);
            glVertex2f(cx+0.0,cy+0.0);
            glVertex2f(cx+x,cy+y);
        glEnd();
    }

    radius = 0.05, cx=-0.55, cy=0.45;
    for(float i = 0; i <= 360; i+=0.1) {
        glBegin(GL_LINES);
            glColor3f(1,0,0);    
            float x = radius * sin(i*3.14/180.0);
            float y = radius * cos(i*3.14/180.0);
            glVertex2f(cx+0.0,cy+0.0);
            glVertex2f(cx+x,cy+y);
        glEnd();
    }

    glBegin(GL_POLYGON);
        glColor3f(1,0,0);
        float r = 0.05;
        glVertex2f(-0.7,0.47-r);
        glVertex2f(-0.55,0.47-r);
        glVertex2f(-0.55,0.5-r);
    glEnd();

    glFlush();
}

int main (int argc, char ** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA|GLUT_SINGLE);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Random");
    glutDisplayFunc(draw);
    glutMainLoop();
    return 0;
}