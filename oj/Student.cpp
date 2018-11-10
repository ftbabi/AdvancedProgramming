//
// Created by 邵一迪 on 2018/10/10.
//

#include "Student.h"
#include <iostream>
#include <cstring>

using namespace std;

Student::Student(int iid, const char *iname, int idate, const char *idepartment, const char *imajor): Member(iid, iname, idate, idepartment){
    major = new char[strlen(imajor) + 1];
    strcpy(major, imajor);
}

Student::Student(const Student &s): Member(s) {
    major = new char[strlen(s.major) + 1];
    strcpy(major, s.major);
}