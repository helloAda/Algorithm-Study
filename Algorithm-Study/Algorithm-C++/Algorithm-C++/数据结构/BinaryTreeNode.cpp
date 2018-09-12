//
//  BinaryTreeNode.cpp
//  Algorithm-C++
//
//  Created by HelloAda on 2018/9/12.
//  Copyright © 2018年 HelloAda. All rights reserved.
//

#include "BinaryTreeNode.hpp"
#include <iostream>

// 创建结点
BinaryTreeNode *createBinaryTreeNode(int value) {
    BinaryTreeNode *node = new BinaryTreeNode();
    node->value = value;
    node->left = nullptr;
    node->right = nullptr;
    return node;
}

// 连接结点
void connectTreeNodes(BinaryTreeNode *parent, BinaryTreeNode *left, BinaryTreeNode *right) {
    if (parent != nullptr) {
        parent->left = left;
        parent->right = right;
    }
}

// 打印结点
void printTreeNode(const BinaryTreeNode *node) {
    if (node != nullptr) {
        
        std::cout << "这个结点的值：" << node->value << std::endl;
        if (node->left != nullptr) {
            std::cout << "这个结点的左子结点的的值：" << node->left->value << std::endl;
        } else {
            std::cout << "这个结点没有左子结点" <<std::endl;
        }
        
        if (node->right != nullptr) {
            std::cout << "这个结点的右子结点的的值：" << node->right->value << std::endl;
        } else {
            std::cout << "这个结点没有右子结点" <<std::endl;
        }
        
    } else {
        std::cout << "这是空指针" << std::endl;
    }
}

// 打印二叉树
void printTree(const BinaryTreeNode *root) {
    printTreeNode(root);
    if (root != nullptr) {
        if (root->left != nullptr) {
            printTree(root->left);
        }
        if (root->right != nullptr) {
            printTree(root->right);
        }
    }
}

// 销毁二叉树
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
