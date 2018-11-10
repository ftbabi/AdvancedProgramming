//
// Created by 邵一迪 on 2018/11/10.
//

#include "Manage.h"

const int MaxInput = 100;
string StringSpliter::spliter = ",";
set<string> IDHandler::id;
set<string> IDHandler::face_id;

string array_s[] = {"\\s*simulate\\s*(.*)", "\\s*load\\s+info\\s+(.*)", "\\s*show\\s+info\\s*(.*)",
                      "\\s*load\\s+id\\s+(.*)", "\\s*load\\s+face\\s+id\\s+(.*)", "\\s*add\\s+id\\s+(.*)",
                      "\\s*add\\s+face\\s+id(.*)", "\\s*delete\\s+id\\s+(.*)", "\\s*delete\\s+face\\s+id\\s+(.*)",
                      "\\s*print\\s+id\\s*(.*)", "\\s*print\\s+face\\s+id\\s*(.*)", "\\s*clear\\s+id\\s*(.*)",
                      "\\s*clear\\s+face\\s+id\\s*(.*)"};
vector<string> CMLParser::pattern(array_s, array_s + 13);

priority_queue<Person*, vector<Person*>, logically_bigger> Manage::info;
set<Person*> Manage::cpy_info;

func cmd[13] = {Manage::simulate, Manage::load_info, Manage::show_info, IDHandler::load_id, IDHandler::load_face_id,
                IDHandler::add_id, IDHandler::add_face_id, IDHandler::delete_id, IDHandler::delete_face_id,
                IDHandler::print_id, IDHandler::print_face_id, IDHandler::clear_id, IDHandler::clear_face_id};



void StringSpliter::split_string(vector<string> &ans, string raw){
    string::size_type pos;

    int raw_size = raw.size();
    for(int i = 0; i < raw_size; ++i){
        pos = raw.find(spliter, i);
        string tmp;
        if(pos == string::npos) {
            tmp = raw.substr(i);
            ans.push_back(tmp);
            break;
        }
        else if(pos < raw_size) {
            tmp = raw.substr(i, pos-i);
            ans.push_back(tmp);
            i = pos + spliter.size() - 1;
        }

    }
//    while(string::npos != pos2) {
//        string tmp = raw.substr(pos1, pos2-pos1);
//        if(!tmp.empty()) { // erase space
//            tmp.erase(0, tmp.find_first_not_of(" "));
//            int raw_end = raw.find_last_not_of(" ");
//            if(raw_end < raw.length()-1)
//                tmp.erase(raw_end+1);
//        }
//        ans.push_back(tmp);
//        pos1 = pos2 + spliter.size();
//        raw = raw.substr(pos1);
//        pos2 = raw.find(spliter);
//    }



}

bool IDHandler::load_id(string raw) {
    return add_id(raw);
}

bool IDHandler::load_face_id(string raw) {
    return add_face_id(raw);
}

bool IDHandler::add_id(string raw) {
    vector<string> ans;
    spliter.set_spliter(",");
    spliter.split_string(ans, raw);
    if(ans.empty())
    {
        return false;
    }

    while(!ans.empty()) {
        id.insert(ans.back());
        ans.pop_back();
    }

    return true;
}

bool IDHandler::add_face_id(string raw) {
    vector<string> ans;
    spliter.set_spliter(",");
    spliter.split_string(ans, raw);
    if(ans.empty())
    {
        return false;
    }

    while(!ans.empty()) {
        face_id.insert(ans.back());
        ans.pop_back();
    }

    return true;
}

bool IDHandler::delete_id(string raw) {
    vector<string> ans;
    spliter.set_spliter(",");
    spliter.split_string(ans, raw);
    if(ans.empty())
    {
        return false;
    }
    while(!ans.empty()) {
        id.erase(ans.back());
        ans.pop_back();
    }

    return true;
}

bool IDHandler::delete_face_id(string raw) {
    vector<string> ans;
    spliter.set_spliter(",");
    spliter.split_string(ans, raw);
    if(ans.empty())
    {
        return false;
    }
    while(!ans.empty()) {
        face_id.erase(ans.back());
        ans.pop_back();
    }

    return true;
}

bool IDHandler::print_id(string t) {
    set<string>::iterator it;
    cout << "Valid id: ";
    if(id.empty()){
        cout << "Empty\n";
        return false;
    }
    else{
        for(it = id.begin(); it != id.end(); ++it) {
            cout << (*it) << " ";
        }
    }
    cout << "\n";
    return true;
}

