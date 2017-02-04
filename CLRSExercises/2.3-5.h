//
//  2.3-5.h
//  CLRSExercises
//
//  Created by Max Reshetey on 01/02/2017.
//  Copyright © 2017 Max Reshetey. All rights reserved.
//

#ifndef __3_5_h
#define __3_5_h

#include "Defines.h"
#include "2.3-4.h" // For insertion sort

int binarySearchRecursive(Array & arr, int startIndex, int endIndex, int val)
{
//	cout << "In search(" << startIndex << ", " << endIndex << ")" << endl;

	const int midIndex = (startIndex + endIndex) / 2;

	if (arr[midIndex] == val)
	{
		return midIndex;
	}

	int finalIndex = -1;

	if (startIndex < endIndex)
	{
		if (val < arr[midIndex])
		{
			// TODO: We already checked val at midIndex!
			finalIndex = binarySearchRecursive(arr, startIndex, midIndex, val);
		}
		else if (val > arr[midIndex])
		{
			finalIndex = binarySearchRecursive(arr, midIndex + 1, endIndex, val);
		}
	}

	return finalIndex;
}

void test_2_3_5()
{
	Array arr = {1, 7, 19, 27, 39, 53, 54, 98};
//	Array arr = randomArrayWithSize(100);

//	printArray(arr);
//
//	insertionSortRecursive(arr, (int)arr.size() - 1);

	printArray(arr);

	const int val = 98;

	const int index = binarySearchRecursive(arr, 0, (int)arr.size() - 1, val);

	cout << "See index of " << val << ": " << index << endl;
}

#endif /* __3_5_h */
