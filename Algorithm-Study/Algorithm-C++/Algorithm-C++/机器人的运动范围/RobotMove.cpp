//
//  RobotMove.cpp
//  Algorithm-C++
//
//  Created by HelloAda on 2018/9/30.
//  Copyright © 2018年 HelloAda. All rights reserved.
//

#include "RobotMove.hpp"
#include <iostream>

/*
 面试题13：机器人的运动范围
 题目：地上有一个m行n列的方格。一个机器人从坐标(0, 0)的格子开始移动，它
 每一次可以向左、右、上、下移动一格，但不能进入行坐标和列坐标的数位之和
 大于k的格子。例如，当k为18时，机器人能够进入方格(35, 37)，因为3+5+3+7=18。
 但它不能进入方格(35, 38)，因为3+5+3+8=19。请问该机器人能够到达多少个格子？
 */

namespace namespace_robotMove {
    // 数位和
    int getDigitSum(int number) {
        int sum = 0;
        while (number > 0) {
            sum += number % 10;
            number /= 10;
        }
        return sum;
    }
    
    // 检查是否允许进入这个位置
    bool check(int threshold, int rows, int cols, int row, int col, bool *visited) {
        if (row >= 0 && row < rows && col >= 0 && col < cols && getDigitSum(row) + getDigitSum(col) <= threshold && !visited[row * cols + col]) {
            return true;
        }
        return false;
    }
    
    
    int movingCountCore(int threshold, int rows, int cols, int row, int col, bool *visited) {
        int count = 0;
        if (check(threshold, rows, cols, row, col, visited)) {
            visited[row * cols + col] = true;
            // 再往4个方向继续查找能进入的位置
            count = 1 + movingCountCore(threshold, rows, cols,
                                        row - 1, col, visited)
            + movingCountCore(threshold, rows, cols,
                              row, col - 1, visited)
            + movingCountCore(threshold, rows, cols,
                              row + 1, col, visited)
            + movingCountCore(threshold, rows, cols,
                              row, col + 1, visited);
            return count;
        }
        return count;
    }
    
    
    /**
     机器人移动

     @param threshold 阈值
     @param rows 行
     @param cols 列
     */
    void movingCount(int threshold, int rows, int cols) {
        if (threshold < 0 || rows <= 0 || cols <= 0) {
            std::cout << "无效数据" << std::endl;
            return;
            
        }
        
        bool *visited = new bool[rows * cols];
        for (int i = 0; i < rows * cols; i++) {
            visited[i] = false;
        }
        
        int count = movingCountCore(threshold, rows, cols, 0, 0, visited);
        std::cout << "总共能够到达格子数：" << count << std::endl;
        delete [] visited;
    }
    
    // ----- 测试 -----
    void test(int threshold, int rows, int cols) {
        std::cout << "测试开始" << std::endl;
        movingCount(threshold, rows, cols);
        std::cout << "测试结束" << std::endl;
    }
    
    // 多行多列
    void test1() {
        test(5, 10, 10);
    }

    // 单行只能到达部分方格
    void test2() {
        test(10, 1, 100);
    }
    
    // 单行到达所有方格
    void test3() {
        test(10, 1, 10);
    }
    
    // 单列到达部分方格
    void test4() {
        test(15, 100, 1);
    }
    
    // 单列能到达所有方格
    void test5() {
        test(10, 10, 1);
    }
    
    // 只有单行列
    void test6() {
        test(10, 1, 1);
    }
    
    // 不能进入方格
    void test7() {
        test(-10, 10, 10);
    }
    
    void robotMove() {
        test1();
        test2();
        test3();
        test4();
        test5();
        test6();
        test7();
    }
}

