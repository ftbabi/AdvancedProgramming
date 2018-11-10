//
// Created by 邵一迪 on 2018/10/10.
//

#ifndef OJ_MANAGER_H
#define OJ_MANAGER_H

#include "Member.h"
#include "Student.h"
#include "Teacher.h"
#include <iostream>

struct MemberNode{
    Member *mem;
    MemberNode *next;
    MemberNode(){ mem = NULL; next = NULL;}
    MemberNode(Member *m, MemberNode *p){ mem = m; next = p;}
};

class Manager {
private:
    MemberNode *head;
    MemberNode *last;
    int count;


public:
    Manager() {
        head = NULL;
        last = head;
        count = 0;
    }
//    Manager(const Manager &m);
    ~Manager();

    void add(Member *m);
    void sortById();
    void sortByDate();
    void printSearch(const int id);
    void printAll();
};


#endif //OJ_MANAGER_H
