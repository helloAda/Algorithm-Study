//
//  NumericStrings.cpp
//  Algorithm-C++
//
//  Created by HelloAda on 2018/12/3.
//  Copyright © 2018 HelloAda. All rights reserved.
//

#include "NumericStrings.hpp"
#include <iostream>

/*
 面试题20：表示数值的字符串
 题目：请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。例如，
 字符串“+100”、“5e2”、“-123”、“3.1416”及“-1E-16”都表示数值，但“12e”、
 “1a3.14”、“1.2.3”、“+-5”及“12e+5.4”都不是
 */


namespace namespcae_numericStrings {
    
    // 扫描无符号数是否含有0-9
    bool scanUnsignedInteger(const char **str) {
        const char *before = *str;
        // 字符串没有结束，并且每个字符都在0-9之间
        while (**str != '\0' && **str >= '0' && **str <= '9') {
            (*str)++;
        }
        // 存在0-9之间的数字，返回true (这里只要进入过一次循环就为true)
        return *str > before;
    }
    
    // 扫描是否有带符号
    bool scanInteger(const char **str) {
        // 判断字符串的第一位是否为 '+'或'-'
        if (**str == '+' || **str == '-') {
            // 如果是，从第二位开始取 例如 '+123.45' 变成 '123.45'
            (*str)++;
        }
        return scanUnsignedInteger(str);
    }
    
    void isNumeric(const char *str) {
        
        if (str == nullptr) {
            std::cout << "空指针" << std::endl;
            return ;
        }
        
        std::cout << str;
        // 扫描整数部分
        bool numeric = scanInteger(&str);
        
        // 如果还有小树部分
        if (*str == '.') {
            str++;
            /*
             还需要|| 是因为
             小数部分 可以没有整数部分 .123
             小数点后面也可以没有数字 123.
             也可以是正常的 123.456
             所以不能只判断小数点后面是否有0-9来决定
             */
            numeric = scanUnsignedInteger(&str) || numeric;
        }
        
        // 如果还有指数部分
        if (*str == 'e' || *str == 'E') {
            str++;
            /*
             用&& 是因为
             e或E 前面没有数字的时候 不能表示数字 .e1 e1
             e或E 后面没有整数的时候 不能表示数字 12e 12e+5.4
             // 感觉&& scanInteger(&str) 如果下面有判断*str == '\0' 是不是到最后了 好像不用？没找到特殊情况，先这样。
             */
            numeric = numeric && scanInteger(&str);
        }
        // 是一个数字 并且已经到最后了
        if (numeric && *str == '\0') {
            std::cout << "是一个数字" << std::endl;
        } else {
            std::cout << "不是一个数字" << std::endl;
        }
    }
    
    
    // ---- 测试代码 ----
    void test (const char *str) {
        std::cout << "测试开始" << std::endl;
        isNumeric(str);
        std::cout << "测试结束" << std::endl;
    }
    
    void numericStrings() {
        test("100");
        test("123.45e+6");
        test("+500");
        test("5e2");
        test("3.1416");
        test("600.");
        test("-.123");
        test("-1E-16");
        test("1.79769313486232E+308");
        test("12e");
        test("1a3.14");
        test("1+23");
        test("1.2.3");
        test("+-5");
        test("12e+5.4");
        test(".");
        test(".e1");
        test("e1");
        test("+.");
        test("");
        test(nullptr);
    }
}
