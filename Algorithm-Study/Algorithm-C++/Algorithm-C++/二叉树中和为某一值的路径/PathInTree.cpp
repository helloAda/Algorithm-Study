//
//  PathInTree.cpp
//  Algorithm-C++
//
//  Created by 黄铭达 on 2019/3/18.
//  Copyright © 2019 HelloAda. All rights reserved.
//

#include "PathInTree.hpp"
#include <iostream>
#include "BinaryTreeNode.hpp"
#include <vector>

/*
 面试题34：二叉树中和为某一值的路径
 题目：输入一棵二叉树和一个整数，打印出二叉树中结点值的和为输入整数的所
 有路径。从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。
 */


namespace namespace_pathInTree {
    
    void findPath(BinaryTreeNode *pRoot, int expectedSum, std::vector<int> &path, int &currentSum, bool &isFound){
        currentSum += pRoot->value;
        path.push_back(pRoot->value);
        
        // 如果是叶结点，并且路径上结点的和等于输入的值 打印出来
        bool isLeaf = pRoot->left == nullptr && pRoot->right == nullptr;
        if (currentSum == expectedSum && isLeaf) {
            std::cout << "找到路径:";
            std::vector<int>::iterator iter = path.begin();
            for (; iter != path.end(); iter++) {
                std::cout << *iter << "\t";
            }
            isFound = true;
            std::cout << "" << std::endl;
        }
        
        // 如果不是叶结点，则遍历它的子结点
        if (pRoot->left != nullptr) {
            findPath(pRoot->left, expectedSum, path, currentSum, isFound);
        }
        if (pRoot->right != nullptr) {
            findPath(pRoot->right, expectedSum, path, currentSum, isFound);
        }
        
        // 在返回父结点之前，在路径上删除当前值
        currentSum -= pRoot->value;
        path.pop_back();
    }
    
    void findPath(BinaryTreeNode *pRoot, int expectedSum) {
        if (pRoot == nullptr) {
            std::cout << "空指针" << std::endl;
            return;
        }
        std::vector<int> path;
        int currentSum = 0;
        bool isFound = false;
        findPath(pRoot, expectedSum, path, currentSum, isFound);
        if (!isFound) {
            std::cout << "不存在路径" << std::endl;
        }
    }
    
    // --- 测试代码 ---
    void test(BinaryTreeNode *pRoot, int expectedSum) {
        std::cout << "测试开始" << std::endl;
        findPath(pRoot, expectedSum);
        std::cout << "测试结束" << std::endl;
    }
    
    // 有两条路径上的结点和为22
    void test1() {
        BinaryTreeNode* pNode10 = createBinaryTreeNode(10);
        BinaryTreeNode* pNode5 = createBinaryTreeNode(5);
        BinaryTreeNode* pNode12 = createBinaryTreeNode(12);
        BinaryTreeNode* pNode4 = createBinaryTreeNode(4);
        BinaryTreeNode* pNode7 = createBinaryTreeNode(7);
        
        connectTreeNodes(pNode10, pNode5, pNode12);
        connectTreeNodes(pNode5, pNode4, pNode7);
        
        test(pNode10, 22);
        
        destoryTree(pNode10);
    }
    
    // 没有路径上的结点和为15
    void test2() {
        BinaryTreeNode* pNode10 = createBinaryTreeNode(10);
        BinaryTreeNode* pNode5 = createBinaryTreeNode(5);
        BinaryTreeNode* pNode12 = createBinaryTreeNode(12);
        BinaryTreeNode* pNode4 = createBinaryTreeNode(4);
        BinaryTreeNode* pNode7 = createBinaryTreeNode(7);
        
        connectTreeNodes(pNode10, pNode5, pNode12);
        connectTreeNodes(pNode5, pNode4, pNode7);
        test(pNode10, 15);
        
        destoryTree(pNode10);
    }
    
    // 有一条路径上面的结点和为15
    void test3() {
        
        BinaryTreeNode* pNode5 = createBinaryTreeNode(5);
        BinaryTreeNode* pNode4 = createBinaryTreeNode(4);
        BinaryTreeNode* pNode3 = createBinaryTreeNode(3);
        BinaryTreeNode* pNode2 = createBinaryTreeNode(2);
        BinaryTreeNode* pNode1 = createBinaryTreeNode(1);
        
        connectTreeNodes(pNode5, pNode4, nullptr);
        connectTreeNodes(pNode4, pNode3, nullptr);
        connectTreeNodes(pNode3, pNode2, nullptr);
        connectTreeNodes(pNode2, pNode1, nullptr);
        
        test(pNode5, 15);
        
        destoryTree(pNode5);
    }
    
    // 没有路径上面的结点和为16
    void test4() {
        BinaryTreeNode* pNode1 = createBinaryTreeNode(1);
        BinaryTreeNode* pNode2 = createBinaryTreeNode(2);
        BinaryTreeNode* pNode3 = createBinaryTreeNode(3);
        BinaryTreeNode* pNode4 = createBinaryTreeNode(4);
        BinaryTreeNode* pNode5 = createBinaryTreeNode(5);
        
        connectTreeNodes(pNode1, nullptr, pNode2);
        connectTreeNodes(pNode2, nullptr, pNode3);
        connectTreeNodes(pNode3, nullptr, pNode4);
        connectTreeNodes(pNode4, nullptr, pNode5);
        
        test(pNode1, 16);
        
        destoryTree(pNode1);
    }
    
    // 树中只有一个结点
    void test5() {
        BinaryTreeNode* pNode1 = createBinaryTreeNode(1);
        
        test(pNode1, 1);
        destoryTree(pNode1);
    }
    
    // 空指针
    void test6() {
        test(nullptr, 0);
    }
    
    void pathInTree() {
        test1();
        test2();
        test3();
        test4();
        test5();
        test6();
    }
}
