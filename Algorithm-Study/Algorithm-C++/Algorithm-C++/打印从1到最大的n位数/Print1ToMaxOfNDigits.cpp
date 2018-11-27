//
//  Print1ToMaxOfNDigits.cpp
//  Algorithm-C++
//
//  Created by HelloAda on 2018/11/23.
//  Copyright © 2018 HelloAda. All rights reserved.
//

#include "Print1ToMaxOfNDigits.hpp"
#include <memory>
#include <iostream>

namespace namespace_Print1ToMaxOfNDigits {
    
    // 共同的打印方法
    // 字符串number表示一个数字，数字有若干个0开头，打印出这个数字，并忽略开头的0
    void printNumber(char* number)
    {
        bool isBeginning0 = true;
        int nLength = (int)strlen(number);
        
        for (int i = 0; i < nLength; ++i)
        {
            // 是第一位并且不等于0则打印
            if (isBeginning0 && number[i] != '0')
                isBeginning0 = false;
        
            if (!isBeginning0)
            {
                printf("%c", number[i]);
            }
        }
        
    }
    
    // -------- 方法一 --------
    
    /**
     在number的基础上增加1,并判断是否最大值（最大值用溢出来来判断）

     @param number 表示一个数字
     @return 做加法如果溢出，就返回true
     */
    bool increment(char *number) {
        // 是否溢出了
        bool isOverFlow = false;
        // 是否进位
        int nTakeOver = 0;
        // 当前字符串数字的长度
        int nLength = (int)strlen(number);

        for (int i = nLength - 1; i >= 0; i--) {
            int nSum = number[i] - '0' + nTakeOver;
            if (i == nLength - 1) {
                nSum++;
            }
            if (nSum >= 10) {
                // 是在最高位进位的话 代表就是溢出了，这个时候代表已经到最大值
                if (i == 0) {
                    isOverFlow = true;
                } else {
                    // 不是在最高位进位，将这一位置为0，并且设置进位标记为1，进入下一次循环，将进位赋值给高位
                    nSum -= 10;
                    nTakeOver = 1;
                    number[i] = '0' + nSum;
                }
            } else {
                number[i] = '0' + nSum;
                break;
            }
        }
        
        return isOverFlow;
    }
    
    void print1ToMaxOfNDigits (int n) {
        if (n <= 0) {
            std::cout << "无效输入" << std::endl;
            return;
        }
        char *number = new char[n + 1];
        memset(number, '0', n);
        number[n] = '\0';
        
        while (!increment(number)) {
            printNumber(number);
        }
        
        delete [] number;
    }
    
    
    // -------- 方法二 --------
    
    void print1ToMaxOfNDigitsRecursively(char *number, int lenght, int index) {
        // 当前是最后一位了，输出这个数字 
        if (index == lenght - 1) {
            printNumber(number);
            return;
        }
        
        // 除了最高位的数字增加
        for (int i = 0; i < 10; i++) {
            number[index + 1] = i + '0';
            print1ToMaxOfNDigitsRecursively(number, lenght, index + 1);
        }
    }
    
    void print1ToMaxOfNDigits_2 (int n) {
        if (n <= 0) {
            std::cout << "无效的输入" << std::endl;
            return;
        }
        
        char *number = new char[n + 1];
        number[n] = '\0';
        
        // 最高位的数字增加 从0到9
        for (int i = 0; i < 10; i++) {
            number[0] = i + '0';
            print1ToMaxOfNDigitsRecursively(number, n, 0);
        }
        
        delete [] number;
    }
    
    
    
    // ----  测试  ----
    void test(int n) {
        std::cout << "测试开始" << std::endl;
//        print1ToMaxOfNDigits(n);
        print1ToMaxOfNDigits_2(n);
        std::cout << "测试结束" << std::endl;
    }
    
    void print1ToMaxOfNDigits () {
        test(1);
        test(2);
        test(3);
        test(0);
        test(-1);
    }
}
