//
//  SymmetricalBinaryTree.cpp
//  Algorithm-C++
//
//  Created by 黄铭达 on 2019/2/5.
//  Copyright © 2019 HelloAda. All rights reserved.
//

#include "SymmetricalBinaryTree.hpp"
#include "BinaryTreeNode.hpp"
#include <iostream>

/*
 面试题28：对称的二叉树
 题目：请实现一个函数，用来判断一棵二叉树是不是对称的。如果一棵二叉树和
 它的镜像一样，那么它是对称的。
 */

namespace namespace_symmetricalBinaryTree {
    
    
    bool isSymmetrical(BinaryTreeNode *pRoot1, BinaryTreeNode *pRoot2) {
        if (pRoot1 == nullptr && pRoot2 == nullptr) {
            return  true;
        }
        if (pRoot1 == nullptr || pRoot2 == nullptr) {
            return false;
        }
        if (pRoot1->value != pRoot2->value) {
            return false;
        }
        
        return isSymmetrical(pRoot1->left, pRoot2->right) && isSymmetrical(pRoot1->right, pRoot2->left);
    }
    
    
    // --- 测试代码 ---
    void test(BinaryTreeNode *pRoot){
        std::cout << "测试开始" << std::endl;
        if (isSymmetrical(pRoot, pRoot)) {
            std::cout << "对称的二叉树" << std::endl;
        } else {
            std::cout << "不对称的二叉树" << std::endl;
        }
        std::cout << "测试结束" << std::endl;
    }
    
    // 对称的二叉树
    void test1() {
        BinaryTreeNode *pNode8Root = createBinaryTreeNode(8);
        BinaryTreeNode *pNode6Left = createBinaryTreeNode(6);
        BinaryTreeNode *pNode6Right = createBinaryTreeNode(6);
        BinaryTreeNode *pNode5Left = createBinaryTreeNode(5);
        BinaryTreeNode *pNode7Right = createBinaryTreeNode(7);
        BinaryTreeNode *pNode7Left = createBinaryTreeNode(7);
        BinaryTreeNode *pNode5Right = createBinaryTreeNode(5);
        
        connectTreeNodes(pNode8Root, pNode6Left, pNode6Right);
        connectTreeNodes(pNode6Left, pNode5Left, pNode7Right);
        connectTreeNodes(pNode6Right, pNode7Left, pNode5Right);
        
        test(pNode8Root);
        
        destoryTree(pNode8Root);
        
    }
    
    // 结构对称 值不对称
    void test2() {
        BinaryTreeNode *pNode8Root = createBinaryTreeNode(8);
        BinaryTreeNode *pNode6Left = createBinaryTreeNode(6);
        BinaryTreeNode *pNode9Right = createBinaryTreeNode(9);
        BinaryTreeNode *pNode5Left = createBinaryTreeNode(5);
        BinaryTreeNode *pNode7Right = createBinaryTreeNode(7);
        BinaryTreeNode *pNode7Left = createBinaryTreeNode(7);
        BinaryTreeNode *pNode5Right = createBinaryTreeNode(5);
        
        connectTreeNodes(pNode8Root, pNode6Left, pNode9Right);
        connectTreeNodes(pNode6Left, pNode5Left, pNode7Right);
        connectTreeNodes(pNode9Right, pNode7Left, pNode5Right);
        
        test(pNode8Root);
        
        destoryTree(pNode8Root);
        
    }
    
    // 结构不对称
    void test3() {
        BinaryTreeNode *pNode8Root = createBinaryTreeNode(8);
        BinaryTreeNode *pNode6Left = createBinaryTreeNode(6);
        BinaryTreeNode *pNode6Right = createBinaryTreeNode(6);
        BinaryTreeNode *pNode5Left = createBinaryTreeNode(5);
        BinaryTreeNode *pNode7Right = createBinaryTreeNode(7);
        BinaryTreeNode *pNode7Left = createBinaryTreeNode(7);
        
        connectTreeNodes(pNode8Root, pNode6Left, pNode6Right);
        connectTreeNodes(pNode6Left, pNode5Left, pNode7Right);
        connectTreeNodes(pNode6Right, pNode7Left, nullptr);
        
        test(pNode8Root);
        
        destoryTree(pNode8Root);
    }
    
    // 子结点有nullptr 结构对称 值对
    void test4() {
        BinaryTreeNode* pNode5Root = createBinaryTreeNode(5);
        BinaryTreeNode* pNode3Left = createBinaryTreeNode(3);
        BinaryTreeNode* pNode3Right = createBinaryTreeNode(3);
        BinaryTreeNode* pNode4Left = createBinaryTreeNode(4);
        BinaryTreeNode* pNode4Right = createBinaryTreeNode(4);
        BinaryTreeNode* pNode2Left = createBinaryTreeNode(2);
        BinaryTreeNode* pNode2Right = createBinaryTreeNode(2);
        BinaryTreeNode* pNode1Left = createBinaryTreeNode(1);
        BinaryTreeNode* pNode1Right = createBinaryTreeNode(1);
        
        connectTreeNodes(pNode5Root, pNode3Left, pNode3Right);
        connectTreeNodes(pNode3Left, pNode4Left, nullptr);
        connectTreeNodes(pNode3Right, nullptr, pNode4Right);
        connectTreeNodes(pNode4Left, pNode2Left, nullptr);
        connectTreeNodes(pNode4Right, nullptr, pNode2Right);
        connectTreeNodes(pNode2Left, pNode1Left, nullptr);
        connectTreeNodes(pNode2Right, nullptr, pNode1Right);
        
        test(pNode5Root);
        
        destoryTree(pNode5Root);
    }
    
