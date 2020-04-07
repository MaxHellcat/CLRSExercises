//
//  2.1-3.h
//  CLRSExercises
//
//  Created by Max Reshetey on 18/01/2017.
//  Copyright © 2017 Max Reshetey. All rights reserved.
//

#ifndef _2_1_3_h
#define _2_1_3_h

#include "Defines.h"

namespace Ex_2_1_3 {

const int nil = 0xDEADBEAF;

int linearSearch(Array & arr, int val)
{
    int i = (int)arr.size() - 1;

    while (i >= 0 && arr[i] != val)
    {
        i = i - 1;
    }

    return (i == -1) ? nil : i;
}

void test()
{
    Array arr = {7, 5, 8, 6, 2, 4, 3, 1, 9};

    const int val = 12;

    cout << "Search result: " << linearSearch(arr, val) << endl;

    cout << endl;
}
}

#endif /* _2_1_3_h */
