//
//  StringPermutation.cpp
//  Algorithm-C++
//
//  Created by HelloAda on 2019/7/19.
//  Copyright © 2019 HelloAda. All rights reserved.
//

/*
 面试题38：字符串的排列
 题目：输入一个字符串，打印出该字符串中字符的所有排列。例如输入字符串abc，
 则打印出由字符a、b、c所能排列出来的所有字符串abc、acb、bac、bca、cab和cba。
 */

#include "StringPermutation.hpp"
#include <iostream>

namespace namespace_stringPermutation {
    
    
    void permutation(char *pStr, char *pBegin) {
        if (*pBegin == '\0') {
            std::cout << pStr << std::endl;
        }
        else {
            for (char *pCh = pBegin; *pCh != '\0'; ++pCh) {
                char temp = *pCh;
                *pCh = *pBegin;
                *pBegin = temp;
                permutation(pStr, pBegin + 1);
                
                temp = *pCh;
                *pCh = *pBegin;
                *pBegin = temp;
            }
        }
    }
    
    void permutation(char *pStr) {
        if (pStr == nullptr) {
            std::cout << "空指针" << std::endl;
            return;
        }
        permutation(pStr, pStr);
    }


    // ----- 测试代码 -----
    void test(char *pStr) {
        std::cout << "测试开始" << std::endl;
        permutation(pStr);
        std::cout << "测试结束" << std::endl;
    }
    
    //  多个字符
    void test1() {
        char string[] = "abcd";
        test(string);
    }
    
    // 单个字符
    void test2() {
        char string[] = "a";
        test(string);
    }
    
    // 空字符
    void test3() {
        char string[] = "";
        test(string);
    }
    
    // 空指针
    void test4() {
        test(nullptr);
    }
    
    void stringPermutation() {
        test1();
        test2();
        test3();
        test4();
    }
}
