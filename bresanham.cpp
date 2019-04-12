#include <GL/freeglut.h>
#include <GL/gl.h>
#include <stdlib.h>
#include <math.h>
#include<bits/stdc++.h>


void myInit (void)
{
    // making background color black as first
    // 3 arguments all are 0.0
    glClearColor(0.0, 0.0, 0.0, 1.0);

    // making picture color green (in RGB mode), as middle argument is 1.0

    // breadth of picture boundary is 1 pixel
    glPointSize(1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    // setting window dimension in X- and Y- direction
    gluOrtho2D(-780, 780, -420, 420);
}



void bresenham_line(int x0, int y0, int x1, int y1)
{
    int temp_x, temp_y, x, y, i;
    float dx, dy, m, d2y, d2x, d2y_x, d2x_y, p;


    m = (float)(y1-y0) / (x1-x0);


    glBegin(GL_POINTS);
    glColor3f(0, 0, 1);


    if ((m >= 0 && m <= 1) || (m <= 0 && m >= -1))
    {
        if (x1 < x0)
        {
            temp_x = x0;
            temp_y = y0;

            x0 = x1;
            y0 = y1;

            x1 = temp_x;
            y1 = temp_y;
        }

        dx = x1 - x0;
        dy = y1 - y0;

        int yi = 1;
        if (dy < 0)
        {
            yi = -1;
            dy = -dy;
        }

        d2y = 2*dy;
        d2y_x = 2*dy - 2*dx;


        glVertex2i(x0,y0);
        p = d2y - dx;
        x = x0; y = y0;

        for (i=0; i<dx; i++)
        {
            x++;

            if (p < 0)
            {
                p = p + d2y;
            }
            else
            {
                y+=yi;
                p = p + d2y_x;
            }
            glVertex2f(x,y);
        }
    }


    else
    {
        if (y1 < y0)
        {
            temp_x = x0;
            temp_y = y0;

            x0 = x1;
            y0 = y1;

            x1 = temp_x;
            y1 = temp_y;
        }

        dx = x1 - x0;
        dy = y1 - y0;

        int xi = 1;
        if (dx < 0)
        {
            xi = -1;
            dx = -dx;
        }

        d2x = 2*dx;
        d2x_y = 2*dx - 2*dy;


        glVertex2i(x0,y0);
        p = d2x - dy;
        x = x0; y = y0;

        for (i=0; i<dy; i++)
        {
            y++;
            if (p < 0)
            {
                p = p + d2x;
            }
            else
            {
                x+=xi;
                p = p + d2x_y;
            }
            glVertex2f(x,y);
        }
    }


    glEnd();
    glFlush();
}



void bresenham_circle(int xc, int yc, float r)
{
    int x, y, i;
    float p;


    glBegin(GL_POINTS);
    glColor3f(0, 0, 1);

    x = 0; y = r;
    p = 3 - 2*r;

    while (y >= x)
    {
        x++;

        if (p > 0)
        {
            y--;
            p += + 4 * (x - y) + 10;
        }
        else
        {
            p += + 4 * x + 6;
        }
        
        glVertex2i(xc+x, yc+y);
        glVertex2i(xc-x, yc+y);
        glVertex2i(xc+x, yc-y);
        glVertex2i(xc-x, yc-y);
        glVertex2i(xc+y, yc+x);
        glVertex2i(xc-y, yc+x);
        glVertex2i(xc+y, yc-x);
        glVertex2i(xc-y, yc-x);
    }


    glEnd();
    glFlush();
}





void display()
{
    int i;
    float r, pi = 3.14159;

    glClear(GL_COLOR_BUFFER_BIT);


    glBegin(GL_QUADS);
    glColor3f(0.957, 0.576, 0.188);

    glVertex2f(-400, 225);
    glVertex2f(400, 225);
    glVertex2f(400, 75);
    glVertex2f(-400, 75);

    glEnd();
    glFlush();




    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);

    glVertex2f(-400, 75);
    glVertex2f(400, 75);
    glVertex2f(400, -75);
    glVertex2f(-400, -75);

    glEnd();
    glFlush();




    glBegin(GL_QUADS);
    glColor3f(0, 1, 0);

    glVertex2f(-400, -75);
    glVertex2f(400, -75);
    glVertex2f(400, -225);
    glVertex2f(-400, -225);

    glEnd();
    glFlush();


    r = 70;
    bresenham_circle(0, 0, r);

    for(i = 0; i < 12; i++)
        bresenham_line(r*cos(pi*i/12), r*sin(pi*i/12), -r*cos(pi*i/12), -r*sin(pi*i/12));

}





int main (int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    // giving window size in X- and Y- direction
    glutInitWindowSize(1366, 768);
    glutInitWindowPosition(0, 0);

    // Giving name to window
    glutCreateWindow("House");
    myInit();

    glutDisplayFunc(display);
    glutMainLoop();
}