    // 子结点有nullptr 结构对称 值不对
    void test5() {
        BinaryTreeNode* pNode5Root = createBinaryTreeNode(5);
        BinaryTreeNode* pNode3Left = createBinaryTreeNode(3);
        BinaryTreeNode* pNode3Right = createBinaryTreeNode(3);
        BinaryTreeNode* pNode4Left = createBinaryTreeNode(4);
        BinaryTreeNode* pNode4Right = createBinaryTreeNode(4);
        BinaryTreeNode* pNode6Left = createBinaryTreeNode(6);
        BinaryTreeNode* pNode2Right = createBinaryTreeNode(2);
        BinaryTreeNode* pNode1Left = createBinaryTreeNode(1);
        BinaryTreeNode* pNode1Right = createBinaryTreeNode(1);
        
        connectTreeNodes(pNode5Root, pNode3Left, pNode3Right);
        connectTreeNodes(pNode3Left, pNode4Left, nullptr);
        connectTreeNodes(pNode3Right, nullptr, pNode4Right);
        connectTreeNodes(pNode4Left, pNode6Left, nullptr);
        connectTreeNodes(pNode4Right, nullptr, pNode2Right);
        connectTreeNodes(pNode6Left, pNode1Left, nullptr);
        connectTreeNodes(pNode2Right, nullptr, pNode1Right);
        
        test(pNode5Root);
        
        destoryTree(pNode5Root);
    }
    
    // 子结点有nullptr 结构不对称
    void test6() {
        BinaryTreeNode* pNode5Root = createBinaryTreeNode(5);
        BinaryTreeNode* pNode3Left = createBinaryTreeNode(3);
        BinaryTreeNode* pNode3Right = createBinaryTreeNode(3);
        BinaryTreeNode* pNode4Left = createBinaryTreeNode(4);
        BinaryTreeNode* pNode4Right = createBinaryTreeNode(4);
        BinaryTreeNode* pNode6Left = createBinaryTreeNode(6);
        BinaryTreeNode* pNode2Right = createBinaryTreeNode(2);
        BinaryTreeNode* pNode1Right = createBinaryTreeNode(1);
        
        connectTreeNodes(pNode5Root, pNode3Left, pNode3Right);
        connectTreeNodes(pNode3Left, pNode4Left, nullptr);
        connectTreeNodes(pNode3Right, nullptr, pNode4Right);
        connectTreeNodes(pNode4Left, pNode6Left, nullptr);
        connectTreeNodes(pNode4Right, nullptr, pNode2Right);
        connectTreeNodes(pNode6Left, nullptr, nullptr);
        connectTreeNodes(pNode2Right, nullptr, pNode1Right);
        
        test(pNode5Root);
        
        destoryTree(pNode5Root);
    }
    
    // 所有结点值相同 结构对称
    void test7() {
        BinaryTreeNode* pNode1 = createBinaryTreeNode(5);
        BinaryTreeNode* pNode21 = createBinaryTreeNode(5);
        BinaryTreeNode* pNode22 = createBinaryTreeNode(5);
        BinaryTreeNode* pNode31 = createBinaryTreeNode(5);
        BinaryTreeNode* pNode32 = createBinaryTreeNode(5);
        BinaryTreeNode* pNode41 = createBinaryTreeNode(5);
        BinaryTreeNode* pNode42 = createBinaryTreeNode(5);
        
        connectTreeNodes(pNode1, pNode21, pNode22);
        connectTreeNodes(pNode21, pNode31, nullptr);
        connectTreeNodes(pNode22, nullptr, pNode32);
        connectTreeNodes(pNode31, pNode41, nullptr);
        connectTreeNodes(pNode32, nullptr, pNode42);
        connectTreeNodes(pNode41, nullptr, nullptr);
        connectTreeNodes(pNode42, nullptr, nullptr);
        
        test(pNode1);
        
        destoryTree(pNode1);
    }
    
    // 所有结点值相同 结构不对称
    void test8() {
        BinaryTreeNode* pNode1 = createBinaryTreeNode(5);
        BinaryTreeNode* pNode21 = createBinaryTreeNode(5);
        BinaryTreeNode* pNode22 = createBinaryTreeNode(5);
        BinaryTreeNode* pNode31 = createBinaryTreeNode(5);
        BinaryTreeNode* pNode32 = createBinaryTreeNode(5);
        BinaryTreeNode* pNode41 = createBinaryTreeNode(5);
        BinaryTreeNode* pNode42 = createBinaryTreeNode(5);
        
        connectTreeNodes(pNode1, pNode21, pNode22);
        connectTreeNodes(pNode21, pNode31, nullptr);
        connectTreeNodes(pNode22, nullptr, pNode32);
        connectTreeNodes(pNode31, pNode41, nullptr);
        connectTreeNodes(pNode32, pNode42, nullptr);
        connectTreeNodes(pNode41, nullptr, nullptr);
        connectTreeNodes(pNode42, nullptr, nullptr);
        
        test(pNode1);
        
        destoryTree(pNode1);
    }
    
    // 只有一个结点
    void test9() {
        BinaryTreeNode *pNodeRoot = createBinaryTreeNode(1);
        test(pNodeRoot);
        destoryTree(pNodeRoot);
    }
    
    // 空指针
    void test10() {
        test(nullptr);
    }
    
    void symmetricalBinaryTree() {
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
