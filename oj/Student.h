//
// Created by 邵一迪 on 2018/10/10.
//

#ifndef OJ_STUDENT_H
#define OJ_STUDENT_H


#include "Member.h"

class Student: public Member {
private:
    char* major;
public:
    Student(int iid, const char* iname, int idate, const char* idepartment, const char* imajor);
    Student(const Student &s);
    ~Student(){
        delete[] major;
    }

};


#endif //OJ_STUDENT_H
