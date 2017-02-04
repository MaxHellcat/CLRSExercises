//
//  Problem_2-3.h
//  CLRSExercises
//
//  Created by Max Reshetey on 03/02/2017.
//  Copyright © 2017 Max Reshetey. All rights reserved.
//

#ifndef Problem_2_3_h
#define Problem_2_3_h

#include "Defines.h"
//#include "cmath"

// a)
// T(n) = Ø(n) as we iterate n + 1 times with Ø(1) time of each iteration

int polynomialHornerRule(int x, int n)
{
	int y = 0;

	for (int i = n; i >= 0; i--)
	{
		y = (i) + x * y;

//		cout << "Iter " << i << ": " << y << endl;
	}

	return y;
}

int pow(int val, int power);

// b)
// The naive running time depends on pow() running time. The naive pow implementation provided here is Ø(n) and so the total T(n) = Ø(n^2). Of course, the real implementation of pow() may be more efficient, but it's rather unlikely it's ever Ø(1) and so Horner's rule implementation will always be more efficient, since it's linear.

int polynomialNaive(int x, int n)
{
	int y = 0;

	for (int i = 0; i <= n; i++)
	{
		y = i * pow(x, i) + y; // Each iteration running time is proportional to i

//		cout << "Iter " << i << ": " << y << endl;
	}

	return y;
}

int pow(int val, int power)
{
	if (power == 0)
	{
		return 1;
	}

	int finalVal = 1;

	for (int i = power; i >= 1; i--)
	{
		finalVal = val * finalVal;
	}

	return finalVal;
}

void test_problem_2_3()
{
	const int x = 3, n = 10;

	cout << "Naive: " << polynomialNaive(x, n) << endl;

	cout << "Horne: " << polynomialHornerRule(x, n) << endl;
}

#endif /* Problem_2_3_h */
