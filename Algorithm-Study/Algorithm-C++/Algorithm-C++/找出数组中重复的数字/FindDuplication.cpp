//
//  FindDuplication.cpp
//  Algorithm-C++
//
//  Created by HelloAda on 2018/9/10.
//  Copyright © 2018年 HelloAda. All rights reserved.
//

#include "FindDuplication.hpp"
#include <iostream>
/*
 面试题3（一）：找出数组中重复的数字
 题目：在一个长度为n的数组里的所有数字都在0到n-1的范围内。数组中某些数字是重复的，但不知道有几个数字重复了，
 也不知道每个数字重复了几次。请找出数组中任意一个重复的数字。
 时间复杂度O(n) 空间复杂度O(1)
 */

namespace namespace_findDuplication {
    /**
     找出重复的数字
     
     @param numbers 数组
     @param length 数组长度
     */
    void duplicate(int numbers[], int length) {
        
        // 异常的输入
        if (numbers == nullptr || length <= 0) {
            std::cout << "无效输入！" << std::endl;
            return ;
        }
        // 检查边界范围
        for (int i = 0 ; i < length; i++) {
            if (numbers[i] < 0 || numbers[i] > length - 1) {
                std::cout << "数值越界！" << std::endl;
                return ;
            }
        }
        
        for (int i = 0; i < length; i++) {
            
            while (numbers[i] != i) {
                if (numbers[i] == numbers[numbers[i]] ) {
                    std::cout << "找到任意的一个重复的数字" << numbers[i] << std::endl;
                    return ;
                } else {
                    int temp = numbers[i];
                    numbers[i] = numbers[temp];
                    numbers[temp] = temp;
                }
            }
        }
        std::cout << "没有重复的数字" << std::endl;
    }
    
    // ----------  测试 -----------
    
    void test(int *numbers, int length) {
        std::cout << "==== 测试开始 ====" << std::endl;
        duplicate(numbers, length);
        std::cout << "==== 测试结束 ====" << std::endl;
    }
    
    // 有重复的数字
    void test1() {
        int numbers[] = {2, 3, 4, 3, 1};
        test(numbers, sizeof(numbers) / sizeof(int));
    }
    
    // 没有重复的数字
    void test2() {
        int numbers[] = {1, 2, 4, 0, 3};
        test(numbers, sizeof(numbers) / sizeof(int));
    }
    
    // 有多个重复的数字
    void test3() {
        int numbers[] = {2, 3, 2, 3, 4};
        test(numbers, sizeof(numbers) / sizeof(int));
    }
    
    // 空输入
    void test4() {
        int numbers[] = {};
        test(numbers, sizeof(numbers) / sizeof(int));
    }
    
    // 无效输入
    void test5() {
        int *numbers = nullptr;
        test(numbers, sizeof(numbers) / sizeof(int));
    }
    
    // 越界数据
    void test6() {
        int numbers[] = {-1, 4, 5, 7, 6};
        test(numbers, sizeof(numbers) / sizeof(int));
    }
    
    void findDuplication() {
        test1();
        test2();
        test3();
        test4();
        test5();
        test6();
    }
}



