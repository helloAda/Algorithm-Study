//
//  Array.cpp
//  Algorithm-C++
//
//  Created by HelloAda on 2019/8/19.
//  Copyright © 2019 HelloAda. All rights reserved.
//

#include "Array.hpp"
#include <stdlib.h>

int randomInRange(int min, int max) {
    int random = rand() % (max - min + 1) + min;
    return random;
}

void swap(int *num1, int *num2) {
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

int partition(int data[], int length, int start, int end) {
    if (data == nullptr || length <= 0 || start < 0 || end >= length) {
        throw "Invalid Parameters";
    }
    
    int index = randomInRange(start, end);
    swap(&data[index], &data[end]);
    
    int small = start - 1;
    for (index = start; index < end; index++) {
        if (data[index] < data[end]) {
            small++;
            if (small != index) {
                swap(&data[index], &data[small]);
            }
        }
    }
    
    small++;
    swap(&data[small], &data[end]);
    return small;
}
