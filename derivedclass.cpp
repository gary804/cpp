#include <iostream>
#include <string>
using namespace std;

class Polygon {
  protected:
    int width, height;
  public:
    Polygon() {cout<< "Polygon: No parameter\n";}
    //Polygon(int a, int b) {cout<< "Polygon: 2 int parameters\n"; set_values(a,b);}  //works
    Polygon(int a, int b) : width(a), height(b) {cout<< "Polygon: 2 int parameters: " <<a <<", " <<b <<"\n";}  //works
    void set_values (int a, int b)
      { width=a; height=b;}
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
    Rectangle(){ cout<< "Rectangle: No parameter\n";}
    //derived_constructor_name (parameters) : base_constructor_name (parameters) {...}
    Rectangle(int a, int b) : Polygon(a,b) { cout<< "Rectangle: 2 int parameters: " <<a <<", " <<b <<"\n";}
    int area ()
      { return width * height; }
 };

class Triangle: public Polygon, public Output {
  public:
    Triangle(){cout<<"Triangle: No parameter\n";}
    Triangle(int a, int b):Polygon(a,b){cout<<"Triangle: 2 int parameters: " <<a <<", " <<b <<"\n";}
    int area ()
      { return width * height / 2; }
  };
  
int main () {
  {
    Rectangle rect;
    Triangle trgl;
    rect.set_values (4,5);
    trgl.set_values (4,5);
    //cout <<"Rectangle area is " << rect.area() << '\n';
    //cout <<"Triangle area is " << trgl.area() << '\n';
    rect.print("Rectangle area is ", rect.area());
    trgl.print("Triangle area is ", trgl.area());
  }
  {
    Rectangle rect(4,5);
    Triangle trgl(4,5);
    //cout <<"Rectangle area is " << rect.area() << '\n';
    //cout <<"Triangle area is " << trgl.area() << '\n';
    rect.print("Rectangle area is ", rect.area());
    //trgl.print("Triangle area is ", trgl.area());  //works
    Triangle::print("Triangle area is ", trgl.area());
  }
  return 0;
}