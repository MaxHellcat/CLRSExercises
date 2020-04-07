//
//  Problem_2-4.h
//  CLRSExercises
//
//  Created by Max Reshetey on 04/02/2017.
//  Copyright © 2017 Max Reshetey. All rights reserved.
//

#ifndef Problem_2_4_h
#define Problem_2_4_h

#include "Defines.h"

// The only way to count inversions that I figured out is to sort the array along the way. As a result, a standard merge sort is used with tiny modifications.

// The key property used for counting is that arrays being merged are sorted. So in addition to current right element being < current left element, since left array sorted, current right element also < all remaining elements in it, and so we count them as inversions as well.

// If we don't sort, I can't see how we can be better than Ø(n^2), as we must compare each with each anyway.

namespace Pr_2_4 {

int merge(Array & A, int p, int q, int r)
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

	int numOfInversions = 0;

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

				// We only count inversions here.
				numOfInversions += (leftArraySize - i);
			}
		}
		else if (i < leftArraySize) // Right array empty
		{
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
			while (k < r + 1)
			{
				A[k] = rightArray[j];
				k = k + 1;
				j = j + 1;
			}

			break;
		}
	}

	return numOfInversions;
}

int mergeSort(Array & A, int p, int r)
{
	int numOfInversions = 0;

	if (p < r)
	{
		const int q = (p + r) / 2;

		numOfInversions += mergeSort(A, p, q);
		numOfInversions += mergeSort(A, q + 1, r);

		numOfInversions += merge(A, p, q, r);
	}

	return numOfInversions;
}

void test()
{
//	Array arr = {5, 2, 4, 7, 1, 3, 2, 6};
//	Array arr = randomArrayWithSize(100);

	Array arr = {4, 3, 2, 1};

	printArray(arr);

	int numOfInversions = mergeSort(arr, 0, (int)arr.size() - 1);
	
	printArray(arr);
	
	cout << "Inversions: " << numOfInversions << endl;
}
}

#endif /* Problem_2_4_h */
