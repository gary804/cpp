// basic file operations
#include <iostream>
#include <fstream>

#include <sstream>

using namespace std;

/*
ofstream:	Stream class to write on files
ifstream:	Stream class to read from files
fstream:	Stream class to both read and write from/to files.

open (filename, mode); here the mode are:
ios::in		Open for input operations.
ios::out	Open for output operations.
ios::binary	Open in binary mode.
ios::ate	Set the initial position at the end of the file.If this flag is not set, the initial position is the beginning of the file.
ios::app	All output operations are performed at the end of the file, appending the content to the current content of the file.
ios::trunc	If the file is opened for output operations and it already existed, its previous content is deleted and replaced by the new one.

stream positioning:
ios::beg	offset counted from the beginning of the stream
ios::cur	offset counted from the current position
ios::end	offset counted from the end of the stream

The following member functions exist to check for specific states of a stream (all of them return a bool value): 
bad():	Returns true if a reading or writing operation fails. For example, in the case that we try to write to a file that is not open for writing or if the device where we try to write has no space left.
fail():	Returns true in the same cases as bad(), but also in the case that a format error happens, like when an alphabetical character is extracted when we are trying to read an integer number.
eof():	Returns true if a file open for reading has reached the end.
good():	It is the most generic state flag: it returns false in the same cases in which calling any of the previous functions would return true. Note that good and bad are not exact opposites (good checks more state flags at once).
clear():	The member function clear() can be used to reset the state flags.

Type		Member type		Description
streampos	ios::pos_type	Defined as fpos<mbstate_t>. It can be converted to/from streamoff and can be added or subtracted values of these types.
streamoff	ios::off_type	It is an alias of one of the fundamental integral types (such as int or long long).
*/

int main () {
/*
	ofstream myfile;
	//myfile.open ("example.txt");	//equal to open ("example.txt", ios::trunc);
	myfile.open ("example.txt", ios::app);
*/
	ofstream myfile ("example.txt", ios::out | ios::app);	//it is same as previous 2 lines
	if (myfile.is_open()){
  		//myfile << "Writing this to a file once more again.\n";
  		myfile << "Writing this to a file once more again." <<endl;	//same with previous line
  		myfile.close();	//This member function takes flushes the associated buffers and closes the file
  		//In case that an object is destroyed while still associated with an open file, the destructor automatically calls the member function close.
	}
	else cout <<"file not opened\n";

	string line;
  	ifstream myifile ("example.txt");
  	if (myifile.is_open())
  	{
    	while ( getline (myifile,line) )
    	{
      		cout << line << '\n';
    	}
    	myifile.close();
  	}

  	else cout << "Unable to open file"; 

  	{
  		streampos begin,end;	//It is an alias of one of the fundamental integral types (such as int or long long).
  		//ifstream myfile ("example.bin", ios::binary);
  		ifstream myfile ("example.txt");
  		begin = myfile.tellg();
  		myfile.seekg (0, ios::end);
  		end = myfile.tellg();
  		myfile.close();
  		cout << "size is: " << (end-begin) << " bytes.\n";
  		cout << "begin is: " << begin << ", " << "end is: " << end << endl;

  	}
  	{
  		streampos size;
  		char * memblock;
  		//ifstream file ("example.bin", ios::in|ios::binary|ios::ate);
  		ifstream file ("example.txt", ios::in|ios::binary|ios::ate);
  		if (file.is_open())
  		{
    		size = file.tellg();
    		memblock = new char [size];
    		file.seekg (0, ios::beg);
    		file.read (memblock, size);
    		file.close();

    		cout << "The entire file content is in memory; " << "the file size is: " <<size <<endl;

    		ofstream ofile ("example.bin", ios::out|ios::binary|ios::trunc);
    		if (ofile.is_open()){
    			ofile.write(memblock, size);
    		}
    		
    		{
	  			cout << "Now the output is from memory\n";
  				stringstream mys(memblock);	//create a input string from char array in buffer, there is no close() member function
				string line;
    			while ( getline (mys,line) )
    			{
      				cout << line << '\n';
    			}
    		}

    		delete[] memblock;
  		}
  		else cout << "Unable to open file\n";


  	}

	return 0;
}
