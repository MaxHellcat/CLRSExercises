//
//  Defines.h
//  CLRSExercises
//
//  Created by Max Reshetey on 18/01/2017.
//  Copyright © 2017 Max Reshetey. All rights reserved.
//

#ifndef Defines_h
#define Defines_h

#include <iostream>
#include <vector>
#include <cstdlib> // For rand, srand

using namespace std::chrono;
using std::cout;
using std::endl;

typedef std::vector<int> Array;

bool checkSorted(const Array & arr)
{
	for (int i = 1; i < arr.size(); i++)
	{
		if (arr[i-1] > arr[i])
		{
			return false;
		}
	}

	return true;
}

void printArray(const Array & array)
{
	for (int i = 0; i < array.size(); i++)
	{
		printf( (i < array.size() - 1) ? "%i, " : "%i", array[i]);
	}

	printf(" (count: %li, %s)\n", array.size(), checkSorted(array)?"sorted":"unsorted");
}

Array randomArrayWithSize(size_t size, bool includeNegative = false)
{
	Array v;

	v.reserve(size);

//	int min = -100;
//	int max = 100;

	const int min = includeNegative ? -(int)size/2 : 1;
	const int max = includeNegative ? (int)size/2 : (int)size;

	srand( unsigned(time(nullptr)) );

	for (int i = 0; i < size; i++)
	{
//		int key = rand() % 100; // 0 to 99

		const int key = min + (rand() % (max - min + 1));

		v.push_back(key);
	}

	return v;
}

#endif /* Defines_h */
