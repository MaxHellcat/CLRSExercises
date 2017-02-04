//
//  2.3-2.h
//  CLRSExercises
//
//  Created by Max Reshetey on 23/01/2017.
//  Copyright © 2017 Max Reshetey. All rights reserved.
//

#ifndef __3_2_Sentinel_h
#define __3_2_Sentinel_h

#include "Defines.h"

const int kSentinel = 1234567890;

void merge(Array & A, int p, int q, int r)
{
//	cout << "In merge(" << p << ", " << q << ", " << r << ")\n";
//	return ;

	const int leftArraySize = q - p + 1;
	const int rightArraySize = r - q;

	Array leftArray(leftArraySize + 1);
	Array rightArray(rightArraySize + 1);

	for (int i = 0; i < leftArraySize; i++)
	{
		leftArray[i] = A[p + i];
	}

	for (int j = 0; j < rightArraySize; j++)
	{
		rightArray[j] = A[q + 1 + j];
	}

	leftArray[leftArraySize] = kSentinel;
	rightArray[rightArraySize] = kSentinel;

	int i = 0, j = 0;
//	for (int k = p; k < r - p + 1; k++) <-- HAHA
	for (int k = p; k < r + 1; k++)
	{
		if (leftArray[i] <= rightArray[j])
		{
			A[k] = leftArray[i];
			i = i + 1;
		}
		else
		{
			A[k] = rightArray[j];
			j = j + 1;
		}
	}
}

void mergeSort(Array & A, int p, int r)
{
//	cout << "In mergeSort(" << p << ", " << r << ")\n";

	if (p < r)
	{
		const int q = (p + r) / 2;

		mergeSort(A, p, q);
		mergeSort(A, q + 1, r);
		merge(A, p, q, r);
	}
}

void test_2_3_2()
{
//	Array A = {5, 2, 4, 7, 1, 3, 2, 6};
	
//	Array A = {5, 2};

	Array A = {3, 41, 52, 26, 38, 57, 9, 49};

//	Array A = randomArrayWithSize(100);

	printArray(A);

	mergeSort(A, 0, (int)A.size() - 1);

	printArray(A);
}


#endif /* __3_2_Sentinel_h */
