//
//  PrintListInReversedOrder.cpp
//  Algorithm-C++
//
//  Created by HelloAda on 2018/9/12.
//  Copyright © 2018年 HelloAda. All rights reserved.
//

#include "PrintListInReversedOrder.hpp"
#include "List.hpp"
#include <stack>
#include <iostream>
/*
 面试题6：从尾到头打印链表
 题目：输入一个链表的头结点，从尾到头反过来打印出每个结点的值。
 */


namespace namespace_printListInReversedOrder {
    
    // 用栈实现
    void PrintListReversingly_Iteratively(ListNode *head) {
        // 存放节点的栈
        std::stack<ListNode *> nodes;
        ListNode *node = head;
        while (node != nullptr) {
            nodes.push(node);
            node = node->next;
        }
        
        while (!nodes.empty()) {
            node = nodes.top();
            std::cout << "节点数据：" << node->value << std::endl;
            nodes.pop();
        }
    }

    // 递归实现
    void PrintListReversingly_Recursively(ListNode* head) {
        if (head != nullptr) {
            if (head->next != nullptr) {
                PrintListReversingly_Recursively(head->next);
            }
            std::cout << "节点数据：" << head->value << std::endl;
        }
    }
    
    
    // ----- 测试 -----
    void test(ListNode *head) {
        std::cout << "==== 测试开始 ====" << std::endl;
        PrintListReversingly_Iteratively(head);
//        PrintListReversingly_Recursively(head);
        std::cout << "==== 测试结束 ====" << std::endl;
    }

    // 正常数据
    void test1() {
        ListNode *node1 = createListNode(1);
        ListNode *node2 = createListNode(2);
        ListNode *node3 = createListNode(3);
        ListNode *node4 = createListNode(4);
        ListNode *node5 = createListNode(5);
        
        connectListNodes(node1, node2);
        connectListNodes(node2, node3);
        connectListNodes(node3, node4);
        connectListNodes(node4, node5);
        
        test(node1);
        
        destoryList(node1);
    }
    
    // 只有一个结点
    void test2() {
        ListNode *node = createListNode(3);
        
        test(node);
        
        destoryList(node);
        
    }
    
    // 空链表
    void test3() {
        test(nullptr);
    }
    
    void printListInReversedOrder() {
        test1();
        test2();
        test3();
    }
}
