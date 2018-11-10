//
// Created by 邵一迪 on 2018/9/21.
//

#ifndef OJ_STACK_H
#define OJ_STACK_H
//template <class T>
//class Stack{
//public:
//    Stack(int size = 10);
//    virtual void Push(const T &item)=0;
//    virtual T Pop()=0;
//    virtual T getTop()=0;
//    virtual void makeEmpty()=0;
//    virtual int IsEmpty() const=0;
//    virtual int IsFull() const=0;
//};
#include <iostream>
using namespace std;


template <class T>
class Stack{
protected:
    T *data;
    int top;
    int maxSize;
    void OverFlow();
public:
    Stack(int sz = 50);
    Stack(const Stack<T> &st);
    ~Stack() {delete[] data;}
    bool Push(T ch);
    bool Pop(T &x);
    bool Pop();
    bool IsFull() const { return top+1 == maxSize; }
    bool IsEmpty() const { return top == -1; }
    bool getTop(T &t);
    void ClearElements() { top = -1; }
    T *GetData() const { T tmp = data[0]; return data; }
    int GetCurSize() const { return top+1; }
    void Show();
    bool ModifyTop(T ch);
    int size() const { return top+1; }
    T GetValue(int i) const { return data[i]; }
    T* GetPointer() const { return data; }

    Stack<T> &operator=(const Stack<T> &st);

    friend ostream &operator<<(ostream &out, const Stack<T> &st);
};

template <class T>
void Stack<T>::OverFlow() {
    maxSize *= 2;
    T *tmp = new T[maxSize];
    for(int i = 0; i <= top; ++i)
    {
        tmp[i] = data[i];
    }
    delete[] data;
    data = tmp;
}

template <class T>
Stack<T>::Stack(int sz) {
    maxSize = sz;
    data = new T[maxSize];
    top = -1;
}

template <class T>
Stack<T>::Stack(const Stack<T> &st) {
    top = st.top;
    maxSize = st.maxSize;
    data = new T[maxSize];
    for(int i = 0; i <= top; ++i)
    {
        data[i] = st.data[i];
    }
}

template <class T>
bool Stack<T>::Push(T ch) {
    if(IsFull())
    {
        OverFlow();
    }
    ++top;
    data[top] = ch;
    return true;
}

template <class T>
bool Stack<T>::Pop(T &x) {
    if(IsEmpty())
        return false;
    x = data[top--];
    return true;
}

template <class T>
bool Stack<T>::Pop() {
    if(IsEmpty())
        return false;
    --top;
    return true;
}

template <class T>
bool Stack<T>::getTop(T &t) {
    if(top >= 0)
    {
        t = data[top];
        return true;
    }

    return false;
}

template <class T>
void Stack<T>::Show() {
    for(int i = 0; i <= top; ++i)
    {
        cout << data[i] << endl;
    }
}

template <class T>
bool Stack<T>::ModifyTop(T ch) {
    if(IsEmpty())
    {
        return false;
    }

    data[top] = ch;
    return true;
}

template <class T>
Stack<T>& Stack<T>::operator=(const Stack<T> &st) {
    if(this == &st)
    {
        return *this;
    }

    delete[] data;
    top = st.top;
    maxSize = st.maxSize;
    data = new T[maxSize];
    for(int i = 0; i <= top; ++i)
    {
        data[i] = st.data[i];
    }

    for(auto k:st.data)

    return *this;
}

#endif //OJ_STACK_H
