#include <iostream>
#include <fstream>
#include <string>
#include "Point2D.h"
using namespace std;

int main() {
    int ans;
    while (true) {
        cout << "Welcome to My project! "
                "\nWhat you want to do : "
                "\n1) Test from txt file "
                "\n2) Input variables from keyboard "
                "\n3) Quit from program\n"
                "What you choose:";
        cin >> ans;
        if (ans == 1) {

            ifstream file("../Test.txt");
            if (!file.is_open()) {
                cout << "I can`t open this file" << endl;
            }
            else {
                int i = 0;
                string line, str[40];
                double str1[40];
                while (getline(file, line)) {
                    str[i] = line;
                    i++;
                }
                file.close();
                for (int j = 0; j < i; ++j) {
                    str1[j] = atoi(str[j].c_str());
                }
                Point2D(str1[1], str1[2]);
                Segment2D segment(str1[1], str1[2], str1[4], str1[5], str1[7], str1[8], str1[9], str1[10]);
                Dtype vec1;
                cout << "Do you want see vectors operation and segments cross?(Yes - 1 | No - 0):";
                cin >> vec1;
                if (Dtype(vec1) == 1.0) {
                    segment.Vector_operation();
                    segment.segment_cross();
                    cout << "Vector Sum :" << segment.x_sum() << " " << segment.y_sum() << endl;
                    cout << "Vector Riz :" << segment.x_riz() << " " << segment.y_riz() << endl;
                    cout << "Scalar :" << segment.scalar_vec() << endl;
                    cout << "Segments Cross:" << segment.x_ans() << " " << segment.y_ans() << endl;
                }
                Line2D line1(str1[12], str1[13], str1[14], str1[15], str1[16], str1[17]);
                line1.line_cross(str1[12], str1[15], str1[13], str1[16], str1[14], str1[17]);
                if (line1.x_ans() > 1e-2 && line1.y_ans() > 1e-2 && line1.x_ans() < 1e+2 && line1.y_ans() < 1e+2) {
                    cout << "X coordinate :" << line1.x_ans() << " Y coordinate:" << line1.y_ans() << endl;
                } else {
                    cout << "Line dont cross" << endl;
                }
                cout << "Coordinates of break line:";
                Polyline2D p2(str1[19], str1[20], str1[21], str1[22], str1[23], str1[24], str1[25], str1[26]);
                Point2D pt2;

                pt2.SetXY(str1[19], str1[20]);
                p2.AddPoint(pt2);

                pt2.SetXY(str1[20], str1[21]);
                p2.AddPoint(pt2);

                pt2.SetXY(str1[21], str1[22]);
                p2.AddPoint(pt2);

                pt2.SetXY(str1[22], str1[23]);
                p2.AddPoint(pt2);

                pt2.SetXY(str1[24], str1[25]);
                p2.AddPoint(pt2);

                pt2.SetXY(str1[26], str1[27]);
                p2.AddPoint(pt2);

                pt2.SetXY(str1[27], str1[28]);
                p2.AddPoint(pt2);

                cout << "Length of line :" << p2.Length() << endl;
                p2.segment_cross();
                if (p2.x_ans() > 1e-2 && p2.y_ans() > 1e-2 && p2.x_ans() < 1e+2 && p2.y_ans() < 1e+2) {
                    cout << "X coordinate :" << p2.x_ans() << " Y coordinate:" << p2.y_ans() << endl;
                } else {
                    cout << "Line dont cross" << endl;
                }
                Polygon2D poly1;
                cout<<"Area of Polygon:"<<poly1.Area2(str1[30],str1[31],str1[32],str1[33],str1[34],str1[35],str1[36],str1[37])<<endl;

            }
                break;
            }
        else if (ans == 2){
            Dtype x1, y1, x2, y2, x3, y3, x4, y4;
            cout << "Input first segments coordinates (x,y) :";
            cin >> x1 >> y1;
            Point2D(x1, y1);
            cout << "Input second segments coordinates (x,y) :";
            cin >> x2 >> y2;
            cout << "Input begin and end coordinates of segment ((x,y)(x,y)):";
            cin >> x3 >> y3 >> x4 >> y4;
            Segment2D segment(x1, y1, x2, y2, x3, y3, x4, y4);
            Dtype vec;
            cout << "Do you want see vectors operation and segments cross?(Yes - 1 | No - 0):";
            cin >> vec;
            if (Dtype(vec) == 1.0)
            {
                segment.Vector_operation();
                segment.segment_cross();
                cout << "Vector Sum : (" << segment.x_sum() << "," << segment.y_sum() << ")" << endl;
                cout << "Vector Riz : (" << segment.x_riz() << "," << segment.y_riz() << ")" << endl;
                cout << "Scalar :" << segment.scalar_vec() << endl;
                if(segment.x_ans() > 1e-2 && segment.y_ans() > 1e-2 && segment.x_ans() < 1e+2 && segment.y_ans() < 1e+2)
                {
                    cout << "Segments Cross: (" << segment.x_ans() << "," << segment.y_ans() << ")" << endl;
                }
                else
                {
                    cout<<"Segment dont crossing!"<<endl;
                }
            }
            Dtype a1, b1, c1, a2, b2, c2;
            cout << "Input first coefficients of line (a b c):";
            cin >> a1 >> b1 >> c1;
            cout << endl;
            cout << "Input second coefficients of line (a b c):";
            cin >> a2 >> b2 >> c2;
            Line2D line(a1, b1, c1, a2, b2, c2);
            Dtype lin;
            cout << "Do you want see lines cross?(Yes - 1 | No - 0):";
            cin >> lin;
            if ((Dtype) lin == 1)
            {
                line.line_cross(a1, a2, b1, b2, c1, c2);
                if(line.x_ans() > 1e-2 && line.y_ans() > 1e-2 && line.x_ans() < 1e+2 && line.y_ans() < 1e+2)
                {
                    cout << "Dots of cross:" << line.x_ans() << " " << line.y_ans() << endl;
                }
                else
                {
                    cout<<"Lines don't crossing"<<endl;
                }
            }
            int cor1, cor2, cor3, cor4, cor5, cor6, cor7, cor8;
            cout << "Input coordinates of break line (8):";
            cin >> cor1 >> cor2 >> cor3 >> cor4 >> cor5 >> cor6 >> cor7 >> cor8;
            Polyline2D p1(cor1, cor2, cor3, cor4, cor5, cor6, cor7, cor8);
            Point2D pt1;

            pt1.SetXY(cor1, cor2);
            p1.AddPoint(pt1);

            pt1.SetXY(cor2, cor3);
            p1.AddPoint(pt1);

            pt1.SetXY(cor4, cor5);
            p1.AddPoint(pt1);

            pt1.SetXY(cor6, cor7);
            p1.AddPoint(pt1);

            pt1.SetXY(cor7, cor8);
            p1.AddPoint(pt1);

            cout << "Length of line :" << p1.Length() << endl;
            p1.segment_cross();
            if (p1.x_ans() > 1e-2 && p1.y_ans() > 1e-2 && p1.x_ans() < 1e+2 && p1.y_ans() < 1e+2)
            {
                cout << "X coordinate :" << p1.x_ans() << " Y coordinate:" << p1.y_ans() << endl;
            } else {
                cout << "Line dont cross" << endl;
            }
            int n;
            cout << "Polygon1 how many points:" << endl;
            cin >> n;
            Polygon2D poly2(n);
            cout << poly2.Area1(n) << endl;
            if (poly2.Convex(n) == 0) {
                cout << "Not polygon!" << endl;
            } else if (poly2.Convex(n) == -1) {
                cout << "Polygon is convex!" << endl;
            } else if (poly2.Convex(n) == 1) {
                cout << "Polygon is prominent!" << endl;
            } else{
                cout << "Something went wrong" << endl;
            }
                break;
            } else if (ans == 3) {
            cout << "Closing Program :(" << endl;
            break;
        } else {
            cout << "You input wrong answer :( Try again!" << endl;
            break;
        }
        }
        return 0;
    }