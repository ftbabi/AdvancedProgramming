//
// Created by 邵一迪 on 2018/11/10.
//

#include "Teacher.h"

string Teacher::get_info() {
    string ans = name + "," + identity + ",face id:" + face_id + ",card id:" + id + "," + orig_time + ",";
//    cout << name << "," << identity << ",card id:" << id << "," << orig_time << ",";
    if(is_in)
        ans += "in";
    else
        ans += "out";

    return ans;
}