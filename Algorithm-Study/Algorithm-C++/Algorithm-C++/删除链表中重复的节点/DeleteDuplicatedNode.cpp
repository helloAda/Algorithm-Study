//
//  DeleteDuplicatedNode.cpp
//  Algorithm-C++
//
//  Created by HelloAda on 2018/11/30.
//  Copyright © 2018 HelloAda. All rights reserved.
//

#include "DeleteDuplicatedNode.hpp"
#include "List.hpp"
#include <iostream>
/*
 面试题18（二）：删除链表中重复的结点
 题目：在一个排序的链表中，如何删除重复的结点
 */

namespace namespace_deleteDuplicatedNode {
    
    
    /**
     删除重复的节点

     @param pHead 指向头节点指针的指针
     */
    void deleteDuplicatedNode(ListNode **pHead) {
        
        if (pHead == nullptr) {
            std::cout << "无效输入" << std::endl;
            return;
        }
        
        if (*pHead == nullptr) {
            std::cout << "空链表" << std::endl;
            return;
        }
        std::cout << "初始链表" << std::endl;
        printList(*pHead);
        
        ListNode *pPreNode = nullptr;
        ListNode *pNode = *pHead;
        
        while (pNode != nullptr) {
            ListNode *pNext = pNode->next;
            bool needDelete = false;
            // 下一个节点不为空 且值相等
            if (pNext != nullptr && pNext->value == pNode->value) {
                needDelete = true;
            }
            
            // 不相等
            if (!needDelete) {
                pPreNode = pNode;
                pNode = pNode->next;
            }
            // 相等
            else {
                int value = pNode->value;
                ListNode *pToBeDelete = pNode;
                // 将后面还有相等的都删除了
                while (pToBeDelete != nullptr && pToBeDelete->value == value) {
                    pNext = pToBeDelete->next;
                    
                    delete pToBeDelete;
                    pToBeDelete = nullptr;
                    pToBeDelete = pNext;
                }
                
                // 头节点被删除了 将没有被删除的第一个赋值给头节点
                if (pPreNode == nullptr) {
                    *pHead = pNext;
                }
                // 将被删除的第一个节点的上一个节点指向没有被删除的第一个节点
                else {
                    pPreNode->next = pNext;
                }
                // 当前节点 指向没有被删除的第一个节点 进入下一轮循环
                pNode = pNext;
            }
        }
        std::cout << "去重后的链表" << std::endl;
        printList(*pHead);
    }
    
    // -- 测试代码 --
    void test(ListNode **pHead) {
        std::cout << "测试开始" << std::endl;
        deleteDuplicatedNode(pHead);
        std::cout << "测试结束" << std::endl;
    }
    
    // 重复节点在中间
    void test1() {
        ListNode* pNode1 = createListNode(1);
        ListNode* pNode2 = createListNode(2);
        ListNode* pNode3 = createListNode(3);
        ListNode* pNode4 = createListNode(3);
        ListNode* pNode5 = createListNode(4);
        ListNode* pNode6 = createListNode(4);
        ListNode* pNode7 = createListNode(5);
        
        connectListNodes(pNode1, pNode2);
        connectListNodes(pNode2, pNode3);
        connectListNodes(pNode3, pNode4);
        connectListNodes(pNode4, pNode5);
        connectListNodes(pNode5, pNode6);
        connectListNodes(pNode6, pNode7);

        test(&pNode1);
        destoryList(pNode1);
    }
    
    // 没有重复节点
    void test2() {
        ListNode* pNode1 = createListNode(1);
        ListNode* pNode2 = createListNode(2);
        ListNode* pNode3 = createListNode(3);
        ListNode* pNode4 = createListNode(4);
        ListNode* pNode5 = createListNode(5);
        ListNode* pNode6 = createListNode(6);
        ListNode* pNode7 = createListNode(7);
        
        connectListNodes(pNode1, pNode2);
        connectListNodes(pNode2, pNode3);
        connectListNodes(pNode3, pNode4);
        connectListNodes(pNode4, pNode5);
        connectListNodes(pNode5, pNode6);
        connectListNodes(pNode6, pNode7);
        
        test(&pNode1);
        destoryList(pNode1);
    }
    
    // 除了一个节点外其余节点都相等
    void test3() {
        ListNode* pNode1 = createListNode(1);
        ListNode* pNode2 = createListNode(1);
        ListNode* pNode3 = createListNode(1);
        ListNode* pNode4 = createListNode(1);
        ListNode* pNode5 = createListNode(1);
        ListNode* pNode6 = createListNode(1);
        ListNode* pNode7 = createListNode(2);
        
        connectListNodes(pNode1, pNode2);
        connectListNodes(pNode2, pNode3);
        connectListNodes(pNode3, pNode4);
        connectListNodes(pNode4, pNode5);
        connectListNodes(pNode5, pNode6);
        connectListNodes(pNode6, pNode7);
        
        test(&pNode1);
        destoryList(pNode1);
    }
    
    // 所有节点都相等
    void test4() {
        ListNode* pNode1 = createListNode(1);
        ListNode* pNode2 = createListNode(1);
        ListNode* pNode3 = createListNode(1);
        ListNode* pNode4 = createListNode(1);
        ListNode* pNode5 = createListNode(1);
        ListNode* pNode6 = createListNode(1);
        ListNode* pNode7 = createListNode(1);
        
        connectListNodes(pNode1, pNode2);
        connectListNodes(pNode2, pNode3);
        connectListNodes(pNode3, pNode4);
        connectListNodes(pNode4, pNode5);
        connectListNodes(pNode5, pNode6);
        connectListNodes(pNode6, pNode7);
        
        test(&pNode1);
        destoryList(pNode1);
    }
    
    // 无效输入
    void test5() {
        test(nullptr);
    }
    
    // 空链表
    void test6() {
        ListNode *pNode = nullptr;
        test(&pNode);
    }
    
    void deleteDuplicatedNode () {
        test1();
        test2();
        test3();
        test4();
        test5();
        test6();
    }
}
