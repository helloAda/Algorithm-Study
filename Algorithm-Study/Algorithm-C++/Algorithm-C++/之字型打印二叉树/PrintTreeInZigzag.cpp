//
//  PrintTreeInZigzag.cpp
//  Algorithm-C++
//
//  Created by HelloAda on 2019/2/26.
//  Copyright © 2019 HelloAda. All rights reserved.
//

#include "PrintTreeInZigzag.hpp"
#include <iostream>
#include <stack>
#include "BinaryTreeNode.hpp"


namespace namespace_printTreeInZigzag {
    
    void print(BinaryTreeNode *pRoot) {
        if (pRoot == nullptr) {
            std::cout << "空指针" << std::endl;
            return;
        }
        
        std::stack<BinaryTreeNode *> levels[2];
        
        int current = 0;
        int next = 1;
        
        levels[current].push(pRoot);
        // 任意一个栈不为空
        while (!levels[0].empty() || !levels[1].empty()) {
            
            BinaryTreeNode *pNode = levels[current].top();
            levels[current].pop();
            
            std::cout << pNode->value << "\t";
            
            if (current == 0) {
                if (pNode->left != nullptr) {
                    levels[next].push(pNode->left);
                }
                if (pNode->right != nullptr) {
                    levels[next].push(pNode->right);
                }
            } else {
                if (pNode->right != nullptr) {
                    levels[next].push(pNode->right);
                }
                if (pNode->left != nullptr) {
                    levels[next].push(pNode->left);
                }
            }
            
            if (levels[current].empty()) {
                std::cout << "" << std::endl;
                current = 1 - current;
                next = 1 - next;
            }
        }
    }
    
    // --- 测试代码 ---
    void test(BinaryTreeNode *pRoot) {
        std::cout << "测试开始" << std::endl;
        print(pRoot);
        std::cout << "测试结束" << std::endl;
    }
    
    
    // 满二叉树
    void test1() {
        BinaryTreeNode* pNode8 = createBinaryTreeNode(8);
        BinaryTreeNode* pNode6 = createBinaryTreeNode(6);
        BinaryTreeNode* pNode10 = createBinaryTreeNode(10);
        BinaryTreeNode* pNode5 = createBinaryTreeNode(5);
        BinaryTreeNode* pNode7 = createBinaryTreeNode(7);
        BinaryTreeNode* pNode9 = createBinaryTreeNode(9);
        BinaryTreeNode* pNode11 = createBinaryTreeNode(11);
        
        connectTreeNodes(pNode8, pNode6, pNode10);
        connectTreeNodes(pNode6, pNode5, pNode7);
        connectTreeNodes(pNode10, pNode9, pNode11);
        
        test(pNode8);
        
        destoryTree(pNode8);
    }
    
    // 只有左子结点二叉树
    void test2() {
        BinaryTreeNode* pNode5 = createBinaryTreeNode(5);
        BinaryTreeNode* pNode4 = createBinaryTreeNode(4);
        BinaryTreeNode* pNode3 = createBinaryTreeNode(3);
        BinaryTreeNode* pNode2 = createBinaryTreeNode(2);
        
        connectTreeNodes(pNode5, pNode4, nullptr);
        connectTreeNodes(pNode4, pNode3, nullptr);
        connectTreeNodes(pNode3, pNode2, nullptr);
        
        test(pNode5);
        
        destoryTree(pNode5);
    }
    
    // 只有右子结点的二叉树
    void test3() {
        BinaryTreeNode* pNode5 = createBinaryTreeNode(5);
        BinaryTreeNode* pNode4 = createBinaryTreeNode(4);
        BinaryTreeNode* pNode3 = createBinaryTreeNode(3);
        BinaryTreeNode* pNode2 = createBinaryTreeNode(2);
        
        connectTreeNodes(pNode5, nullptr, pNode4);
        connectTreeNodes(pNode4, nullptr, pNode3);
        connectTreeNodes(pNode3, nullptr, pNode2);
        
        test(pNode5);
        
        destoryTree(pNode5);
    }
    
    // 只有一个结点的二叉树
    void test4() {
        BinaryTreeNode* pNode5 = createBinaryTreeNode(5);
        
        test(pNode5);
        
        destoryTree(pNode5);
    }
    
    // 空指针
    void test5() {
        test(nullptr);
    }
    
    // 只有左结点或者只有右结点
    void test6() {
        BinaryTreeNode* pNode100 = createBinaryTreeNode(100);
        BinaryTreeNode* pNode50 = createBinaryTreeNode(50);
        BinaryTreeNode* pNode150 = createBinaryTreeNode(150);
        
        connectTreeNodes(pNode100, pNode50, nullptr);
        connectTreeNodes(pNode50, nullptr, pNode150);
        
        test(pNode100);
        
        destoryTree(pNode100);
    }
    
    void printTreeInZigzag() {
        test1();
        test2();
        test3();
        test4();
        test5();
        test6();
    }
}
