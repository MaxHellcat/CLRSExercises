//
//  2.1-3.h
//  CLRSExercises
//
//  Created by Max Reshetey on 18/01/2017.
//  Copyright © 2017 Max Reshetey. All rights reserved.
//

#ifndef __1_3_h
#define __1_3_h

#include <iostream>
#include <vector>

const int nil = 0xDEADBEAF;

// Invariant:
//	Before each iteration, the subarray A[ i+1 .. A.count ] doesn't contain desired value.

// Initialisation:
//	The i == A.count, so A[ A.count+1 .. A.count ] doesn't contain anything

// Maintenance:
//	The loop header checks if A[i] equals val, if not then i is decremented in body, and so
//	the invariant preserves

// Termination:
//	At the end the i == 0, so entire array A[ 0+1 .. A.count ] doesn't contain the value

// TODO: Otherwise the value exists??


// Another approach
// Invariant:
//	Before each loop iteration, if A[i] equals val, the subarray A[ i .. A.count ] contains desired value at i, otherwise it doesn't.

// Initialisation:
//	The i == A.count, so if A[A.count] == val, then subarray A[ A.count .. A.count ] contains desired value at A.count

// Maintenance:
//	The i is decremented in the loop body, preserving invariant before the next iteration

// Termination:
//	If i == 0, then A[0] has no value (out-of-range) and so A[ 0 .. A.count] has no desired value
//	If i != 0 AND A[i] == val, the subarray A[i] has the desired value at index i

// TODO: Are conditions allowed in invariants? Anyway looking too vague to me..

int linearSearch(std::vector<int> & arr, int val)
{
	int i = (int)arr.size() - 1;
	
	while (i >= 0 && arr[i] != val)
	{
		i = i - 1;
	}
	
	return (i == -1) ? nil : i;
}

void test_2_1_3()
{
	std::vector<int> arr = {7, 5, 8, 6, 2, 4, 3, 1, 9};
	
	const int val = 12;
	
	std::cout << "Search result: " << linearSearch(arr, val) << std::endl;
	
	std::cout << std::endl;
}

#endif /* __1_3_h */
