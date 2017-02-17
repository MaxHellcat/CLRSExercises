//
//  4.1-3.h
//  CLRSExercises
//
//  Created by Max Reshetey on 17/02/2017.
//  Copyright © 2017 Max Reshetey. All rights reserved.
//

#ifndef __1_3_h
#define __1_3_h

#include "Defines.h"

struct Tuple
{
	int lowIndex, hiIndex;
	int sum;
};

Tuple findMaxSubarrayBruteForce(Array & arr)
{
	int maxSum = -INT_MIN;
	int leftIndex = 0, rightIndex = 0;
	
	int sum = 0;

	// Caveat 1: We must include last element, as it may be the max subarray, like 1 in {-5, -2, -4, 1}
	for (int i = 0; i < arr.size()/* - 1*/; i++)
	{
		sum = arr[i];

		// Caveat 2: It's crucial we check here, as arr[i] itself may be max subarray, like 3 in {1, -1, 3, -4}
		// Caveat 3: The non-strict comparisson "narrows" the max subarray range
		if (sum >= maxSum)
		{
			maxSum = sum;

			leftIndex = i;
			rightIndex = i;
		}

		for (int j = i + 1; j < arr.size(); j++)
		{
			sum = sum + arr[j];

			if (sum >= maxSum)
			{
				maxSum = sum;

				leftIndex = i;
				rightIndex = j;
			}
		}
	}

	return {leftIndex, rightIndex, maxSum};
}

Tuple findMaxCrossingSubarray(Array & arr, int lowIndex, int midIndex, int hiIndex)
{
	int leftSum = INT_MIN;
	int leftIndex = 0;

	int sum = 0;

	for (int i = midIndex; i >= lowIndex; i--)
	{
		sum = sum + arr[i];

		if (sum > leftSum)
		{
			leftSum = sum;
			leftIndex = i;
		}
	}

	int rightSum = -INT_MIN;
	int rightIndex = 0;

	sum = 0;

	for (int j = midIndex + 1; j <= hiIndex; j++)
	{
		sum = sum + arr[j];

		if (sum > rightSum)
		{
			rightSum = sum;
			rightIndex = j;
		}
	}

	return (Tuple){leftIndex, rightIndex, leftSum + rightSum};
}

Tuple findMaxSubarray(Array & arr, int lowIndex, int hiIndex)
{
	if (lowIndex == hiIndex)
	{
		return {lowIndex, hiIndex, arr[lowIndex]};
	}

	const int midIndex = (lowIndex + hiIndex) / 2;

	Tuple leftTuple = findMaxSubarray(arr, lowIndex, midIndex);
	Tuple rightTuple = findMaxSubarray(arr, midIndex + 1, hiIndex);

	Tuple crossTuple = findMaxCrossingSubarray(arr, lowIndex, midIndex, hiIndex);

	// Caveat 1: The non-strict comparisson "narrows" the max subarray range
	if (leftTuple.sum >= rightTuple.sum && leftTuple.sum >= crossTuple.sum)
	{
		return leftTuple;
	}

	if (rightTuple.sum >= leftTuple.sum && rightTuple.sum >= crossTuple.sum)
	{
		return rightTuple;
	}

	return crossTuple;
}

void test_4_1_3()
{
//	Array arr = {100, 113, 110, 85, 105, 102, 86, 63, 81, 101, 94, 106, 101, 79, 94, 90, 97};
	Array arr = {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};
//	Array arr = {1, -4, 3, -4};
//	Array arr = {1, -1, 3, -4};
//	Array arr = {-23, -9, -56, -8};
//	Array arr = {-8, -9, -56, -18};
//	Array arr = {-5, -2, -4, 1};
//	Array arr = {-5, 1, -4, 1};

	printArray(arr);

	Tuple tuple1 = findMaxSubarray(arr, 0, (int)arr.size() - 1);
	Tuple tuple2 = findMaxSubarrayBruteForce(arr);

	cout << "Max subarray sum: " << tuple1.sum << " {" << tuple1.lowIndex << ", " << tuple1.hiIndex << "}\n";
	cout << "Max subarray sum: " << tuple2.sum << " {" << tuple2.lowIndex << ", " << tuple2.hiIndex << "}\n";
}

#endif /* __1_3_h */
