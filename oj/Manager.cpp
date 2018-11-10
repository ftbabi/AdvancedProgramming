//
// Created by 邵一迪 on 2018/10/10.
//

#include "Manager.h"
#include <iostream>

using namespace std;

//Manager::Manager(const Manager &m) {
//    MemberNode *cur = m.head;
//    if(cur != NULL)
//    {
//        head = new MemberNode()
//    }
//
//}

Manager::~Manager() {
    MemberNode *cur = NULL;
    while(head)
    {
        cur = head;
        head = head->next;
        delete cur;
    }
}

void Manager::add(Member *m) {
    if(NULL == head)
    {
        head = new MemberNode(m, NULL);
        last = head;
    }
    else
    {
        last->next = new MemberNode(m, NULL);
        last = last->next;
    }
}

void Manager::sortById() {
    bool change = true;
    MemberNode *j = NULL;
    MemberNode *pre = NULL;

    while(change)
    {
        j = head;
        change = false;
        while(j && j->next)
        {
            if(j->mem->getId() > j->next->mem->getId())
            {
                change = true;
                if(j == head)
                {
                    head = j->next;
                    j->next = head->next;
                    head->next = j;
                }
                else{
                    pre->next = j->next;
                    j->next = j->next->next;
                    pre->next->next = j;
                }
            }
            if(pre)
            {
                j = pre->next;
                pre = pre->next;
                j = j->next;
            }
            else{
                pre = head;
                j = pre->next;
            }
        }
        if(!change)
        {
            break;
        }
        pre = NULL;
    }

}

void Manager::sortByDate() {
    bool change = true;
    MemberNode *j = NULL;
    MemberNode *pre = NULL;

    while(change)
    {
        j = head;
        change = false;
        while(j && j->next)
        {
            if(j->mem->getDate() > j->next->mem->getDate() || (j->mem->getDate() == j->next->mem->getDate() && j->mem->getId() > j->next->mem->getId()))
            {
                change = true;
                if(j == head)
                {
                    head = j->next;
                    j->next = head->next;
                    head->next = j;
                }
                else{
                    pre->next = j->next;
                    j->next = j->next->next;
                    pre->next->next = j;
                }
            }
            if(pre)
            {
                j = pre->next;
                pre = pre->next;
                j = j->next;
            }
            else{
                pre = head;
                j = pre->next;
            }
        }
        if(!change)
        {
            break;
        }
        pre = NULL;
    }
}

void Manager::printSearch(const int id) {
    MemberNode *cur = head;
    while(cur)
    {
        if(cur->mem->getId() == id)
        {
            cur->mem->printInfo();
            break;
        }
        cur = cur->next;
    }
}

void Manager::printAll() {
    MemberNode *cur = head;
    while(cur)
    {
        cur->mem->printInfo();
        cur = cur->next;
    }
}