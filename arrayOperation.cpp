#include <iostream>
//#include <sstream>
#include <string>
//#include <stdio.h>
#include <cstring>

#define ARRAY_SIZE(array) (sizeof((array))/sizeof((array[0])))

using namespace std;

bool hasDuplication(int *array, int size);
int binarySearch(int* array, int size, int item);
int atoi(const char *str);
int atoi(std::string str);
char* reverseWords(char *str);
std::string reverseWords(std::string str);
char* reverseWords1(char *str);
char* reverseCharacter(char *str);
std::string reverseCharacter(std::string str);
int * merge(int * half1, int size1, int * half2, int size2);
int * mergeSort(int * array, int size);
int * mergeSortIterate(int * array, int size);
void quickSort(int array[], int startIndex, int endIndex);

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

assicToInteger:
	{	cout<<"atoi test:\n";
		char number[] = "+1234";
		cout << atoi(number) << endl;
		char number1[] = "-12345.5";
		cout << atoi(number1) << endl;
		char number2[] = "-123a45.5";
		cout << atoi(number2) << endl;
		std::string s1 =  "+1234";
		cout << atoi(s1) << endl;
	}

reverseWordsTest:
	{	cout <<"reverseWordsTest:\n";
		char s[] = "Write a function to reverse the order of words in a string in place.";
		cout << s << endl;
		cout << reverseWords1(s) << endl;
		cout << s << endl;
		cout <<"std::string test:\n";
		std::string s2 = "Write a function to reverse the order of words in a string in place.";
		cout << s2 << endl;
		cout << reverseWords(s2) << endl;
		cout << s2 << endl;
		cout <<"reverseCharacter test:\n";
		char s1[] = "Write a function to reverse the order of words in a string in place.";
		cout << reverseCharacter(s1)<<endl;
		std::string s3 = "Write a function to reverse the order of words in a string in place.";
		cout << reverseCharacter(s3)<<endl;

	}

