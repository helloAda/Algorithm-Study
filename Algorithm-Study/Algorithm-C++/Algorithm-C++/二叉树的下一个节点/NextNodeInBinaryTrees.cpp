//
//  NextNodeInBinaryTrees.cpp
//  Algorithm-C++
//
//  Created by HelloAda on 2018/9/12.
//  Copyright © 2018年 HelloAda. All rights reserved.
//

#include "NextNodeInBinaryTrees.hpp"
#include <iostream>
/*
 面试题8：二叉树的下一个结点
 题目：给定一棵二叉树和其中的一个结点，如何找出中序遍历顺序的下一个结点？
 树中的结点除了有两个分别指向左右子结点的指针以外，还有一个指向父结点的指针。
 */

namespace namespace_nextNodeInBinaryTrees {
    
    // ------ 辅助代码 -------
    struct BinaryTreeNode {
        int value;
        BinaryTreeNode *left;
        BinaryTreeNode *right;
        BinaryTreeNode *parent;
    };
    
    BinaryTreeNode *createBinaryTreeNode(int value) {
        BinaryTreeNode *node = new BinaryTreeNode();
        node->value = value;
        node->left = nullptr;
        node->right = nullptr;
        node->parent = nullptr;
        return node;
    }
    
    void connectTreeNodes(BinaryTreeNode *parent, BinaryTreeNode* left, BinaryTreeNode* right) {
        if (parent != nullptr) {
            parent->left = left;
            parent->right = right;
            
            if (left != nullptr) {
                left->parent = parent;
            }
            if (right != nullptr) {
                right->parent = parent;
            }
        }
    }
    
    void printTreeNode(BinaryTreeNode *node) {
        if (node != nullptr) {
            std::cout << "该节点的值：" << node->value << std::endl;
            
            if (node->left != nullptr) {
                std::cout << "该节点的左子节点：" << node->left->value << std::endl;
            } else {
                std::cout << "该节点没有左子节点" << std::endl;
            }
            
            if (node->right != nullptr) {
                std::cout << "该节点的右子节点：" << node->right->value << std::endl;
            } else {
                std::cout << "该节点没有右子节点" << std::endl;
            }
        } else {
            std::cout << "这是一个空指针" << std::endl;
        }
    }
    
    void printTree(BinaryTreeNode *root) {
        printTreeNode(root);
        if (root != nullptr) {
            if (root->left != nullptr) {
                printTreeNode(root->left);
            }
            if (root->right != nullptr) {
                printTreeNode(root->right);
            }
        }
    }
    
    void destoryTree(BinaryTreeNode *root) {
        if (root != nullptr) {
            BinaryTreeNode *left = root->left;
            BinaryTreeNode *right = root->right;
            
            delete root;
            root = nullptr;
            
            destoryTree(left);
            destoryTree(right);
        }
    }
    
    
    // ------ 实现 ------
    void getNext(BinaryTreeNode *node) {
        if (node == nullptr) {
            std::cout << "这是一个空指针，没有下一节点" << std::endl;
            return ;
        }
        
        BinaryTreeNode *next = nullptr;
        // 有右子节点 就要一直找到右子节点的最左子节点
        if (node->right != nullptr) {
            BinaryTreeNode *right = node->right;
            while (right->left != nullptr) {
                right = right->left;
            }
            next = right;
        }
        // 如果没有右子节点
        else if (node->parent != nullptr) {
            
            BinaryTreeNode *current = node;
            BinaryTreeNode *parent = node->parent;
            // 如果这个节点是父节点的右子节点 就要一直往上找
            while (parent != nullptr && current == parent->right) {
                current = parent;
                parent = parent->parent;
            }
            
            next = node->parent;
            
        }
        
        if (next != nullptr) {
            std::cout << "这个节点的中序遍历的下一节点是：" << next->value << std::endl;
        } else {
            std::cout << "这个节点的中序遍历没有下一节点了" << std::endl;
        }
    }
    
    // ----- 测试 -----
    void test(BinaryTreeNode *node) {
        std::cout << "==== 测试开始 ====" << std::endl;
        getNext(node);
        std::cout << "==== 测试结束 ====" << std::endl;
    }
    
    // 完全二叉树
    void test1() {
        BinaryTreeNode* node8 = createBinaryTreeNode(8);
        BinaryTreeNode* node6 = createBinaryTreeNode(6);
        BinaryTreeNode* node10 = createBinaryTreeNode(10);
        BinaryTreeNode* node5 = createBinaryTreeNode(5);
        BinaryTreeNode* node7 = createBinaryTreeNode(7);
        BinaryTreeNode* node9 = createBinaryTreeNode(9);
        BinaryTreeNode* node11 = createBinaryTreeNode(11);
        
        connectTreeNodes(node8, node6, node10);
        connectTreeNodes(node6, node5, node7);
        connectTreeNodes(node10, node9, node11);
        
        test(node8);
        test(node6);
        test(node10);
        test(node5);
        test(node7);
    }
    
    // 一般的二叉树
    void test2() {
        BinaryTreeNode* node8 = createBinaryTreeNode(8);
        BinaryTreeNode* node6 = createBinaryTreeNode(6);
        BinaryTreeNode* node10 = createBinaryTreeNode(10);
        BinaryTreeNode* node7 = createBinaryTreeNode(7);
        BinaryTreeNode* node9 = createBinaryTreeNode(9);
        
        connectTreeNodes(node8, node6, node10);
        connectTreeNodes(node6, nullptr, node7);
        connectTreeNodes(node10, node9, nullptr);
        
        test(node6);
        test(node10);
    }
    
    // 只有右子节点
    void test3() {
        BinaryTreeNode* node2 = createBinaryTreeNode(2);
        BinaryTreeNode* node3 = createBinaryTreeNode(3);
        BinaryTreeNode* node4 = createBinaryTreeNode(4);
        BinaryTreeNode* node5 = createBinaryTreeNode(5);
        BinaryTreeNode* node6 = createBinaryTreeNode(6);
        
        connectTreeNodes(node2, nullptr, node3);
        connectTreeNodes(node3, nullptr, node4);
        connectTreeNodes(node4, nullptr, node5);
        connectTreeNodes(node5, nullptr, node6);
        
        test(node2);
        test(node6);
    }
    
    // 只有左子节点
    void test4() {
        BinaryTreeNode* node2 = createBinaryTreeNode(2);
        BinaryTreeNode* node3 = createBinaryTreeNode(3);
        BinaryTreeNode* node4 = createBinaryTreeNode(4);
        BinaryTreeNode* node5 = createBinaryTreeNode(5);
        BinaryTreeNode* node6 = createBinaryTreeNode(6);
        
        connectTreeNodes(node2, node3, nullptr);
        connectTreeNodes(node3, node4, nullptr);
        connectTreeNodes(node4, node5, nullptr);
        connectTreeNodes(node5, node6, nullptr);
        
        test(node2);
        test(node6);
    }
    
    // 空指针
    void test5() {
        test(nullptr);
    }
    
    void nextNodeInBinaryTrees() {
        test1();
        test2();
        test3();
        test4();
        test5();
    }
    
}


