#include <iostream>
#include <string>

#include <exception>

#include <typeinfo>

using namespace std;

class Polygon {
  protected:
    int width, height;
  public:
    Polygon() {cout<< "Polygon constructor: No parameter\n";}
    //Polygon(int a, int b) {cout<< "Polygon: 2 int parameters\n"; set_values(a,b);}  //works
    Polygon(int a, int b) : width(a), height(b) {cout<< "Polygon constructor: 2 int parameters: " <<a <<", " <<b <<"\n";}  //works
    void set_values (int a, int b)
      { width=a; height=b;}
    //virtual member: A virtual member is a member function that can be redefined in a derived class, while preserving its calling properties through references.
    //virtual int area() {return 0;}  //if called, it will call the member of the class that is pointed by a pointer. it just works like in Java
    //virtual int area() =0;  //now it is a pure virtual function, and the class is a abstract class that will not allow to instantiate
    virtual int area(void) =0;  //now it is a pure virtual function, and the class is a abstract class that will not allow to instantiate
    void printarea(){ cout<<this->area() << endl;}  //this->area() will call subclass member function
 };

 class Output {
  public:
    static void print (string str, int i);
};
void Output::print (string str, int i) {
  cout << str << i << '\n';
}

class Rectangle: public Polygon , public Output {
  public:
    Rectangle(){ cout<< "Rectangle constructor: No parameter\n";}
    //derived_constructor_name (parameters) : base_constructor_name (parameters) {...}
    Rectangle(int a, int b) : Polygon(a,b) { cout<< "Rectangle constructor: 2 int parameters: " <<a <<", " <<b <<"\n";}
    int area ()
      { return width * height; }
 };

class Triangle: public Polygon, public Output {
  public:
    Triangle(){cout<<"Triangle constructor: No parameter\n";}
    Triangle(int a, int b):Polygon(a,b){cout<<"Triangle constructor: 2 int parameters: " <<a <<", " <<b <<"\n";}
    int area ()
      { return width * height / 2; }
  };

class Base { virtual void dummy() {} };
class Derived: public Base { int a; };

  
int main () {
  {
    cout << "Testing Group 1\n";
    Rectangle rect;
    Triangle trgl;
    //Polygon poly;
    Polygon * ppolygon1, * ppolygon2, * ppolygon3; //pay attention on * here
    ppolygon1 = &rect;
    ppolygon2 = &trgl;
    //ppolygon3 = &poly;
    //rect.set_values (4,5);
    //trgl.set_values (4,5);
    ppolygon1->set_values (4,5);
    ppolygon2->set_values (4,5);
    //ppolygon3->set_values (4,5);
    //cout <<"Rectangle area is " << rect.area() << '\n';
    //cout <<"Triangle area is " << trgl.area() << '\n';
    //rect.print("Rectangle area is ", rect.area());  //works
    //trgl.print("Triangle area is ", trgl.area()); //works
    //rect.print("Rectangle area is ", ppolygon1->area());  //it won't work, because area is not a member in Polygon without virtual member
    //trgl.print("Triangle area is ", ppolygon2->area());  //it won't work, only the members inherited from Polygon can be accessed
    rect.print("Rectangle area is ", ppolygon1->area());  //now works, because it is virtual member
    trgl.print("Triangle area is ", ppolygon2->area());  //now works
    cout << "using printarea function\n";
    cout<<"Rectangle area is "; ppolygon1->printarea();  //now works, because it is virtual member
    cout<<"Triangle area is "; ppolygon2->printarea();  //now works
    //cout <<"Polygon area is " << ppolygon3->area() <<endl;  //now works
  }

  {
    cout << "Testing Group 2\n";
    Rectangle rect(4,5);
    Triangle trgl(4,5);
    //cout <<"Rectangle area is " << rect.area() << '\n';
    //cout <<"Triangle area is " << trgl.area() << '\n';
    rect.print("Rectangle area is ", rect.area());
    //trgl.print("Triangle area is ", trgl.area());  //works
    Triangle::print("Triangle area is ", trgl.area());
  }
  {
    cout << "Testing Group 3\n";
//following 2 lines are declared being of type "pointer to Polygon", but the objects allocated have been declared having the derived class type directly (Rectangle and Triangle).
    Polygon * ppoly1 = new Rectangle (4,5);
    Polygon * ppoly2 = new Triangle (4,5);
    ppoly1->printarea();
    ppoly2->printarea();
    delete ppoly1;
    delete ppoly2;
  }
  try {
//dynamic_cast can only be used with pointers and references to classes (or with void*). 
//Its purpose is to ensure that the result of the type conversion points to a valid complete object of the destination pointer type.
//But dynamic_cast can also downcast (convert from pointer-to-base to pointer-to-derived) polymorphic classes (those with virtual members) if -and only if- the pointed object is a valid complete object of the target type.
    cout<< "dynamic_cast Testing\n";
    Base * pba = new Derived;
    Base * pbb = new Base;
    Derived * pd;

    pd = dynamic_cast<Derived*>(pba);
    if (pd==0) cout << "Null pointer on first type-cast.\n";

    pd = dynamic_cast<Derived*>(pbb);
    if (pd==0) cout << "Null pointer on second type-cast.\n"; //if not cast, the pd will be 0;

  } catch (exception& e) {cout << "Exception: " << e.what();}
//static_cast can perform conversions between pointers to related classes, not only upcasts, but also downcasts 
//No checks are performed during runtime to guarantee that the object being converted is in fact a full object of the destination type.
//Therefore, it is up to the programmer to ensure that the conversion is safe. 

//reinterpret_cast converts any pointer type to any other pointer type, even of unrelated classes.
//The operation result is a simple binary copy of the value from one pointer to the other.
//All pointer conversions are allowed: neither the content pointed nor the pointer type itself is checked.

//const_cast: This type of casting manipulates the constness of the object pointed by a pointer, either to be set or to be removed.

  {
    //typeid allows to check the type of an expression: typeid (expression)
    cout << "typeid (expression) testing\n";
    int * a, b;
    a=0; b=0;
    if (typeid(a) != typeid(b))
    {
      cout << "a and b are of different types:\n";
      cout << "a is: " << typeid(a).name() << '\n';
      cout << "b is: " << typeid(b).name() << '\n';
    }
  }

  try {
    Base* a = new Base;
    Base* b = new Derived;
    cout << "a is: " << typeid(a).name() << '\n';
    cout << "b is: " << typeid(b).name() << '\n';
    cout << "*a is: " << typeid(*a).name() << '\n';
    cout << "*b is: " << typeid(*b).name() << '\n';
  } catch (exception& e) { cout << "Exception: " << e.what() << '\n'; }

  return 0;
}