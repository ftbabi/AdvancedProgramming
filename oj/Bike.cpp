//
// Created by 邵一迪 on 2018/10/26.
//

#include "Bike.h"
#include <iostream>
#include <cmath>

using std::cout;
using std::endl;

bool Bike::unlock() {
    if(!occupied){
        occupied = true;
        return true;
    }
    else
        return false;
}

int Bike::lock() {
    if(occupied){
        occupied = false;
        int cost = compute_cost();
        distance = 0;
        return cost;
    } else{
        return -1;
    }
}

int Bike::move_to(int des_x, int des_y) {
    if(occupied){
        cout << "from " << x << "," << y << " to " << des_x << "," << des_y << endl;
        distance += abs(des_x-x) + abs(des_y-y);
        x = des_x;
        y = des_y;
    }
    return distance;
}

int Bike::compute_cost() {
    return distance;
}

int Bike::compute_dis(int dx, int dy) {
    return abs(dx-x) + abs(dy-y);
}