//
//  ReplaceSpaces.cpp
//  Algorithm-C++
//
//  Created by HelloAda on 2018/9/11.
//  Copyright © 2018年 HelloAda. All rights reserved.
//

#include "ReplaceSpaces.hpp"
#include <iostream>
/*
 面试题5：替换空格
 题目：请实现一个函数，把字符串中的每个空格替换成"%20"。例如输入“We are happy.”，
 则输出“We%20are%20happy.”。
 */
namespace namespace_replaceSpaces {
    
    void replaceBlank(char str[], int length) {
        if (str == nullptr && length <= 0) {
            std::cout << "无效字符" << std::endl;
            return;
        }
        
        int originalLength = 0; // 原字符串长度
        int numberOfBlank = 0; // 空格数量
        int i = 0;
        while (str[i] != '\0') {
            originalLength++;
            if (str[i] == ' ') {
                numberOfBlank++;
            }
            i++;
        }
        
        int newLength = originalLength + numberOfBlank * 2;
        if (newLength > length) {
            std::cout << "替换后超过字符串最大容量" << std::endl;
            return;
        }
        
        int indexOfOriginal = originalLength;
        int indexOfNew = newLength;
        while (indexOfOriginal >= 0 && indexOfNew > indexOfOriginal) {
            if (str[indexOfOriginal] == ' ') {
                str[indexOfNew--] = '0';
                str[indexOfNew--] = '2';
                str[indexOfNew--] = '%';
            } else {
                str[indexOfNew--] = str[indexOfOriginal];
            }
            indexOfOriginal--;
        }
        
        std::cout << "替换后的字符串:" << str << std::endl;
    }
    
    
    
    // ------ 测试 --------
    
    // 空格在开始
    void test1() {
        const int length = 100;
        char str[length] = " helloworld";
        replaceBlank(str, length);
    }
    
    // 空格在中间
    void test2() {
        const int length = 100;
        char str[length] = "hello world";
        replaceBlank(str, length);
    }
    
    // 空格在末尾
    void test3() {
        const int length = 100;
        char str[length] = "helloworld ";
        replaceBlank(str, length);
    }
    
    // 连续空格 多个空格
    void test4() {
        const int length = 100;
        char str[length] = "hello  world ";
        replaceBlank(str, length);
    }
    
    // 空指针
    void test5() {
        replaceBlank(nullptr, 0);
    }
    
    // 超过容量
    void test6() {
        const int length = 12;
        char str[length] = "hello world";
        replaceBlank(str, length);
    }
    
    
    void replaceSpaces() {
        test1();
        test2();
        test3();
        test4();
        test5();
        test6();
    }
}
