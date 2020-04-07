//
//  4.1-5.h
//  CLRSExercises
//
//  Created by Max Reshetey on 21/02/2017.
//  Copyright © 2017 Max Reshetey. All rights reserved.
//

#ifndef _4_1_5_h
#define _4_1_5_h

#include "Defines.h"
#include "4.1-3.h" // For Tuple data structure and other implementations

namespace Ex_4_1_5 {

using Ex_4_1_3::Tuple;

// The linear implementation of the maximum-subarray problem (the fastest of all implemented so far)
// Time: Ø(n)
Tuple findMaxSubarrayLinear(Array & arr)
{
	int lowIndex = 0, hiIndex = 0, maxSum = INT_MIN;
	int sum = 0;

	int i = 0;

	for (int j = 0; j < arr.size(); j++)
	{
		// The key operation in the linear approach is to reset current sum and helper index i to j, whenever previous sum is negative. In other words, we drop calculated negative sum because adding it to the new element will always decrease the new sum, potentially breaking correct new sum calculation.

		// Caveat 1: The non-strict comparisson "narrows" the max subarray range, e.g. for {1, -1, 3, -4} the result array would be {3}, instead of {1, -1, 3}
		if (sum < 0)
		{
			sum = 0;
			i = j;
		}

		sum = sum + arr[j];

		if (sum > maxSum)
		{
			maxSum = sum;
			lowIndex = i;
			hiIndex = j;
		}
	}

	return {lowIndex, hiIndex, maxSum};
}

void test()
{
//	Array arr = {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};
//	Array arr = {1, -4, 3, -4};

//	Array arr = randomArrayWithSize(1000, true);
	
	Array arr = {-1, -4, -3};

	printArray(arr);

	// Checking here all 4 implementations halt with the correct answer.
	Tuple linear = findMaxSubarrayLinear(arr);
	Tuple recursive = Ex_4_1_3::findMaxSubarray(arr, 0, (int)arr.size()-1, false);
	Tuple recursiveBrute = Ex_4_1_3::findMaxSubarray(arr, 0, (int)arr.size()-1, true);
	Tuple brute = Ex_4_1_3::findMaxSubarrayBruteForce(arr, 0, (int)arr.size()-1);

	cout << "Linear: " << linear.sum << " {" << linear.lowIndex << ", " << linear.hiIndex << "}\n";
	cout << "Recurs: " << recursive.sum << " {" << recursive.lowIndex << ", " << recursive.hiIndex << "}\n";
	cout << "ReBrut: " << recursiveBrute.sum << " {" << recursiveBrute.lowIndex << ", " << recursiveBrute.hiIndex << "}\n";
	cout << "Brutef: " << brute.sum << " {" << brute.lowIndex << ", " << brute.hiIndex << "}\n";
}
}

#endif /* _4_1_5_h */
