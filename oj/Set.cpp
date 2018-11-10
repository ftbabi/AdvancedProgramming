//
// Created by 邵一迪 on 2018/10/25.
//

#include "Set.h"
#include <cstring>
#define DEFAULTSIZE 10

Set *p_free = NULL;

Set::Set() {
    m_size = DEFAULTSIZE;
    array = new int[m_size];
    cur_size = 0;
}

Set::Set(const Set &set) {
    m_size = set.m_size;
    array = new int[m_size];
    for(int i = 0; i < m_size; ++i) {
        array[i] = set.array[i];
    }
    cur_size = set.cur_size;
}

Set::Set(int *elements, int length) {
    m_size = length;
    cur_size = 0;
    array = new int[m_size];
    for(int i = 0; i < length; ++i){
        int min = i;
        for(int j = i+1; j < length; ++j){
            if(elements[min] > elements[j]) {
                min = j;
            }
        }
        if(min != i){
            int tmp = elements[i];
            elements[i] = elements[min];
            elements[min] = tmp;
        }
    }


    int pre = elements[0];
    for(int i = 1; i < m_size; ++i){
        if(elements[i] != pre){
            array[cur_size++] = pre;
            pre = elements[i];
        }
    }
    if(pre != array[cur_size-1]){
        array[cur_size++] = pre;
    }

}

Set::~Set() {
    delete[] array;
}

void Set::add(int ele) {
//    if(ele == 4)
//        cout << "here";
    int i = 0;
    for(; i < cur_size && ele > array[i]; ++i){

    }
    if(i < cur_size && ele == array[i]){
        return;
    }

//    if(ele == 4)
//        cout << "here";

    // overflow
    if(cur_size >= m_size){
//        if(ele == 4)
//            cout << "here";
        int *narray = new int[m_size * 2];
        int j = 0;
        for( ; j < i; ++j){
            narray[j] = array[j];
        }
        narray[j++] = ele;
        for(; j <= cur_size; ++j) {
            narray[j] = array[j-1];
        }
        ++cur_size;
        m_size *= 2;
        delete[] array;
        array = narray;
//        cout << "plus " << ele << endl;
    }
    else{
//        if(ele == 4)
//            cout << "here";
        for(int j = cur_size; j > i; --j){
            array[j] = array[j-1];
        }
        array[i] = ele;
        ++cur_size;
//        cout << "plus " << ele << endl;
    }

    return;
}

bool Set::erase(int ele) {
    for(int i = 0; i < cur_size; ++i){
        if(ele == array[i]) { // delete
            --cur_size;
            for(int j = i; j < cur_size; ++j){
                array[j] = array[j+1];
            }
            return true;
        }
        else if(ele < array[i])
            break;
    }

    return false;
}

bool Set::contains(int ele) const {
    for(int i = 0; i < cur_size; ++i){
        if(ele == array[i])
            return true;
        else if(ele < array[i])
            break;
    }

    return false;
}

int Set::size() const {
    return cur_size;
}

ostream &operator<<(ostream &os, const Set &s) {
    if(s.cur_size <= 0)
        os << "Empty";
    else{
        for(int i = 0; i < s.cur_size; ++i){
            os << s.array[i] << " ";
        }
    }

    return os;
}

Set operator+(const Set &l, const Set &r) {
    Set ans(l);
//    int i, j;
//    while(i < l.cur_size && j < r.cur_size){
//        if(l.array[i] < r.array[j]){
//            ans.add(l.array[i]);
//            ++i;
//        }
//        else if(l.array[i] > r.array[j]){
//            ans.add(r.array[j]);
//            ++j;
//        }
//        else{
//            ans.add(l.array[i]);
//            ++i;
//            ++j;
//        }
//    }
//    while(i < l.cur_size){
//        ans.add(l.array[i]);
//        ++i;
//    }
//    while (j < r.cur_size){
//        ans.add(r.array[j]);
//        ++j;
//    }
    ans += r;
//    cout << "ans + " << ans.cur_size;
    return ans;
}

Set& Set::operator+=(const Set &s) {
    for(int i = 0; i < s.cur_size; ++i){
        add(s.array[i]);
    }

    return *this;
}

Set operator-(const Set &l, const Set &r){
    Set ans(l);
    ans -= r;

    return ans;
}

Set& Set::operator-=(const Set &s) {
    for(int i = 0; i < s.cur_size; ++i){
        if(contains(s.array[i])){
            erase(s.array[i]);
        }
    }

    return *this;
}

Set operator&(const Set& l, const Set &r) {
    Set ans;
    for(int i = 0; i < r.cur_size; ++i){
        if(l.contains(r.array[i])){
            ans.add(r.array[i]);
        }
    }

    return ans;
}

Set operator|(const Set& l, const Set& r) {
    Set ans(l+r);
//    cout << ans.cur_size << " | cursize";
    return l+r;
}

bool operator==(const Set& l, const Set& r) {
    Set tmp = l - r;
    return tmp.cur_size == 0 && l.cur_size == r.cur_size;
}

bool operator!=(const Set& l, const Set& r) {
    return !(l == r);
}

bool operator>(const Set &l, const Set &r) {
    if(l.cur_size > r.cur_size) {
        for(int i = 0; i < r.cur_size; ++i){
            if(!l.contains(r.array[i])){
                return false;
            }
        }

        return true;
    }

    return false;

}

bool operator>=(const Set &l, const Set &r) {
    return (l == r) || (l > r);
}

bool operator<(const Set &l, const Set &r) {
    return r > l;
}

bool operator<=(const Set &l, const Set &r) {
    return r >= l;
}




void* Set::operator new(size_t size) {
    Set *p;
    if(p_free == NULL)
    {
        p_free = (Set *)malloc(size*100); // 申请连续的空间
        for(p = p_free; p != p_free+99; ++p)
            p->next = p+1;                  // 利用next将内存串起来
        p->next = NULL;
    }

    // 从链表中给当前对象分配空间
    p = p_free;
    p_free = p_free->next;
    memset(p, 0, size);     // 将这块空间初始化为0
    return p;               // 返回指向这个空间的指针
}

void Set::operator delete(void *p, size_t size){
    ((Set *)p)->next = p_free;
    p_free = (Set *)p; // 相当于退回空
//    free(p);
}