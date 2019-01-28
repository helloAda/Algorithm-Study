//
//  SubstructureInTree.cpp
//  Algorithm-C++
//
//  Created by HelloAda on 2019/1/5.
//  Copyright © 2019 HelloAda. All rights reserved.
//

#include "SubstructureInTree.hpp"
#include "BinaryTreeNode.hpp"
#include <iostream>

/*
 面试题26：树的子结构
 题目：输入两棵二叉树A和B，判断B是不是A的子结构。
*/


namespace namespace_substructureInTree {
    
    bool doesTreeAHaveTreeB(BinaryTreeNode *pRootA, BinaryTreeNode *pRootB) {
        // 如果B树已经没有结点，则代表满足条件
        if (pRootB == nullptr) {
            return true;
        }
        // 如果B树还有结点 A树已经没有节点了，则代表不满足条件
        if (pRootA == nullptr) {
            return false;
        }
        // 如果两棵树都还有节点 但是值不想等 也不满足条件
        if (pRootA->value != pRootB->value) {
            return false;
        }
        // 只有当两个相等Root结点 的左子树和又子树都想等才返回满足条件
        return doesTreeAHaveTreeB(pRootA->left, pRootB->left) && doesTreeAHaveTreeB(pRootA->right, pRootB->right);
        
    }
    
    bool hasSubTree(BinaryTreeNode *pRootA, BinaryTreeNode *pRootB) {
        bool result = false;
        if (pRootA != nullptr && pRootB != nullptr) {
            // 根结点值想等，可以去寻找子结构
            if (pRootA->value == pRootB->value) {
                result = doesTreeAHaveTreeB(pRootA, pRootB);
            }
            // 上一个根结点不满足条件 去左子树找
            if (!result) {
                result = hasSubTree(pRootA->left, pRootB);
            }
            // 左子树 不满足 继续在右子树找
            if (!result) {
                result = hasSubTree(pRootA->right, pRootB);
            }
        }
        return result;
    }
    

    
    // --- 测试代码 ---
    void test(BinaryTreeNode *pRootA, BinaryTreeNode *pRootB) {
        std::cout << "测试开始" << std::endl;
        bool isSub = hasSubTree(pRootA, pRootB);
        if (isSub) {
            std::cout << "B是A的子结构" << std::endl;
        } else {
            std::cout << "B不是A的子结构" << std::endl;
        }
        std::cout << "测试结束" << std::endl;
    }
    
    
    // 树中结点含有分叉，树B是树A的子结构
    void test1() {
        BinaryTreeNode *pNodeA1 = createBinaryTreeNode(8);
        BinaryTreeNode *pNodeA2 = createBinaryTreeNode(8);
        BinaryTreeNode *pNodeA3 = createBinaryTreeNode(7);
        BinaryTreeNode *pNodeA4 = createBinaryTreeNode(9);
        BinaryTreeNode *pNodeA5 = createBinaryTreeNode(2);
        BinaryTreeNode *pNodeA6 = createBinaryTreeNode(4);
        BinaryTreeNode *pNodeA7 = createBinaryTreeNode(7);
        
        connectTreeNodes(pNodeA1, pNodeA2, pNodeA3);
        connectTreeNodes(pNodeA2, pNodeA4, pNodeA5);
        connectTreeNodes(pNodeA5, pNodeA6, pNodeA7);
        
        BinaryTreeNode *pNodeB1 = createBinaryTreeNode(8);
        BinaryTreeNode *pNodeB2 = createBinaryTreeNode(9);
        BinaryTreeNode *pNodeB3 = createBinaryTreeNode(2);
        
        connectTreeNodes(pNodeB1, pNodeB2, pNodeB3);
        
        test(pNodeA1, pNodeB1);
        
        destoryTree(pNodeA1);
        destoryTree(pNodeB1);
    }
    
