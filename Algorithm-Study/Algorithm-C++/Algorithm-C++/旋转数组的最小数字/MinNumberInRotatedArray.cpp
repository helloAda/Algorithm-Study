//
//  MinNumberInRotatedArray.cpp
//  Algorithm-C++
//
//  Created by HelloAda on 2018/9/26.
//  Copyright © 2018年 HelloAda. All rights reserved.
//

#include "MinNumberInRotatedArray.hpp"
#include <iostream>
/*
 面试题11：旋转数组的最小数字
 题目：把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
 输入一个递增排序的数组的一个旋转，输出旋转数组的最小元素。例如数组
 {3, 4, 5, 1, 2}为{1, 2, 3, 4, 5}的一个旋转，该数组的最小值为1
 */


namespace namespace_minNumberInRotatedArray {
    
    // 顺序查找
    void findMinInOrder(int *numbers, int index1, int index2) {
        int result = numbers[index1];
        for (int i = index1 + 1; i <= index2; i++) {
            // 只要从头开始查找出现了一个比它小的 这个数字就是最小值。
            // 如果一直没有找到，那么原来index1位置的值就是最小的。
            if (result > numbers[i]) {
                result = numbers[i];
                break;
            }
        }
        
        std::cout << "找到最小值为:" << result << std::endl;
    }
    
    // 找旋转数组中的最小的值
    void findMin(int *numbers, int length) {
        if (numbers == nullptr || length <= 0) {
            std::cout << "无效数据" << std::endl;
            return;
        }
        
        int index1 = 0;
        int index2 = length - 1;
        int indexMid = index1;
        while (numbers[index1] >= numbers[index2]) {
            // 如果两个索引已经相邻了 那么第二个指向的就是最小值
            if ((index2 - index1) == 1) {
                indexMid = index2;
                break;
            }
            
            indexMid = (index1 + index2) / 2;
            if (numbers[index1] == numbers[index2] == numbers[indexMid]) {
                findMinInOrder(numbers, index1, index2);
                return;
            }
            
            // 二分查找
            if (numbers[indexMid] >= numbers[index1]) {
                index1 = indexMid;
            } else if (numbers[indexMid] <= numbers[index2]) {
                index2 = indexMid;
            }
        }
        
        std::cout << "找到最小值为" << numbers[indexMid] << std::endl;
    }
    

    
    
    
    //---- 测试 ----
    
    void test(int *numbers, int length) {
        std::cout << "=== 测试开始 ===" << std::endl;
        findMin(numbers, length);
        std::cout << "=== 测试结束 ===" << std::endl;
    }
    // 正常数据
    void test1() {
        int array[] = {3, 4, 5, 1, 2};
        test(array, sizeof(array) / sizeof(int));
    }
    
    // 有重复数据，并且刚好是最小的数据
    void test2() {
        int array[] = {3, 4, 5, 1, 1, 2};
        test(array, sizeof(array) / sizeof(int));
    }
    
    // 有重复数据，并且刚好在末尾
    void test3() {
        int array[] = {3, 4, 5, 1, 2, 2};
        test(array, sizeof(array) / sizeof(int));
    }
    
    // 有重复数字，并且刚好是第一个数字和最后一个数字
    void test4() {
        int array[] = {3, 4, 5, 1, 2, 3};
        test(array, sizeof(array) / sizeof(int));
    }
    
    // 已经排序好的数据
    void test5() {
        int array[] = {1, 2, 3, 4, 5};
        test(array, sizeof(array) / sizeof(int));
    }
    
    // 有重复数据，并且中间和头尾两边数据相等
    void test6() {
        int array[] = {1, 0, 1, 1, 1};
        test(array, sizeof(array) / sizeof(int));
    }
    
    // 只有一个数据
    void test7() {
        int array[] = {1};
        test(array, sizeof(array) / sizeof(int));
    }
    
    // 空数据
    void test8() {
        int array[] = {};
        test(array, sizeof(array) / sizeof(int));
    }
    
    // 空指针
    void test9() {
        test(nullptr, 0);

    }
    
    void minNumberInRotatedArray() {
        test1();
        test2();
        test3();
        test4();
        test5();
        test6();
        test7();
        test8();
        test9();
    }
}

