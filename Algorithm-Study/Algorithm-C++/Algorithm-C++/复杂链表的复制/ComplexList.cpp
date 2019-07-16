//
//  ComplexList.cpp
//  Algorithm-C++
//
//  Created by HelloAda on 2019/7/16.
//  Copyright © 2019 HelloAda. All rights reserved.
//

#include "ComplexList.hpp"

ComplexListNode *createNode(int value) {
    ComplexListNode *pNode = new ComplexListNode();
    
    pNode->value = value;
    pNode->pNext = nullptr;
    pNode->pSibling = nullptr;
    return pNode;
}

void buildNodes(ComplexListNode *pNode, ComplexListNode *pNext, ComplexListNode *pSibling) {
    if (pNode != nullptr) {
        pNode->pNext = pNext;
        pNode->pSibling = pSibling;
    }
}

void printList(ComplexListNode *pHead) {
    ComplexListNode* pNode = pHead;
    while(pNode != nullptr)
    {
        printf("结点的值: %d.\n", pNode->value);
        
        if(pNode->pSibling != nullptr)
            printf("指向的任意结点的值 %d.\n", pNode->pSibling->value);
        else
            printf("这个结点指向的任意节点是空节点\n");
        
        printf("\n");
        
        pNode = pNode->pNext;
    }
}
