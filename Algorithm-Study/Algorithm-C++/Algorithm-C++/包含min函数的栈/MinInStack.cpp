//
//  MinInStack.cpp
//  Algorithm-C++
//
//  Created by HelloAda on 2019/2/16.
//  Copyright © 2019 HelloAda. All rights reserved.
//

#include "MinInStack.hpp"
#include "StackWithMin.h"
#include <iostream>

/*
 面试题30：包含min函数的栈
 题目：定义栈的数据结构，请在该类型中实现一个能够得到栈的最小元素的min
 函数。在该栈中，调用min、push及pop的时间复杂度都是O(1)。
 */

namespace namespace_minInStack {
    
    
    void printTip(const StackWithMin<int> & stack) {
        std::cout << "当前最小值是 - " << stack.min() << std::endl;
    }
    
    // --- 测试代码 ---
    void test() {
        std::cout << "测试开始" << std::endl;
        StackWithMin<int> stack;
        
        stack.push(3);
        printTip(stack);
        stack.push(4);
        printTip(stack);
        stack.push(2);
        printTip(stack);
        stack.pop();
        printTip(stack);
        stack.pop();
        printTip(stack);
        stack.push(0);
        printTip(stack);
        std::cout << "测试结束" << std::endl;
    }
    
    void minInStack() {
        test();
    }
}


