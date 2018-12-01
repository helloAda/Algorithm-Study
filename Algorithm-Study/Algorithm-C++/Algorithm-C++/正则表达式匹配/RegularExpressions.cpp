//
//  RegularExpressions.cpp
//  Algorithm-C++
//
//  Created by HelloAda on 2018/12/1.
//  Copyright © 2018 HelloAda. All rights reserved.
//

#include "RegularExpressions.hpp"
#include <iostream>

/*
 面试题19：正则表达式匹配
 题目：请实现一个函数用来匹配包含'.'和'*'的正则表达式。模式中的字符'.'
 表示任意一个字符，而'*'表示它前面的字符可以出现任意次（含0次）。在本题
 中，匹配是指字符串的所有字符匹配整个模式。例如，字符串"aaa"与模式"a.a"
 和"ab*ac*a"匹配，但与"aa.a"及"ab*a"均不匹配。
 */

namespace namespace_regularExpressions {
    
    /**
     正则表达式匹配

     @param str 匹配字符
     @param pattern 正则字符
     @return 是否匹配
     */
    bool matchCore(const char *str, const char *pattern) {
        
        // 匹配字符还没匹配完，正则字符已经为空 返回不匹配
        if (*str != '\0' && *pattern == '\0') {
            return false;
        }
        // 匹配字符和正则字符都匹配完了 返回匹配
        if (*str == '\0' && *pattern == '\0') {
            return true;
        }
        
        // 如果正则字符的下一个字符是是'*'的话
        if (*(pattern + 1) == '*') {
            // 匹配字符和正则字符匹配
            if (*pattern == *str || (*pattern == '.' && *str != '\0')) {
                // 同时进入下一个字符的匹配(相当于这个*代表一个相同字符)
                return matchCore(str + 1, pattern + 2)
                // 匹配字符进入下一个 正则字符继续在当前的字符(相当于这个*代表了多个相同字符)
                || matchCore(str + 1, pattern)
                // 正则字符继续在当前字符 正则字符进入下一个(相当于这个*不用于表示这个相等字符，跳过这个'*')
                || matchCore(str, pattern + 2);
            } else {
                // 当前字符和正则字符不匹配 直接跳过这个'*'
                return matchCore(str, pattern + 2);
            }
        }
        
        // 当前字符和正则字符匹配 或者 (正则字符为'.'并且当前字符不能为空) 则当前字符匹配 进入下一个字符
        if (*str == *pattern || (*pattern == '.' && *str != '\0')) {
            return matchCore(str + 1, pattern + 1);
        }

        return false;
    }
    
    void match(const char *str, const char *pattern) {
        if (str == nullptr || pattern == nullptr) {
            std::cout << "无效输入" << std::endl;
            return;
        }
        bool result = matchCore(str, pattern);
        if (result) {
            std::cout << " --- 匹配成功! 匹配字符: " << str << " --- 正则字符: " << pattern << std::endl;
        } else {
            std::cout << " --- 匹配失败! 匹配字符: " << str << " --- 正则字符: " << pattern << std::endl;
        }
    }
    
    // ---- 测试代码 ----
    void test(const char *str, const char *pattern) {
        std::cout << "测试开始" << std::endl;
        match(str, pattern);
        std::cout << "测试结束" << std::endl;
    }
    
    void regularExpressions () {
        test(nullptr, nullptr);
        test("", "");
        test("", ".*");
        test("", ".");
        test("", "c*");
        test("a", ".*");
        test("a", "a.");
        test("a", "");
        test("a", ".");
        test("a", "ab*");
        test("a", "ab*a");
        test("aa", "aa");
        test("aa", "a*");
        test("aa", ".*");
        test("aa", ".");
        test("ab", ".*");
        test("ab", ".*");
        test("aaa", "aa*");
        test("aaa", "aa.a");
        test("aaa", "a.a");
        test("aaa", ".a");
        test("aaa", "a*a");
        test("aaa", "ab*a");
        test("aaa", "ab*ac*a");
        test("aaa", "ab*a*c*a");
        test("aaa", ".*");
        test("aab", "c*a*b");
        test("aaca", "ab*a*c*a");
        test("aaba", "ab*a*c*a");
        test("bbbba", ".*a*a");
        test("bcbbabab", ".*a*a");
    }
}
