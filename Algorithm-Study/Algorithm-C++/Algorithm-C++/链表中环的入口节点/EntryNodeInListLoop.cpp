//
//  EntryNodeInListLoop.cpp
//  Algorithm-C++
//
//  Created by HelloAda on 2018/12/6.
//  Copyright © 2018 HelloAda. All rights reserved.
//

#include "EntryNodeInListLoop.hpp"
#include "List.hpp"
#include <iostream>

/*
 面试题23：链表中环的入口结点
 题目：一个链表中包含环，如何找出环的入口结点？
 */

namespace namespace_entryNodeInListLoop {
    
    // 判断链表存不存在环，存在返回快慢指针相遇时的节点
    ListNode* meetingNode(ListNode *pHead) {

        ListNode *pSlow = pHead->next;
        if (pSlow == nullptr) {
            return nullptr;
        }
        ListNode *pFast = pSlow->next;
        
        // 都不为空 就继续遍历
        while (pFast != nullptr && pSlow != nullptr) {
            // 快的指针 追上慢的则代表有环的存在
            if (pFast == pSlow) {
                return pFast;
            }
            pSlow = pSlow->next;
            pFast = pFast->next;
            if (pFast != nullptr) { // 下一个节点不为空才继续 指向下一个节点
                pFast = pFast->next;
            }
        }
        return nullptr;
    }
    
    void entryNodeOfLoop(ListNode *pHead) {
        if (pHead == nullptr) {
            std::cout << "空链表" << std::endl;
            return;
        }
        ListNode *meetNode = meetingNode(pHead);
        if (meetNode == nullptr) {
            std::cout << "链表不存在环" << std::endl;
            return;
        }
        // 链表中环的节点的数目
        int nodesInLoop = 1;
        ListNode *pNode1 = meetNode;
        // 下一个节点不是一开始的节点 证明环还没走完
        while (pNode1->next != meetNode) {
            pNode1 = pNode1->next;
            nodesInLoop++;
        }
        
        // 先移动pNode1指针 nodesInLoop次
        pNode1 = pHead;
        for (int i = 0; i < nodesInLoop; i++) {
            pNode1 = pNode1->next;
        }
        
        // 再从头移动pNode2
        ListNode *pNode2 = pHead;
        
        while (pNode1 != pNode2) {
            pNode1 = pNode1->next;
            pNode2 = pNode2->next;
        }
        
        std::cout << "环入口节点：" << pNode1->value << std::endl;
        
    }
    
    
    // --- 测试代码 ---
    
    void test(ListNode * pHead) {
        std::cout << "测试开始" << std::endl;
        entryNodeOfLoop(pHead);
        std::cout << "测试结束" << std::endl;
    }
    
    // 只有一个节点没有环
    void test1() {
        ListNode *pNode1 = createListNode(1);
        test(pNode1);
        destoryList(pNode1);
    }
    
    // 只有一个节点 有环
    void test2() {
        ListNode *pNode1 = createListNode(1);
        connectListNodes(pNode1, pNode1);
        test(pNode1);
        delete [] pNode1;
    }
    
    // 有多个节点 没有环
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

        test(pNode1);
        
        destoryList(pNode1);

    }
    
    // 有多个节点 有环
    void test4() {
        ListNode *pNode1 = createListNode(1);
        ListNode *pNode2 = createListNode(2);
        ListNode *pNode3 = createListNode(3);
        ListNode *pNode4 = createListNode(4);
        ListNode *pNode5 = createListNode(5);
        
        connectListNodes(pNode1, pNode2);
        connectListNodes(pNode2, pNode3);
        connectListNodes(pNode3, pNode4);
        connectListNodes(pNode4, pNode5);
        connectListNodes(pNode5, pNode3);
        
        test(pNode1);
        
        delete pNode1;
        pNode1 = nullptr;
        delete pNode2;
        pNode2 = nullptr;
        delete pNode3;
        pNode3 = nullptr;
        delete pNode4;
        pNode4 = nullptr;
        delete pNode5;
        pNode5 = nullptr;
    }
    
    // 有多个节点 整个链表就是一个环
    void test5() {
        ListNode *pNode1 = createListNode(1);
        ListNode *pNode2 = createListNode(2);
        ListNode *pNode3 = createListNode(3);
        ListNode *pNode4 = createListNode(4);
        ListNode *pNode5 = createListNode(5);
        
        connectListNodes(pNode1, pNode2);
        connectListNodes(pNode2, pNode3);
        connectListNodes(pNode3, pNode4);
        connectListNodes(pNode4, pNode5);
        connectListNodes(pNode5, pNode1);
        
        test(pNode1);
        
        delete pNode1;
        pNode1 = nullptr;
        delete pNode2;
        pNode2 = nullptr;
        delete pNode3;
        pNode3 = nullptr;
        delete pNode4;
        pNode4 = nullptr;
        delete pNode5;
        pNode5 = nullptr;
    }
    
    // 空链表
    void test6() {
        test(nullptr);
    }
    
    void entryNodeInListLoop() {
        test1();
        test2();
        test3();
        test4();
        test5();
        test6();

    }
}
