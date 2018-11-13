//
// Created by 邵一迪 on 2018/11/10.
//

#ifndef SIM_TEACHER_H
#define SIM_TEACHER_H

#include "Person.h"
#include <vector>

class Teacher: public Person{
public:
    Teacher(string n, string idtty, string f_id, string iid, string t, bool gin):
            Person(n, idtty, iid, t, gin), face_id(f_id) {}
    Teacher(vector<string> &info, bool gin):
            Person(info[0], info[1], info[3], info[4], gin), face_id(info[2]) {}
    ~Teacher() {}
    string get_faceid() const { return face_id; }
    string get_info(); // 重载，将face id加入信息
    string get_face_id() const { return face_id; }
    string judge_person() const { return face_id+":"+id; } // 实际没有使用
private:
    string face_id;
};


#endif //SIM_TEACHER_H
