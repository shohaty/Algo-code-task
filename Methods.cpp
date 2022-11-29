#include "Methods.h"
// the funcion gets a binary number and increases it by 1 and check at the end if all the digits are 111... add 1 to the beginning of the vector and all the other 0
vector<int> Methods::incrementByOne(vector<int> i_BinaryNumber)

{

	int carry = 1;
	for (int i = i_BinaryNumber.size() - 1; i >= 0; i--)
	{
		if (i_BinaryNumber[i] == 1 && carry == 1)
		{
			i_BinaryNumber[i] = 0;
			carry = 1;
		}
		else if (i_BinaryNumber[i] == 0 && carry == 1)
		{
			i_BinaryNumber[i] = 1;
			carry = 0;
		}
		
	}
	if(carry == 1) // check if correct
	{
		i_BinaryNumber.insert(i_BinaryNumber.begin(), 1);
	}
	return i_BinaryNumber;
}
// the function gets a binary number and decreases it by 1
vector<int> Methods::decrementByOne(vector<int> i_BinaryNumber)
{
	int carry = 1;
	for (int i = i_BinaryNumber.size() - 1; i >= 0; i--)
	{
		if (i_BinaryNumber[i] == 0 && carry == 1)
		{
			i_BinaryNumber[i] = 1;
			carry = 1;
		}
		else if (i_BinaryNumber[i] == 1 && carry == 1)
		{
			i_BinaryNumber[i] = 0;
			carry = 0;
		}
	}
	return i_BinaryNumber;
}
vector<int> Methods::sumOfVectors(vector<int> n, vector<int> m)
{
	//the function call until m is not 0 to encrement n by m
	while (m != vector<int>(m.size(), 0))
	{
		n = incrementByOne(n);
		m = decrementByOne(m);
	}
	return n;
}

vector <int> Methods::longSumOfVectors(vector<int> i_Vec1, vector<int> i_Vec2)
{
	//the long sum is the sum of the 2 vectors from the end to the begining of the vectors to a new vector
	vector<int> longSum;
	int carry = 0;
	//find which vector is the shorter vector
	int size = i_Vec1.size() < i_Vec2.size() ? i_Vec1.size() : i_Vec2.size();
	for (int i = size - 1; i >= 0; i--)
	{
		longSum[i] += i_Vec1[i] + i_Vec2[i];
		if (longSum[i] == 2 && carry == 0)
		{
			longSum[i] = 0;
			carry = 1;
		}
		else if (longSum[i] == 2 && carry == 1)
		{
			longSum[i] = 1;
			carry = 1;
		}
		else if (longSum[i] == 1 && carry == 1)
		{
			longSum[i] = 0;
			carry = 1;
		}
		else if (longSum[i] == 0 && carry == 1)
		{
			longSum[i] = 1;
			carry = 0;
		}
	}
	return longSum;
}
//the function gets two vectors n,m and return n*m by using the sum of vectors function until m is not 0
vector <int> Methods::multiplyNaiveVectors(vector<int> n, vector<int> m)
{
	vector <int> tempN;
	while (m != vector<int>(m.size(), 0))
	{
		// add n to tempN check if correct
		tempN = sumOfVectors(tempN, n);
		m = Methods::decrementByOne(m);
	}
	return tempN;
}
vector <int> Methods::multiplyVectors(vector<int> n, vector<int> m)
{
	vector<int> result;
	int counter = 0;
	//create a copy of n
	vector <int> tempN = n;
	//loop until m.size is not 0
	while(m.size() !=0)
	{
		int index = m.size() - 1;
		//if the last bit is 1
		if (m[index] == 1)
		{
			//add 0 to the end of tempN and add it to the result
			tempN.push_back(0);
			result = Methods::sumOfVectors(result, tempN);

		}
	}
	return result;
}
//the naive function gets two <int> vectors n,m and return q,r such that n = m*q + r and 0<=r<m
void Methods::divideNaiveVectors(vector<int> n, vector<int> m, vector<int> q, vector<int> r)
{
	//q vector <int> = 1, r vector <int> = 0
	vector <int> q = vector<int>(1, 1);
	vector <int> r = vector<int>(1, 0);
	vector <int> tempM = Methods::multiplyVectors(m,q);
	vector <int> tempN = vector<int>(1, 0);
	bool flag = true;
	
	while (flag)
	{
		while(r!=m)
		{
			r = Methods::incrementByOne(r);
			tempN = Methods::sumOfVectors(tempM, r);
			if(n==tempN)
			{
				break;
			}
		}
		if(n==tempN)
		{
			break;
		}
		else
		{
		r = vector<int>(1, 0);
		q = Methods::incrementByOne(q);	
		}
			
	} 
}