    // 树中结点有分叉，树B不是树A的子结构
    void test2() {
        BinaryTreeNode *pNodeA1 = createBinaryTreeNode(8);
        BinaryTreeNode *pNodeA2 = createBinaryTreeNode(8);
        BinaryTreeNode *pNodeA3 = createBinaryTreeNode(7);
        BinaryTreeNode *pNodeA4 = createBinaryTreeNode(9);
        BinaryTreeNode *pNodeA5 = createBinaryTreeNode(3);
        BinaryTreeNode *pNodeA6 = createBinaryTreeNode(4);
        BinaryTreeNode *pNodeA7 = createBinaryTreeNode(7);
        
        connectTreeNodes(pNodeA1, pNodeA2, pNodeA3);
        connectTreeNodes(pNodeA2, pNodeA4, pNodeA5);
        connectTreeNodes(pNodeA5, pNodeA6, pNodeA7);
        
        BinaryTreeNode *pNodeB1 = createBinaryTreeNode(8);
        BinaryTreeNode *pNodeB2 = createBinaryTreeNode(9);
        BinaryTreeNode *pNodeB3 = createBinaryTreeNode(2);
        
        connectTreeNodes(pNodeB1, pNodeB2, pNodeB3);
        
        test(pNodeA1, pNodeB1);
        
        destoryTree(pNodeA1);
        destoryTree(pNodeB1);
    }
    
    // 树只有左结点，树B是树A的子结构
    void test3() {
        BinaryTreeNode* pNodeA1 = createBinaryTreeNode(8);
        BinaryTreeNode* pNodeA2 = createBinaryTreeNode(8);
        BinaryTreeNode* pNodeA3 = createBinaryTreeNode(9);
        BinaryTreeNode* pNodeA4 = createBinaryTreeNode(2);
        BinaryTreeNode* pNodeA5 = createBinaryTreeNode(5);
        
        connectTreeNodes(pNodeA1, pNodeA2, nullptr);
        connectTreeNodes(pNodeA2, pNodeA3, nullptr);
        connectTreeNodes(pNodeA3, pNodeA4, nullptr);
        connectTreeNodes(pNodeA4, pNodeA5, nullptr);
        
        BinaryTreeNode* pNodeB1 = createBinaryTreeNode(8);
        BinaryTreeNode* pNodeB2 = createBinaryTreeNode(9);
        BinaryTreeNode* pNodeB3 = createBinaryTreeNode(2);
        
        connectTreeNodes(pNodeB1, pNodeB2, nullptr);
        connectTreeNodes(pNodeB2, pNodeB3, nullptr);
        
        test(pNodeA1, pNodeB1);
        
        destoryTree(pNodeA1);
        destoryTree(pNodeB1);
    }
    
    // 树只有左结点，树B不是树A的子结构
    void test4() {
        BinaryTreeNode* pNodeA1 = createBinaryTreeNode(8);
        BinaryTreeNode* pNodeA2 = createBinaryTreeNode(8);
        BinaryTreeNode* pNodeA3 = createBinaryTreeNode(9);
        BinaryTreeNode* pNodeA4 = createBinaryTreeNode(3);
        BinaryTreeNode* pNodeA5 = createBinaryTreeNode(5);
        
        connectTreeNodes(pNodeA1, pNodeA2, nullptr);
        connectTreeNodes(pNodeA2, pNodeA3, nullptr);
        connectTreeNodes(pNodeA3, pNodeA4, nullptr);
        connectTreeNodes(pNodeA4, pNodeA5, nullptr);
        
        BinaryTreeNode* pNodeB1 = createBinaryTreeNode(8);
        BinaryTreeNode* pNodeB2 = createBinaryTreeNode(9);
        BinaryTreeNode* pNodeB3 = createBinaryTreeNode(2);
        
        connectTreeNodes(pNodeB1, pNodeB2, nullptr);
        connectTreeNodes(pNodeB2, pNodeB3, nullptr);
        
        test(pNodeA1, pNodeB1);
        
        destoryTree(pNodeA1);
        destoryTree(pNodeB1);
    }
    
