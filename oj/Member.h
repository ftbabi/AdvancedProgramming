//
// Created by 邵一迪 on 2018/10/10.
//

#ifndef OJ_MEMBER_H
#define OJ_MEMBER_H


class Member {
private:
    int id;
    char *name;
    int date;
    char *department;

public:
    Member(int iid, const char* iname, int idate, const char* idepartment);
    Member(const Member &m);
    ~Member(){
        delete[] name;
        delete[] department;
    }
    void printInfo();
    int getId() const { return id; }
    int getDate() const { return date; }
};


#endif //OJ_MEMBER_H
