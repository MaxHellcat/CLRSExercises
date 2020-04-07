//
//  2.3-2.h
//  CLRSExercises
//
//  Created by Max Reshetey on 24/01/2017.
//  Copyright © 2017 Max Reshetey. All rights reserved.
//

#ifndef _2_3_2_h
#define _2_3_2_h

#include "Defines.h"

namespace Ex_2_3_2 {

void merge(Array & A, int p, int q, int r)
{
	const int leftArraySize = q - p + 1;
	const int rightArraySize = r - q;

	Array leftArray(leftArraySize), rightArray(rightArraySize);

	for (int i = 0; i < leftArraySize; i++)
	{
		leftArray[i] = A[p + i];
	}

	for (int j = 0; j < rightArraySize; j++)
	{
		rightArray[j] = A[q + 1 + j];
	}

//	cout << "Left: ";
//	printArray(leftArray);
//
//	cout << "Right: ";
//	printArray(rightArray);

	int i = 0, j = 0;
	for (int k = p; k < r + 1; k++)
	{
		if ((i < leftArraySize) && (j < rightArraySize))
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
		else if (i < leftArraySize) // Right array empty
		{
//			A[k] = leftArray[i];
//			i = i + 1;
			while (k < r + 1)
			{
				A[k] = leftArray[i];
				k = k + 1;
				i = i + 1;
			}

			break;
		}
		else if (j < rightArraySize)
		{
//			A[k] = rightArray[j];
//			j = j + 1;
			while (k < r + 1)
			{
				A[k] = rightArray[j];
				k = k + 1;
				j = j + 1;
			}

			break;
		}
	}
}

void mergeSort(Array & A, int p, int r)
{
	if (p < r)
	{
		const int q = (p + r) / 2;

		mergeSort(A, p, q);
		mergeSort(A, q + 1, r);

		merge(A, p, q, r);
	}
}

void test()
{
	Array arr = {5, 2, 4, 7, 1, 3, 2, 6};
//	Array arr = randomArrayWithSize(100);

	printArray(arr);

	mergeSort(arr, 0, (int)arr.size() - 1);

	printArray(arr);
}
}

#endif /* _2_3_2_h */
