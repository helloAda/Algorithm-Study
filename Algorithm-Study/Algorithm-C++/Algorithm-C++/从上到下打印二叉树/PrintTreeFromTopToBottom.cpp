//
//  PrintTreeFromTopToBottom.cpp
//  Algorithm-C++
//
//  Created by HelloAda on 2019/2/19.
//  Copyright © 2019 HelloAda. All rights reserved.
//

#include "PrintTreeFromTopToBottom.hpp"
#include <iostream>
#include <deque>
#include "BinaryTreeNode.hpp"

/*
 面试题32（一）：不分行从上往下打印二叉树
 题目：从上往下打印出二叉树的每个结点，同一层的结点按照从左到右的顺序打印。
 */

namespace namespace_printTreeFromTopToBottom {
    
    void printTreeFromTopToBottom(BinaryTreeNode *pRoot) {
        if (pRoot == nullptr) {
            std::cout << "空指针" << std::endl;
            return;
        }
        
        std::deque<BinaryTreeNode *> dequeTreeNode;
        // 将根结点加入队列后
        dequeTreeNode.push_back(pRoot);
        
        // 队列还有结点
        while (dequeTreeNode.size()) {
            // 取出队列前面的结点
            BinaryTreeNode *pNode = dequeTreeNode.front();
            // 移出队列
            dequeTreeNode.pop_front();
            std::cout << pNode->value <<std::endl;
            
            // 如果有子结点将它们加入队列后
            if (pNode->left) {
                dequeTreeNode.push_back(pNode->left);
            }
            if (pNode->right) {
                dequeTreeNode.push_back(pNode->right);
            }
        }
    }
    
    
    
    
    
    
    // --- 测试代码 ---
    void test(BinaryTreeNode *pRoot) {
        std::cout << "测试开始" << std::endl;
        printTreeFromTopToBottom(pRoot);
        std::cout << "测试结束" << std::endl;
    }
    
    // 满二叉树
    void test1() {
        BinaryTreeNode *pNode10 = createBinaryTreeNode(10);
        BinaryTreeNode* pNode6 = createBinaryTreeNode(6);
        BinaryTreeNode* pNode14 = createBinaryTreeNode(14);
        BinaryTreeNode* pNode4 = createBinaryTreeNode(4);
        BinaryTreeNode* pNode8 = createBinaryTreeNode(8);
        BinaryTreeNode* pNode12 = createBinaryTreeNode(12);
        BinaryTreeNode* pNode16 = createBinaryTreeNode(16);
        
        connectTreeNodes(pNode10, pNode6, pNode14);
        connectTreeNodes(pNode6, pNode4, pNode8);
        connectTreeNodes(pNode14, pNode12, pNode16);
        
        test(pNode10);
        
        destoryTree(pNode10);
    }
    
    // 只有左子结点的二叉树
    void test2() {
        BinaryTreeNode* pNode5 = createBinaryTreeNode(5);
        BinaryTreeNode* pNode4 = createBinaryTreeNode(4);
        BinaryTreeNode* pNode3 = createBinaryTreeNode(3);
        BinaryTreeNode* pNode2 = createBinaryTreeNode(2);
        BinaryTreeNode* pNode1 = createBinaryTreeNode(1);
        
        connectTreeNodes(pNode5, pNode4, nullptr);
        connectTreeNodes(pNode4, pNode3, nullptr);
        connectTreeNodes(pNode3, pNode2, nullptr);
        connectTreeNodes(pNode2, pNode1, nullptr);
        
        test(pNode5);
        
        destoryTree(pNode5);
    }
    
    // 只有右子结点的二叉树
    void test3() {
        BinaryTreeNode* pNode1 = createBinaryTreeNode(1);
        BinaryTreeNode* pNode2 = createBinaryTreeNode(2);
        BinaryTreeNode* pNode3 = createBinaryTreeNode(3);
        BinaryTreeNode* pNode4 = createBinaryTreeNode(4);
        BinaryTreeNode* pNode5 = createBinaryTreeNode(5);
        
        connectTreeNodes(pNode1, nullptr, pNode2);
        connectTreeNodes(pNode2, nullptr, pNode3);
        connectTreeNodes(pNode3, nullptr, pNode4);
        connectTreeNodes(pNode4, nullptr, pNode5);
        
        test(pNode1);
        
        destoryTree(pNode1);
    }
    
    // 树中只有一个结点
    void test4() {
        BinaryTreeNode* pNode1 = createBinaryTreeNode(1);
        test(pNode1);
        
        destoryTree(pNode1);
    }
    
    // 空指针
    void test5() {
        test(nullptr);
    }
    
    void printTreeFromTopToBottom() {
        test1();
        test2();
        test3();
        test4();
        test5();
    }
}
