//
// Created by 邵一迪 on 2018/10/26.
//

#include "OfoBike.h"
#include <iostream>
#include <cmath>
using std::cout;
using std::endl;

bool OfoBike::unlock() {
    if(!occupied){
        cout << "unlock " << serial << endl;
        occupied = true;
        return true;
    }
    else{
        cout << "fail to unlock " << serial << endl;
        return false;
    }
}

int OfoBike::lock() {
    if(occupied){
        cout << "lock " << serial << endl;
        occupied = false;
        int cost = compute_cost();
        distance = 0;
        return cost;
    } else{
        cout << serial << " has been locked" << endl;
        return -1;
    }
}

int OfoBike::compute_cost() {
    int cost = ceil(distance/21.0) * 2;
    cost -= 7;
    if(cost < 0)
    {
        cost = 0;
    }
    return cost;
}