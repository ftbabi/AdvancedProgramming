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
                      "\\s*clear\\s+face\\s+id\\s*(.*)", "\\s*load\\s+from\\s+file\\s+(.*)", "\\s*clear\\s+info\\s*(.*)",
                      "\\s*clear\\s+all\\s*(.*)"};
vector<string> CMLParser::pattern(array_s, array_s + NumOfFunc);

//priority_queue<Person*, vector<Person*>, logically_bigger> Manage::info;
vector<Person*> Manage::pinfo;

func Manage::cmd[NumOfFunc] = {Manage::simulate, Manage::load_info, Manage::show_info, IDHandler::load_id, IDHandler::load_face_id,
                IDHandler::add_id, IDHandler::add_face_id, IDHandler::delete_id, IDHandler::delete_face_id,
                IDHandler::print_id, IDHandler::print_face_id, IDHandler::clear_id, IDHandler::clear_face_id, Manage::load_from_file,
                Manage::clear_info, Manage::clear_all};


void StringSpliter::erase_space(string &str) {
//    if(!tmp.empty()) { // erase space
//            tmp.erase(0, tmp.find_first_not_of(" "));
//            int raw_end = raw.find_last_not_of(" ");
//            if(raw_end < raw.length()-1)
//                tmp.erase(raw_end+1);
//        }
    if(!str.empty()) {
        str.erase(0, str.find_first_not_of(" "));
//        int str_end = str.find_last_not_of(" ");
//        if(str.find_last_not_of(" ") != string::npos)
        str.erase(str.find_last_not_of(" ")+1);
    }
}

void StringSpliter::split_string(vector<string> &ans, string raw){
    string::size_type pos;

    int raw_size = raw.size();
    for(int i = 0; i < raw_size; ++i){
        pos = raw.find(spliter, i);
        string tmp;
        if(pos == string::npos) {
            tmp = raw.substr(i);
            erase_space(tmp);
            ans.push_back(tmp);
            break;
        }
        else if(pos < raw_size) {
            tmp = raw.substr(i, pos-i);
            erase_space(tmp);
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
        string tmp = ans.back();
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
//    Person *cur;
//    while(!pinfo.empty()) {
//        cur = pinfo.back();
//        delete cur;
//        pinfo.pop_back();
//    }
    clear_info();
}


bool Manage::simulate(string t) {
    vector<Person *> pcur(pinfo);
    stable_sort(pcur.begin(), pcur.end(), earlier_latter);
    // debug_vec(pcur);

    Person* p;
    bool face_v, id_v;

    while(!pcur.empty()) {
        p = pcur.back();
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
        if(!id_v && !face_v) {
            cout << "-invalid";
        }
        cout << endl;

        pcur.pop_back();
    }

    return true;
}

bool Manage::load_info(string raw){
    vector<string> rinfo;
    spliter.set_spliter(",");
    spliter.split_string(rinfo, raw);
    if(rinfo[1] == "student"){
        if(rinfo.size() < 5) {
            cout << "load student info error! lack parameters\n";
            return false;
        }
        bool gin = false;
        if(rinfo[4] == "in") {
            gin = true;
        }
        else if(rinfo[4] == "out") {
            gin = false;
        }
        else {
            cout << "load student info error! lack parameters\n";
            return false;
        }
        Student *stu = new Student(rinfo, gin);
//        if(cpy_info.find())
        if(!is_duplicated(stu)) {
            pinfo.push_back(stu);
        }
//        info.push(stu);
    }
    else if(rinfo[1] == "teacher"){
        if(rinfo.size() < 6) {
            cout << "load teacher info error! lack parameters\n";
            return false;
        }
        bool gin = false;
        if(rinfo[5] == "in") {
            gin = true;
        }
        else if(rinfo[5] == "out") {
            gin = false;
        }
        else{
            cout << "load teacher info error! lack parameters\n";
            return false;
        }
        Teacher *tea = new Teacher(rinfo, gin);
        if(!is_duplicated(tea)) {
            pinfo.push_back(tea);
        }
//        info.push(tea);
    }
    else {
        cout << "type not found\n";
        return false;
    }
    //debug_vec(pinfo);
    return true;
}

bool Manage::show_info(string raw) {
//    priority_queue<Person*, vector<Person*>, logically_bigger> cur(info);
    vector<Person*>::iterator iter;
    Person* p;
    for(iter = pinfo.begin(); iter != pinfo.end(); ++iter) {
        cout << (*iter)->get_info() << endl;
    }
//    while(!cur.empty()) {
//        p = cur.top();
//        cout << p->get_info() << endl;
//        cur.pop();
//    }

    return true;
}

bool Manage::load_from_file(string raw) {
    ifstream in(raw, ios_base::in);
    string inputs = "";

    if(!in.is_open()) {
        return false;
    }
    char buff[MaxInput];
    while(in.getline(buff, MaxInput)) {
        inputs = buff;
        inner_execute(inputs);
    }
    in.close();

    return true;
}


void Manage::show_prefix() {
    cout << "(guard system)==> ";
}

bool Manage::execute() {
    show_prefix();

    string inputs = "";

    char input[MaxInput];
    cin.getline(input, MaxInput);
    inputs = input;
    return inner_execute(inputs);
}

bool Manage::inner_execute(string &inputs) {
    regex quit("\\s*q|quit|Q|Quit|QUIT\\s*");

    smatch m_quit;
    regex_match(inputs, m_quit, quit);
    if(!m_quit.empty()){
        cout << "bye bye~\n";
        return false;
    }

    string raw;
    int sel = parser.parser(inputs, raw);
    if(sel == -1) {
        cout << "cmd error!\n";
        return true;
    }

    cmd[sel](raw);
    return true;
}

bool Manage::debug_vec(vector<Person*> &vec) {
    vector<Person*>::iterator it;
    for(it = vec.begin(); it != vec.end(); ++it) {
        cout << (*it)->get_info() << endl;
    }

    return true;
}

bool Manage::is_duplicated(Person* p) {
    vector<Person*>::iterator it;

    for(it = pinfo.begin(); it != pinfo.end(); ++it) {
        if((*it)->get_info() == p->get_info()) {
            return true;
        }
    }

    return false;
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

bool earlier_latter(const Person* p1, const Person *p2) {
    if(p1->get_time() > p2->get_time()) {
        return true;
    }
    else if(p1->get_time() == p2->get_time()) {
        if(p1->judge_person() != p2->judge_person()) {
            return true;
        }
        else if(p1->judge_person() == p2->judge_person() && (p1->get_in() < p2->get_in())) {
            return true;
        }
        else{
            return false;
        }
    } else{
        return false;
    }
}

bool Manage::clear_info(string raw) {
    Person *cur;
    while(!pinfo.empty()) {
        cur = pinfo.back();
        delete cur;
        pinfo.pop_back();
    }
    return true;
}

bool Manage::clear_all(string raw) {
    clear_info();
    idHandler.clear_face_id();
    idHandler.clear_id();
    return true;
}