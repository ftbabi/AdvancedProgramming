//
// Created by 邵一迪 on 2018/11/10.
//

#ifndef SIM_MANAGE_H
#define SIM_MANAGE_H

#include <set>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <queue>
#include <regex>
#include <algorithm>
#include <map>
#include <fstream>
#include "Person.h"
#include "Student.h"
#include "Teacher.h"

#define NumOfFunc 16

using namespace std;

typedef bool (*func)(string);

//struct logically_bigger{
//    bool operator()(const Person* p1, const Person* p2) {
//        if(p1->get_time() > p2->get_time()) {
//            // time early
//            return true;
//        }
//        else if(p1->get_time() == p2->get_time() && p1->get_in() < p2->get_in()) {
//            // first in then out
//            return true;
//        }
//        else{
//            return false;
//        }
//    }
//};

class StringSpliter {
public:
    StringSpliter() {}
    ~StringSpliter() {}

    static void set_spliter(string newspliter) { spliter = newspliter; }
    static void split_string(vector<string> &ans, string raw);

private:
    static string spliter;

    static void erase_space(string &str);
};


class IDHandler {
public:
    IDHandler() {}
    ~IDHandler() {}
    static bool load_id(string raw);
    static bool load_face_id(string raw);
    static bool add_id(string raw);
    static bool add_face_id(string raw);
    static bool delete_id(string raw = "");
    static bool delete_face_id(string raw = "");
    static bool print_id(string t = "");
    static bool print_face_id(string t = "");
    static bool clear_id(string t = "") { id.clear(); return true; }
    static bool clear_face_id(string t = "") { face_id.clear(); return true; }

    static bool is_valid(string name, bool& id_v, bool& face_v, string id, string face_id = "");

private:
    static set<string> id;
    static set<string> face_id;
    static StringSpliter spliter;

};


class CMLParser {
public:
    CMLParser() {
        // 13 choices
//        pattern.push_back("\\s*simulate\\s*(.*)");
//        pattern.push_back("\\s*load\\s+info\\s+(.*)"); // load info asd, teacher, 1, 2, 8:00, 1
//        pattern.push_back("\\s*show\\s+info\\s+(.*)");
//        pattern.push_back("\\s*load\\s+id\\s+(.*)");
//        pattern.push_back("\\s*load\\s+face\\s+id\\s+(.*)");
//        pattern.push_back("\\s*add\\s+id\\s+(.*)");
//        pattern.push_back("\\s*add\\s+face\\s+id(.*)");
//        pattern.push_back("\\s*delete\\s+id\\s+(.*)");
//        pattern.push_back("\\s*delete\\s+face\\s+id\\s+(.*)");
//        pattern.push_back("\\s*print\\s+id\\s*(.*)");
//        pattern.push_back("\\s*print\\s+face\\s+id\\s*(.*)");
//        pattern.push_back("\\s*clear\\s+id\\s*(.*)");
//        pattern.push_back("\\s*clear\\s+face\\s+id\\s*(.*)");
    }
    ~CMLParser() {}

    static int parser(string raw, string &ans);

private:
    static vector<string> pattern;
};


class Manage {
public:
    Manage() {}
    ~Manage();

    static bool simulate(string t);
    static bool load_info(string raw);
    static bool show_info(string raw);
    static bool load_from_file(string raw);
    static bool clear_info(string raw = "");
    static bool clear_all(string raw = "");

    static void show_prefix();
    static bool execute();
    static bool debug_vec(vector<Person*> &vec); // 用于调试的时候输出
    static bool is_duplicated(Person* p);
private:
    static IDHandler idHandler;
    static StringSpliter spliter;
    static CMLParser parser;
//    static priority_queue<Person*, vector<Person*>, logically_bigger> info;
    static vector<Person*> pinfo;
    static func cmd[NumOfFunc];

    static bool inner_execute(string &raw);
};

bool earlier_latter(const Person* p1, const Person *p2);




#endif //SIM_MANAGE_H
