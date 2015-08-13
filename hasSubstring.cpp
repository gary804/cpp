// my first program in C++
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

struct movies_t {
  string title;
  int year;
} mine, yours;


//void printmovie (movies_t& movie);
void printmovie (movies_t movie);

bool hasSubstring(const char *str, const char *find);
int addition (int a, int b);
int subtraction (int a, int b);
int operation (int x, int y, int (*functocall)(int,int));

class Square;	//an empty declaration of class Square

class Rectangle {
    int width, height;
  public:
    Rectangle ();
  	Rectangle (int,int);
    void set_values (int,int);
    int area() {return width*height;}
    //That is done by including a declaration of this external function within the class, and preceding it with the keyword friend:
    friend Rectangle duplicate (const Rectangle&);
    void convert (Square a);
};

Rectangle::Rectangle () {
  width = 5;
  height = 5;
}

Rectangle::Rectangle (int a, int b) {
  width = a;
  height = b;
}

void Rectangle::set_values (int x, int y) {
  width = x;
  height = y;
}
// friend functions
Rectangle duplicate (const Rectangle& param)
{
  Rectangle res;
  res.width = param.width*2;
  res.height = param.height*2;
  return res;
}

class Square {
  friend class Rectangle;
  private:
    int side;
  public:
    Square (int a) : side(a) {}
};

void Rectangle::convert (Square a) {
  width = a.side;
  height = a.side;
}

class Circle {
    double radius;
  public:
    Circle(double r) { radius = r; }	//works
    //Circle(double r) :radius(r) {  }	//works
    double circum() {return 2*radius*3.14159265;}
    double area() {return radius*radius*3.14159265;}
};

class Cylinder {
    Circle base;
    double height;
  public:
    Cylinder(double r, double h) : base (r), height(h) {}	//works
    //Cylinder(double r, double h) : base (r)  {height=h;}	//works
    //Cylinder(double r, double h) {base(r); height=h;}	//not work, because the object member is not initialized after the colon, they are defualt -constructed
    double volume() {return base.area() * height;}
};

class CVector {
  public:
    int x,y;
    CVector () {};
    CVector (int a,int b) : x(a), y(b) {}
    CVector operator + (const CVector&);
    CVector& operator= (const CVector& param);
};

CVector CVector::operator+ (const CVector& param) {
  CVector temp;
  temp.x = x + param.x;
  temp.y = y + param.y;
testing:
  cout << "here x is " <<x;
  cout << ", y is " <<y;
  cout << ", and param.x is " <<param.x;
  cout << ", param.y is " <<param.y <<"\n";

  return temp;
}

//In fact, this function is very similar to the code that the compiler generates implicitly for this class for operator=.
CVector& CVector::operator= (const CVector& param)
{
  x=param.x;
  y=param.y;
  return *this;
}


class Dummy {
  public:
  	static int n;
    Dummy () { n++; };
    bool isitme (Dummy& param);
};
int Dummy::n=0;	//Again, it is just like a non-member variable, but with a name that requires to be accessed like a member of a class (or an object).

bool Dummy::isitme (Dummy& param)
{
  if (&param == this) return true;
  else return false;
}

class MyClass {
  public:
    int x;
    MyClass(int val) : x(val) {}
    //int get() {return x;}
    int& get() {return x;}
    //int get() const {return x;}	//works
    const int& get() const {return x;}
    //int get() const {return x;}        // const member functional	//In essence, const members shall not modify the state of an object.
	//const int& get() {return x;}       // member function returning a const&
	//const int& get() const {return x;} // const member function returning a const& 
};

template <class T>
class mypair {
    T values [2];
  public:
    mypair (T first, T second)
    {
      values[0]=first; values[1]=second;
    }
    T* get() {return values;}	//works
    T getmax ();
};
template <class T>
T mypair<T>::getmax ()
{
  T retval;
  retval = values[0]>values[1]? values[0] : values[1];
  return retval;
}

// class template:
template <class T>
class mycontainer {
    T element;
  public:
    mycontainer (T arg) {element=arg;}
    T increase () {return ++element;}
};

