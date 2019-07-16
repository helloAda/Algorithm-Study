//
//  CopyComplexList.cpp
//  Algorithm-C++
//
//  Created by HelloAda on 2019/7/15.
//  Copyright © 2019 HelloAda. All rights reserved.
//


/*
 面试题35：复杂链表的复制
 题目：请实现复制一个复杂链表。
 在复杂链表中，每个结点除了有一个pNext指针指向下一个结点外，
 还有一个pSibling 指向链表中的任意结点或者nullptr。
 */
#include "CopyComplexList.hpp"
#include "ComplexList.hpp"
#include <iostream>

namespace namespace_copyComplexList {
    
    ComplexListNode* reconnectNodes(ComplexListNode *pHead) {
        ComplexListNode *pNode = pHead;
        ComplexListNode *pCopyHead = nullptr;
        ComplexListNode *pCopyNode = nullptr;
        
        if (pNode != nullptr) {
            pCopyHead = pCopyNode = pNode->pNext;
            pNode->pNext = pCopyNode->pNext;
            pNode = pNode->pNext;
        }
        
        while (pNode != nullptr) {
            pCopyNode->pNext = pNode->pNext;
            pCopyNode = pCopyNode->pNext;
            
            pNode->pNext = pCopyNode->pNext;
            pNode = pNode->pNext;
        }
        return pCopyHead;
    }
    
    // 连接任意结点
    void connectSiblingNodes(ComplexListNode *pHaed) {
        ComplexListNode *pNode = pHaed;
        
        while (pNode != nullptr) {
            ComplexListNode *pCopy = pNode->pNext;
            if (pNode->pSibling != nullptr) {
                // 这里要指向该结点复制出来的结点，也就是后面一个
                pCopy->pSibling = pNode->pSibling->pNext;
            }
            pNode = pCopy->pNext;
        }
    }
    
    // 复制结点
    void copyNodes(ComplexListNode *pHead) {
        ComplexListNode *pNode = pHead;
        while (pNode != nullptr) {
            ComplexListNode *pCopy = new ComplexListNode();
            pCopy->value = pNode->value;
            pCopy->pNext = pNode->pNext;
            pCopy->pSibling = nullptr;
            
            pNode->pNext = pCopy;
            
            pNode = pCopy->pNext;
        }
    }
    
    // 复制整个链表
    ComplexListNode* copy(ComplexListNode *pHead) {
        if (pHead == nullptr) {
            std::cout << "空链表" << std::endl;
        }
        copyNodes(pHead);
        connectSiblingNodes(pHead);
        return reconnectNodes(pHead);
    }
    
    
    
    // ----- 测试代码 ------
    void test(ComplexListNode *pHead) {
        std::cout << "测试开始" << std::endl;
        printList(copy(pHead));
        std::cout << "测试结束" << std::endl;
    }
    
    // 正常情况
    void test1() {
        ComplexListNode* pNode1 = createNode(1);
        ComplexListNode* pNode2 = createNode(2);
        ComplexListNode* pNode3 = createNode(3);
        ComplexListNode* pNode4 = createNode(4);
        ComplexListNode* pNode5 = createNode(5);
        
        buildNodes(pNode1, pNode2, pNode3);
        buildNodes(pNode2, pNode3, pNode5);
        buildNodes(pNode3, pNode4, nullptr);
        buildNodes(pNode4, pNode5, pNode2);
        
        test(pNode1);
    }
    
    // 任意结点指向自己
    void test2() {
        ComplexListNode* pNode1 = createNode(1);
        ComplexListNode* pNode2 = createNode(2);
        ComplexListNode* pNode3 = createNode(3);
        ComplexListNode* pNode4 = createNode(4);
        ComplexListNode* pNode5 = createNode(5);
        
        buildNodes(pNode1, pNode2, nullptr);
        buildNodes(pNode2, pNode3, pNode5);
        buildNodes(pNode3, pNode4, pNode3);
        buildNodes(pNode4, pNode5, pNode2);
        
        test(pNode1);
    }
    
    // 任意结点形成环
    void test3() {
        ComplexListNode* pNode1 = createNode(1);
        ComplexListNode* pNode2 = createNode(2);
        ComplexListNode* pNode3 = createNode(3);
        ComplexListNode* pNode4 = createNode(4);
        ComplexListNode* pNode5 = createNode(5);
        
        buildNodes(pNode1, pNode2, nullptr);
        buildNodes(pNode2, pNode3, pNode4);
        buildNodes(pNode3, pNode4, nullptr);
        buildNodes(pNode4, pNode5, pNode2);
        
        test(pNode1);

    }
    
    // 只有一个结点
    void test4() {
        ComplexListNode* pNode1 = createNode(1);
        buildNodes(pNode1, nullptr, pNode1);
        
        test(pNode1);
    }
    
    // 空链表
    void test5() {
        test(nullptr);
    }
    
    
    void copyComplexList() {
        test1();
        test2();
        test3();
        test4();
        test5();

    }
}
