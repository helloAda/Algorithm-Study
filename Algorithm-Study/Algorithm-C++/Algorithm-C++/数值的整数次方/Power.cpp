//
//  Power.cpp
//  Algorithm-C++
//
//  Created by HelloAda on 2018/11/20.
//  Copyright © 2018 HelloAda. All rights reserved.
//

#include "Power.hpp"
#include <iostream>

namespace namespace_power {
    
    bool equal(double num1, double num2) {
        // 精度
        if ((num1 - num2) > -0.0000001 && (num1 - num2) < 0.0000001) {
            return true;
        } else {
            return false;
        }
    }
    
    double powerWithExponent(double base, int exponent) {
        if (exponent == 0) {
            return 1.0;
        }
        if (exponent == 1) {
            return base;
        }
        // 递归  移位比除法高效
        double result = powerWithExponent(base, exponent >> 1);
        result *= result;
        // 用位运算代替求余
        if ((exponent & 0x1) == 1) {
            result *= base;
        }
        
        return result;
    }
    
    double power(double base, int exponent) {
        // 底数为0 且 指数小于等于0 是没有意义的
        if (equal(base, 0.0) && exponent <= 0) {
            std::cout << "输入的参数没有意义" << std::endl;
            return 0.0;
        }
        
        // 如果指数为负取正去计算
        int absExponent = exponent;
        if (exponent < 0) {
            absExponent = -exponent;
        }
        
        double result = powerWithExponent(base, absExponent);
        if (exponent < 0) {
            result = 1.0 / result;
        }
        std::cout << "结果" << result << std::endl;
        return result;
    }
    
    

    
    
    
    // 测试代码
    void test(double base, int exponent) {
        std::cout << "测试开始" << std::endl;
        power(base, exponent);
        std::cout << "测试结束" << std::endl;
    }
    
    void power() {
        test(2, 2);
        test(2, -2);
        test(-2, 2);
        test(-2, -2);
        test(0, 2);
        test(0, -2);
        test(0, 0);
        test(2, 0);
        test(-2, 0);
    }
}
