//
//  ConstructBinaryTree.cpp
//  Algorithm-C++
//
//  Created by HelloAda on 2018/9/12.
//  Copyright © 2018年 HelloAda. All rights reserved.
//

#include "ConstructBinaryTree.hpp"
#include "BinaryTreeNode.hpp"
#include <iostream>
#include <cstdio>
/*
 面试题7：重建二叉树
 题目：输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。假设输
 入的前序遍历和中序遍历的结果中都不含重复的数字。
 */

namespace namespace_constructBinaryTree {
    
    
    /**
     重建二叉树处理逻辑

     @param startPreorder 前序开始
     @param endPreorder 前序结束
     @param startInorder 中序开始
     @param endInorder 中序结束
     @return 二叉树
     */
    BinaryTreeNode *constructCore(int *startPreorder, int *endPreorder, int *startInorder, int *endInorder) {
        // 根节点
        int rootValue = startPreorder[0];
        BinaryTreeNode *root = new BinaryTreeNode();
        root->value = rootValue;
        root->left = nullptr;
        root->right = nullptr;
        
        if (startPreorder == endPreorder) {
            if (startInorder == endInorder && *startPreorder == *startInorder) {
                return root;
            } else {
                throw std::exception();
            }
        }
        
        // 在中序遍历中找到根节点的值
        int *rootInrorder = startInorder;
        while (rootInrorder <= endInorder && *rootInrorder != rootValue) {
            rootInrorder++;
        }
        
        // 如果没找到对应的值，代表是错误的序列
        if (rootInrorder == endInorder && *rootInrorder != rootValue) {
            throw std::exception();
        }

        int leftlength = (int)(rootInrorder - startInorder);
        int *leftPreorderEnd = startPreorder + leftlength;
        
        // 如果还有左子节点 构建左子树
        if (leftlength > 0) {
            root->left = constructCore(startPreorder + 1, leftPreorderEnd, startInorder, rootInrorder - 1);
        }
        
        // 如果还有右子节点 构建右子树
        if (leftlength < endInorder - startInorder) {
            root->right = constructCore(leftPreorderEnd + 1, endPreorder, rootInrorder + 1, endInorder);
        }
        return root;
    }
    /**
     重建二叉树

     @param preorder 前序序列
     @param inorder 中序序列
     @param length 序列长度
     */
    void construct(int *preorder, int *inorder, int length) {
        if (preorder == nullptr || inorder == nullptr || length <= 0) {
            std::cout << "无效的序列" << std::endl;
            return;
        }
        
        try {
           BinaryTreeNode *root = constructCore(preorder, preorder + length - 1, inorder, inorder + length - 1);
            printTree(root);
            
            destoryTree(root);
        } catch (std::exception &exception) {
            std::cout << "序列不匹配，不能构建二叉树" << std::endl;
        }
    }
    
    
    
    // ---- 测试 -----
    
    void test(int *preorder, int *inorder, int length) {
        std::cout << "==== 测试开始 ====" << std::endl;
        construct(preorder, inorder, length);
        std::cout << "==== 测试结束 ====" << std::endl;
    }
    // 普通二叉树
    void test1() {
        const int length = 8;
        int preorder[length] = {1, 2, 4, 7, 3, 5, 6, 8};
        int inorder[length] = {4, 7, 2, 1, 5, 3, 8, 6};
        test(preorder, inorder, length);
    }
    
    // 完全二叉树
    void test2() {
        const int length = 7;
        int preorder[length] = {1, 2, 4, 5, 3, 6, 7};
        int inorder[length] = {4, 2, 5, 1, 6, 3, 7};
        test(preorder, inorder, length);
    }
    
    // 只有左子节点
    void test3() {
        const int length = 5;
        int preorder[length] = {1, 2, 3, 4, 5};
        int inorder[length] = {5, 4, 3, 2, 1};
        test(preorder, inorder, length);

    }
    
    // 只有右子节点
    void test4() {
        const int length = 5;
        int preorder[length] = {1, 2, 3, 4, 5};
        int inorder[length] = {1, 2, 3, 4, 5};
        test(preorder, inorder, length);

    }
    
    // 只有根节点
    void test5() {
        const int length = 1;
        int preorder[length] = {1};
        int inorder[length] = {1};
        test(preorder, inorder, length);

    }
    
    // 不匹配的序列
    void test6 () {
        const int length = 7;
        int preorder[length] = {1, 2, 4, 5, 3, 6, 7};
        int inorder[length] = {4, 2, 8, 1, 6, 3, 7};
        test(preorder, inorder, length);

    }
    // 空指针
    void test7() {
        test(nullptr, nullptr, 0);

    }
    
    void constructBinaryTree() {
        test1();
        test2();
        test3();
        test4();
        test5();
        test6();
        test7();
    }
}
