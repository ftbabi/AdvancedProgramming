//
// Created by 邵一迪 on 2018/10/27.
//

#ifndef OJ_SHELL_H
#define OJ_SHELL_H

#include <iostream>
#include <cstring>
using namespace std;

class Shell {
public:
    Shell(string home="/"): path("/"), dis(0) {
//        if(home[home.length()-1] != '/'){
//            homedir += "/";
//        }
        cd(home);
        homedir = path;
    }
    ~Shell() {}
    void cd(string path="");
    void pwd();
    void distance(string path);

private:
    string path; // 尾部加/
    string homedir;
    int dis;
};

void Shell::cd(string p) {
    if(p.empty()){
        path = homedir;
        return;
    }
    if(p[0] == '/'){
        path = "/";
    }
    char *p_copy = new char[p.length()+1];
    strcpy(p_copy, p.c_str());
    char *token = strtok(p_copy, "/");
    while(token){
        if(strcmp(token, "..") == 0){
            if(path != "/"){
                int length = path.length();

                for(int i = length-2; i >= 0; --i){
                    if(path[i] == '/'){
//                        char *ans = new char[i+1+1];
//                        strncpy(ans, path.c_str(), i+1);
//                        path = ans;
                        path.erase(i+1, length-i-1);
                        break;
                    }
                }
            }
        }
        else if(strcmp(token, "~") == 0) {
            path = homedir;
        }
        else if(strcmp(token, ".") != 0){
            path += token;
            path += "/";
        }

        token = strtok(NULL, "/");
    }
    delete[] p_copy;

}

void Shell::pwd() {
    cout << path << endl;
}

void Shell::distance(string p) {
    dis = 0;
    string original_path(path);
    cd(p);
//    char *orginalpath_copy = new char[original_path.length()+1];
//    char *curpath_copy = new char[path.length()+1];
//    strcpy(orginalpath_copy, original_path.c_str());
//    strcpy(curpath_copy, path.c_str());
//    char *token_path = strtok(orginalpath_copy, "/");
//    char *token_p = strtok(curpath_copy, "/");
//
//    while(token_path && token_p) {
//        if(strcmp(token_p, token_path) == 0){
//            token_p = strtok(NULL, "/");
//            token_path = strtok(NULL, "/");
//
//        }
//        else{
//            break;
//        }
//    }
//    while(token_path){
//        ++dis;
//        token_path = strtok(NULL, "/");
//    }
//    while(token_p) {
//        if(strcmp(token_p, ".") != 0){
//            ++dis;
//        }
//        token_p = strtok(NULL, "/");
//    }
    int olength = original_path.length();
    int i = 0;
    for(; i < olength; ++i){
        if(original_path[i] != path[i])
            break;
    }

    int tmp_i = i;
    for(; i < olength; ++i){
        if(original_path[i] == '/'){
            ++dis;
        }
    }
    for(i = tmp_i; i < path.length(); ++i){
        if(path[i] == '/'){
            ++dis;
        }
    }
//    char *token = NULL;
//    char *str;
//    if(i == olength){
//        str = new char[1];
//        str[0] = '\0';
//    }
//    else{
//        str = new char[olength-i+1];
//        strcpy(str, original_path.c_str() + i);
//    }
////    char *str = new char[olength - i + 1];
//    token = strtok(str, "/");
//    while(token){
//        ++dis;
//        token = strtok(NULL, "/");
//    }
//    delete[] str;
//    if(i == path.length()){
//        str = new char[1];
//        str[0] = '\0';
//    }
//    else{
//        str = new char[path.length()-i+1];
//        strcpy(str, path.c_str() + i);
//    }
////    str = new char[path.length()-i+1];
//    token = strtok(str, "/");
//    while(token){
//        ++dis;
//        token = strtok(NULL, "/");
//    }
//    delete[] str;
    path = original_path;
    cout << dis << endl;
}

#endif //OJ_SHELL_H
