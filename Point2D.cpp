#include <iostream>
#include "Point2D.h"
using namespace std;
//Point2D
int Point2D::GetX(void) { return x; }

int Point2D::GetY(void) { return y; }

void Point2D::SetXY(int nx, int ny)
{
    x = nx;
    y = ny;
}

//Segment2D
Dtype Segment2D::Length1(){return sqrt((end1.x-begin1.x)*(end1.x-begin1.x)+(end1.y-begin1.y)*(end1.y-begin1.y));}

Dtype Segment2D::Length2(){return sqrt((end2.x-begin2.x)*(end2.x-begin2.x)+(end2.y-begin2.y)*(end2.y-begin2.y));}

bool Segment2D::Vector_operation()
{
    vec1[0] = end1.x-begin1.x;///координата першого вектора по х
    vec1[1] = end1.y-begin1.y;///координата першого вектора по у
    vec1[3] = end2.x-begin2.x;///координата другого вектора по х
    vec1[4] = end2.y-begin2.y;///координата другого вектора по у
    sum[0] = vec1[0]+vec1[3];///Векторна сума по х
    sum[1] = vec1[1]+vec1[4];///Векторна сума по у
    riz[0] = vec1[0]-vec1[3];///Векторна різниця по х
    riz[1] = vec1[1]-vec1[4];///Векторна різниця по у
    scalar = vec1[0]*vec1[3] + vec1[1]+vec1[4];///Скалярний добуток векторів
    return 1;
}

Dtype Segment2D::x_sum(){return sum[0];}

Dtype Segment2D::y_sum(){return sum[1];}

Dtype Segment2D::x_riz(){return riz[0];}

Dtype Segment2D::y_riz(){return riz[1];}

Dtype Segment2D::scalar_vec(){return scalar;}

bool Segment2D::segment_cross() {
    Dtype n;
    if (end1.y - begin1.y != 0) {  // a(y)
        Dtype q = (end1.x - begin1.x) / (begin1.y - end1.y);
        Dtype sn = (begin2.x - end2.x) + (begin2.y - end2.y) * q; if (!sn) { return 0; }  // c(x) + c(y)*q
        Dtype fn = (begin2.x - begin1.x) + (begin2.y - begin1.y) * q;   // b(x) + b(y)*q
        n = fn / sn;
    }
    else {
        if (!(begin2.y - end2.y)) { return 0; }  // b(y)
        n = (begin2.y - begin1.y) / (begin2.y - end2.y);   // c(y)/b(y)
    }
    dot[0] = begin2.x + (end2.x - begin2.x) * n;  // x3 + (-b(x))*n
    dot[1] = begin2.y + (end2.y - begin2.y) * n;  // y3 +(-b(y))*n

    return 1;
}

Dtype Segment2D::x_ans(){return dot[0];}

Dtype Segment2D::y_ans(){return dot[1];}

//Line2D

void Line2D::line_cross(Dtype a1, Dtype a2, Dtype b1, Dtype b2, Dtype c1, Dtype c2)
{   if ((a1 / a2) == (b1 / b2))
    {
        cout << "Lines are parallel!"<<endl;
    }
    else {
        Dtype det = a1 * b2 - a2 * b1;
        pot[0] = (b1 * c2 - b2 * c1) / det;
        pot[1] = (a2 * c1 - a1 * c2) / det;
    }
}

Dtype Line2D::x_ans(){return pot[0];}

Dtype Line2D::y_ans(){return pot[1];}

//Polyline2D

void Polyline2D::SetPoint(int index, Point2D & pt)
{
    if (index>=n) return;
    cp[index] = pt;
}

void Polyline2D::AddPoint(Point2D pt)
{
    if (n<10) n++;
    else return;
    cp[n-1] = pt;
}

double Polyline2D::Length(void)
{
    double len, t;
    int x1, y1, x2, y2;

    len = 0;
    for (int i=0; i<n-1; i++)
    {
        x1 = cp[i].GetX();
        y1 = cp[i].GetY();
        x2 = cp[i+1].GetX();
        y2 = cp[i+1].GetY();
        t = sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
        len += t;
    }
    return len;

}

double Polygon2D::Area1(int Point)
{
    int x1, x2, y1, y2, x, y;
    double sum=0;
    cin >> x >> y;
    x1=x;
    y1=y;
    for (int i=0; i<(Point-1); i++) {
        cin >> x2 >> y2;
        sum=sum+(x1+x2)*(y2-y1);
        x1=x2;
        y1=y2;
    }
    sum=sum+(x+x2)*(y-y2);
    return sum;
}

double Polygon2D::Area2(Dtype x1,Dtype y1,Dtype x2,Dtype y2,Dtype x3,Dtype y3,Dtype x4,Dtype y4)
{
    double sum=0;
    sum=sum+(x1+x2)*(y1-y2)+(x2+x3)*(y2-y3)+(x3+x4)*(y3-y4);
    return sum;
}
int Polygon2D::Convex(int n)
{
    int i,j,k;
    int flag = 0;
    double z;
    Vertexes;

    if (n < 3)
        return(0);

    for (i=0;i<n;i++) {
        j = (i + 1) % n;
        k = (i + 2) % n;
        z  = (Vertexes[j].x - Vertexes[i].x) * (Vertexes[k].y - Vertexes[j].y);
        z -= (Vertexes[j].y - Vertexes[i].y) * (Vertexes[k].x - Vertexes[j].x);
        if (z < 0)
            flag |= 1;
        else if (z > 0)
            flag |= 2;
        if (flag == 3)
            return(1);
    }
    if (flag != 0)
        return(-1);
    else
        return(0);
}







