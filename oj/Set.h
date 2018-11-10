//
// Created by 邵一迪 on 2018/10/25.
//

#ifndef OJ_SET_H
#define OJ_SET_H

#include <iostream>

using namespace std;

class Set {
public:
    Set();
    Set(const Set &set);
    Set(int elements[], int length);
    ~Set();
    void add(int ele);
    bool erase(int ele);
    bool contains(int ele) const;
    int size() const;
    friend ostream &operator<<(ostream &os, const Set &s);
    friend Set operator+(const Set &l, const Set &r);
    Set &operator+=(const Set &s);
    friend Set operator-(const Set &l, const Set &r);
    Set &operator-=(const Set &s);
    friend Set operator&(const Set &l, const Set &r);
    friend Set operator|(const Set &l, const Set &r);
    friend bool operator==(const Set &l, const Set &r);
    friend bool operator!=(const Set &l, const Set &r);
    friend bool operator>(const Set &l, const Set &r);
    friend bool operator>=(const Set &l, const Set &r);
    friend bool operator<(const Set &l, const Set &r);
    friend bool operator<=(const Set &l, const Set &r);
    void *operator new(size_t size);
    void operator delete(void *p, size_t size);

public:
    int *array;
    int m_size;
    int cur_size;
    Set *next;
};

ostream &operator<<(ostream &os, const Set &s);
Set operator+(const Set &l, const Set &r);
Set operator-(const Set &l, const Set &r);
Set operator&(const Set &l, const Set &r);
Set operator|(const Set &l, const Set &r);
bool operator==(const Set &l, const Set &r);
bool operator!=(const Set &l, const Set &r);
bool operator>(const Set &l, const Set &r);
bool operator>=(const Set &l, const Set &r);
bool operator<(const Set &l, const Set &r);
bool operator<=(const Set &l, const Set &r);

#endif //OJ_SET_H
