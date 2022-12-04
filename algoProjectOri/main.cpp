#pragma once

#include "Methods.h"
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <math.h>
using namespace std;

void wrongInput();
void convertStringToIntVector(string i_Input, vector<int>& i_NumbersVector);
int calculateVec(vector<int>& vec);


int main()
{
	string n, m;
	int whichMethod, res, res2;
	vector <int> nVector;
	vector <int> mVector;
	vector <int> myVec;

	cout << "Please enter the first number: ";
	cin >> n;
	cout << "Please enter the second number: ";
	cin >> m;
	cout << "Please enter the method you want to use: ";
	cin >> whichMethod;

	convertStringToIntVector(n, nVector);
	convertStringToIntVector(m, mVector);
	Methods::compareSizes(nVector, mVector);

	switch (whichMethod)
	{
	case 1:
	{
		Methods::sumOfVectors(nVector, mVector);
		res = calculateVec(nVector);
		break;
	}
	case 2:
	{
		myVec = Methods::longSumOfVectors(nVector, mVector);
		res = calculateVec(myVec);
		break;
	}
	case 3:
	{
		myVec= Methods::multiplyNaiveVectors(nVector, mVector);
		res = calculateVec(myVec);
		break;
	}
	case 4:
	{
		myVec = Methods::multiplyVectors(nVector, mVector);
		res = calculateVec(myVec);
		break;
	}
	case 5:
	{
		Methods::multiplyKaratsubaVectors(nVector, mVector);
		break;
	}
	case 6:
	{
		Methods::dynamicProg(nVector, mVector);
		break;
	}
	case 7:
	{
		vector <int> q = vector<int>(1, 1);
		vector <int> r = vector<int>(1, 0);
		Methods::divideNaiveVectors(nVector, mVector, q, r);
		res = calculateVec(q);
		res2 = calculateVec(r);

		break;
	}
	//case 8:
	//{
		//Methods::divideBinarySearch(nVector, mVector);
		//break;
	//}
	default:
	{
		cout << "Wrong input";
		break;
	}
	}

	cout << res;
	cout << res2;

}

void wrongInput()
{
	cout << "invalid input";
	exit(1);
}

void convertStringToIntVector(string i_Input, vector<int>& i_NumbersVector){
	i_NumbersVector.reserve(i_Input.size());
	for (auto a : i_Input)
		i_NumbersVector.push_back(a == '1');
}

int calculateVec(vector<int>& vec) {
	int index = vec.size()-1;
	int res = 0;
	for (auto& n : vec) {
		res = res + n * pow(2, index);
		index--;
	}

	return res;
}