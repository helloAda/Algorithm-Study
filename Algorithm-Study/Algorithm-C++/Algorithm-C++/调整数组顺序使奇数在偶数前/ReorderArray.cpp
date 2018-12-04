//
//  ReorderArray.cpp
//  Algorithm-C++
//
//  Created by HelloAda on 2018/12/4.
//  Copyright © 2018 HelloAda. All rights reserved.
//

#include "ReorderArray.hpp"
#include <iostream>

/*
 面试题21：调整数组顺序使奇数位于偶数前面
 题目：输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有
 奇数位于数组的前半部分，所有偶数位于数组的后半部分。
 */

namespace namespace_reorderArray {
    
    void printArray(int numbers[], int length)
    {
        if(length < 0)
            return;
        std::cout << "排序完: ";
        for(int i = 0; i < length; ++i)
            std::cout << "\t" << numbers[i];
        
        printf("\n");
    }
    
    // ----- 方法一 -----
    void reorderOddEven_1 (int *pData, unsigned int length) {
        if (pData == nullptr || length == 0) {
            std::cout << "无效输入" << std::endl;
            return;
        }
        
        int *pBegin = pData;
        int *pEnd = pData + length - 1;
        
        while (pBegin < pEnd) {
            
            // 向后移动 直到找到偶数为止
            while (pBegin < pEnd && (*pBegin & 0x1) != 0) {
                pBegin++;
            }
            
            // 向前移动 直到找到奇数为止
            while (pBegin < pEnd && (*pEnd & 0x1) == 0) {
                pEnd--;
            }
            
            if (pBegin < pEnd) {
                int temp = *pBegin;
                *pBegin = *pEnd;
                *pEnd = temp;
            }
        }
        
        printArray(pData, length);
    }
    
    
    // ----- 方法二 -----
    // 将判断逻辑抽象出来 可以扩展成解决一系列相同问题的代码
    
    bool isEven(int n) {
        return (n & 1) == 0;
    }
    
    void reorder(int *pData, unsigned int length, bool (*func)(int)) {
        if(pData == nullptr || length == 0) {
            std::cout << "无效输入" << std::endl;
            return;
        }

        int *pBegin = pData;
        int *pEnd = pData + length - 1;
        
        while(pBegin < pEnd)
        {
            // 向后移动pBegin
            while(pBegin < pEnd && !func(*pBegin))
                pBegin ++;
            
            // 向前移动pEnd
            while(pBegin < pEnd && func(*pEnd))
                pEnd --;
            
            if(pBegin < pEnd)
            {
                int temp = *pBegin;
                *pBegin = *pEnd;
                *pEnd = temp;
            }
        }
        printArray(pData, length);
    }
    
    void reorderOddEven_2(int *pData, unsigned int length) {
        reorder(pData, length, isEven);
    }
    
    
    // ---- 测试代码 ----
    void test(int *pData, unsigned int length) {
        std::cout << "测试开始" << std::endl;
//        reorderOddEven_1(pData, length);
        reorderOddEven_2(pData, length);
        std::cout << "测试结束" << std::endl;
    }
    
    // 正常数据
    void test1() {
        int number[] = {1, 2, 3, 4, 5, 6, 7, 8};
        test(number, sizeof(number) / sizeof(int));
    }
    // 偶数全部在前面
    void test2() {
        int number[] = {2, 4, 6, 8, 1, 3, 5, 7};
        test(number, sizeof(number) / sizeof(int));
    }
    // 奇数全部在前面
    void test3() {
        int number[] = {1, 3, 5, 7, 2, 4, 6, 8};
        test(number, sizeof(number) / sizeof(int));
    }
    // 只有一个奇数
    void test4() {
        int number[] = {1};
        test(number, sizeof(number) / sizeof(int));
    }
    // 只有一个偶数
    void test5() {
        int number[] = {2};
        test(number, sizeof(number) / sizeof(int));
    }
    void test6() {
        test(nullptr, 0);
    }
    
    void reorderArray() {
        test1();
        test2();
        test3();
        test4();
        test5();
        test6();
    }
}
