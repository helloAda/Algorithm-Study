//
//  Fibonacci.cpp
//  Algorithm-C++
//
//  Created by HelloAda on 2018/9/19.
//  Copyright © 2018年 HelloAda. All rights reserved.
//

#include "Fibonacci.hpp"
#include <iostream>
/*
 面试题10：斐波那契数列
 题目：写一个函数，输入n，求斐波那契（Fibonacci）数列的第n项。
 */


namespace namespace_fibonacci {
    
    // 递归实现
    long long fibonacci_Solution1(int n) {
        if (n <= 0) {
            return 0;
        }
        if (n == 1) {
            return 1;
        }
        
        return fibonacci_Solution1(n - 1) + fibonacci_Solution1(n - 2);
    }
    
    // 循环实现
    long long fibonacci_Solution2(int n) {
        if (n <= 0) {
            return 0;
        }
        if (n == 1) {
            return 1;
        }
        
        long long fibOne = 0;
        long long fibTwo = 1;
        long long fib = 0;
        for (int i = 2; i<= n; i++) {
            fib = fibOne + fibTwo;
            fibOne = fibTwo;
            fibTwo = fib;
        }
        return fib;
    }

    
    // ------ 测试 -------
    void test(int n) {
        long long result;
        std::cout << "测试开始" << std::endl;
        
        
//        result = fibonacci_Solution1(n);
//        std::cout << "递归实现/// 结果是:" << result << std::endl;
        
        result = fibonacci_Solution2(n);
        std::cout << "循环实现/// 结果是:" << result << std::endl;
        
        std::cout << "测试结束" << std::endl;
    }
    
    void fibonacci() {
        // 正常数据
        test(3);
        test(5);
        test(6);
        // 边界数据
        test(0);
        test(1);
        test(2);
        // 异常数据
        test(-2);
        test(-3);
        // 性能数据
        test(40);
        test(100);
    }
}




