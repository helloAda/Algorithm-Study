//
//  StringPathInMatrix.cpp
//  Algorithm-C++
//
//  Created by HelloAda on 2018/9/29.
//  Copyright © 2018年 HelloAda. All rights reserved.
//

#include "StringPathInMatrix.hpp"
#include <iostream>
/*
 面试题12：矩阵中的路径
 题目：请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有
 字符的路径。路径可以从矩阵中任意一格开始，每一步可以在矩阵中向左、右、
 上、下移动一格。如果一条路径经过了矩阵的某一格，那么该路径不能再次进入
 该格子。例如在下面的3×4的矩阵中包含一条字符串“bfce”的路径（路径中的字
 母用下划线标出）。但矩阵中不包含字符串“abfb”的路径，因为字符串的第一个
 字符b占据了矩阵中的第一行第二个格子之后，路径不能再次进入这个格子。
 */

namespace namespace_stringPathInMatrix {
    
    bool pathCheckCore(const char *matrix, int rows, int cols, int row, int col, const char *str, int &pathLength, bool *visited) {
        if (str[pathLength] == '\0') return true;
        
        bool hasPath = false;
        // 矩阵中的字符与字符串该位置的字符匹配，并且这个字符不在已经走过路径中
        if (row >= 0 && row < rows && col >= 0 && col < cols && matrix[row * cols + col] == str[pathLength] && !visited[row * cols + col]) {
            // 继续找下一个字符
            pathLength++;
            // 这个位置已经在路径中
            visited[row * cols + col] = true;
            
            // 只要有一个字符匹配先找到就先到该字符 顺序：左 上 右 下
            hasPath = pathCheckCore(matrix, rows, cols, row, col - 1,
                                  str, pathLength, visited)
            || pathCheckCore(matrix, rows, cols, row - 1, col,
                           str, pathLength, visited)
            || pathCheckCore(matrix, rows, cols, row, col + 1,
                           str, pathLength, visited)
            || pathCheckCore(matrix, rows, cols, row + 1, col,
                           str, pathLength, visited);
            
            // 如果当前的这个字符的下一个字符都不匹配字符串的下一个字符，就会退到上一个字符
            if (!hasPath) {
                pathLength--;
                visited[row * cols + col] = false;
            }
        }
        
        return hasPath;
    }
    
    /**
     检查矩阵中的字符串路径

     @param matrix 矩阵
     @param rows 行
     @param cols 列
     @param str 要查找的字符串
     */
    void pathCheck(const char *matrix, int rows, int cols, const char *str) {
        if (matrix == nullptr || rows <= 0 || cols <= 0 || str == nullptr) {
            std::cout << "无效数据" << std::endl;
        }
        
        // 存放bool值的矩阵 用于表示当前的路径
        bool *visited = new bool[rows * cols];
        memset(visited, 0, rows * cols);
        // 表示当前已经检查到的字符串长度
        int pathLength = 0;

        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                if (pathCheckCore(matrix, rows, cols, row, col, str, pathLength, visited)) {
                    std::cout << "找到匹配的字符路径:" << std::endl;
                    for (int i = 1; i <= rows * cols ; i++) {
                        if ( i % cols == 0) {
                            std::cout << visited[i - 1] << std::endl;
                        } else {
                            printf("%d\t",visited[i - 1]);
                        }
                    }
                    delete[] visited;
                    return;
                }
            }
        }
        
        std::cout << "没有找到匹配的字符路径" << std::endl;
        delete[] visited;
    }
    
    // ---- 测试 ----
    void test(const char *matrix, int rows, int cols, const char *str) {
        std::cout << "测试开始" << std::endl;
        pathCheck(matrix, rows, cols, str);
        std::cout << "测试结束" << std::endl;
    }
    
    // 多行多列 且存在路径
    void test1() {
        const char *matrix = "ABTGCFCSJDEH";
        const char *str = "BFCE";
        test(matrix, 3, 4, str);
    }
    
    // 多行多列 不存在路径
    void test2() {
        const char* matrix = "ABTGCFCSJDEH";
        const char* str = "ABFB";
        test(matrix, 3, 4, str);
    }
    
    // 单行 且存在路径
    void test3() {
        const char* matrix = "ABCD";
        const char* str = "AB";
        test(matrix, 1, 4, str);
    }
    
    // 单行 不存在路径
    void test4() {
        const char* matrix = "ABCD";
        const char* str = "AC";
        test(matrix, 1, 4, str);
    }
    
    // 单列 存在路径
    void test5() {
        const char* matrix = "ABCD";
        const char* str = "AB";
        test(matrix, 4, 1, str);
    }
    
    // 单列 不存在路径
    void test6() {
        const char* matrix = "ABCD";
        const char* str = "AC";
        test(matrix, 4, 1, str);
    }
    
    // 全部是一样的字符
    void test7() {
        const char* matrix = "AAAAAAAAAAAA";
        const char* str = "AAAAAA";
        test(matrix, 3, 4, str);
    }
    
    // 单独字符匹配
    void test8() {
        const char* matrix = "A";
        const char* str = "A";
        test(matrix, 1, 1, str);
    }
    
    // 单独字符不匹配
    void test9() {
        const char* matrix = "A";
        const char* str = "B";
        test(matrix, 1, 1, str);
    }
    
    // 空指针
    void test10() {
        test(nullptr, 0, 0, nullptr);
    }
    
    void stringPathInMatrix() {
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
    }
}
