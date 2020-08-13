#include <iostream>
using namespace std;

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
            throw "y must be from 0 to 599. setY was unsuccessfull. y will be set 0 by default.";
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
   
    Point a,b,c;
    try
    {
        a.setX(500);
        
    }
    catch (const exception& except)
    {
        cout << "Caught exception: " << except.what() << endl;
    }
    try
    {
        a.setY(599);
    }
    catch(const char* except)
    {
        cout << "Caught exception: " << except << endl;
    }

    
    cout <<"a x= "<< a.getX() << endl;
    cout << "a y= " << a.getY() << endl;
    b.setX(500);
    b.setY(599);
    cout << "b x= " << b.getX() << endl;
    cout << "b y= " << b.getY() << endl;
    c = a + b;
    cout << "c = sum of a and b:" << endl;
    c.showFields();

    Colour a_col, b_col;
    try
    {
        a_col.setColour(255, 125, 45);
    }
    catch(const exception & except)
    {
        cout << "Caught exception: " << except.what() << endl;
    }
    cout << "a_col object has fields: " << endl;
    a_col.showFields();
    try
    {
        b_col.setColour(45, 200, 31);
    }
    catch (const exception& except)
    {
        cout << "Caught exception: " << except.what() << endl;
    }
    cout << "b_col object has fields: " << endl;
    b_col.showFields();
    Colour c_col;
    c_col = a_col + b_col;
    cout << "c_col sum of a_col+b_col:" << endl;
    c_col.showFields();
   
    return 0;
}

