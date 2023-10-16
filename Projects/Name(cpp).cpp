/*
* Jack Utzerath
* CST-210
* Contact Manager
* 2/08/22
* This is my own work
*/

#include "Name.h"

Name::Name ()
{
	this->l_name = "";
	this->f_name = "";
}
Name::Name(string l_name, string f_name)
{
	this->l_name = l_name;
	this->f_name = f_name;
}

void Name::setFirstName(string a)
{
	this->f_name = a;

}
void Name::setLastName(string b)
{
	this->l_name = b;
}



istream& operator >>(istream& in, Name& rhs)
{
	getline(in, rhs.l_name);
	getline(in, rhs.f_name);
	return in;
}