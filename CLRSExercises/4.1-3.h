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

// Implementations of the maximum-subarray problem

// TODO: Note that all implementations below return a single max array, even if there're actually more than one.

// Experimentally found problem size, when divide-and-conquer version starts to beat the brute-force one.
const int kCrossoverSize = 40;

struct Tuple
{
	int lowIndex, hiIndex;
	int sum;
};

// The brute-force approach
// Time: Ø(n^2)
Tuple findMaxSubarrayBruteForce(Array & arr, int lowIndex, int hiIndex)
{
	int leftIndex = 0, rightIndex = 0, maxSum = INT_MIN;

	int sum = 0;

	for (int i = lowIndex; i <= hiIndex; i++)
	{
		sum = 0;

		// Caveat 1: It's crucial we start with arr[i], as it itself may be max subarray, like 3 in {1, -1, 3, -4}
		for (int j = i/* + 1*/; j <= hiIndex; j++)
		{
			sum = sum + arr[j];

			// Caveat 2: The non-strict comparisson "narrows" the max subarray range
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

// The divide-and-conquer approach
// Time: Ø(n*lg(n))
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

	int rightSum = INT_MIN;
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

	return {leftIndex, rightIndex, leftSum + rightSum};
}

Tuple findMaxSubarray(Array & arr, int lowIndex, int hiIndex, bool useBruteForce = false)
{
//	cout << "In findMaxSubarray(arr, " << lowIndex << ", " << hiIndex << "\n";

	if (useBruteForce)
	{
		if (hiIndex - lowIndex + 1 <= kCrossoverSize)
		{
//			cout << "Oops, switched to brute force here!\n";
			return findMaxSubarrayBruteForce(arr, lowIndex, hiIndex);
		}
	}
	else
	{
		if (lowIndex == hiIndex)
		{
			return {lowIndex, hiIndex, arr[lowIndex]};
		}
	}

	const int midIndex = (lowIndex + hiIndex) / 2;

	Tuple leftTuple = findMaxSubarray(arr, lowIndex, midIndex, useBruteForce);
	Tuple rightTuple = findMaxSubarray(arr, midIndex + 1, hiIndex, useBruteForce);

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
//	Array arr = {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};
//	Array arr = {1, -4, 3, -4};
//	Array arr = {1, -1, 3, -4};
//	Array arr = {-23, -9, -56, -8};
//	Array arr = {-8, -9, -56, -18};
//	Array arr = {-5, -2, -4, 1};
//	Array arr = {-5, 1, -4, 1};

	Array arr = randomArrayWithSize(10000, true);

	printArray(arr);

	const auto t0 = high_resolution_clock::now();
	Tuple tuple0 = findMaxSubarrayBruteForce(arr, 0, (int)arr.size() - 1);
	const auto t1 = high_resolution_clock::now();

	Tuple tuple1 = findMaxSubarray(arr, 0, (int)arr.size() - 1, false);
	const auto t2 = high_resolution_clock::now();

	Tuple tuple2 = findMaxSubarray(arr, 0, (int)arr.size() - 1, true);
	const auto t3 = high_resolution_clock::now();

	cout << "Brutforce took: " << duration_cast<nanoseconds>(t1 - t0).count() << "\n";
	cout << "Recursive took: " << duration_cast<nanoseconds>(t2 - t1).count() << "\n";
	cout << "Recursive(brute) took: " << duration_cast<nanoseconds>(t3 - t2).count() << "\n";

	cout << endl;

	cout << "Sum (brutforce): " << tuple0.sum << " {" << tuple0.lowIndex << ", " << tuple0.hiIndex << "}\n";
	cout << "Sum (recursive): " << tuple1.sum << " {" << tuple1.lowIndex << ", " << tuple1.hiIndex << "}\n";
	cout << "Sum (recursive-brut): " << tuple2.sum << " {" << tuple2.lowIndex << ", " << tuple2.hiIndex << "}\n";
}

#endif /* __1_3_h */
