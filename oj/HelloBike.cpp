//
// Created by 邵一迪 on 2018/10/27.
//

#include "HelloBike.h"
#include <iostream>
#include <cmath>

using std::cout;
using std::endl;

bool HelloBike::unlock() {
    if(!occupied){
        cout << "unlock " << serial << " " << elock_id << endl;
        occupied = true;
        return true;
    }
    else{
        cout << "fail to unlock " << serial << " " << elock_id << endl;
        return false;
    }
}

int HelloBike::lock() {
    if(occupied){
        cout << "lock " << serial << " " << elock_id << endl;
        occupied = false;
        int cost = compute_cost();
        distance = 0;
        return cost;
    } else{
        cout << serial << " " << elock_id << " has been locked" << endl;
        return -1;
    }
}

int HelloBike::compute_cost() {
    int cost = ceil(distance/25.0) * 2;
    cost -= 5;
    if(cost < 0)
    {
        cost = 0;
    }
    return cost;
}