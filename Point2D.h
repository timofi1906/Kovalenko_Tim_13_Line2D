
#ifndef LINES2D_KOVALENKO_CPP_POINT2D_H
#define LINES2D_KOVALENKO_CPP_POINT2D_H
#include <cmath>
#include <stdlib.h>
#include <string>

using namespace std;
typedef double Dtype;

/// класс Точка
class Point2D
{
public:
    Dtype x, y; // 2 змінні
    string a = "ABCDEFGHIJKLMNOP";//Обозначення точки
    Point2D(Dtype x, Dtype y)//в данному конструкторі ми ініціалізуемо змінні та виводемо інформацію про точку
    {
        this->x = x;//Ініціалізація
        this->y = y;//Ініціалізація
        cout << a[rand() % (a.length())] << " : " << x << " " << y << endl;//Вивід
    }Point2D(void)
    {
        x = y = 0;
    }
    ///Повертае Х координату точки
    int GetX(void) ;
    ///Повертае Y координату точки
    int GetY(void) ;
    ///Привласнюе передані координати до х та у
    void SetXY(int nx, int ny);
};


class Segment2D///Класс Сегмент
{
private:
    Point2D begin1,end1,begin2,end2;//координати кінця 4 точок які
    Dtype vec1[5],sum[2],riz[2],dot[2],scalar;//змінні в якіх містяться відповіді з обчисленями
public:
    Segment2D(Dtype x1, Dtype y1, Dtype x2, Dtype y2, Dtype x3, Dtype y3 , Dtype x4, Dtype y4): begin1(x1, y1), end1(x2, y2), begin2(x3, y3), end2(x4, y4)
    {
        cout<<"Segment base on 2 dots ("<<begin1.x<<" "<<begin1.y<<") and ("<<end1.x<<" "<<end1.y<<") and his length :"<<Length1()<<endl;//вивід першого відрізка
        cout<<"Segment base on 2 dots ("<<begin2.x<<" "<<begin2.x<<") and ("<<end2.x<<" "<<end2.y<<") and his length :"<<Length2()<<endl;//вивід другого відрізка
    }
    ///Обчислення довжини першого відрізку
    Dtype Length1();
    ///Обчислення довжини другого відрізку
    Dtype Length2();
    ///Операції з векторами
    bool Vector_operation();

    ///Відповідь сумми векторів по х
    Dtype x_sum();

    ///Відповідь сумми векторів по у
    Dtype y_sum();

    ///Відповідь різниці векторів по х
    Dtype x_riz();

    ///Відповідь різниці векторів по у
    Dtype y_riz();

    ///Відповідь скалярного добутка
    Dtype scalar_vec();

    ///Функція перетину сегментів
    bool segment_cross();

    ///Координати точки-відповіді по х
    Dtype x_ans();

    ///Координати точки-відповіді по у
    Dtype y_ans();

};

///Класс Лінія
class Line2D{
protected:
    Dtype a;//
    Dtype b;//Змінні классу
    Dtype c;//
    Dtype pot[2];
public:
    Line2D(Dtype a, Dtype b, Dtype c, Dtype a2, Dtype b2, Dtype c2)
    {
        this->a = a;//Ініціалізація
        this->b = b;//Ініціалізація
        this->c = c;//Ініціалізація
        cout << "First Line have view :" << a << "x+" << b << "y+" << c << "=0" << endl;    //Вид 1 лінії
        cout<<endl;
        cout << "Second Line have view :" << a2 << "x+" << b2 << "y+" << c2 << "=0" << endl;//Вид 2 лінії
    }
    ///Перетин ліній
    void line_cross(Dtype a1, Dtype a2, Dtype b1, Dtype b2, Dtype c1, Dtype c2);

    ///Координати точки-відповіді по х
    Dtype x_ans();

    ///Координати точки-відповіді по y
    Dtype y_ans();
};
///Класс Ламана лінія
class Polyline2D:public Segment2D
{
    int n;          // кількість точок
    Point2D cp[10]; // массив точек

public:
    /// конструктор классу
    Polyline2D(Dtype x1, Dtype y1, Dtype x2, Dtype y2, Dtype x3, Dtype y3, Dtype x4, Dtype y4) : Segment2D(x1, y1, x2, y2, x3, y3, x4, y4) { n = 0; }

    /// метод доступу
    Point2D GetPoint(int index)
    {
        return cp[index];
    }

    /// встановлюе нове значення точки
    void SetPoint(int index, Point2D & pt);

    /// додае точку ламаної
    void AddPoint(Point2D pt);

    /// визначае довжину лінії
    double Length(void);
};

class Polygon2D
{
public:
   Point2D *Vertexes;  //Динамический массив вершин много угольника

//Конструктор
    Polygon2D(int n)
    {
        Vertexes = new Point2D[n];

        for(int z = 0; z < n; z++)
        {
            cout << "Input" << z+1 << " dot of polygone:\nx=";
            cin >> Vertexes[z].x;
            cout << "\ny=";
            cin >> Vertexes[z].y;
        }
    }
    Polygon2D()
    {};
    ~Polygon2D(void)
    {
        delete[] Vertexes;
    }

    ///Площа багатокутника для юзера
    double Area1(int Points);

    ///Опуклий чи випуклий
    int Convex(int n);

    ///Площа багатокутника для файлу
    double Area2(Dtype x1, Dtype y1, Dtype x2, Dtype y2, Dtype x3, Dtype y3, Dtype x4, Dtype y4);
};

#endif ///LINES2D_KOVALENKO_CPP_POINT2D_H
