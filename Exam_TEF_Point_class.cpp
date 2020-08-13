#include <iostream>
using namespace std;


                                               /*it was an exam problem to solve, but personally my opinion is:
                                               in this kind of relationship we should not use inheritance, 
                                               as class colour should not have such methods as setX/setY/getX/getY
                                               colour "is not" a point (inheritance has a relationships "is a"), 
                                               so here it is better to use aggregation(Point "has a" colour)*/
class Point
{
private:
    double m_x;//can be from 0 to 799
    double m_y;//can be from 0 to 599
   
public:
    Point(): m_x (0), m_y(0)
    {
    }
    void setX(double x)
    {
        if (x < 0 || x > 799)
        {
            throw exception("x must be from 0 to 799. setX was unsuccessfull. x will be set 0 by default.");
        }
        m_x = x;
        
    }
    double getX()
    {
        return m_x;
    }
    void setY(double y)
    {
        if (y < 0 || y > 599)
        {
            throw exception("y must be from 0 to 599. setY was unsuccessfull. y will be set 0 by default.");
        }
        m_y = y;
    }
    double getY()
    {
        return m_y;
    }
    virtual void showFields()
    {
        cout << "x= " << m_x << endl;
        cout << "y= " << m_y << endl;
    }

    Point operator+(const Point& other)
    {
        Point temp;
        temp.m_x = this->m_x + other.m_x;
        temp.m_y = this->m_y + other.m_y;
        if (temp.m_x > 799)
        {
            temp.m_x -= 799;
        }
        if (temp.m_y > 599)
        {
            temp.m_y -= 599;
        }
        return temp;
    }
};

class Colour: public Point
{
private:
    
    int  m_red;
    int  m_green;
    int  m_blue;
  
public:
    Colour(): m_red(0), m_green(0), m_blue(0)
    {
        
    }
    void setColour(int red, int green, int blue)
    {
        if ((red < 0 || red > 255) || (green < 0 || green > 255) || (blue < 0 || blue > 255))
        {
            throw exception("colour value must be from 0 to 255. Red will be 0, Green will be 0, Blue will be 0 by default.");
        }
            m_red = red;
            m_green = green;
            m_blue = blue;
        
    }

    void showFields() override
    {
        cout << "red= " << m_red << endl;
        cout << "green= " << m_green << endl;
        cout << "blue= " << m_blue << endl;
    }
    Colour operator+(const Colour& other)//result is average value of the fields values
    {
        Colour temp;
        temp.m_blue = (this->m_blue + other.m_blue) / 2;
        temp.m_green = (this->m_green + other.m_green) / 2;
        temp.m_red = (this->m_red + other.m_red) / 2;
        return temp;
    }
};





int main()
{
    Point a, b, c;
    try
    {
       
        a.setX(99);
        a.setY(78);
        
        b.setX(700);
        b.setY(67);
        
        c.setX(56);
        c.setY(350);

    }
    catch (const exception& except)
    {
        cout << "Caught exception: " << except.what() << endl;
    }

    cout << "a fields:" << endl;
    a.showFields();

    cout << "b fields:" << endl;
    b.showFields();

    cout << "c fields:" << endl;
    c.showFields();

    Colour a_col, b_col, c_col;
    try
    {
        a_col.setColour(124, 45, 98);
        b_col.setColour(16, 87, 94);
        c_col.setColour(98, 33, 90);
        
    }
    catch (const exception& except)
    {
        cout << "Caught exception: " << except.what() << endl;
    }
    cout << "a_col fields:" << endl;
    a_col.showFields();
    cout << "b_col fields:" << endl;
    b_col.showFields();
    cout << "c_col fields:" << endl;
    c_col.showFields();

    Point d = a + b;
    Colour d_col = a_col + b_col;

    cout << "d fields:" << endl;
    d.showFields();

    cout << "d_col fields:" << endl;
    d_col.showFields();

    return 0;
}