    // 树只有右结点，树B是树A的子结构
    void test5() {
        BinaryTreeNode* pNodeA1 = createBinaryTreeNode(8);
        BinaryTreeNode* pNodeA2 = createBinaryTreeNode(8);
        BinaryTreeNode* pNodeA3 = createBinaryTreeNode(9);
        BinaryTreeNode* pNodeA4 = createBinaryTreeNode(2);
        BinaryTreeNode* pNodeA5 = createBinaryTreeNode(5);
        
        connectTreeNodes(pNodeA1, nullptr, pNodeA2);
        connectTreeNodes(pNodeA2, nullptr, pNodeA3);
        connectTreeNodes(pNodeA3, nullptr, pNodeA4);
        connectTreeNodes(pNodeA4, nullptr, pNodeA5);
        
        BinaryTreeNode* pNodeB1 = createBinaryTreeNode(8);
        BinaryTreeNode* pNodeB2 = createBinaryTreeNode(9);
        BinaryTreeNode* pNodeB3 = createBinaryTreeNode(2);
        
        connectTreeNodes(pNodeB1, nullptr, pNodeB2);
        connectTreeNodes(pNodeB2, nullptr, pNodeB3);
        
        test(pNodeA1, pNodeB1);
        
        destoryTree(pNodeA1);
        destoryTree(pNodeB1);
    }
    
    // 树只有右结点，树B不是树A的子结构
    void test6() {
        BinaryTreeNode* pNodeA1 = createBinaryTreeNode(8);
        BinaryTreeNode* pNodeA2 = createBinaryTreeNode(8);
        BinaryTreeNode* pNodeA3 = createBinaryTreeNode(9);
        BinaryTreeNode* pNodeA4 = createBinaryTreeNode(3);
        BinaryTreeNode* pNodeA5 = createBinaryTreeNode(5);
        
        connectTreeNodes(pNodeA1, nullptr, pNodeA2);
        connectTreeNodes(pNodeA2, nullptr, pNodeA3);
        connectTreeNodes(pNodeA3, nullptr, pNodeA4);
        connectTreeNodes(pNodeA4, nullptr, pNodeA5);
        
        BinaryTreeNode* pNodeB1 = createBinaryTreeNode(8);
        BinaryTreeNode* pNodeB2 = createBinaryTreeNode(9);
        BinaryTreeNode* pNodeB3 = createBinaryTreeNode(2);
        
        connectTreeNodes(pNodeB1, nullptr, pNodeB2);
        connectTreeNodes(pNodeB2, nullptr, pNodeB3);
        
        test(pNodeA1, pNodeB1);
        
        destoryTree(pNodeA1);
        destoryTree(pNodeB1);
    }
    
    // 树A是空树
    void test7() {
        BinaryTreeNode* pNodeB1 = createBinaryTreeNode(8);
        BinaryTreeNode* pNodeB2 = createBinaryTreeNode(9);
        BinaryTreeNode* pNodeB3 = createBinaryTreeNode(3);
        BinaryTreeNode* pNodeB4 = createBinaryTreeNode(2);
        
        connectTreeNodes(pNodeB1, nullptr, pNodeB2);
        connectTreeNodes(pNodeB2, pNodeB3, pNodeB4);
        
        test(nullptr, pNodeB1);

        destoryTree(pNodeB1);
    }
    
    // 树B是空树
    void test8() {
        BinaryTreeNode* pNodeA1 = createBinaryTreeNode(8);
        BinaryTreeNode* pNodeA2 = createBinaryTreeNode(9);
        BinaryTreeNode* pNodeA3 = createBinaryTreeNode(3);
        BinaryTreeNode* pNodeA4 = createBinaryTreeNode(2);
        
        connectTreeNodes(pNodeA1, nullptr, pNodeA2);
        connectTreeNodes(pNodeA2, pNodeA3, pNodeA4);
        
        test(pNodeA1, nullptr);
        
        destoryTree(pNodeA1);
    }
    
    // 树A和树B都是空树
    void test9() {
        test(nullptr, nullptr);
    }
    
    void substructureInTree() {
        test1();
        test2();
        test3();
        test4();
        test5();
        test6();
        test7();
        test8();
        test9();
    }
}
