/*
* Jack Utzerath
* CST-210
* Quadratic Equation
* 2/1/21
*/

#ifndef QUADRATION_H
#define QUADRATION_H
#include <iostream>
#include <cmath>
using namespace std;


class QuadraticEquation
{
	

private:
	double a, b, c;

	bool nonnegDiscrim();

public:
	QuadraticEquation(double, double, double);
	double getSolution1();
	QuadraticEquation operator+(const QuadraticEquation& rhs);

	//Friend methods
	friend QuadraticEquation operator-(const QuadraticEquation& lhs, const QuadraticEquation& rhs);
	friend ostream& operator<<(ostream& out, const QuadraticEquation& rhs);



};

//Constructor
QuadraticEquation::QuadraticEquation(double a, double b, double c) {
	this->a = a;
	this->b = b;
	this->c = c;
}

//Non neg Discrim
bool QuadraticEquation::nonnegDiscrim() {
	double disc = b * b - 4 * a * c;
	return disc >= 0;
}
double QuadraticEquation::getSolution1() {
	if (!nonnegDiscrim()) return 0;
	else 
	{
		double disc = b * b - 4 * a * c;
		double solution = (-b - sqrt(disc)) / (2 * a);
			return solution;
	}
}

QuadraticEquation QuadraticEquation:: operator+(const QuadraticEquation& rhs) {
	double newA = this->a + rhs.a;
	double newB = this->b + rhs.b;
	double newC = this->c + rhs.c;

	QuadraticEquation result(newA, newB, newC);

	return result;


}
QuadraticEquation operator-(const QuadraticEquation& lhs, const QuadraticEquation& rhs)
{
	double newA = lhs.a - rhs.a;
	double newB = lhs.b - rhs.b;
	double newC = lhs.c - rhs.c;

	QuadraticEquation result(newA, newB, newC);

	return result;
}

ostream& operator<<(ostream& out, const QuadraticEquation& rhs)
{
	out << rhs.a;
	out << "x^2";
	out << " + ";
	out << rhs.b;
	out << "x";
	out << " + ";
	out << rhs.c;
	return out;
}

#endif


