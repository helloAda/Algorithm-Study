//
//  CuttingRope.cpp
//  Algorithm-C++
//
//  Created by HelloAda on 2018/10/19.
//  Copyright © 2018年 HelloAda. All rights reserved.
//

#include "CuttingRope.hpp"
#include <iostream>
#include <cmath>

/*
 面试题14：剪绳子
 题目：给你一根长度为n绳子，请把绳子剪成m段（m、n都是整数，n>1并且m≥1）。
 每段的绳子的长度记为k[0]、k[1]、……、k[m]。k[0]*k[1]*…*k[m]可能的最大乘
 积是多少？例如当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此
 时得到最大的乘积18。
 */

namespace namespace_cuttingRope {
    
    // ---- 动态规划 ----
    int maxProductAfterCutting_solution1(int length) {
        if (length < 2) {
            return 0;
        }
        if (length == 2) {
            return 1;
        }
        if (length == 3) {
            return 2;
        }
        
        int *products = new int[length + 1];
        products[0] = 0;
        products[1] = 1;
        products[2] = 2;
        products[3] = 3;
        
        int max = 0;
        for (int i = 4; i <= length; i++) {
            max = 0;
            // 遍历每一种可能 找出最大的保存起来
            for (int j = 1; j <= i / 2; j++) {
                int product = products[j] * products[i - j];
                if (max < product) {
                    max = product;
                }
                products[i] = max;
            }
        }
        
        max = products[length];
        delete [] products;
        
        return max;
    }
    
    
    
    // ---------- 贪婪算法 -----------
    int maxProductAfterCutting_solution2(int length) {
        if (length < 2) {
            return 0;
        }
        if (length == 2) {
            return 1;
        }
        if (length == 3) {
            return 2;
        }
        
        // 尽可能多的剪长度为3的绳子
        int timesOf3 = length / 3;
        // 当绳子剩下的长度为4的时候，不用再剪成3的了，剪成2*2比3*1好
        if (length - timesOf3 * 3 == 1) {
            timesOf3 --;
        }
        
        int timesOf2 = (length - timesOf3 * 3) / 2;
        
        return (int) (pow(3, timesOf3)) * (int) (pow(2, timesOf2));
    }
    
    
    // ------ 测试 -------
    void test(int length) {
        std::cout << "测试开始" << std::endl;
        int max;
//        max = maxProductAfterCutting_solution1(length);
      max = maxProductAfterCutting_solution2(length);
        std::cout << "最大乘积为" << max << std::endl;
        std::cout << "测试开始" << std::endl;
    }
    
    void cuttingRope(){
        // 边界值 测定
        test(0);
        test(1);
        test(2);
        test(3);
        test(4);
        test(5);
        
        // 效率测试
        test(10);
        test(50);
    }
}


