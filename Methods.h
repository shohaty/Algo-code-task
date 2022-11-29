#pragma once
using namespace std;
#include <iostream>
#include <sstream>
#include <vector>
#include <string>

class Methods
{
public:
	static vector <int> sumOfVectors(vector<int> i_Vec1, vector<int> i_Vec2);
	static vector <int> longSumOfVectors(vector<int> i_Vec1, vector<int> i_Vec2);
	static vector<int> incrementByOne(vector<int> i_BinaryNumber);
	static vector<int> decrementByOne(vector<int> i_BinaryNumber);
	static vector <int> multiplyNaiveVectors(vector<int> i_BinaryNumber, vector<int> i_BinaryNumber2);
	static vector <int> multiplyKaratsubaVectors(vector<int> i_BinaryNumber, vector<int> i_BinaryNumber2);
	static vector <int> multiplyVectors(vector<int> i_BinaryNumber, vector<int> i_BinaryNumber2);
	static vector <int> dynamicProg(vector<int> i_BinaryNumber, vector<int> i_BinaryNumber2);
	static void divideNaiveVectors(vector<int> i_BinaryNumber, vector<int> i_BinaryNumber2, vector<int> q, vector<int> r);
	static vector <int> divideBinarySearch(vector<int> i_BinaryNumber, vector<int> i_BinaryNumber2);

};