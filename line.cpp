#include <bits/stdc++.h>
using namespace std;

const int INSIDE = 0; // 0000
const int LEFT = 1;   // 0001
const int RIGHT = 2;  // 0010
const int BOTTOM = 4; // 0100
const int TOP = 8;    // 1000

const int x_max = 10;
const int y_max = 8;
const int x_min = 4;
const int y_min = 4;

int computeCode(double x, double y)
{
    int code = INSIDE;

    if (x < x_min)       // to the left of rectangle
        code |= LEFT;
    else if (x > x_max)  // to the right of rectangle
        code |= RIGHT;
    if (y < y_min)       // below the rectangle
        code |= BOTTOM;
    else if (y > y_max)  // above the rectangle
        code |= TOP;

    return code;
}

void cohenSutherlandClip(double x1, double y1,
                         double x2, double y2)
{
    int code1 = computeCode(x1, y1);
    int code2 = computeCode(x2, y2);

    bool accept = false;

    while (true)
    {
        if ((code1 == 0) && (code2 == 0))
        {
            accept = true;
            break;
        }
        else if (code1 & code2)
        {
            break;
        }
        else
        {
            int code_out;
            double x, y;

            if (code1 != 0)
                code_out = code1;
            else
                code_out = code2;

            // Find intersection point;
            // using formulas y = y1 + slope * (x - x1),
            // x = x1 + (1 / slope) * (y - y1)
            if (code_out & TOP)
            {
                // point is above the clip rectangle
                x = x1 + (x2 - x1) * (y_max - y1) / (y2 - y1);
                y = y_max;
            }
            else if (code_out & BOTTOM)
            {
                // point is below the rectangle
                x = x1 + (x2 - x1) * (y_min - y1) / (y2 - y1);
                y = y_min;
            }
            else if (code_out & RIGHT)
            {
                // point is to the right of rectangle
                y = y1 + (y2 - y1) * (x_max - x1) / (x2 - x1);
                x = x_max;
            }
            else if (code_out & LEFT)
            {
                // point is to the left of rectangle
                y = y1 + (y2 - y1) * (x_min - x1) / (x2 - x1);
                x = x_min;
            }

            // Now intersection point x,y is found
            // We replace point outside rectangle
            // by intersection point
            if (code_out == code1)
            {
                x1 = x;
                y1 = y;
                code1 = computeCode(x1, y1);
            }
            else
            {
                x2 = x;
                y2 = y;
                code2 = computeCode(x2, y2);
            }
        }
    }
    if (accept)
    {
        cout <<"Line accepted from " << x1 << ", "
             << y1 << " to "<< x2 << ", " << y2 << endl;
    }
    else
        cout << "Line rejected" << endl;
}

int main()
{
    double x1,y1,x2,y2;
    cout<<"enter co-ordinates for first point"<<endl;

    cin>>x1>>y1;

    cout<<"enter co-ordinates for second point"<<endl;

    cin>>x2>>y2;

    cohenSutherlandClip(x1, y1, x2, y2);

    return 0;
}
