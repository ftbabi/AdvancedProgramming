//
// Created by 邵一迪 on 2018/11/9.
//

#ifndef SIM_STUDENT_H
#define SIM_STUDENT_H

#include "Person.h"
#include <vector>

using namespace std;

class Student: public Person{
public:
    Student(string n, string idtty, string iid, string t, bool gin):
            Person(n, idtty, iid, t, gin) {}
    Student(vector<string> &info, bool gin):
            Person(info[0], info[1], info[2], info[3], gin) {}
    ~Student() {}

private:

};


#endif //SIM_STUDENT_H
