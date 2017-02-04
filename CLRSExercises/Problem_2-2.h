//
//  Problem_2-2.h
//  CLRSExercises
//
//  Created by Max Reshetey on 02/02/2017.
//  Copyright © 2017 Max Reshetey. All rights reserved.
//

#ifndef Problem_2_2_h
#define Problem_2_2_h

#include "Defines.h"

// a)
// In order to show that bubble sorts actually sorts, we must prove that all 3 properties of the loop invariant hold. To be more specific, proving only fist two properties is enough to show that it sorts. The 3rd property shows us that it terminates with the correct answer (sorted output)

// b)
// Invariant, inner for loop:
// Upon each iteration, the value in A[j] is the smallest (<=) in the subarray A[j+1 .. A.size]

// Initialisation:
// Prior to the 1st iteration, j = A.size, so A[A.size+1 .. A.size] is empty

// Maintenance:
// In the j-th iteration, the loop body swaps A[j] with A[j-1], if A[j] < A[j-1]. Thus, value A[j-1] becomes the smallest in the subarray A[j .. A.size]. Decrementing j in loop header reestablishes the invariant.

// Termination:
// Upon termination, j = i, so A[i] is the smallest in A[i+1 .. A.size]

// c)
// Main invariant, outer for loop:
// Upon each iteration, A[1 .. i-1] consists of the smallest elements from the subarray A[i .. A.size], in sorted order.

// Initialisation:
// Before the 1st iteration, i = 1, so A[1 .. 0] is empty

// Maintenance:
// In the i-th iteration, according to inner loop termination, since A[i] is the next smallest in A[i+1 .. A.size], the  A[1 .. i] contains the smallest elements of A[i+1 .. A.size] in sorted order. Incrementing i in the loop header reestablishes the invariant.

// Termination:
// Upon termination, we have i = A.size, so A[1 .. A.size - 1] is sorted and since all its elements are the smallest (<=) of the subarray A[A.size .. A.size], the entire A[1 .. A.size] is sorted.

// d)
// Worst (and average) case is Ø(n^2). The standard implementation here doesn't allow to enhance it to Ø(n) for the best-case running time in case of sorted input, as inner loop always traverses A.size.
// However, trivial modification allows Ø(n), which is shown in code.

void bubbleSort(Array & arr)
{
	for (int i = 0; i < arr.size() - 1; i++)
	{
//		bool swapped = false; // To enhance to Ø(n) if input sorted

		for (int j = (int)arr.size() - 1; j > i; j--) // The key here is reversed loop
		{
			if (arr[j] < arr[j-1])
			{
				const int tmp = arr[j];
				arr[j] = arr[j-1];
				arr[j-1] = tmp;

//				swapped = true;
			}
		}

//		if (!swapped)
//		{
//			cout << "Wow sorted!, i = " << i << endl;
//			
//			return ;
//		}
	}
}

void test_problem_2_2()
{
	Array arr = {5, 2, 4, 7, 1, 3, 2, 6};
//	Array arr = randomArrayWithSize(1000);
	
	printArray(arr);

	bubbleSort(arr);
	
	printArray(arr);
}

#endif /* Problem_2_2_h */
