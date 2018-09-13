//
//  List.hpp
//  Algorithm-C++
//
//  Created by HelloAda on 2018/9/11.
//  Copyright © 2018年 HelloAda. All rights reserved.
//

#ifndef List_hpp
#define List_hpp

#include <stdio.h>
struct ListNode {
    int value;
    ListNode *next;
};

// 创建节点
ListNode *createListNode(int value);

// 连接节点
void connectListNodes(ListNode *pCurrent, ListNode *pNext);

// 打印节点
void printListNode(ListNode *node);

// 打印链表
void printList(ListNode *head);

// 销毁链表
void destoryList(ListNode *head);

// 添加节点到末尾
void addToTail(ListNode **head, int value);

// 删除节点
void removeNode(ListNode **head, int value);

#endif /* List_hpp */

