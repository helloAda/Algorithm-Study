//
//  SerializeBinaryTrees.cpp
//  Algorithm-C++
//
//  Created by HelloAda on 2019/7/18.
//  Copyright © 2019 HelloAda. All rights reserved.
//

/*
 面试题37：序列化二叉树
 题目：请实现两个函数，分别用来序列化和反序列化二叉树。
 */

#include "SerializeBinaryTrees.hpp"
#include "BinaryTreeNode.hpp"
#include <iostream>
#include <fstream>

using namespace std;

namespace namespace_serializeBinaryTrees {
    
    // 序列化
    void serialize(const BinaryTreeNode *pRoot, ostream &stream) {
        if (pRoot == nullptr) {
            stream << "$,";
            return;
        }
        
        stream << pRoot->value << ',';
        serialize(pRoot->left, stream);
        serialize(pRoot->right, stream);
    }
    
    bool readStream(istream &stream, int* number) {
        if(stream.eof())
            return false;
        
        char buffer[32];
        buffer[0] = '\0';
        
        char ch;
        stream >> ch;
        int i = 0;
        while(!stream.eof() && ch != ',')
        {
            buffer[i++] = ch;
            stream >> ch;
        }
        
        bool isNumeric = false;
        if(i > 0 && buffer[0] != '$')
        {
            *number = atoi(buffer);
            isNumeric = true;
        }
        
        return isNumeric;
    }
    
    void deserialize(BinaryTreeNode **pRoot, istream &stream) {
        int number;
        if (readStream(stream, &number)) {
            *pRoot = new BinaryTreeNode();
            (*pRoot)->value = number;
            (*pRoot)->left = nullptr;
            (*pRoot)->right = nullptr;
            deserialize(&(*pRoot)->left, stream);
            deserialize(&(*pRoot)->right, stream);
        }
    }
    
    
    // ----- 测试代码 -----
    
    bool isSameTree(const BinaryTreeNode* pRoot1, const BinaryTreeNode* pRoot2)
    {
        if(pRoot1 == nullptr && pRoot2 == nullptr)
            return true;
        
        if(pRoot1 == nullptr || pRoot2 == nullptr)
            return false;
        
        if(pRoot1->value != pRoot2->value)
            return false;
        
        return isSameTree(pRoot1->left, pRoot2->left) &&
        isSameTree(pRoot1->right, pRoot2->right);
    }
    
    void test(BinaryTreeNode *pRoot) {
        cout << "测试开始" << endl;
        // 序列化
        string fileName = "test.txt";
        ofstream fileOut;
        fileOut.open(fileName);
        serialize(pRoot, fileOut);
        fileOut.close();
        // 打印序列化文件
        ifstream fileIn;
        char ch;
        fileIn.open(fileName);
        while (!fileIn.eof()) {
            fileIn >> ch;
            cout << ch;
        }
        fileIn.close();
        cout << endl;
        
        // 反序列化
        ifstream fileIn1;
        fileIn1.open(fileName);
        BinaryTreeNode* pNewRoot = nullptr;
        deserialize(&pNewRoot, fileIn1);
        fileIn1.close();
        
        if(isSameTree(pRoot, pNewRoot))
            cout << "序列化后的树和原来相同" << endl;
        else
            cout << "序列化后的树和原来不同" << endl;

        cout << "测试结束" << endl;
        
        destoryTree(pNewRoot);
    }
    
    // 完全二叉树
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
    
    // 只有左子结点的二叉树
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
    
    // 重复数字的二叉树
    void test5() {
        BinaryTreeNode* pNode1 = createBinaryTreeNode(5);
        BinaryTreeNode* pNode2 = createBinaryTreeNode(5);
        BinaryTreeNode* pNode3 = createBinaryTreeNode(5);
        BinaryTreeNode* pNode4 = createBinaryTreeNode(5);
        BinaryTreeNode* pNode5 = createBinaryTreeNode(5);
        BinaryTreeNode* pNode61 = createBinaryTreeNode(5);
        BinaryTreeNode* pNode62 = createBinaryTreeNode(5);
        BinaryTreeNode* pNode71 = createBinaryTreeNode(5);
        BinaryTreeNode* pNode72 = createBinaryTreeNode(5);
        
        connectTreeNodes(pNode1, nullptr, pNode2);
        connectTreeNodes(pNode2, nullptr, pNode3);
        connectTreeNodes(pNode3, pNode4, nullptr);
        connectTreeNodes(pNode4, pNode5, nullptr);
        connectTreeNodes(pNode5, pNode61, pNode62);
        connectTreeNodes(pNode61, pNode71, nullptr);
        connectTreeNodes(pNode62, nullptr, pNode72);
        
        test(pNode1);
        
        destoryTree(pNode1);
    }
    
    // 空树
    void test6() {
        test(nullptr);
    }
    
    void serializeBinaryTrees() {
        test1();
        test2();
        test3();
        test4();
        test5();
        test6();

    }
}
