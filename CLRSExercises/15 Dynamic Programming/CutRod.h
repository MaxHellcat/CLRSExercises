//
//  CutRod.h
//  CLRSExercises
//
//  Created by Max Reshetey on 04/12/2018.
//  Copyright © 2018 Max Reshetey. All rights reserved.
//

#ifndef CutRod_h
#define CutRod_h

#include "iostream"
#include "vector"
#include "map"

using namespace std;

namespace CutRod {

int cutRodAux(const vector<int> &prices, int rodLength, map<int, int> &mem);

int cutRodMemoize(const vector<int> &prices, int rodLength) {

	map<int, int> mem; // May well be switched to array

	return cutRodAux(prices, rodLength, mem);
}

int cutRodAux(const vector<int> &prices, int rodLength, map<int, int> &mem) {

	if (rodLength == 0) {
		return 0;
	}

	if (mem.find(rodLength) != mem.end()) {
		return mem[rodLength];
	}

	int maxRev = INT_MIN;

	for (int index=0; index < rodLength; index++) {

		const int rev = prices[index] + cutRodAux(prices, rodLength-(index+1), mem);

		if (rev > maxRev) {
			maxRev = rev;
		}
	}

	mem[rodLength] = maxRev;

	return maxRev;
}

int cutRodIter(const vector<int> &prices, int rodLength) {

	vector<int> mem(rodLength+1);

	mem[0] = 0; // [0] means length, not index of prices array

	for (int len = 1; len <= rodLength; len++) {

		int maxRev = INT_MIN;

		for (int index = 0; index < len; index++) {

			const int rev = prices[index] + mem[len-(index+1)];

			if (rev > maxRev) {
				maxRev = rev;
			}
		}

		mem[len] = maxRev;
	}

	return mem[rodLength];
}

void test() {

    const int length = 4;
    vector<int> prices = {1, 5, 8, 9, 10, 17, 17, 20, 24, 30};

    const auto val1 = cutRodMemoize(prices, length);
    cout << "See max revenue memoize: " << val1 << endl;

    const auto val2 = cutRodIter(prices, length);
    cout << "See max revenue iter: " << val2 << endl;
}
}

#endif /* CutRod_h */
