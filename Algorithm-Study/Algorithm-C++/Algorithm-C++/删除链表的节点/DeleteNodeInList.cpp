//
//  DeleteNodeInList.cpp
//  Algorithm-C++
//
//  Created by HelloAda on 2018/11/29.
//  Copyright © 2018 HelloAda. All rights reserved.
//

#include "DeleteNodeInList.hpp"
#include "List.hpp"
#include <iostream>
/*
 面试题18（一）：在O(1)时间删除链表结点
 题目：给定单向链表的头指针和一个结点指针，定义一个函数在O(1)时间删除该
 结点。
 */

namespace namespace_deleteNodeInList {
    
    void deleteNode(ListNode **head, ListNode *pDeleted) {
        
        if (!head) {
            std::cout << "空链表" << std::endl;
            return;
        }
        
        if (!pDeleted) {
            std::cout << "删除的节点为空" << std::endl;
            return;
        }
        
        // 要删除的不是最后一个节点
        if (pDeleted->next != nullptr) {
            ListNode *pNext = pDeleted->next;
            std::cout << "删除的节点为" << pDeleted->value << std::endl;
            pDeleted->value = pNext->value;
            pDeleted->next = pNext->next;
            delete pNext;
            pNext = nullptr;
        }
        
        // 链表只有一个节点，删除头节点
        else if (*head == pDeleted) {
            std::cout << "删除的节点为" << pDeleted->value << std::endl;
            delete pDeleted;
            pDeleted = nullptr;
            *head = nullptr;
        }
        
        // 链表中有多个节点，要删除的是尾节点
        else {
            ListNode *pNode = *head;
            while (pNode->next != pDeleted) {
                pNode = pNode->next;
            }
            std::cout << "删除的节点为" << pDeleted->value << std::endl;
            pNode->next = nullptr;
            delete pDeleted;
            pDeleted = nullptr;
        }
        
    }
    
    // --- 测试代码 ----
    
    void test(ListNode **head, ListNode *pNode) {
        std::cout << "测试开始" << std::endl;
        deleteNode(head, pNode);
        std::cout << "测试结束" << std::endl;
    }
    
    // 链表有多个节点，删除中间节点
    void test1() {
        ListNode *pNode1 = createListNode(1);
        ListNode *pNode2 = createListNode(2);
        ListNode *pNode3 = createListNode(3);
        ListNode *pNode4 = createListNode(4);
        ListNode *pNode5 = createListNode(5);
        
        connectListNodes(pNode1, pNode2);
        connectListNodes(pNode2, pNode3);
        connectListNodes(pNode3, pNode4);
        connectListNodes(pNode4, pNode5);

        
        test(&pNode1, pNode3);

        destoryList(pNode1);
    }
    
    // 链表有多个节点，删除头节点
    void test2() {
        ListNode *pNode1 = createListNode(1);
        ListNode *pNode2 = createListNode(2);
        ListNode *pNode3 = createListNode(3);
        ListNode *pNode4 = createListNode(4);
        ListNode *pNode5 = createListNode(5);
        
        connectListNodes(pNode1, pNode2);
        connectListNodes(pNode2, pNode3);
        connectListNodes(pNode3, pNode4);
        connectListNodes(pNode4, pNode5);
        
        
        test(&pNode1, pNode1);
        
        destoryList(pNode1);
    }
    
    // 链表有多个节点，删除尾节点
    void test3() {
        ListNode *pNode1 = createListNode(1);
        ListNode *pNode2 = createListNode(2);
        ListNode *pNode3 = createListNode(3);
        ListNode *pNode4 = createListNode(4);
        ListNode *pNode5 = createListNode(5);
        
        connectListNodes(pNode1, pNode2);
        connectListNodes(pNode2, pNode3);
        connectListNodes(pNode3, pNode4);
        connectListNodes(pNode4, pNode5);
        
        
        test(&pNode1, pNode5);
        
        destoryList(pNode1);
    }
    
    // 链表中只有一个节点
    void test4() {
        ListNode *pNode1 = createListNode(1);

        test(&pNode1, pNode1);
        
        destoryList(pNode1);
    }
    
    // 空链表
    void test5() {
        ListNode *pNode1 = createListNode(1);
        
        test(nullptr, nullptr);
        
        destoryList(pNode1);
    }
    
    
    void deleteNodeInList() {
        test1();
        test2();
        test3();
        test4();
        test5();
    }
}