// class template specialization:
template <>
class mycontainer <char> {
    char element;
  public:
    mycontainer (char arg) {element=arg;}
    char uppercase ()
    {
      if ((element>='a')&&(element<='z'))
      element+='A'-'a';
      return element;
    }
};

class Example3 {
    string data;
  public:
    Example3 (const string& str) : data(str) {}
    Example3() {}
    const string& content() const {return data;}
};

class Example4 {
    string* ptr;
  public:
    // constructors:
    Example4() : ptr(new string) {}
    Example4 (const string& str) : ptr(new string(str)) {}
    // destructor:
    ~Example4 () {delete ptr;}
    // access content:
    const string& content() const {return *ptr;}
};

class Example5 {
    string* ptr;
  public:
    Example5 (const string& str) : ptr(new string(str)) {}
    ~Example5 () {delete ptr;}
    // copy constructor:
    Example5 (const Example5& x) : ptr(new string(x.content())) {}
    //copy assignment operator
 /*   Example5& operator= (const Example5& x) {
  		delete ptr;                      // delete currently pointed string
  		ptr = new string (x.content());  // allocate space for new string, and copy
  		return *this;
	}
*/
	//Or even better, since its string member is not constant, it could re-utilize the same string object:
	Example5& operator= (const Example5& x) {
  		*ptr = x.content();
  		return *this;
	}
    // access content:
    const string& content() const {return *ptr;}
};
/* not support &&
class Example6 {
    string* ptr;
  public:
    Example6 (const string& str) : ptr(new string(str)) {}
    ~Example6 () {delete ptr;}
    // move constructor
    Example6 (Example6&& x) : ptr(x.ptr) {x.ptr=nullptr;}
    // move assignment
    Example6& operator= (Example6&& x) {
      delete ptr; 
      ptr = x.ptr;
      x.ptr=nullptr;
      return *this;
    }
    // access content:
    const string& content() const {return *ptr;}
    // addition:
    Example6 operator+(const Example6& rhs) {
      return Example6(content()+rhs.content());
    }
};
*/
int main()
{
  //std::cout << "Hello World!" << "\n";
  //cout << "Hello World!" << "\n";
	//const char * greeting = "Hello World!";
	//const char * greeting = 0;
	const char * greeting = NULL;
	greeting = "Hello World!";
  cout << greeting << "\n";
  string mainString, subString;
  char maincString[] = "Hello World";
  char subcString[] = "o Wor";
  mainString = maincString;
  subString = subcString;
 	cout << "mainString is " << mainString << endl;
  	cout << "subString is " << subString << endl;
  //if (hasSubstring(mainString.c_str(), subString.c_str()))
  	const char * mstr = mainString.c_str();
  	const char * sstr = subString.c_str();
  if (hasSubstring(mstr, sstr))
  	//std::cout << "Yes";
  	cout << "Yes, subString is part of the mainString";
  else
  	//std::cout << "No";
  	cout << "No, subString is not part of the mainString";
  //std::cout << "\n";
  cout << endl;
  {
  cout << "Pointer to function test\n";
  int addResult,subResult;
  int (*pFunction)(int a,int b) = addition;	//function name is the address of the function

  addResult = operation (7, 5, pFunction);	//works
  addResult = operation (7, 5, addition);
  pFunction = subtraction;
  subResult = operation (20, 4, pFunction);
  cout << "7+5= "<<addResult << " and 20-4= " << subResult << endl;
  }

  {
  	cout << "new and delete test\n";
  	int i,n;
  	int * p;
  	//cout << "How many numbers would you like to type? ";
  	//cin >> i;
  	string mystr;
  tryinput:
  	cout << "How many numbers would you like to type? ";
  	getline(cin, mystr);
  	stringstream(mystr) >> i;
  	if (i<0 || i>10) goto tryinput;
  	p= new (nothrow) int[i];
  	//if (p == nullptr)
  	if (p == NULL)
    	cout << "Error: memory could not be allocated";
  	else
  	{
    	for (n=0; n<i; n++)
    	{
      		cout << "Enter number: ";
      		cin >> p[n];
    	}
    	cout << "You have entered: ";
    	for (n=0; n<i; n++)
      		cout << p[n] << ", ";
    	delete[] p;
		}
	}
	cout<<endl;
	{
		cout << "Structure test\n";
		string mystr;
		//movies_t mine, yours;
		movies_t * pmovie;
		pmovie = &mine;
  		//mine.title = "2001 A Space Odyssey";
  		//mine.year = 1968;
  		pmovie->title = "2001 A Space Odyssey";	//=(*pmovie).title	//string variable can be assigned new string
  		pmovie->year = 1968;
		pmovie = &yours;
  		getline (cin, pmovie->title);
  		if (yours.title!="") goto inputyear;
inputtitle:
  		cout << "Enter title: ";
  		//getline (cin,yours.title);
  		getline (cin, pmovie->title);
  		if (yours.title=="") goto inputtitle;
inputyear:
  		cout << "Enter year: ";
  		getline (cin,mystr);
  		if (mystr=="") goto inputyear;
  		//stringstream(mystr) >> yours.year;
  		stringstream(mystr) >> pmovie->year;
  		if (pmovie->year==0) goto inputyear;

  		cout << "My favorite movie is:\n ";
  		printmovie (mine);
  		cout << "And yours is:\n ";
  		printmovie (yours);

  		printmovie (mine);
  		printmovie (yours);
	}
	{
		cout <<"Class testing\n";
		Rectangle rect(2,3);
		Rectangle rectb;	//works
		//Rectangle rectb();	//not work
		//Rectangle rectb{};	//not works here, it should work on new version C++
  		cout << "Rectangle(2,3) area: " << rect.area() <<endl;
  		rect.set_values (3,4);
  		cout << "Rectangle(3,4) area: " << rect.area() <<endl;
  		cout << "Rectangle area: " << rectb.area() <<endl;
  		rectb = duplicate(rect);
  		cout << "Rectangle area: " << rectb.area() <<endl;

  		Circle foo (10.0);   // functional form
  		Circle bar = 20.0;   // assignment init.
  		//Circle baz {30.0};   // uniform init.	//not work here
  		//Circle qux = {40.0}; // POD-like	//not work here

  		cout << "foo's circumference: " << foo.circum() << '\n';

		Cylinder cfoo (10, 20);
  		cout << "foo's volume: " << cfoo.volume() << '\n';
  		{
  			Rectangle obj (3, 4);
  			Rectangle * foo, * bar, * baz;
  			foo = &obj;
  			bar = new Rectangle (5, 6);
  			//baz = new Rectangle[2] { {2,5}, {3,6} };	//not work here, old version C++
  			baz = new Rectangle[2];
  			//baz[0].set_values (2,5);	//works
  			//baz[1].set_values (3,6);	//works
  			baz->set_values (2,5);	//works
  			(baz+1)->set_values (3,6);	//works
  			cout << "obj's area: " << obj.area() << '\n';
  			cout << "*foo's area: " << foo->area() << '\n';
  			cout << "*bar's area: " << bar->area() << '\n';
  			cout << "baz[0]'s area:" << baz[0].area() << '\n';
  			cout << "baz[1]'s area:" << baz[1].area() << '\n';       
  			delete bar;
  			delete[] baz;
  		}
  		{
  			cout << "Operator testing: result = foo + bar;\n";
  			CVector foo (3,1);
  			CVector bar (1,2);
  			CVector result;
  			//result = foo + bar;	//= foo.operator+ (bar);
  			result = foo.operator+ (bar);
  			cout <<"(3,1)+(1,2) and result = (" << result.x << ',' << result.y << ")\n";
  			result = foo;	//class can be copied even if no operator= function
  			cout <<"? foo = (" << result.x << ',' << result.y << ")\n";
  		}
  		{
  			Dummy a;
  			Dummy* b = &a;
  			if ( b->isitme(a) )
    			cout << "yes, &a is b\n";

    		Dummy b1[5];
    		cout <<"Dummy count= " << a.n << endl;
    		Dummy * c = new Dummy;
  			cout <<"Dummy count= " << Dummy::n << '\n';
  			delete c;
  		}
  		{
  			cout << "const object testing\n";
  			const MyClass foo(10);
  			MyClass fo(1);
			//foo.x = 20;            // not valid: x cannot be modified
  			cout << foo.x << '\n';  // ok: data member x can be read
  			cout << foo.get() << '\n';  //The member functions of a const object can only be called if they are themselves specified as const members;
  			fo.get()+=10;
  			cout <<fo.get()<<endl;
  		}
  		{
  			cout<< "template class testing";
  			mypair<int> myintpait (115, 36);
  			mypair<double> mydoublepair (3.0, 2.18);
  			int* ipair = myintpait.get();
  			cout <<ipair[0] <<',' <<ipair[1]<<endl;
  			ipair[0] +=5; ipair[1] +=4;	//you can modify the member data
  			cout <<"the pair is "<<ipair[0] <<',' <<ipair[1]<<endl;
  			cout <<"max in the pair is "<< myintpait.getmax() <<endl;
  		}
  		{
  			cout <<"class template specialization testing\n";
  			mycontainer<int> myint (7);
  			mycontainer<char> mychar ('j');
  			cout << myint.increase() << endl;
  			cout << mychar.uppercase() << endl;
  		}
  		{
  			cout << "class defualt constructor testing\n";
  			Example3 foo;
  			Example3 bar ("Example");
  			cout << "bar's content: " << bar.content() << '\n';
  		}
		{
			cout << "Destructor testing\n";
			Example4 foo;
			Example4 bar ("Example");
			cout << "bar's content: " << bar.content() << '\n';
		}
		{
			cout << "Copy constructor testing\n";
			Example5 foo ("Example");
  			Example5 bar = foo;
  			cout << "bar's content: " << bar.content() << '\n';

  			//MyClass foo;
			//MyClass bar (foo);       // object initialization: copy constructor called
			//MyClass baz = foo;       // object initialization: copy constructor called
			//foo = bar;               // object already initialized: copy assignment called 

			//MyClass fn();            // function returning a MyClass object
			//MyClass foo;             // default constructor
			//MyClass bar = foo;       // copy constructor
			//MyClass baz = fn();      // move constructor
			//foo = bar;               // copy assignment
			//baz = MyClass();         // move assignment 
		}
		{
			cout << "move constructor and assignment\n";
			//MyClass (MyClass&&);             // move-constructor
			//MyClass& operator= (MyClass&&);  // move-assignment
//An rvalue reference is specified by following the type with two ampersands (&&). As a parameter, an rvalue reference matches arguments of temporaries of this type.
//- Copying from A to B means that new memory is allocated to B and then the entire content of A is copied to this new memory allocated for B.
//- Moving from A to B means that the memory already allocated to A is transferred to B without allocating any new storage. It involves simply copying the pointer.

		}
	}
  	return 0;

}

bool hasSubstring(const char *str, const char *find) {
	if (str[0] == '\0' && find[0] == '\0')
		return true;
	for(int i = 0; str[i] != '\0'; i++) {
		bool foundNonMatch = false;
		for(int j = 0; find[j] != '\0'; j++) {
			if (str[i + j] != find[j]) {
			foundNonMatch = true;
			break;
			}
		}
		if (!foundNonMatch)
			return true;
	}
	return false;
}

int addition (int a, int b)
{ return (a+b); }

int subtraction (int a, int b)
{ return (a-b); }

//int operation (int x, int y, int (*functocall)(int a,int b))
int operation (int x, int y, int (*functocall)(int ,int ))
{
  int g;
  g = (*functocall)(x,y);
  return (g);
}
//void printmovie (movies_t& movie)	//arguments are passed by reference 
void printmovie (movies_t movie)	//structure argument is passed by copy
{

  cout << movie.title;
  cout << " (" << movie.year << ")\n";
  movie.title = movie.title + " suffix";	//it is testing to see if the copy or reference of the structure
}