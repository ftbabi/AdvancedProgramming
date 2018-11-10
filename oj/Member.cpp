//
// Created by 邵一迪 on 2018/10/10.
//

#include "Member.h"
#include <iostream>
#include <cstring>

using namespace std;

Member::Member(int iid, const char *iname, int idate, const char *idepartment) {
    id = iid;
    date = idate;
    name = new char[strlen(iname) + 1];
    strcpy(name, iname);
    department = new char[strlen(idepartment) + 1];
    strcpy(department, idepartment);

}

Member::Member(const Member &m) {
    id = m.id;
    date = m.date;
    name = new char[strlen(m.name) + 1];
    strcpy(name, m.name);
    department = new char[strlen(m.department) + 1];
    strcpy(department, m.department);
}

void Member::printInfo() {
    cout << id << " " << name << " " << date << " " << department << endl;
}