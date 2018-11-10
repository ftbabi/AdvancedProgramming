//
// Created by 邵一迪 on 2018/11/10.
//

#include "Person.h"

//bool operator<(const Person &p1, const Person& p2){
//    return p1.time < p2.time;
//}

//bool operator<(const Person *p1, const Person *p2){
//    return p1->time > p2->time;
//}

bool operator==(const Person &p1, const Person& p2){
    return (p1.id == p2.id) && (p1.name == p2.name) && (p1.identity == p2.identity) && (p1.time == p2.time) && (p1.is_in == p2.is_in);
}

string Person::get_info() {
    string ans = name + "," + identity + ",card id:" + id + "," + orig_time + ",";
//    cout << name << "," << identity << ",card id:" << id << "," << orig_time << ",";
    if(is_in)
        ans += "in";
    else
        ans += "out";

    return ans;
}