bool IDHandler::print_face_id(string t) {
    set<string>::iterator it;
    cout << "Valid face_id: ";
    if(face_id.empty())
    {
        cout << "Empty\n";
        return false;
    }
    else{
        for(it = face_id.begin(); it != face_id.end(); ++it) {
            cout << (*it) << " ";
        }
    }
    cout << "\n";
    return true;
}

bool IDHandler::is_valid(string name, bool& id_v, bool& face_v, string iid, string face) {
    id_v = false;
    face_v = false;
    set<string>::iterator finder;
    if(!face.empty()) {
        finder = face_id.find(face);
        if(finder != face_id.end()){
            face_v = true;
            return true;
        }
    }

    finder = id.find(iid);
    if(finder != id.end()) {
        id_v = true;
        return true;
    }

    return false;
}

int CMLParser::parser(string raw, string &ans) {
    for(int i = pattern.size() - 1; i >= 0; --i) {
        regex re(pattern[i]);
        smatch sm;
        regex_match(raw, sm, re);
        if(!sm.empty()) {
            //match
            ans = sm.str(1);
            return i;
        }
    }

    return -1;
}

Manage::~Manage() {
    Person *cur;
    while(!info.empty()) {
        cur = info.top();
        delete cur;
        info.pop();
    }
}


bool Manage::simulate(string t) {
    priority_queue<Person*, vector<Person*>, logically_bigger> cur(info);
    Person* p;
    bool face_v, id_v;

    while(!cur.empty()) {
        p = cur.top();
        cout << p->get_identity() << " " << p->get_name() << ",";
        Teacher *t = dynamic_cast<Teacher *>(p);  // judge if it's teacher
        if(t != NULL) {
            idHandler.is_valid(t->get_name(), id_v, face_v, t->get_id(), t->get_face_id());
            if(face_v){
                cout << "valid face id,";
            }
            else{
                cout << "invalid face id,";
                if(id_v){
                    cout << "valid card id,";
                }
                else{
                    cout << "invalid card id,";
                }
            }
        }
        else{
            idHandler.is_valid(p->get_name(), id_v, face_v, p->get_id());
            if(id_v){
                cout << "valid card id,";
            }
            else{
                cout << "invalid card id,";
            }
        }
        cout << p->get_orig_time() << ",";
        if(p->get_in()){
            cout << "in";
        }
        else{
            cout << "out";
        }
        cout << endl;

        cur.pop();
    }

    return true;
}

bool Manage::load_info(string raw){
    vector<string> rinfo;
    spliter.set_spliter(",");
    spliter.split_string(rinfo, raw);
    if(string::npos == raw.find("teacher")){
        if(rinfo.size() < 5) {
            cerr << "load student info error! lack parameters\n";
            return false;
        }
        bool gin = false;
        if(rinfo[4] == "in") {
            gin = true;
        }
        Student *stu = new Student(rinfo, gin);
//        if(cpy_info.find())
        info.push(stu);
    }
    else{
        if(rinfo.size() < 6) {
            cerr << "load teacher info error! lack parameters\n";
            return false;
        }
        bool gin = false;
        if(rinfo[5] == "in") {
            gin = true;
        }
        Teacher *tea = new Teacher(rinfo, gin);
        info.push(tea);
    }
    return true;
}

bool Manage::show_info(string raw) {
    priority_queue<Person*, vector<Person*>, logically_bigger> cur(info);
    Person* p;
    while(!cur.empty()) {
        p = cur.top();
        cout << p->get_info() << endl;
        cur.pop();
    }

    return true;
}


void Manage::show_prefix() {
    cout << "(guard system)==> ";
}

bool Manage::execute() {
    show_prefix();

    string inputs = "";
    regex quit("\\s*q\\s*");
    smatch m_quit;

    char input[MaxInput];
    cin.getline(input, MaxInput);
    inputs = input;
    regex_match(inputs, m_quit, quit);
    if(!m_quit.empty()){
        return false;
    }

    string raw;
    int sel = parser.parser(inputs, raw);
    if(sel == -1) {
        cerr << "cmd error!\n";
        return false;
    }

    cmd[sel](raw);
    return true;
}

//bool logically_bigger(const Person* p1, const Person* p2) {
//    if(p1->get_time() < p2->get_time()) {
//        // time early
//        return true;
//    }
//    else if(p1->get_time() == p2->get_time() && p1->get_in() > p2->get_in()) {
//        // first in then out
//        return true;
//    }
//    else{
//        return false;
//    }
//}