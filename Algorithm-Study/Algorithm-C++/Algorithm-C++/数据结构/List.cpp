//
//  List.cpp
//  Algorithm-C++
//
//  Created by HelloAda on 2018/9/11.
//  Copyright © 2018年 HelloAda. All rights reserved.
//

#include "List.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

// 创建节点
ListNode *createListNode(int value) {
    ListNode *node = new ListNode();
    node->value = value;
    node->next = nullptr;
    return node;
}

// 连接节点
void connectListNodes(ListNode *pCurrent, ListNode *pNext) {
    if (pCurrent == nullptr) {
        std::cout << "连接出错" << std::endl;
        return;
    }
    pCurrent->next = pNext;
}

// 打印节点
void printListNode(ListNode *node) {
    if (node == nullptr) {
        std::cout << "这是一个空指针" << std::endl;
    } else {
        std::cout << "节点的值：" << node->value << std::endl;
    }
}

// 打印链表
void printList(ListNode *head) {
    std::cout << "打印链表开始" << std::endl;
    ListNode *node = head;
    while (node != nullptr) {
        std::cout << node->value << std::endl;
        node = node->next;
    }
    std::cout << "打印链表结束" << std::endl;
}

// 销毁链表
void destoryList(ListNode *head) {
    ListNode *node = head;
    while (node != nullptr) {
        head = head->next;
        delete node;
        node = head;
    }
}


// 添加节点到末尾
void addToTail(ListNode **head, int value) {
    ListNode *pNew = new ListNode();
    pNew->value = value;
    pNew->next = nullptr;
    
    // 如果当前链表为空
    if (*head == nullptr) {
        *head = pNew;
    } else {
        ListNode *node = *head;
        while (node->next != nullptr) {
            node = node->next;
        }
        node->next = pNew;
    }
}

// 删除节点
void removeNode(ListNode **head, int value) {
    if (head == nullptr || *head == nullptr) {
        return;
    }
    
    // 这样写的逻辑 确实比以前的看起来好一点
    ListNode *deleteNode = nullptr;
    
    if ((*head)->value == value) {
        deleteNode = *head;
        *head = (*head)->next;
    } else {
        ListNode *node = *head;
        while (node->next != nullptr && node->next->value != value) {
            node = node->next;
        }
        
        if (node->next != nullptr && node->next->value == value) {
            deleteNode = node->next;
            node->next = node->next->next;
        }
    }
    
    if (deleteNode != nullptr) {
        delete deleteNode;
        deleteNode = nullptr;
    }
    
    
}

