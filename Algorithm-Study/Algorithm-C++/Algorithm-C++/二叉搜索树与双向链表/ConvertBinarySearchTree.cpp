//
//  ConvertBinarySearchTree.cpp
//  Algorithm-C++
//
//  Created by HelloAda on 2019/7/17.
//  Copyright © 2019 HelloAda. All rights reserved.
//

/*
 面试题36：二叉搜索树与双向链表
 题目：输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。要求
 不能创建任何新的结点，只能调整树中结点指针的指向。
 */
#include "ConvertBinarySearchTree.hpp"
#include "BinaryTreeNode.hpp"
#include <iostream>

namespace namespace_convertBinarySearchTree {

    
    void convertNode(BinaryTreeNode *pNode, BinaryTreeNode **pLastNodeInList) {
        // 递归跳出的条件
        if (pNode == nullptr) {
            return;
        }
        
        BinaryTreeNode *pCurrent = pNode;
        
        // 还有左子结点的话
        if (pCurrent->left != nullptr) {
            convertNode(pCurrent->left, pLastNodeInList);
        }
        
        pCurrent->left = *pLastNodeInList;
        if (*pLastNodeInList != nullptr) {
            (*pLastNodeInList)->right = pCurrent;
        }
        
        *pLastNodeInList = pCurrent;
        if (pCurrent->right != nullptr) {
            convertNode(pCurrent->right, pLastNodeInList);
        }
    }
    
    BinaryTreeNode* convert(BinaryTreeNode *pRootOfTree) {
        if (pRootOfTree == nullptr) {
            std::cout << "空链表" << std::endl;
            return nullptr;
        }
        BinaryTreeNode *pLastNodeInList = nullptr;
        convertNode(pRootOfTree, &pLastNodeInList);
        // 返回头结点
        BinaryTreeNode *pHeadOfList = pLastNodeInList;
        while (pHeadOfList != nullptr && pHeadOfList->left != nullptr) {
            pHeadOfList = pHeadOfList->left;
        }
        return pHeadOfList;
    }
    
    // ------ 测试代码 ------
    void test(BinaryTreeNode *pRoot) {
        std::cout << "测试开始" << std::endl;
        BinaryTreeNode *pNode = convert(pRoot);
        std::cout << "从左到右打印" << std::endl;
        while (pNode != nullptr) {
            std::cout << "结点值:" << pNode->value << std::endl;
            if (pNode->right == nullptr) {
                break;
            }
            pNode = pNode->right;
        }
        std::cout << "从右到左打印" << std::endl;
        while (pNode != nullptr) {
            std::cout << "结点值" << pNode->value << std::endl;
            if (pNode->left == nullptr) {
                break;
            }
            pNode = pNode->left;
        }
        
        std::cout << "测试结束" << std::endl;
        while (pNode != nullptr) {
            BinaryTreeNode *pNext = pNode->right;
            delete pNode;
            pNode = pNext;
        }
        
    }
    
    // 完全二叉树
    void test1() {
        BinaryTreeNode* pNode10 = createBinaryTreeNode(10);
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
        
    }
    
    // 只有一个结点的二叉树
    void test4() {
        BinaryTreeNode* pNode1 = createBinaryTreeNode(1);
        
        test(pNode1);
        
    }
    
    // 空链表
    void test5() {
        test(nullptr);
    }
    
    void convertBinarySearchTree() {
        test1();
        test2();
        test3();
        test4();
        test5();

    }
}
