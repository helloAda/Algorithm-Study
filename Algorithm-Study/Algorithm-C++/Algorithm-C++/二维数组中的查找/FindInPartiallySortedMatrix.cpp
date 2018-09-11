//
//  FindInPartiallySortedMatrix.cpp
//  Algorithm-C++
//
//  Created by HelloAda on 2018/9/11.
//  Copyright © 2018年 HelloAda. All rights reserved.
//

#include "FindInPartiallySortedMatrix.hpp"
#include <iostream>
/*
 面试题4：二维数组中的查找
 题目：在一个二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按
 照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个
 整数，判断数组中是否含有该整数。
 */

namespace namespace_findInPartiallySortedMatrix {
    
    /**
     查找二维数组中的数
     
     @param matrix 二维数组
     @param rows 二维数组的行数
     @param columns 二维数组的列数
     @param number 要查找的数
     */
    void find(int* matrix, int rows, int columns, int number) {
        if (matrix == nullptr || rows <= 0 || columns <= 0) {
            std::cout << "无效的数据" << std::endl;
            return;
        }
        
        int row = 0;
        int column = columns - 1;
        
        while (row < rows && column >= 0) {
            // 如果等于这个数
            if (matrix[row * columns + column] == number) {
                std::cout << "找到数：" << number << std::endl;
                return;
            } else if (matrix[row * columns + column] > number) {
                column--;
            } else {
                row++;
            }
        }
        std::cout << "数不存在" << std::endl;
    }
    
    // 是最大的数
    void test1() {
        int matrix[][4] = {{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};
        find((int *)matrix, 4, 4, 15);
    }
    
    // 是最小的数
    void test2() {
        int matrix[][4] = {{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};
        find((int *)matrix, 4, 4, 1);
    }
    
    // 数不存在
    void test3() {
        int matrix[][4] = {{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};
        find((int *)matrix, 4, 4, 18);
    }
    
    // 正常查找
    void test4() {
        int matrix[][4] = {{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};
        find((int *)matrix, 4, 4, 7);
    }
    
    // 空指针的情况
    void test5() {
        find(nullptr, 0, 0, 20);
    }
    
    void findInPartiallySortedMatrix() {
        test1();
        test2();
        test3();
        test4();
        test5();
    }
}




