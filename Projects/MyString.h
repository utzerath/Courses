/*
* Jack Utzerath
* CST-201
* My String
* 9/15/22
*/

#include <string>

using namespace std;

class MyString
{
private:
	char *myArray2;
	int arrLength;
	int maxArrLength;
	int ensureCapacity(MyString& s);

public:
	MyString();
	MyString(string yourString);
	MyString(MyString& copy);
	void showString();
	int length();
	void operator <<(MyString& s);
	void operator +(MyString& s);
	bool operator ==(MyString& s);
	bool operator <(MyString& s);
	bool operator >(MyString& s);
	char get(int);
	void toUpper();
	void toLower();
	MyString substring(int);
	MyString substring(int n, int m);
	int indexOf(MyString& s);
	int lastIndexOf(MyString& s);



};