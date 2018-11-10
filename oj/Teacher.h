//
// Created by 邵一迪 on 2018/10/10.
//
// 析构函数怎么调用的******************************************************************
#ifndef OJ_TEACHER_H
#define OJ_TEACHER_H

#include "Member.h"

class Teacher: public Member {
private:
    char* title;

public:
    Teacher(int iid, const char* iname, int idate, const char* idepartment, const char* ititle);
    Teacher(const Teacher &t);
    ~Teacher() {
        delete[] title;
    }



};


#endif //OJ_TEACHER_H
