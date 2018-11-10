//
// Created by 邵一迪 on 2018/10/26.
//

#ifndef OJ_LIST_H
#define OJ_LIST_H

#include <iostream>

template <class T>
struct _List_node{
    _List_node<T> *prev;
    _List_node<T> *next;
    T data;
};

template <class T>
struct _List_iterator {
    _List_node<T> *_p_node;
    _List_iterator(_List_node<T> *x): _p_node(x) {}
    ~_List_iterator() {}
    bool operator==(const _List_iterator &l);
    bool operator!=(const _List_iterator &l);
    _List_iterator&operator++(); //前置
    const _List_iterator operator++(int);
    _List_iterator&operator--(); //前置
    const _List_iterator operator--(int);
    T &operator*();
};

template <class T>
class List {
public:
    typedef _List_node<T> link_type;
    typedef _List_iterator<T> iterator;
    List();
    ~List();
    bool empty();
    iterator begin() {
        iterator ans(node->next);
        return ans;
    }
    iterator end() {
        iterator ans(node);
        return ans;
    }
    iterator insert(iterator it, T e) {
        link_type *ans = new link_type;
        ans->data = e;
        ans->next = it._p_node;
        it._p_node->prev->next = ans;
        ans->prev = it._p_node->prev;
        ans->next->prev = ans;
        iterator it_ans(ans);
        return it_ans;
    }
    iterator erase(iterator it) {
        link_type *cur = it._p_node;
        iterator ans(cur->next);
        cur->prev->next = cur->next;
        cur->next->prev = cur->prev;
        delete cur;

        return ans;
    }

private:
    link_type* node;
};

template <class T>
bool _List_iterator<T>::operator==(const _List_iterator &l) {
    return _p_node == l._p_node;
}

template <class T>
bool _List_iterator<T>::operator!=(const _List_iterator &l) {
    return !((*this) == l);
}

template <class T>
_List_iterator<T>& _List_iterator<T>::operator++() {
    _p_node = _p_node->next;
    return *this;
}

template <class T>
const _List_iterator<T> _List_iterator<T>::operator++(int) {
    _List_iterator<T> tmp(*this); // 默认拷贝构造函数
    ++(*this);
    return tmp;
}

template <class T>
_List_iterator<T>& _List_iterator<T>::operator--() {
    _p_node = _p_node->prev;
    return *this;
}

template <class T>
const _List_iterator<T> _List_iterator<T>::operator--(int) {
    _List_iterator<T> tmp(*this);
    --(*this);
    return tmp;
}

template <class T>
T& _List_iterator<T>::operator*() {
    return _p_node->data;
}

template <class T>
List<T>::List() {
    node = new link_type;
    node->next = node;
    node->prev = node;
}

template <class T>
List<T>::~List() {
    link_type *cur = node->next;
    while(cur != node){
        node->next = cur->next;
        delete cur;
        cur = node->next;
    }
    delete node;
    node = NULL;
}

template <class T>
bool List<T>::empty() {
    return node == node->next;
}

//template <class T>
//List<T>::iterator List<T>::begin() {
//    iterator ans(node->next);
//    return ans;
//}

//template <class T>
//List<T>::iterator List<T>::end() {
//    iterator ans(node);
//    return ans;
//}

//template <class T>
//List<T>::iterator List<T>::insert(iterator it, T e) {
//    link_type *ans = new link_type;
//    ans->data = e;
//    ans->next = it._p_node;
//    it._p_node->prev->next = ans;
//    ans->prev = it._p_node->prev;
//    ans->next->prev = ans;
//    iterator it_ans(ans);
//    return it_ans;
//}

//template <class T>
//List<T>::iterator List<T>::erase(iterator it) {
//    link_type *cur = it._p_node;
//    iterator ans(cur->next);
//    cur->prev->next = cur->next;
//    cur->next->prev = cur->prev;
//    delete cur;
//
//    return ans;
//}

#endif //OJ_LIST_H