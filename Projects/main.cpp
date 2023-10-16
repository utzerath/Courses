/*
* Jack Utzerath
* CST-201
* My String
* 9/15/22
*/

#include "MyString.h"
#include <iostream>
using namespace std;



int main()
{
	MyString str("Nerd");
	MyString str2("School");
  
	cout << "ShowString method: ";
  str.showString();
  
  cout << "Length of string: ";
	str.length();
  
  cout << "Overloading << : ";
	str << str;
  
  cout << "Overloading == : ";
  cout << (str == str2) << endl;
  
  cout << "Overloading ++ : ";
	str + str2;

  cout << "Overloading > : ";
  cout << (str > str2) << endl;
   cout << "Overloading < : ";
  cout << (str < str2) << endl;

  MyString str3("Books");
  cout << "get function : ";
  char k = str3.get(3);
  cout << k << endl;
  
  cout << "toLower function : ";
  str3.toLower();
  str3.showString();
  
  cout << "toUpper function : ";
  str3.toUpper();
  str3.showString();

  cout << "Substring with one parameter (start) : ";
  str3.substring(2);
  
  cout << "Substring with two parameter (start, end) : ";
  str3.substring(2,3);

  MyString str4("Jack is a great guy");
  MyString str5("great");
  
  cout << "indexOf function : ";
  int j = str4.indexOf(str5);
  cout << j << endl;
  cout << "lastIndexOf function : ";
  int n = str4.lastIndexOf(str5);
  cout << n << endl;
  

}