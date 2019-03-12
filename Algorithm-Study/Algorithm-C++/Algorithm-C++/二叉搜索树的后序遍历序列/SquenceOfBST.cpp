//
//  SquenceOfBST.cpp
//  Algorithm-C++
//
//  Created by 黄铭达 on 2019/3/12.
//  Copyright © 2019 HelloAda. All rights reserved.
//

#include "SquenceOfBST.hpp"
#include <iostream>
#include "BinaryTreeNode.hpp"

/*
 面试题33：二叉搜索树的后序遍历序列
 题目：输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。
 如果是则返回true，否则返回false。假设输入的数组的任意两个数字都互不相同。
 */


namespace namespace_squenceOfBST {
    
    bool verifySquenceOfBST(int sequence[], int length) {
        if (sequence == nullptr || length <= 0) {
            return false;
        }
        // 后序遍历序列的最后一个值 是根结点
        int root = sequence[length - 1];
        
        // 在二叉搜索树中左子树的结点小于根结点
        int i = 0;
        for (; i < length - 1; i++) {
            if (sequence[i] > root) {
                break;
            }
        }
        
        // 在二叉搜索树中右子树的结点大于根结点
        int j = i;
        for (; j < length - 1; j++) {
            if (sequence[j] < root) {
                return false;
            }
        }
        
        // 判断左子树是不是二叉搜索树
        bool left = true;
        if (i > 0) {
            left = verifySquenceOfBST(sequence, i);
        }
        
        // 判断右子树是不是二叉搜索树
        bool right = true;
        if (i < length - 1) {
            right = verifySquenceOfBST(sequence + i, length - i - 1);
        }
        
        return (left && right);
    }
    
    // --- 测试代码 ---
    void test(int sequence[], int length) {
        std::cout << "测试开始" << std::endl;
        bool result = verifySquenceOfBST(sequence, length);
        if (result) {
            std::cout << "是二叉搜索树的后序遍历序列" << std::endl;
        } else {
            std::cout << "不是二叉搜索树的后序遍历序列" << std::endl;
        }
        std::cout << "测试结束" << std::endl;
    }
    
    // 满二叉树
    void test1() {
        int data[] = {4, 8, 6, 12, 16, 14, 10};
        test(data, sizeof(data)/sizeof(int));
    }
    
    // 一般二叉树
    void test2() {
        int data[] = {4, 6, 7, 5};
        test(data, sizeof(data)/sizeof(int));
    }
    
    // 只有左子结点的二叉树
    void test3() {
        int data[] = {1, 2, 3, 4, 5};
        test(data, sizeof(data)/sizeof(int));
    }
    
    // 只有右子结点的二叉树
    void test4() {
        int data[] = {5, 4, 3, 2, 1};
        test(data, sizeof(data)/sizeof(int));
    }
    
    // 只有一个结点
    void test5() {
        int data[] = {5};
        test(data, sizeof(data)/sizeof(int));
    }
    
    // 空指针
    void test6() {
        test(nullptr, 0);
    }
    
    // 错误的序列
    void test7() {
        int data[] = {7, 4, 6, 5};
        test(data, sizeof(data)/sizeof(int));
    }
    
    // 错误的序列
    void test8() {
        int data[] = {4, 6, 12, 8, 16, 14, 10};
        test(data, sizeof(data)/sizeof(int));
    }
    
    void squenceOfBST() {
        test1();
        test2();
        test3();
        test4();
        test5();
        test6();
        test7();
        test8();
    }
}
