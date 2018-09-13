//
//  QueueWithTwoStacks.cpp
//  Algorithm-C++
//
//  Created by HelloAda on 2018/9/13.
//  Copyright © 2018年 HelloAda. All rights reserved.
//

#include "QueueWithTwoStacks.hpp"
#include <stack>
#include <iostream>

/*
 面试题9：用两个栈实现队列
 题目：用两个栈实现一个队列。队列的声明如下，请实现它的两个函数appendTail
 和deleteHead，分别完成在队列尾部插入结点和在队列头部删除结点的功能。
 */

using namespace std;
namespace namespace_QueueWithTwoStacks {
    template <typename T>
    class CQueue {
        
    public:
        CQueue(void);
        ~CQueue(void);
        
        // 在队列末尾添加一个节点
        void appendTail(const T &node);
        // 删除队列的头节点
        void deleteHead();
    private:
        stack<T> stack1;
        stack<T> stack2;
    };
    
    template <typename T> CQueue<T>::CQueue(void)
    {
    }
    
    template <typename T> CQueue<T>::~CQueue(void)
    {
    }
    
    template <typename T>
    void CQueue<T>::appendTail(const T &element) {
        stack1.push(element);
        cout << "在队列中添加了" << element << endl;
    }
    
    template <typename T> void CQueue<T>::deleteHead() {
        if (stack2.size() <= 0) {
            while (stack1.size() > 0) {
                T &data = stack1.top();
                stack1.pop();
                stack2.push(data);
            }
        }
        
        if (stack2.size() == 0) {
            cout << "队列为空" << endl;
        } else {
            T head = stack2.top();
            stack2.pop();
            cout << "从队列中删除了" << head << endl;
        }
        
    }

    // ------ 测试 -------
    
    
    void test() {
        cout << "==== 测试开始 ====" << endl;
        CQueue<char> queue;
        // 在空队列中删除数据
        queue.deleteHead();
        // 空队列中添加数据
        queue.appendTail('a');
        queue.appendTail('b');
        queue.appendTail('c');
        // 在非空的队列中 添加删除数据
        queue.deleteHead();
        queue.appendTail('d');
        
        cout << "==== 测试结束 ====" << endl;

    }

    void queueWithTwoStacks() {
        test();
    }
    
}


