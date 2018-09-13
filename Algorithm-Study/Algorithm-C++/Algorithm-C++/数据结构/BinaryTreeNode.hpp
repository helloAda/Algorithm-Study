//
//  BinaryTreeNode.hpp
//  Algorithm-C++
//
//  Created by HelloAda on 2018/9/12.
//  Copyright © 2018年 HelloAda. All rights reserved.
//

#ifndef BinaryTreeNode_hpp
#define BinaryTreeNode_hpp

#include <stdio.h>
struct BinaryTreeNode {
    int value;
    BinaryTreeNode *left;
    BinaryTreeNode *right;
};

// 创建节点
BinaryTreeNode *createBinaryTreeNode(int value);

// 连接节点
void connectTreeNodes(BinaryTreeNode *parent, BinaryTreeNode *left, BinaryTreeNode *right);

// 打印节点
void printTreeNode(const BinaryTreeNode *node);

// 打印二叉树
void printTree(const BinaryTreeNode *root);

// 销毁二叉树
void destoryTree(BinaryTreeNode *root);

#endif /* BinaryTreeNode_hpp */
