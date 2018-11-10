//
// Created by 邵一迪 on 2018/11/9.
//

#ifndef SIM_PERSON_H
#define SIM_PERSON_H

#include <iostream>
#include <sstream>
using namespace std;


class Person{
public:
    Person(string n, string idtty, string iid, string t, bool gin):
            name(n), identity(idtty), id(iid), is_in(gin) {
        orig_time = t;
        int hour = 0, min = 0;
        stringstream ss;
        int pos = t.find(":");
        if(pos == string::npos){
            cerr << "input error!\n";
            assert(0);
        }
        ss << t.substr(0, pos);
        ss >> hour;
        ss << t.substr(pos+1, t.length()-pos-1);
        ss >> min;
        time = hour*60 + min;

    }
    virtual ~Person() {}
    string get_name() const { return name; }
    string get_identity() const { return identity; }
    string get_id() const {return id; }
    int get_time() const { return time; }
    string get_orig_time() const { return orig_time; }
    bool get_in() const { return is_in; }
//    friend bool operator<(const Person &p1, const Person& p2);
//    friend bool operator<(const Person *p1, const Person *p2);
    friend bool operator==(const Person &p1, const Person& p2);
    string get_full_name() const { return identity+id; }
    virtual string get_info();

protected:
    string name;
    string identity;
    string id;
    string orig_time;
    int time;
    bool is_in; // false -> out
};

bool operator<(const Person &p1, const Person& p2);
#endif //SIM_PERSON_H
