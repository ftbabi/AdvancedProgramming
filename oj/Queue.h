//
// Created by 邵一迪 on 2018/9/22.
//

#ifndef OJ_QUEUE_H
#define OJ_QUEUE_H

#include <iostream>
using namespace std;

template <class T>
struct QueueNode{
    T data;
    QueueNode *next;
    QueueNode(){next = NULL;}
    QueueNode(T d) {next = NULL; data = d;}
};

template <class T>
class Queue{
private:
    QueueNode<T> *head;
    QueueNode<T> *rear;
    int cursize;
public:
    Queue();
    ~Queue();
    void push(T e);
    T pop();
    T back();
    T front();
    size_t size();
    void show();
    bool isEmpty();
};

template <class T>
Queue<T>::Queue() {
    cursize = 0;
    head = NULL;
    rear = head;
}

template <class T>
Queue<T>::~Queue() {
    QueueNode<T> *cur;
    cur = head;
    while(cur)
    {
        cur = cur->next;
        delete head;
        head = cur;
    }
}

template <class T>
T Queue<T>::pop(){
    T ans;
    if(head != NULL)
    {
        QueueNode<T> *cur = head;
        head = head->next;
        ans = cur->data;
        --cursize;
        delete cur;
    }


    return ans;
}

template <class T>
void Queue<T>::push(T e){
    if(head == NULL)
    {
        head = new QueueNode<T>(e);
        rear = head;
        ++cursize;
    }
    else{
        rear->next = new QueueNode<T>(e);
        rear = rear->next;
        ++cursize;
    }
}

template <class T>
T Queue<T>::back() {
    if(rear)
        return rear->data;
    else
        return 0;
}

template <class T>
T Queue<T>::front() {
    if(head)
        return head->data;
    else
        return 0;
}

template <class T>
bool Queue<T>::isEmpty() {
    return cursize == 0;
}

template <class T>
size_t Queue<T>::size() {
    return cursize;
}

template <class T>
void Queue<T>::show() {
    QueueNode<T> *cur = head;
    while(cur){
        cout << cur->data << " ";
        cur = cur->next;
    }

    cout << endl;
}

#endif //OJ_QUEUE_H
