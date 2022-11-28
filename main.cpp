#pragma once

#include "Methods.h"
#include <iostream>
#include <sstream>
#include <vector>
#include <string>

void getInput(string io_N, string io_M,	int io_whichMethod);
void wrongInput();
void convertStringToIntVector(string i_Input, vector<int>& i_NumbersVector);

int main()
{
	string n, m;
	int whichMethod = 0;
	vector <int> nVector;
	vector <int> mVector;
	getInput(n, m, whichMethod);
	convertStringToIntVector(n, nVector);
	convertStringToIntVector(m, mVector);

	//create switch case to choose the method to use
	switch (whichMethod)
	{
	case 1:
	{
		Methods::sumOfVectors(nVector, mVector);
		break;
	}
	case 2:
	{
		Methods::longSumOfVectors(nVector, mVector);
		break;
	}
	case 3:
	{
		Methods::multiplyNaiveVectors(nVector, mVector);
		break;
	}
	case 4:
	{
		Methods::multiplyVectors(nVector, mVector);
		break;
	}
	default:
	{
		cout << "Wrong input";
		break;
	}
	}


	return 0;

}

void getInput(string io_N, string io_M, int io_whichMethod)
{
	cout << "Please enter the first number: ";
	cin >> io_N;
	cout << "Please enter the second number: ";
	cin >> io_M;
	cout << "Please enter the method you want to use: ";
	cin >> io_whichMethod;
}

void wrongInput()
{
	cout << "invalid input";
	exit(1);
}
