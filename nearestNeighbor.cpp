#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

#define ARRAY_SIZE(array) (sizeof((array))/sizeof((array[0])))

using namespace std;
/*
class AAA
{
	friend ostream &operator<<(ostream &, const AAA &);
	public:
		int x;
		int y;
		float z;
		AAA();
		AAA(const AAA &);
		~AAA(){};
		AAA &operator=(const AAA &rhs);
		int operator==(const AAA &rhs) const;
		int operator<(const AAA &rhs) const;
};

AAA::AAA()   // Constructor
{
	x = 0;
	y = 0;
	z = 0;
}

AAA::AAA(const AAA &copyin)   // Copy constructor to handle pass by value.
{                            
	x = copyin.x;
	y = copyin.y;
	z = copyin.z;
}

ostream &operator<<(ostream &output, const AAA &aaa)
{
	output << aaa.x << ' ' << aaa.y << ' ' << aaa.z << endl;
	return output;
}

AAA& AAA::operator=(const AAA &rhs)
{
	this->x = rhs.x;
	this->y = rhs.y;
	this->z = rhs.z;
	return *this;
}

int AAA::operator==(const AAA &rhs) const
{
	if( this->x != rhs.x) return 0;
	if( this->y != rhs.y) return 0;
	if( this->z != rhs.z) return 0;
	return 1;
}
// This function is required for built-in STL list functions like sort
int AAA::operator<(const AAA &rhs) const
{
	if( this->x == rhs.x && this->y == rhs.y && this->z < rhs.z) return 1;
	if( this->x == rhs.x && this->y < rhs.y) return 1;
	if( this->x < rhs.x ) return 1;
	return 0;
}
*/
class Person
{
	friend ostream &operator<<(ostream &, const Person &person);
public:
	string name;
	int location;
	Person();
	~Person(){};
	Person(const Person & copyin);   // Copy constructor to handle pass by value.
	Person &operator=(const Person &rhs);
	int operator==(const Person &rhs) const;
	int operator<(const Person &rhs) const;
};
ostream &operator<<(ostream &output, const Person &person)
{
	output << person.name << ", " << person.location << endl;
	return output;
}
Person::Person()
{
	name = "";
	location = 0;	
}
Person::Person(const Person &copyin)   // Copy constructor to handle pass by value.
{                            
	name = copyin.name;
	location = copyin.location;
}
Person & Person::operator=(const Person &rhs)
{
	this->name = rhs.name;
	this->location = rhs.location;
}
int Person::operator==(const Person &rhs) const
{
	if(this->name!=rhs.name) return 0;
	if(this->location!=rhs.location) return 0;
	return 1;
}
int Person::operator<(const Person &rhs) const
{
	//if (this->name<rhs.name) return 1;
	if (this->location<rhs.location) return 1;
	return 0;
}

