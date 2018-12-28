//
//  ReverseList.cpp
//  Algorithm-C++
//
//  Created by HelloAda on 2018/12/28.
//  Copyright © 2018 HelloAda. All rights reserved.
//

#include "ReverseList.hpp"
#include <iostream>
#include "List.hpp"

/*
 面试题24：反转链表
 题目：定义一个函数，输入一个链表的头结点，反转该链表并输出反转后链表的头结点。
 */

namespace namespace_reverseList {
    
    ListNode* _reverseList(ListNode *pHead) {
        if (pHead == nullptr) {
            std::cout << "空链表" << std::endl;
            return nullptr;
        }
        // 前一个节点
        ListNode *pPrev = nullptr;
        // 当前节点
        ListNode *pNode = pHead;
        // 下一个节点 也是反转后的头节点
        ListNode *pNext = nullptr;
        
        while (pNode != nullptr) {
            pNext = pNode->next;
            // 如果下一个节点等于空指针,代表已经反转完了
            if (pNext == nullptr) {
                pNext = pNode;
                pNode->next = pPrev;
                return pNext;
            }
            
            pNode->next = pPrev;
            pPrev = pNode;
            pNode = pNext;
        }
        
        return nullptr;
    }
    
    
    
    
    // --- 测试代码 ---
    void test(ListNode *pHead) {
        std::cout << "测试开始" << std::endl;
        ListNode *pReversHead = _reverseList(pHead);
        if (pReversHead != nullptr) {
            std::cout << "反转后的链表" << std::endl;
            printList(pReversHead);
        }
        destoryList(pReversHead);
        std::cout << "测试结束" << std::endl;
    }
    
    // 多个节点
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

        test(pNode1);
        
    }
    
    // 只有一个节点
    void test2() {
        ListNode *pNode1 = createListNode(1);
        test(pNode1);

    }
    
    // 空链表
    void test3() {
        test(nullptr);
    }
    
    void reverseList() {
        test1();
        test2();
        test3();
    }
}