sortingTest:
	{	cout<<"merging test\n";
		//int si1[] ={1,3,5,7,9};
		//int si2[] ={0,2,4,6,8};
		int si1[] ={3,4,6,7};
		int si2[] ={2,5};
		int * msip = NULL;
		msip = merge(si1,ARRAY_SIZE(si1),si2,ARRAY_SIZE(si2));
		for (int i=0; i< ARRAY_SIZE(si1)+ARRAY_SIZE(si2); i++){
			cout <<msip[i] <<( ( i < (ARRAY_SIZE(si1)+ARRAY_SIZE(si2)-1) )? ", " : "\n" );
		}
		delete[] msip;

		cout<<"sorting test\n";
		int si3[] ={8,4,6,2,0,1,5,3,9,7};
		//int* ip = mergeSort(si3, ARRAY_SIZE(si3));
		//int* ip = mergeSortIterate(si3, ARRAY_SIZE(si3));
		quickSort(si3, 0, ARRAY_SIZE(si3)-1);
		for (int i=0; i < (ARRAY_SIZE(si3)); i++){
			cout<<si3[i]<<((i!=ARRAY_SIZE(si3)-1)?",":"\n");
		}

		int si4[] ={10,8,4,6,2,0,1,5,3,9,7};
		//int* ip = mergeSort(si3, ARRAY_SIZE(si3));
		quickSort(si4, 0, ARRAY_SIZE(si4)-1 );
		for (int i=0; i < (ARRAY_SIZE(si4)); i++){
			cout<<si4[i]<<((i!=ARRAY_SIZE(si4)-1)?",":"\n");
		}

		int si5[] ={10,8,4,6,11,2,0,1,5,3,9,7};
		//int* ip = mergeSort(si3, ARRAY_SIZE(si3));
		quickSort(si5, 0, ARRAY_SIZE(si5)-1 );
		for (int i=0; i < (ARRAY_SIZE(si5)); i++){
			cout<<si5[i]<<((i!=ARRAY_SIZE(si5)-1)?",":"\n");
		}

		int si6[] ={10,8,4,6,11,2,0,12,1,5,3,9,7};
		//ip = mergeSort(si3, ARRAY_SIZE(si3));
		quickSort(si6, 0, ARRAY_SIZE(si6)-1 );
		for (int i=0; i < (ARRAY_SIZE(si6)); i++){
			cout<<si6[i]<<((i!=ARRAY_SIZE(si6)-1)?",":"\n");
		}

		int si7[] ={10,8,13,4,6,11,2,0,12,1,5,3,9,7};
		//ip = mergeSort(si3, ARRAY_SIZE(si3));
		quickSort(si7, 0, ARRAY_SIZE(si7)-1 );
		for (int i=0; i < (ARRAY_SIZE(si7)); i++){
			cout<<si7[i]<<((i!=ARRAY_SIZE(si7)-1)?",":"\n");
		}

		int si8[] ={10,8,13,4,14,6,11,2,0,12,1,5,3,9,7};
		//ip = mergeSort(si3, ARRAY_SIZE(si3));
		quickSort(si8, 0, ARRAY_SIZE(si8)-1 );
		for (int i=0; i < (ARRAY_SIZE(si8)); i++){
			cout<<si8[i]<<((i!=ARRAY_SIZE(si8)-1)?",":"\n");
		}

		int si9[] ={10,8,13,4,14,6,11,2,0,12,1,5,3,15,9,7};
		//int* ip = mergeSort(si3, ARRAY_SIZE(si3));
		//for (int i=0; i < (ARRAY_SIZE(si9)); i++){
		//	cout<<ip[i]<<((i!=ARRAY_SIZE(si9)-1)?",":"\n");
		//}
		quickSort(si9, 0, ARRAY_SIZE(si9)-1 );
		for (int i=0; i < (ARRAY_SIZE(si9)); i++){
			cout<<si9[i]<<((i!=ARRAY_SIZE(si9)-1)?",":"\n");
		}

		int si10[] ={16,10,8,8,13,4,14,6,11,2,0,8,12,1,5,3,8,15,9,7};
		//int* ip = mergeSort(si3, ARRAY_SIZE(si3));
		//for (int i=0; i < (ARRAY_SIZE(si10)); i++){
		//	cout<<ip[i]<<((i!=ARRAY_SIZE(si10)-1)?",":"\n");
		//}
	cout<<"=================================================\n";
		quickSort(si10, 0, ARRAY_SIZE(si10)-1 );
		for (int i=0; i < (ARRAY_SIZE(si10)); i++){
			cout<<si10[i]<<((i!=ARRAY_SIZE(si10)-1)?",":"\n");
		}

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
int atoi(std::string str) {
	int integer=0, sign=1;

	for (int i=0; i<str.length(); i++) {

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

char* reverseWords(char *str){
	char * pch;
	int len= strlen(str);
	//char nstr[len+1];	//connot be used in functions
	char* nstr = new char[len+1];
	memset (nstr,'-',len);
	nstr[len]=0;
	int posi = len;
	pch = strtok (str," ,.-");
	while(pch != NULL){
		//cout << pch <<", ";
		if (posi!=len) nstr[posi] = ' ';
		//cout <<nstr <<endl;
		int l = strlen(pch);
		posi -= l;
		memcpy(nstr+posi, pch, l);
		posi--;
		pch = strtok (NULL, " ,.-");
	}
	//nstr[len] = 0;
	//cout << nstr <<endl;
	memcpy(str, nstr, len+1);
	delete[] nstr;
	int i =0;
	while(str[i]=='-'){
		i++;
	}
	return str+i;
}
std::string reverseWords(std::string str){
	int len= str.length();
	std::string nstr;
	int startPosition=0, stopPosition=0;
	while(stopPosition<len){
		if (str[stopPosition] == ' ') {
			if (nstr.length()>0) nstr.insert(0, " ");
			nstr.insert(0, str.substr(startPosition, stopPosition-startPosition));
			while (str[++stopPosition] == ' ' && stopPosition<len);
			startPosition = stopPosition;
		} else if (stopPosition == len-1) {
			if (nstr.length()>0) nstr.insert(0, " ");
			nstr.insert(0, str.substr(startPosition, len-startPosition));
			break;
		} else {
			stopPosition++;
		}
	}
	return nstr;
}

char* reverseWords1(char *str){
	int len= strlen(str);
	//char nstr[len+1];	//connot be used in functions
	char* nstr = new char[len+1];
	memset (nstr,'-',len);
	nstr[len]=0;
	int posi = len;
	int startPosition=0, stopPosition=0;
	int l;
	while(stopPosition<=len){
		if (str[stopPosition] != ' ' && str[stopPosition] != 0) {
			stopPosition++;
			continue;
		}
		l=stopPosition - startPosition;
		//cout << l <<"," <<startPosition <<"," <<stopPosition << endl;
		posi -= l;
		for (int i=0; i<l; i++){
			nstr[posi+i] = str[startPosition+i];
		}
		//cout <<nstr <<"," <<posi<<endl;
		//if (posi==0) break;
		if (str[stopPosition] == 0) break;
		nstr[--posi] = ' ';
		for (; stopPosition< len && str[stopPosition]==' '; stopPosition++); //skip spaces
		startPosition = stopPosition;
	}
	memcpy(str, nstr+posi, len+1);
	delete[] nstr;
	int i =0;
	while(str[i]=='-'){
		i++;
	}
	return str+i;
}


char* reverseCharacter(char *str){
	int len= strlen(str);
	//cout <<len<<endl;
	for (int i=0; i<len/2; i++){
		char c = str[i];
		str[i] = str[len-i-1];
		str[len-i-1] = c;
		//cout <<str<<endl;
	}
	return str;
}
std::string reverseCharacter(std::string str){
	int len= str.length();
	//cout <<len<<endl;
	for (int i=0; i<len/2; i++){
		char c = str[i];
		str[i] = str[len-i-1];
		str[len-i-1] = c;
		//cout <<str<<endl;
	}
	return str;
}

int * merge(int * half1, int size1, int * half2, int size2){
	int * mergedArray = new int[size1+size2];
	int i1=0, i2=0, i=0;
	while(i<size1+size2){
		if (i1<size1&&i2<size2){
			mergedArray[i++]=(half1[i1]<=half2[i2])? half1[i1++]: half2[i2++];
		} else if (i1<size1){
			mergedArray[i++]=half1[i1++];
		} else {mergedArray[i++]=half2[i2++];}
		//cout <<i<<","<<i1<<","<<i2<<endl;
	}
	return mergedArray;
}

int * mergeSort(int * array, int size){
	if (size==1) return array;
	int l = size/2;
	//cout<<"a1:l="<<l<<":";
	int* a1 = mergeSort(array, l);
/*	
	for (int i=0; i<l; i++){
		cout<<a1[i]<<",";
	}
	cout<<endl;
	cout<<"a2:size-l="<<size-l<<":";
*/
	int* a2 = mergeSort(array+l, size-l);
/*
	for (int i=0; i<size-l; i++){
		cout<<a2[i]<<",";
	}
	cout<<endl<<"l="<<l<<",size-l="<<size-l<<";"<<a1[0]<<","<<a2[0]<<endl;
*/
	int* a = merge(a1, l, a2, size-l);
/*
	cout<<"a:";
	for (int i=0; i<size; i++){
		cout<<a[i]<<",";
	}
	cout<<endl;
*/
	memcpy(array, a, size*sizeof(int));
/*
	cout<<"array:";
	for (int i=0; i<size; i++){
		cout<<array[i]<<",";
	}
	cout<<endl;
*/
	delete[] a;
	return array;
}

int * mergeSortIterate(int * array, int size){
	int k;	//sorting subgroup size
	int rsize; //right side group size
	for (k=1; k<=size/2; k=2*k){
/*
		for (int i=0; i < size; i++){
			cout<<array[i]<<((i!=size-1)?",":"\n");
		}
*/
		for (int j=0; j<size; j+=2*k){
			if (j+k >= size) {
				break;
			} else if (j+2*k >= size){
				rsize= size - (j+k);
//				cout <<"rsize="<<rsize<<",size="<<size<<",j+k="<<j+k<<endl;
			} else {
				rsize = k;
//				cout <<"rsize="<<rsize<<endl;
			}
			int * temp = merge(array+j,k, array+j+k,rsize);
			memcpy(array+j, temp, (k+rsize)*sizeof(int));
			delete[] temp;
/*
			cout<<"j="<<j<<endl;
			for (int i=0; i < k+rsize; i++){
				cout<<array[j+i]<<",";
			}
			cout<<endl;
*/
		}
	}
	int * temp = merge(array,k, array+k,size-k);
	memcpy(array, temp, (size)*sizeof(int));
	delete[] temp;
	return array;
}

void quickSort(int array[], int startIndex, int endIndex){
	int pivot = array[startIndex+(endIndex-startIndex)/2];
	int i = startIndex;
	int j = endIndex;
	int temp;
	/*
	cout<<"----------------------------------\n";
	cout <<"i="<<i<<",j="<<j<<",startIndex="<<startIndex<<",endIndex="<<endIndex<<",Pivot="<<pivot<<endl;
	for (int i=startIndex; i <= endIndex; i++){
		cout<<array[i]<<((i!=endIndex)?",":"\n");
	}
	*/
	if (endIndex-startIndex<=1){
		if (array[startIndex] > array[endIndex]){
			temp= array[startIndex];
			array[startIndex] = array[endIndex];
			array[endIndex] = temp;
		}
		return ;
	}
	while(i<j){
		while(array[i]<pivot) i++;
		while(array[j]>pivot) j--;
		if (i>=j) break;
		temp = array[i];
		array[i++] = array[j];
		array[j--] = temp;
	}
	/*
	cout <<"i="<<i<<",j="<<j<<",startIndex="<<startIndex<<",endIndex="<<endIndex<<",Pivot="<<pivot<<endl;
	for (int i=startIndex; i <= endIndex; i++){
		cout<<array[i]<<((i!=endIndex)?",":"\n");
	}
	*/
	if (startIndex<i-1) quickSort(array, startIndex, i-1);
	if (i<endIndex) quickSort(array, i, endIndex);
}