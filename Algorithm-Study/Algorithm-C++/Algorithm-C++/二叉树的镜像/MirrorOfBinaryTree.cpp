//
//  MirrorOfBinaryTree.cpp
//  Algorithm-C++
//
//  Created by 黄铭达 on 2019/1/30.
//  Copyright © 2019 HelloAda. All rights reserved.
//

#include "MirrorOfBinaryTree.hpp"
#include "BinaryTreeNode.hpp"
#include <iostream>
#include <stack>
/*
 面试题27：二叉树的镜像
 题目：请完成一个函数，输入一个二叉树，该函数输出它的镜像。
 */
namespace namespace_mirrorOfBinaryTree {
    
    
    // 递归实现
    void mirrorRecursively(BinaryTreeNode *pNode) {
        if (pNode == nullptr || (pNode->left == nullptr && pNode->right)) {
            return;
        }
        
        // 交换左右结点
        BinaryTreeNode *pTemp = pNode->left;
        pNode->left = pNode->right;
        pNode->right = pTemp;
        
        if (pNode->left) {
            mirrorRecursively(pNode->left);
        }
        if (pNode->right) {
            mirrorRecursively(pNode->right);
        }
    }
    
    
    // 栈实现
    void mirrorIteratively(BinaryTreeNode *pNode) {
        if (pNode == nullptr) {
            return;
        }
        
        std::stack<BinaryTreeNode *> stackTreeNode;
        stackTreeNode.push(pNode);
        
        while (stackTreeNode.size() > 0) {
            
            BinaryTreeNode *pNode = stackTreeNode.top();
            stackTreeNode.pop();
            
            BinaryTreeNode *pTemp = pNode->left;
            pNode->left = pNode->right;
            pNode->right = pTemp;
            
            if (pNode->left) {
                stackTreeNode.push(pNode->left);
            }
            if (pNode->right) {
                stackTreeNode.push(pNode->right);
            }
            
        }
        
    }
    
    
    
    // --- 测试代码 ---
    void test(BinaryTreeNode *pNode) {
        std::cout << "测试开始" << std::endl;
        std::cout << "初始二叉树" << std::endl;
        printTree(pNode);
        mirrorRecursively(pNode);
        std::cout << "递归实现后" << std::endl;
        printTree(pNode);
        mirrorIteratively(pNode);
        std::cout << "栈实现后" << std::endl;
        printTree(pNode);
        std::cout << "测试结束" << std::endl;
    }
    
    // 完全二叉树
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
    
    // 都只有左子结点
    void test2() {
        BinaryTreeNode* pNode8 = createBinaryTreeNode(8);
        BinaryTreeNode* pNode7 = createBinaryTreeNode(7);
        BinaryTreeNode* pNode6 = createBinaryTreeNode(6);
        BinaryTreeNode* pNode5 = createBinaryTreeNode(5);
        BinaryTreeNode* pNode4 = createBinaryTreeNode(4);
        
        connectTreeNodes(pNode8, pNode7, nullptr);
        connectTreeNodes(pNode7, pNode6, nullptr);
        connectTreeNodes(pNode6, pNode5, nullptr);
        connectTreeNodes(pNode5, pNode4, nullptr);
        
        test(pNode8);
        
        destoryTree(pNode8);
    }
    
    // 都只有右子结点
    void test3() {
        BinaryTreeNode* pNode8 = createBinaryTreeNode(8);
        BinaryTreeNode* pNode7 = createBinaryTreeNode(7);
        BinaryTreeNode* pNode6 = createBinaryTreeNode(6);
        BinaryTreeNode* pNode5 = createBinaryTreeNode(5);
        BinaryTreeNode* pNode4 = createBinaryTreeNode(4);
        
        connectTreeNodes(pNode8, nullptr, pNode7);
        connectTreeNodes(pNode7, nullptr, pNode6);
        connectTreeNodes(pNode6, nullptr, pNode5);
        connectTreeNodes(pNode5, nullptr, pNode4);
        
        test(pNode8);
        
        destoryTree(pNode8);
    }
    
    //  只有一个结点
    void test4() {
        BinaryTreeNode *pNode8 = createBinaryTreeNode(8);
        
        test(pNode8);
        
        destoryTree(pNode8);
    }
    
    // 空指针
    void test5() {
        BinaryTreeNode *pNode = nullptr;
        test(pNode);
        
        destoryTree(pNode);
    }
    
    void mirrorOfBinaryTree () {
        test1();
        test2();
        test3();
        test4();
        test5();

    }
}
