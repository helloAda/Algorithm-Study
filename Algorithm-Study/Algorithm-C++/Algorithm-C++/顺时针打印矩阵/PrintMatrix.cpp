//
//  PrintMatrix.cpp
//  Algorithm-C++
//
//  Created by HelloAda on 2019/2/14.
//  Copyright © 2019 HelloAda. All rights reserved.
//

/*
 面试题29：顺时针打印矩阵
 题目：输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字。
 */

#include "PrintMatrix.hpp"
#include <iostream>


namespace namespace_printMatrix {
    
    void printMatrixInCircle(int **numbers, int columns, int rows, int start) {
        int endX = columns - 1 - start;
        int endY = rows - 1 - start;
        
        // 从左到右打印一行
        for (int i = start; i <= endX; i++) {
            int number = numbers[start][i];
            std::cout << number << "\t";
        }
        
        // 从上到下打印一列
        if (start < endY) {
            for (int i = start + 1; i <= endY; i++) {
                int number = numbers[i][endX];
                std::cout << number << "\t";
            }
        }
        
        
        // 从右到左打印一行
        if (start < endX && start < endY) {
            for (int i = endX - 1; i >= start; i--) {
                int number = numbers[endY][i];
                std::cout << number << "\t";
            }
        }
        
        // 从下到上打印一行
        if (start < endX && start < endY - 1) {
            for (int i = endY - 1; i >= start + 1; i--) {
                int number = numbers[i][start];
                std::cout<< number << "\t";
            }
        }
        
    }
    
    void printMatrix(int ** numbers, int columns, int rows) {
        if (numbers == nullptr || columns <= 0 || rows <= 0) {
            return;
        }
        
        int start = 0;
        
        while (columns > start * 2 && rows > start * 2) {
            printMatrixInCircle(numbers, columns, rows, start);
            start ++;
        }
    }
    
    // --- 测试代码 ---
    void test(int columns, int rows) {
        std::cout << "测试开始" << std::endl;
        if (columns < 1 || rows < 1) {
            return;
        }
        // 构造数据
        int **numbers = new int*[rows];
        for (int i = 0; i < rows; i++) {
            numbers[i] = new int[columns];
            for (int j = 0; j < columns; j++) {
                numbers[i][j] = i * columns + j + 1;
            }
        }
        printMatrix(numbers, columns, rows);
        
        for (int i = 0; i < rows; i++) {
            delete [] (int *)numbers[i];
        }
        delete [] numbers;
        std::cout << "\n测试结束" << std::endl;
    }
    
    // 1 * 1
    void test1() {
        test(1, 1);
    }
    
    // 2 * 2
    void test2() {
        test(2, 2);
    }
    
    // 4 * 4
    void test3() {
        test(4, 4);
    }
    
    // 5 * 5
    void test4() {
        test(5, 5);
    }
    
    // 1 * n
    void test5() {
        test(1, 5);
    }
    
    // 2 * n
    void test6() {
        test(2, 5);
    }
    
    // 3 * n
    void test7() {
        test(3, 5);
    }
    
    // 4 * n
    void test8() {
        test(4, 5);
    }
    
    // n * 1
    void test9() {
        test(5, 1);
    }
    
    // n * 2
    void test10() {
        test(5, 2);
    }
    
    // n * 3
    void test11() {
        test(5, 3);
    }
    
    // n * 4
    void test12() {
        test(5, 4);
    }
    
    
    void printMatrix() {
        test1();
        test2();
        test3();
        test4();
        test5();
        test6();
        test7();
        test8();
        test9();
        test10();
        test11();
        test12();
    }
}
