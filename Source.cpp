/*
Author: Josue Magallanes
Date: April, 19, 2016
Project: Using Euler's method for y'=f(Ax+Bxy+Cy)  
									y(a)=Yo
Problem to solve y'=e^(4x+5xy+6y)-e^-(4x+5xy+6y)
				 y(0) = 1;
*/
#include <iostream>
#include <math.h>
#include <iomanip>

float negate(float);
float functionSolver(float x, float y);
void arrayFiller(float a[]);

using namespace std;

int main()
{
	float steps[41]; //represent the x value, or steps 
	float y [42]; //created array that will hold 4 values, matches with steps
	y[0] = 1; //initialize first array to 1, as given by the IVP
	arrayFiller(steps); //fills the steps up to 40
	
	cout << "Steps\t\tYvalues" << endl;
	for (int i = 0; i < 41; i++)
	{
		y[i+1] = functionSolver(steps[i], y[i]);
		cout << i << "\t\t" << y[i] << endl;
	}
	system("pause");
}
float functionSolver(float x, float y)
{
	float inner, negative, function, result;
	inner = (4 * x) + (-5 * x*y) + (6 * y); //inner function
	negative = negate(inner); //negating the function result
	function = exp(inner) - exp(negative); //solving for f(x,y) = e^x-e^(-(x))
	result = y + (function * x);// y + h * f(x,y)
	return result;
}

float negate(float x)
{
	float negative;
	negative = -1 * x;
	return negative;
}

void arrayFiller(float a [])
{
	for (int i = 0; i < 41; i++)
	{
		a[i] = i;
	}
	
}

