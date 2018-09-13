//
//  FindDuplicationNoEdit.cpp
//  Algorithm-C++
//
//  Created by HelloAda on 2018/9/10.
//  Copyright © 2018年 HelloAda. All rights reserved.
//

#include "FindDuplicationNoEdit.hpp"
#include <iostream>

/*
 面试题3（二）：不修改数组找出重复的数字
 题目：在一个长度为n+1的数组里的所有数字都在1到n的范围内，所以数组中至
 少有一个数字是重复的。请找出数组中任意一个重复的数字，但不能修改输入的
 数组。例如，如果输入长度为8的数组{2, 3, 5, 4, 3, 2, 6, 7}，那么对应的
 输出是重复的数字2或者3。
 时间复杂度O(nlogn) 空间复杂度O(1)
 */


namespace namespace_findDuplicationNoEdit {
    /**
     二分查找
     
     @param numbers 数组
     @param length 数组长度
     @param start 开始数字
     @param end 结束数字
     @return 在这个start-end范围的数字的数目
     */
    int countRange(const int* numbers, int length, int start, int end) {
        int count = 0;
        for (int i = 0; i < length; i++) {
            if (numbers[i] >= start && numbers[i] <= end) {
                count++;
            }
        }
        return count;
    }
    
    /**
     数组中重复的数字
     
     @param numbers 数组
     @param length 数组长度
     */
    void getDuplication(const int *numbers, int length) {
        if (numbers == nullptr || length <= 0) {
            std::cout << "无效输入！" << std::endl;
            return;
        }
        for (int i = 0; i < length; i++) {
            if (numbers[i] <= 0 || numbers[i] >= length) {
                std::cout << "数值越界！" << std::endl;
                return;
            }
        }
        
        int start = 1;
        int end = length - 1;
        while (start <= end) {
            int mid = ((end - start) >> 1) + start;
            int count = countRange(numbers, length, start, mid);
            
            // 找到的时候
            if (start == end) {
                if (count > 1) {
                    std::cout << "重复的数字" << start << std::endl;
                    return;
                } else {
                    break;
                }
            }
            
            if (count > (mid - start + 1)) {
                end = mid;
            } else {
                start = mid + 1;
            }
        }
        // 加了越界判断，，走不到这里。。
        std::cout << "没有重复的数字" << std::endl;
    }
    
    
    // -------- 测试 -----------
    
    void test(int *numbers, int length) {
        std::cout << "==== 测试开始 ====" << std::endl;
        getDuplication(numbers, length);
        std::cout << "==== 测试结束 ====" << std::endl;
    }
    
    // 有重复的数字
    void test1() {
        int numbers[] = {2, 3, 4, 5, 2, 1};
        test(numbers, sizeof(numbers) / sizeof(int));
    }
    
    // 多个重复的数字
    void test2() {
        int numbers[] = {2, 3, 2, 4, 5, 5, 4};
        test(numbers, sizeof(numbers) / sizeof(int));
    }
    
    // 空数组
    void test3() {
        int numbers[] = {};
        test(numbers, sizeof(numbers) / sizeof(int));
    }
    
    // 空指针
    void test4() {
        int *numbers = nullptr;
        test(numbers, sizeof(numbers) / sizeof(int));
    }
    
    // 越界的数据
    void test5() {
        int numbers[] = {-3, 2, 8, 9, 5, 6};
        test(numbers, sizeof(numbers) / sizeof(int));
    }
    
    // 对于这题，没有重复的数字，那么其实就是会有越界数据存在
    void test6() {
        int numbers[] = {1, 2, 3, 4, 5, 6};
        test(numbers, sizeof(numbers) / sizeof(int));
    }
    
    void findDuplicationNoEdit() {
        test1();
        test2();
        test3();
        test4();
        test5();
        test6();
    }
}
