//
//  StackPushPopOrder.cpp
//  Algorithm-C++
//
//  Created by HelloAda on 2019/2/18.
//  Copyright © 2019 HelloAda. All rights reserved.
//

#include "StackPushPopOrder.hpp"
#include <stack>
#include <iostream>

/*
 面试题31：栈的压入、弹出序列
 题目：输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是
 否为该栈的弹出顺序。假设压入栈的所有数字均不相等。例如序列1、2、3、4、
 5是某栈的压栈序列，序列4、5、3、2、1是该压栈序列对应的一个弹出序列，但
 4、3、5、1、2就不可能是该压栈序列的弹出序列。
 */

namespace namespace_stackPushPopOrder {
    
    
    void isPopOrder(const int *pPush, const int *pPop, int nLength) {
        if (pPush == nullptr || pPop == nullptr || nLength <= 0) {
            std::cout << "数据有误，不是弹出序列" << std::endl;
            return;
        }
        
        const int *pNextPush = pPush;
        const int *pNextPop = pPop;
        std::stack<int> stackData;
        
        // 直到弹出序列都判断完了
        while (pNextPop - pPop < nLength) {
            
            /*
             栈空了，或者栈顶元素不是要弹出的元素，压入数据
             */
            while (stackData.empty() || stackData.top()!= *pNextPop) {
                // 所有数字都压入了 退出这层循环
                if (pNextPush - pPush == nLength) {
                    break;
                }
                
                stackData.push(*pNextPush);
                pNextPush++;
            }
            
            // 如果栈顶元素还是不等于下一个要出栈的数据 跳出循环
            if (stackData.top() != *pNextPop) {
                break;
            }
            
            stackData.pop();
            pNextPop++;
        }

        if (stackData.empty() && pNextPop - pPop == nLength) {
            std::cout <<"是弹出序列" << std::endl;
        } else {
            std::cout << "不是弹出序列" << std::endl;
        }
    }
    
    
    // --- 测试代码 ---
    void test(const int *pPush, const int *pPop, int nLength) {
        std::cout << "测试开始" << std::endl;
        isPopOrder(pPush, pPop, nLength);
        std::cout << "测试结束" << std::endl;
    }
    
    // 正确的序列
    void test1() {
        const int nLength = 5;
        int push[nLength] = {1, 2, 3, 4, 5};
        int pop[nLength] = {4, 5, 3, 2, 1};
        test(push, pop, nLength);
    }
    
    // 正确的序列
    void test2() {
        const int nLength = 5;
        int push[nLength] = {1, 2, 3, 4, 5};
        int pop[nLength] = {3, 5, 4, 2, 1};
        test(push, pop, nLength);
    }
    
    // 错误的序列
    void test3() {
        const int nLength = 5;
        int push[nLength] = {1, 2, 3, 4, 5};
        int pop[nLength] = {4, 3, 5, 1, 2};
        test(push, pop, nLength);
    }
    
    // 错误的序列
    void test4() {
        const int nLength = 5;
        int push[nLength] = {1, 2, 3, 4, 5};
        int pop[nLength] = {3, 5, 4, 1, 2};
        test(push, pop, nLength);
    }
    
    // 只有一个数字 正确的
    void test5() {
        const int nLength = 1;
        int push[nLength] = {1};
        int pop[nLength] = {1};
        test(push, pop, nLength);
    }
    
    // 只有一个数字 错误的
    void test6() {
        const int nLength = 1;
        int push[nLength] = {1};
        int pop[nLength] = {2};
        test(push, pop, nLength);
    }
    
    // 空指针
    void test7() {
        test(nullptr, nullptr, 0);
    }
    
    void stackPushPopOrder() {
        test1();
        test2();
        test3();
        test4();
        test5();
        test6();
        test7();
    }
}
