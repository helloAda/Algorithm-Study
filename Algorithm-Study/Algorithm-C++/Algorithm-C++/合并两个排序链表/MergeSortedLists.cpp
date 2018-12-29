//
//  MergeSortedLists.cpp
//  Algorithm-C++
//
//  Created by HelloAda on 2018/12/29.
//  Copyright © 2018 HelloAda. All rights reserved.
//

#include "MergeSortedLists.hpp"
#include "List.hpp"
#include <iostream>

/*
 面试题25：合并两个排序的链表
 题目：输入两个递增排序的链表，合并这两个链表并使新链表中的结点仍然是按
 照递增排序的。
 */

namespace namespace_mergeSortedLists {
    
    ListNode* merger(ListNode *pHead1, ListNode *pHead2) {
        
        if (pHead1 == nullptr) {
            return pHead2;
        } else if (pHead2 == nullptr) {
            return pHead1;
        }
        
        ListNode *pMergedHead = nullptr;
        
        if (pHead1->value < pHead2->value) {
            pMergedHead = pHead1;
            pMergedHead->next = merger(pHead1->next, pHead2);
        } else {
            pMergedHead = pHead2;
            pMergedHead->next = merger(pHead1, pHead2->next);
        }
        
        return pMergedHead;
    }
    
    

    // --- 测试代码 ---
    void test(ListNode *pHead1, ListNode *pHead2) {
        std::cout << "测试开始" << std::endl;
        if (pHead1 == nullptr && pHead2 == nullptr) {
            std::cout << "两个都是空链表" << std::endl;
        } else {
            ListNode *pMergeHead = merger(pHead1, pHead2);
            printList(pMergeHead);
            destoryList(pMergeHead);
        }
        std::cout << "测试结束" << std::endl;
    }
    
    // 两个链表有多个节点 并且没有重复的数
    void test1() {
        ListNode *pNode1 = createListNode(1);
        ListNode *pNode3 = createListNode(3);
        ListNode *pNode5 = createListNode(5);
        ListNode *pNode7 = createListNode(7);
        
        connectListNodes(pNode1, pNode3);
        connectListNodes(pNode3, pNode5);
        connectListNodes(pNode5, pNode7);

        
        ListNode *pNode2 = createListNode(2);
        ListNode *pNode4 = createListNode(4);
        ListNode *pNode6 = createListNode(6);
        
        connectListNodes(pNode2, pNode4);
        connectListNodes(pNode4, pNode6);

        test(pNode1, pNode2);
        
    }
    
    // 两个链表有多个节点 有重复的数
    void test2() {
        ListNode *pNode1 = createListNode(1);
        ListNode *pNode3 = createListNode(2);
        ListNode *pNode5 = createListNode(5);
        ListNode *pNode7 = createListNode(7);
        
        connectListNodes(pNode1, pNode3);
        connectListNodes(pNode3, pNode5);
        connectListNodes(pNode5, pNode7);
        
        
        ListNode *pNode2 = createListNode(2);
        ListNode *pNode4 = createListNode(4);
        ListNode *pNode6 = createListNode(6);
        
        connectListNodes(pNode2, pNode4);
        connectListNodes(pNode4, pNode6);
        
        test(pNode1, pNode2);
    }
    
    // 两个链表都只有一个节点
    void test3() {
        ListNode *pNode1 = createListNode(1);
        ListNode *pNode2 = createListNode(2);

        test(pNode1, pNode2);

    }
    
    // 一个为空 一个有值
    void test4() {
        ListNode *pNode1 = createListNode(1);
        test(pNode1, nullptr);
    }
    
    // 两个都为空
    void test5() {
        test(nullptr, nullptr);
    }
    
    void mergeSortedList() {
        test1();
        test2();
        test3();
        test4();
        test5();
    }
}
