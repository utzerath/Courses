/*
* Jack Utzerath
* CST-201
* My String
* 9/15/22
*/

#include "MyString.h"
#include <iostream>

MyString::MyString()
{
  //initialize variables
	arrLength = 0;
	maxArrLength = 0;
	myArray2 = new char[arrLength];

}

MyString::MyString(string yourString)
{
  //initialize variables
	arrLength = 0;
	maxArrLength = 0;
  //create dynamic array so we are able to manipulate arrLength
	myArray2 = new char[arrLength];

  //for loop to fill array and get correct arr length
	for (int i = 0; i < yourString.length(); i++)
	{
		arrLength++;
		maxArrLength++;
		
		myArray2[i] = yourString[i];

	}
}

int MyString::ensureCapacity(MyString& s)
{
  //return the arrLength and the s.arrlength so we have the right capacity
	int n = maxArrLength + s.arrLength;
	return n;
	
}

MyString::MyString(MyString& copy)
{
  //Copy constructor
	for (int i = 0; i < arrLength; i++)
	{
		myArray2[i] = copy.myArray2[i];
	}
}

void MyString::showString()
{
  //For loop to interate through array and print out array at i
	for (int i = 0; i < arrLength; i++)
	{
		cout << myArray2[i];
	}
	cout << endl;
	
}

int MyString::length()
{
  //get arrLength
	cout << arrLength << endl;
	return arrLength;
}

//to String
void MyString::operator<<(MyString& s)
{
  //for loop to interate through the array and print out array at i 
  //overloading the cout operator
	for (int i = 0; i < arrLength; i++)
	{
		cout << myArray2[i];
	}
	cout << endl;
}

void MyString::operator+(MyString& s)
{
  //ensure we have enough space
	int capacity = ensureCapacity(s);
  //create temp array
	char temp[100];
  //fill temp array with myArray2
	for (int i = 0; i < arrLength; i++)
	{
		temp[i] = myArray2[i];

	}
  
  //delete myArray2 so we can increase the size of the array
	delete[] myArray2;
	myArray2[capacity];

  //fill myArray with the lastArray
	for (int i = 0; i < arrLength; i++)
	{
		myArray2[i] = temp[i];
    
	}
  //fill myArray with the addedArray
  for (int i = 0; i < capacity; i++)
	{
		myArray2[i + arrLength] = s.myArray2[i];
	}
  
  //initialize the new arrLength and maxArrLength
  arrLength = capacity;
  maxArrLength = capacity;
	showString();
}

bool MyString::operator==(MyString& s)
{
  //overload the == operator
	bool truth;
  
  //is the size not equal too?
	if (s.arrLength > arrLength || s.arrLength < arrLength)
	{
    
		return false;

	}

  //loop through every letter to see if they are not equal
	for (int i = 0; i < arrLength; i++)
	{
		if (myArray2[i] != s.myArray2[i])
		{
      //return false is not equal
			return false;
		}
	}
  //return true if equal
	return true;
}

bool MyString::operator<(MyString& s)
{
  //overload the < operator
  //check if smaller
  if (myArray2[1] < s.myArray2[1])
  {
    return true;
  }
  else
    return false;
}
bool MyString::operator>(MyString& s)
{
  //overload the > operator
  //check if bigger
	if (myArray2[1] > s.myArray2[1])
  {
    return true;
  }
  else
    return false;
}

char MyString::get(int j)
{
  //return myArray2 at the int given
  return myArray2[j];
}

void MyString::toLower()
{
  //loop through myArray2
	for(int i = 0; i < arrLength; i++)
    {
      //if myArray2[i] is uppercase we add 32 to make it lowercase
      if((int(myArray2[i]) > 65 && int(myArray2[i]) < 90 ))
      {
        char toLower = char(int(myArray2[i]) + 32);
        myArray2[i] = toLower;
        
      }
      else
        myArray2[i] = myArray2[i];
    }

 
}
void MyString::toUpper()
{
  //loop through myArray2
  for(int i = 0; i < arrLength; i++)
    {
      //if myArray2[i] is lowercase we subtract 32 to make it uppercase
      if((int(myArray2[i]) > 97 && int(myArray2[i]) < 122 ))
      {
        char toUpper = char(int(myArray2[i]) - 32);
        myArray2[i] = toUpper;
        
      }
      else
        myArray2[i] = myArray2[i];
    }
  
}

MyString MyString::substring(int j)
{
  //check to see if j is a valid index of the arr
  if(j <= arrLength && j >= 0)
  {
    //create a temp string
    string temp;
    //make for loop to fill temp string at the given index
    for(int i = j; i < arrLength; i++)
    {
      temp[i] = myArray2[i];
      cout << temp[i];
    }
    cout << endl;

    //return the MyString parameter as temp for the string
    MyString str(temp);
    return str;
  }
  
  MyString str2(" ");
  return str2;
 
  
}

MyString MyString::substring(int j, int m)
{
  //check to see if j and m is a valid index of the arr
  if((j&m) <= arrLength && (j&m) >= 0 && j < m)
    {
      //create a temp string
      string temp;
      //make for loop to fill temp string at the given index and until the last index
      for(int i = j; i <= m; i++)
      {
        temp[i] = myArray2[i];
        cout << temp[i];
      }
      cout << endl;

      //return the MyString parameter as temp for the string
      MyString str(temp);
      return str;
    }
    MyString str2(" ");
    return str2;
}

int MyString::indexOf(MyString& s)
{
  //initialize parameters
  int count = 0;
  int j = 0;
  int index = -1;

  //create for loop to loop through MyArray2
  for (int i = 0; i < arrLength; i++)
    {
      int reset = count;

      //get first/current char of s.myArray2
      char curr = s.myArray2[j];

      //if the char in myArray is equal to the current char of s.myArray then increment the count
      //also increment j so the next loop searchs for the next letter of s.myArray2
      if (myArray2[i] == curr)
      {
        count++;
        j++;
      }
      //if count is equal to the amount of letter in s.myArray2 then we have the starting index of the substring
      if (count == s.arrLength)
      {
        index = i - s.arrLength;
      }
      //if count did not increase then reset count and j 
      if( reset == count)
      {
        count = 0;
        j = 0;
      }
    }
  return index;
}

int MyString::lastIndexOf(MyString& s)
{
  //initialize parameters
  int count = 0;
  int j = 0;
  int index = -1;

  //create for loop to loop through MyArray2
  for (int i = 0; i < arrLength; i++)
    {
      int reset = count;

      //get first/current char of s.myArray2
      char curr = s.myArray2[j];

      //if the char in myArray is equal to the current char of s.myArray then increment the count
      //also increment j so the next loop searchs for the next letter of s.myArray2
      if (myArray2[i] == curr)
      {
        count++;
        j++;
      }

      //if count is equal to the amount of letter in s.myArray2 then we have the last index of the substring
      if (count == s.arrLength)
      {
        index = i;
      }
      
      //if count did not increase then reset count and j 
      if( reset == count)
      {
        count = 0;
        j = 0;
      }
    }
  return index;
}








