//
// Created by 邵一迪 on 2018/11/9.
//

#ifndef SIM_PERSON_H
#define SIM_PERSON_H

#include <iostream>
#include <sstream>
using namespace std;

//struct action {
//    string orig_time;
//    int time;
//    bool is_in;
//    action() {}
//    action(string ot, int t, bool in) { orig_time = ot; time = t; in = is_in; }
//    ~action() {}
//    bool operator<(const action &a) {
//        if(time < a.time) {
//            return true;
//        }
//        else if((time == a.time) && (is_in > a.is_in)) {
//            return true;
//        } else{
//            return false;
//        }
//    }
//};

class Person{
public:
    Person(string n, string idtty, string iid, string t, bool gin):
            name(n), identity(idtty), id(iid), is_in(gin) {
        // 将字符串时间转换为int类型
        orig_time = t;
        int hour = 0, min = 0;
        stringstream ss;
        stringstream smin;
        int pos = t.find(":");
        if(pos == string::npos){
            cerr << "input error!\n";
            assert(0);
        }
        string debug;
        ss << t.substr(0, pos);
        ss >> hour;
        smin << t.substr(pos+1, t.length()-pos-1);
        debug = t.substr(pos+1, t.length()-pos-1);
        smin >> min;
        time = hour*60 + min;
    }
    virtual ~Person() {}
    string get_name() const { return name; }
    string get_identity() const { return identity; }
    string get_id() const {return id; }
    virtual string judge_person() const { return id; }
    int get_time() const { return time; }
    string get_orig_time() const { return orig_time; }
    bool get_in() const { return is_in; }
    friend bool operator==(const Person &p1, const Person& p2);
    string get_full_name() const { return identity+id; }
    virtual string get_info(); // 将所有成员拼接成一条信息，根据动态绑定用于判断是否是相同实体

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
