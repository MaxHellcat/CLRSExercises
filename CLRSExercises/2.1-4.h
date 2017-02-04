//
//  2.1-4.h
//  CLRSExercises
//
//  Created by Max Reshetey on 18/01/2017.
//  Copyright © 2017 Max Reshetey. All rights reserved.
//

#ifndef __1_4_h
#define __1_4_h

#include <iostream>
#include <vector>

#include <cmath>

// Addition of integers problem

// Formal problem statement:

// Input: Two bit arrays A[1 .. n] and B[1 .. n] representing two n-bit integers
// Output: A bit array C[ 1 .. n+1 ] representing n+1 bit integer, containing sum of A and B

// Extra

// Invariant:
//	Before each iteration, array C[i+1..C.count] contains sum of A[i .. A.count] and B[i .. B.count]

// Init: Prior to the 1st iteration we don't have any sum yet?!

std::vector<bool> sum(std::vector<bool> & A, std::vector<bool> & B)
{
	std::vector<bool> C = {0, 0, 0, 0, 0, 0, 0, 0, 0};
	
	bool floatBit = false;
	
	int i;
	for (i = (int)A.size() - 1; i >= 0; i--)
	{
		bool resBit = false;
		
		if (A[i] == true && B[i] == true) // or A[i] & B[i]
		{
			if (floatBit == true)
			{
				resBit = true;
			}
			else
			{
				resBit = false;
			}
			
			floatBit = true;
		}
		else if ((A[i] == false && B[i] == true) || (A[i] == true && B[i] == false)) // or A[i] | B[i] or A[i] ^ B[i]
		{
			if (floatBit == true)
			{
				resBit = false;
				floatBit = true;
			}
			else
			{
				resBit = true;
				floatBit = false;
			}
		}
		else // if (A[i] == false && B[i] == false) // or !(A[i] | B[i])
		{
			resBit = floatBit;
			floatBit = false; // if not already
		}
		
		C[i + 1] = resBit;
	}
	
	C[i + 1] = floatBit;
	
	return C;
}

int value(std::vector<bool> & V)
{
	int val = 0;
	
	for (int i = (int)V.size()-1; i >= 0; i--)
	{
		if (V[i] == true)
		{
			const int power = (((int)V.size() - 1) - i);
			val += pow(2, power);
		}
	}
	
	return val;
}

void print(std::vector<bool> & V)
{
	for (auto val: V)
	{
		std::cout << val << ", ";
	}
	
	std::cout << " (" << value(V) << ")";
	
	std::cout << std::endl;
}

void test_2_1_4()
{
//	std::vector<bool> A = {1, 1, 1, 1, 1, 1, 1, 1};
//	std::vector<bool> B = {1, 1, 1, 1, 1, 1, 1, 1};
	
//	std::vector<bool> A = {1, 0, 0, 0, 0, 0, 0, 0};
//	std::vector<bool> B = {1, 0, 0, 0, 0, 0, 0, 0};
	
	std::vector<bool> A = {1, 1, 0, 1, 1, 0, 0, 0};
	std::vector<bool> B = {1, 0, 0, 1, 1, 0, 1, 0};
	
	std::cout << "See A: " << std::endl;
	std::cout << "   ";
	print(A);
	
	std::cout << "See B: " << std::endl;
	std::cout << "   ";
	print(B);
	
	auto C = sum(A, B);
	
	std::cout << "See C: " << std::endl;
	print(C);
	
	std::cout << std::endl;
}

#endif /* __1_4_h */
