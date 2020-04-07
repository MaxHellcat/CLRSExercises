//
//  2.3-4.h
//  CLRSExercises
//
//  Created by Max Reshetey on 01/02/2017.
//  Copyright © 2017 Max Reshetey. All rights reserved.
//

#ifndef _2_3_4_h
#define _2_3_4_h

#include "Defines.h"

namespace Ex_2_3_4 {

void insertionSortRecursive(Array & arr, int endIndex)
{
	if (endIndex == 0)
	{
		return ;
	}

	const int nextEndIndex = endIndex - 1; // Divide, O(1)

	insertionSortRecursive(arr, nextEndIndex); // Conquer, O(n-1)

	// Combine, O(n)
	// Key operation, find a place for the key in sorted 0 .. n-1 and then insert the key
	const int key = arr[endIndex];

	int i = endIndex - 1;
	while (i >= 0 && key < arr[i])
	{
		arr[i + 1] = arr[i];
		i = i - 1;
	}

	arr[i + 1] = key;
}

void test()
{
	Array A = {5, 2, 4, 7, 1, 3, 2, 6};
//	Array A = randomArrayWithSize(100);

	printArray(A);

	insertionSortRecursive(A, int(A.size()) - 1);

	printArray(A);
}
}

#endif /* _2_3_4_h */
