/*enum error
   {
       WRONG_X,
       WRONG_Y,
   };*/

   /*assert(x >= 0 && x <= 799);//#include <cassert>
               m_x = x;*/

               
//if (x >= 0 && x <= 799)
//{
//    m_x = x;
//}
//else
//{
//   cerr << "You entered wrong X";
//   exit(WRONG_X); //#include <cstdlib>
//}


//static_assert(sizeof(long) == 8, "Long must be 8 bytes.");

//Point a, b, c;
//try
//{
//    a.setX(500);
//
//}
//catch (const exception& except)
//{
//    cout << "Caught exception: " << except.what() << endl;
//}
//try
//{
//    a.setY(599);
//}
//catch (const char* except)
//{
//    cout << "Caught exception: " << except << endl;
//}
//
//
//cout << "a x= " << a.getX() << endl;
//cout << "a y= " << a.getY() << endl;
//b.setX(500);
//b.setY(599);
//cout << "b x= " << b.getX() << endl;
//cout << "b y= " << b.getY() << endl;
//c = a + b;
//cout << "c = sum of a and b:" << endl;
//c.showFields();
//
//Colour a_col, b_col;
//try
//{
//    a_col.setColour(255, 125, 45);
//}
//catch (const exception& except)
//{
//    cout << "Caught exception: " << except.what() << endl;
//}
//cout << "a_col object has fields: " << endl;
//a_col.showFields();
//try
//{
//    b_col.setColour(45, 200, 31);
//}
//catch (const exception& except)
//{
//    cout << "Caught exception: " << except.what() << endl;
//}
//cout << "b_col object has fields: " << endl;
//b_col.showFields();
//Colour c_col;
//c_col = a_col + b_col;
//cout << "c_col sum of a_col+b_col:" << endl;
//c_col.showFields();
