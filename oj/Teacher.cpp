//
// Created by 邵一迪 on 2018/10/10.
//

#include "Teacher.h"
#include <iostream>
#include <cstring>

using namespace std;

Teacher::Teacher(int iid, const char *iname, int idate, const char *idepartment, const char *ititle): Member(iid, iname, idate, idepartment) {
    title = new char[strlen(ititle) + 1];
    strcpy(title, ititle);
}

Teacher::Teacher(const Teacher &t): Member(t){
    title = new char[strlen(t.title) + 1];
    strcpy(title, t.title);
}