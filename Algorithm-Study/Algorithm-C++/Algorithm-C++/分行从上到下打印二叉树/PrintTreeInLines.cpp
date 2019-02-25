//
//  PrintTreeInLines.cpp
//  Algorithm-C++
//
//  Created by HelloAda on 2019/2/25.
//  Copyright © 2019 HelloAda. All rights reserved.
//


/*
 面试题32（二）：分行从上到下打印二叉树
 题目：从上到下按层打印二叉树，同一层的结点按从左到右的顺序打印，每一层
 打印到一行。
 */

#include "PrintTreeInLines.hpp"
#include <iostream>
#include <queue>
#include "BinaryTreeNode.hpp"


namespace namespace_printTreeInLines {
    
    
    void print(BinaryTreeNode *pRoot) {
        if (pRoot == nullptr) {
            std::cout << "空指针" << std::endl;
            return;
        }
        
        std::queue<BinaryTreeNode *> nodes;
        nodes.push(pRoot);
        // 下一行要打印的数量
        int nextLevel = 0;
        // 这一行还没打印的数量
        int toBePrinted = 1;
        // 队列中的结点不为空的话
        while (!nodes.empty()) {
            
            BinaryTreeNode *pNode = nodes.front();
            std::cout << pNode->value << "\t";
            
            // 将左子结点入队
            if (pNode->left != nullptr) {
                nodes.push(pNode->left);
                nextLevel++;
            }
            
            // 将右子结点入队
            if (pNode->right != nullptr) {
                nodes.push(pNode->right);
                nextLevel++;
            }
            
            nodes.pop();
            toBePrinted--;
            if (toBePrinted == 0) {
                std::cout<< "" <<std::endl;
                toBePrinted = nextLevel;
                nextLevel = 0;
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
    
    void printTreeInLines() {
        test1();
        test2();
        test3();
        test4();
        test5();

    }
}
