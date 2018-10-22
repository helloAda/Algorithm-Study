//
//  NumberOf1InBinary.cpp
//  Algorithm-C++
//
//  Created by HelloAda on 2018/10/20.
//  Copyright © 2018年 HelloAda. All rights reserved.
//

#include "NumberOf1InBinary.hpp"
#include <iostream>

/*
 面试题15：二进制中1的个数
 题目：请实现一个函数，输入一个整数，输出该数二进制表示中1的个数。例如
 把9表示成二进制是1001，有2位是1。因此如果输入9，该函数输出2。
 */


namespace namespace_NumberOf1InBinary {
    
    int numberOf1_Solution1(int n) {
        int count = 0;
        unsigned int flag = 1;
        while (flag) {
            if (n & flag) {
                count++;
            }
            flag = flag << 1;
        }
        
        return count;
    }
    
    // 这个算法 有几个1就执行几次
    int numberOf1_Solution2(int n) {
        int count = 0;
        while (n) {
            count++;
            n = (n - 1) & n;
        }
        return count;
    }
    
    // ----- 测试 -----
    void test(int n) {
        std::cout << "测试开始" << std::endl;
        int count = numberOf1_Solution1(n);
//        int count = numberOf1_Solution2(n);
        std::cout << "测试结果" << count << std::endl;
        std::cout << "测试结束" << std::endl;
    }
    
    void numberOf1InBinary() {
        test(-1);
        test(0);
        test(1);
        test(10);
        test(0x7FFFFFFF);
        test(0xFFFFFFFF);
        test(0x80000000);
    }
}
