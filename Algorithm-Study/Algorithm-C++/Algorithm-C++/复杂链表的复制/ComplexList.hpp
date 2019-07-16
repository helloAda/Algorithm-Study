//
//  ComplexList.hpp
//  Algorithm-C++
//
//  Created by HelloAda on 2019/7/16.
//  Copyright © 2019 HelloAda. All rights reserved.
//

#ifndef ComplexList_hpp
#define ComplexList_hpp

#include <stdio.h>

struct ComplexListNode {
    int value;
    ComplexListNode *pNext;
    ComplexListNode *pSibling;
};

ComplexListNode* createNode(int value);
void buildNodes(ComplexListNode *pNode, ComplexListNode *pNext, ComplexListNode* pSibling);
void printList(ComplexListNode *pHead);

#endif /* ComplexList_hpp */
