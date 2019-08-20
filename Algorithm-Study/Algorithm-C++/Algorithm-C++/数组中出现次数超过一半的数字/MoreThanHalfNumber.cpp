//
//  MoreThanHalfNumber.cpp
//  Algorithm-C++
//
//  Created by HelloAda on 2019/8/19.
//  Copyright © 2019 HelloAda. All rights reserved.
//

/*
 面试题39：数组中出现次数超过一半的数字
 题目：数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。例
 如输入一个长度为9的数组{1, 2, 3, 2, 2, 2, 5, 4, 2}。由于数字2在数组中
 出现了5次，超过数组长度的一半，因此输出2。
 */

#include "MoreThanHalfNumber.hpp"
#include "Array.hpp"
#include <iostream>

namespace namespace_moreThanHalfNumber {
    
    bool checkMoreThanHalf(int *numbers, int lenght, int number) {
        int times = 0;
        for (int i = 0; i < lenght; i++) {
            if (numbers[i] == number) {
                times++;
            }
        }
        
        bool isMoreThanHalf = true;
        if (times * 2 <= lenght) {
            isMoreThanHalf = false;
        }
        
        return isMoreThanHalf;
    }
    
    // 方法1
    int moreThanHalfNumber1(int *numbers, int length) {
        if (numbers == nullptr || length <= 0) {
            std::cout << "无效参数" << std::endl;
            return 0;
        }
        
        int middle = length >> 1;
        int start = 0;
        int end = length - 1;
        int index = partition(numbers, length, start, end);
        // 找到排序后在中间的数
        while (index != middle) {
            if (index > middle) {
                end = index - 1;
                index = partition(numbers, length, start, end);
            } else {
                start = index + 1;
                index = partition(numbers, length, start, end);
            }
        }
        
        int result = numbers[middle];
        if (!checkMoreThanHalf(numbers, length, result)) {
            result = 0;
        }
        
        return result;
        
    }
    
    // 方法2
    int moreThanHalfNumber2(int *numbers, int length) {
        if (numbers == nullptr || length <= 0) {
            std::cout << "无效参数" << std::endl;
            return 0;
        }
        
        int result = numbers[0];
        int times = 1;
        for (int i = 1; i < length; i++) {
            if (times == 0) {
                result = numbers[i];
                times = 1;
            } else if (numbers[i] == result) {
                times++;
            } else {
                times--;
            }
        }
        
        if (!checkMoreThanHalf(numbers, length, result)) {
            result = 0;
        }
        
        return result;
    }
    
    // --- 测试代码 ---
    void test(int *numbers, int length) {
        std::cout << "测试开始" << std::endl;
        std::cout << "方法1" << std::endl;
        int result = moreThanHalfNumber1(numbers, length);
        if (result) {
            std::cout << "有次数超过一半的数字:" << result << std::endl;
        } else {
            std::cout << "没有次数超过一半的数字" << std::endl;
        }
        std::cout << "方法2" << std::endl;
        int result1 = moreThanHalfNumber2(numbers, length);
        if (result1) {
            std::cout << "有次数超过一半的数字:" << result1 << std::endl;
        } else {
            std::cout << "没有次数超过一半的数字" << std::endl;
        }
        std::cout << "测试结束" << std::endl;
    }
    
    // 有次数超过一半的数字
    void test1() {
        int numbers[] = {1, 2, 3, 2, 2, 2, 5, 4, 2};
        test(numbers, sizeof(numbers) / sizeof(int));
    }
    
    // 没有次数超过一半的数字
    void test2() {
        int numbers[] = {1, 2, 3, 2, 4, 2, 5, 2, 3};
        test(numbers, sizeof(numbers) / sizeof(int));
    }
    
    // 只有一个数字
    void test3() {
        int numbers[] = {1};
        test(numbers, sizeof(numbers) / sizeof(int));
    }
    // 空指针
    void test4() {
        test(nullptr, 0);
    }
    
    void moreThanHalfNumber() {
        test1();
        test2();
        test3();
        test4();
    }
}
