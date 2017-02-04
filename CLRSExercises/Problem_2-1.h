//
//  Problem_2-1.h
//  CLRSExercises
//
//  Created by Max Reshetey on 01/02/2017.
//  Copyright © 2017 Max Reshetey. All rights reserved.
//

#ifndef Problem_2_1_h
#define Problem_2_1_h

#include "Defines.h"
#include "2.3-2_Sentinel.h" // For merge(...)
#include "2.3-4.h" // For insertion sort

const int kMinProblemSize = 20;

void insertionSort(Array & arr, int p, int r);

void mergeSortWithInsertionSort(Array & arr, int p, int r)
{
//	cout << "In mergeSort(" << p << ", " << r << ")" << ", size: " << r - p + 1 << endl;

	if (p < r)
	{
		const int q = (p + r) / 2;

		// Coarsen the leaves of the recursion here
		if (r - p + 1 <= kMinProblemSize)
		{
			insertionSort(arr, p, r);
		}
		else
		{
			mergeSortWithInsertionSort(arr, p, q);
			mergeSortWithInsertionSort(arr, q+1, r);
		}

		merge(arr, p, q, r);
	}
}

void insertionSort(Array & arr, int p, int r)
{
//	cout << "In insertionSort(" << p << ", " << r << ")" << ", size: " << r - p + 1 << endl;

	for (int i = p + 1; i < r + 1; i++)
	{
		const int key = arr[i];

		int j = i - 1;

		while (j >= p && key < arr[j])
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}

		arr[j + 1] = key;
	}
}

void test_problem_2_1()
{
//	Array arr = {5, 2, 4, 7, 1, 3, 2, 6};
	Array arr1 = randomArrayWithSize(524288);
	Array arr2 = randomArrayWithSize(524288);
//	Array arr1 = randomArrayWithSize(20);
//	Array arr2 = randomArrayWithSize(20);

//	printArray(arr1);

	using namespace std::chrono;

	const high_resolution_clock::time_point t1 = high_resolution_clock::now();

//	mergeSortWithInsertionSort(arr1, 0, (int)arr1.size() - 1);
	mergeSort(arr1, 0, (int)arr1.size() - 1);
	
	const auto t2 = high_resolution_clock::now();
	
	const auto duration = duration_cast<microseconds>(t2 - t1).count();
	
	cout << "Duration 1: " << duration << endl;
	

//	printArray(arr);

	
	const auto tt1 = high_resolution_clock::now();
	
	mergeSortWithInsertionSort(arr1, 0, (int)arr1.size() - 1);
//	mergeSort(arr2, 0, (int)arr2.size() - 1);
//	insertionSort(arr2, 0, (int)arr2.size() - 1);

	const auto tt2 = high_resolution_clock::now();
	
	const auto dduration = duration_cast<microseconds>(tt2 - tt1).count();
	
	cout << "Duration 2: " << dduration << endl;

	
}

#endif /* Problem_2_1_h */