main(){
/* vector operation demo
	vector<string> SS;

	SS.push_back("The number is 10");
	SS.push_back("The number is 20");
	SS.push_back("The number is 30");

 	cout << "Loop by index:" << endl;
	int ii;
	for(ii=0; ii < SS.size(); ii++)
	{
		cout << SS[ii] << endl;
	}

	cout << endl << "Constant Iterator:" << endl;
	vector<string>::const_iterator cii;

	for(cii=SS.begin(); cii!=SS.end(); cii++)
	{
		cout << *cii << endl;
	}

	cout << endl << "Reverse Iterator:" << endl;
	vector<string>::reverse_iterator rii;
	for(rii=SS.rbegin(); rii!=SS.rend(); ++rii)
	{
		cout << *rii << endl;
	}

	cout << endl << "Sample Output:" << endl;
	cout << SS.size() << endl;
	cout << SS[2] << endl;
	swap(SS[0], SS[2]);
	cout << SS[2] << endl;

	vector< vector<int> > vI2Matrix;    // Declare two dimensional array
	vector<int> A, B;
	vector< vector<int> >::iterator iter_ii;
	vector<int>::iterator           iter_jj;

	A.push_back(10);
	A.push_back(20);
	A.push_back(30);
	B.push_back(100);
	B.push_back(200);
	B.push_back(300);
	vI2Matrix.push_back(A);
	vI2Matrix.push_back(B);
	cout << endl << "Using Iterator:" << endl;
	for(iter_ii=vI2Matrix.begin(); iter_ii!=vI2Matrix.end(); iter_ii++){
    	for(iter_jj=(*iter_ii).begin(); iter_jj!=(*iter_ii).end(); iter_jj++){
    		cout << *iter_jj << endl;
		}
	}
*/
/*
	list<int> L;
	L.push_back(0);             // Insert a new element at the end
	L.push_front(0);            // Insert a new element at the beginning
	L.insert(++L.begin(),2);    // Insert "2" before position of first argument
                              	// (Place before second argument)
	L.push_back(5);
	L.push_back(6);
	list<int>::iterator i;
	for(i=L.begin(); i != L.end(); ++i) cout << *i << " ";
	cout << endl;
	return 0;	
//Output: 0 2 0 5 6
*/
/*
	list<AAA> L;
	AAA Ablob ;
	
	Ablob.x=7;
	Ablob.y=2;
	Ablob.z=4.2355;
	L.push_back(Ablob);  // Insert a new element at the end
	
	Ablob.x=5;
	L.push_back(Ablob);  // Object passed by value. Uses default member-wise
	                     // copy constructor
	Ablob.z=3.2355;
	L.push_back(Ablob);
	
	Ablob.x=3;
	Ablob.y=7;
	Ablob.z=7.2355;
	L.push_back(Ablob);
	
	list<AAA>::iterator i;
	for(i=L.begin(); i != L.end(); ++i) cout << (*i).x << " "; // print member
	cout << endl;     
	for(i=L.begin(); i != L.end(); ++i) cout << *i << " "; // print with overloaded operator
	cout << endl;
	
	cout << "Sorted: " << endl;
	L.sort();
	for(i=L.begin(); i != L.end(); ++i) cout << *i << " "; // print with overloaded operator
	cout << endl;
	return 0;
//output:
//7 5 5 3 
//7 2 4.2355
// 5 2 4.2355
// 5 2 3.2355
// 3 7 7.2355
 
//Sorted: 
//3 7 7.2355
// 5 2 3.2355
// 5 2 4.2355
// 7 2 4.2355
*/
	/* initialize random seed: */
	srand (time(NULL));
	/* generate secret number between 1 and 100: */
	int iRandom = rand() % 100 + 1;

	list<Person> pList;
	list<Person>::iterator i, j;
	Person person;	//in C++, the person object is created by this line.

	for (int i='A'; i<='Z';i++){
		person.name = i;	//i is int or char, it will work
		person.name = "Person "+ person.name;
		person.location = iRandom;
		iRandom = rand() % 100 + 1;
		pList.push_back(person);
	}
	/*
	cout<<"This is the original data:"<<endl<<" ";
	for (i = pList.begin(); i != pList.end(); ++i)
	{
		cout << *i << " "; // print with overloaded operator
	}
	*/
	cout<<endl<<"This is sorted data:"<<endl<<" ";
	pList.sort();
	for (i = pList.begin(); i != pList.end(); ++i)
	{
		cout << *i << " "; // print with overloaded operator
	}
	for (i = pList.begin(); i != pList.end(); ++i)
	{
		Person iperson = *i ;
		
		list<Person> tList;
		int k=0;
		for (j = i; j != pList.begin();){
			--j;
			Person jperson = *j ;
			jperson.location = abs(jperson.location-iperson.location);
			tList.push_back(jperson);
			k++;
			if (k>=3)
			{
				break;
			}
		}
		list<Person>::iterator jj = j;
		k=0;
		for (j = i, ++j; j != pList.end();++j){
			Person jperson = *j ;
			jperson.location = abs(jperson.location-iperson.location);
			tList.push_back(jperson);
			k++;
			if (k>=3)
			{
				break;
			}
		}
		tList.sort();
		tList.resize(3);
		cout << iperson<< "and the closest three friends:"<<endl<<" ";
		
		for (j = tList.begin(); j != tList.end(); ++j)
		{
			//cout << *j << " "; // print with overloaded operator
			for (list<Person>::iterator tj=jj; tj!=pList.end(); ++tj){
				if (j->name==tj->name){
					cout<<*tj<<" ";
					break;
				}
			}
		}
		cout<<endl;
	}

}
