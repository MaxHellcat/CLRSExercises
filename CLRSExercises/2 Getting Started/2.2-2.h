//
//  2.2-2.h
//  CLRSExercises
//
//  Created by Max Reshetey on 18/01/2017.
//  Copyright © 2017 Max Reshetey. All rights reserved.
//

#include "Defines.h"

#ifndef _2_2_2_h
#define _2_2_2_h

// Sorting problem

// Selection sort

// Input:
//	Sequence of numbers A = <a1, a2, ..., an>, represented by an array

// Output:
//	Permutation (reordering) A' of A, such that A' = <a1' <= a2' ... <= an'>, represented by an array

// Invariant:
//	Before each iteration, the subarray A[1 .. i-1] consists of keys from A, but asc sorted AND A[i-1] <= than any key in A[i..A.count]

// TODO: I don't like this init property, I think it's wrong.

// Initialisation:
//	When we start, i = 1 and so A[1 .. -1] doesn't have any keys and so the invariant trivially holds??

// Maintainance:
//	The inner for loop compares current key A[i] against each in A[i+1] to find the smallest, after which they are swapped and A[i] becomes the smallest. Incrementing i in outer for loop therefore preserves the loop invariant.

// Termination:
//	When i = A.count, we have A[1 .. A.count-1] sorted and since A[A.count-1] is the smallest of all from A[A.count .. A.count] we state that entire A[1 .. A.count] is sorted.

// The outer loop only needs to run for 1 .. n-1 keys, because upon termination A[n-1] <= A[n], according to the loop invariant.

// The best-case running time here is the same as worst-case, since inner loop always traverses A[i+1 .. n] to find the next smallest key, and is Ø(n^2)

namespace Ex_2_2_2 {

void selectionSort(Array & array)
{
	for (int i = 0; i < array.size()-1; i++)
	{
		int minJ = i;

		for (int j = i+1; j < array.size(); j++)
		{
			if (array[minJ] > array[j])
			{
				minJ = j;
			}
		}

		const int key = array[i];
		array[i] = array[minJ];
		array[minJ] = key;
	}
}

void test()
{
	Array array = randomArrayWithSize(10);

//	Array array = {5, 2, 4, 6, 1, 3};

	printArray(array);
	
	selectionSort(array);
	
	printArray(array);

	cout << endl;

}
}

#endif /* _2_2_2_h */
