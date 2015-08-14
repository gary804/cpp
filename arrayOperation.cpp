#include <iostream>
//#include <sstream>
//#include <string>

#define ARRAY_SIZE(array) (sizeof((array))/sizeof((array[0])))

using namespace std;

bool hasDuplication(int *array, int size);
int binarySearch(int* array, int size, int item);
int atoi(const char *str);

int main(){
	cout << "Good, it works\n";

	int array[] ={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
	int al = ARRAY_SIZE(array);
	for (int i=0; i<al; i++) {
		cout << binarySearch(array, al, i) <<endl;
	}
	cout <<"Has Duplication? "<< ((hasDuplication(array, al))? "True": "False") << endl;
	//cout <<array[0] << endl;
	int array1[] ={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,4,15,16,17,18,19,20};
	cout <<"Has Duplication? "<< ((hasDuplication(array1, ARRAY_SIZE(array1)))? "True": "False") << endl;
	//cout <<array1[0] << endl;
	{
		char number[] = "+1234";
		cout << atoi(number) << endl;
		char number1[] = "-12345.5";
		cout << atoi(number1) << endl;
		char number2[] = "-123a45.5";
		cout << atoi(number2) << endl;
	}
}

//bool hasDuplication(int *array, int size){ //works
bool hasDuplication(int array[], int size){	//array just use its address, like previous line
	for (int i=0; i<size-1; i++){
		for (int j = i+1; j < size; ++j)
		{
			if (array[i] == array[j]) {
				cout << "i=" <<i <<", j=" << j <<endl;
				return	true;
			}
		}
	}
	//array[0] = 10;	//test array varaible only
	return false;
}

//int binarySearch(int* array, int size, int item){	//works
int binarySearch(int array[], int size, int item){
	int al = size;
	//int al = ARRAY_SIZE(array);
	int p = al/2;
	int hl1 = 0, hl2 = p-1;
	int hh1 = p+1, hh2 = al - 1;
	
	while (true){
		cout <<"(" <<p  <<", " <<hl1 <<", " << hl2  << ", "  << hh1 << ", " << hh2 <<"); ";
		if (array[p]==item){
			return p;
		}
		else if (item>array[p]) {
			if (hh2-hh1>1) {
				p = hh1 + (hh2-hh1)/2;
				hl1 = hh1;
				hl2 = p-1;
				hh1 = p+1;
				//hh2=hh2;
			}
			else {
				for (int j=hh1; j<=hh2 ; j++){
					if (item==array[j]) return j;
				}
				return -1;
			}
		}
		else {
			if (hl2-hl1>1) {
				p=hl1+(hl2-hl1)/2;
				hh1 = p+1;
				hh2 = hl2;
				hl2 = p-1;
				//hl1=hl1;
			}
			else {
				for (int j=hl1; j<=hl2; j++){
					if (item==array[j]) return j;
				}
				return -1;
			}
		}
	}
}
int atoi(const char *str) {
	int integer=0, sign=1;
	for (int i=0; str[i]!=0; i++) {
		if (str[i]=='-') {
			sign *= -1;
		}
		else if (str[i]=='+') {
			continue;
		}
		else if (str[i]>='0' && str[i]<='9')
		{
			integer = integer*10+ str[i]-'0';
		} else
		{
			if (str[i] == '.') 
				break;
			else
				return 0;
		}
	}
	return integer * sign;
}