//
//  KthNodeFromEnd.cpp
//  Algorithm-C++
//
//  Created by HelloAda on 2018/12/5.
//  Copyright © 2018 HelloAda. All rights reserved.
//

#include "KthNodeFromEnd.hpp"
#include <iostream>
#include "List.hpp"

/*
 面试题22：链表中倒数第k个结点
 题目：输入一个链表，输出该链表中倒数第k个结点。为了符合大多数人的习惯，
 本题从1开始计数，即链表的尾结点是倒数第1个结点。例如一个链表有6个结点，
 从头结点开始它们的值依次是1、2、3、4、5、6。这个链表的倒数第3个结点是
 值为4的结点。
 */

namespace namespace_kthNodeFromEnd {
    
    void findKthFromEnd(ListNode *pHead, unsigned int k) {
        if (pHead == nullptr || k == 0) {
            std::cout << "无效输入" << std::endl;
            return ;
        }
        
        ListNode *pFront = pHead;
        ListNode *pBehind = nullptr;
        
        // 先让一个指针走 k-1 如果长度不够直接返回nullptr
        for (int i = 0; i < k - 1; i++) {
            if (pFront->next != nullptr) {
                pFront = pFront->next;
            } else {
                std::cout << "链表长度不够" << std::endl;
                return;
            }
        }
        
        pBehind = pHead;
        // 两个指针同时走
        while (pFront->next != nullptr) {
            pFront = pFront->next;
            pBehind = pBehind->next;
        }
        
        std::cout << "找到倒数第"<< k <<"个节点：" << pBehind->value << std::endl;
    }
    
    // ---- 测试代码 ----
    void test(ListNode *pHead, unsigned int k) {
        std::cout << "测试开始" << std::endl;
        findKthFromEnd(pHead, k);
        std::cout << "测试结束" << std::endl;
    }
    
    // 要找的节点在中间
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
        
        test(pNode1, 3);
    }
    
    //  要找的节点在最后
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
        
        test(pNode1, 1);
    }
    
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
        
        test(pNode1, 5);
    }
    
    // 大于整个链表长度
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
        
        test(pNode1, 7);
    }
    
    // 第0个节点
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
        
        test(pNode1, 0);
    }
    
    // 空链表
    void test6() {
        test(nullptr, 100);
    }
    
    void kthNodeFromEnd() {
        test1();
        test2();
        test3();
        test4();
        test5();
        test6();
    }
}
