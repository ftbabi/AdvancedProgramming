//
// Created by 邵一迪 on 2018/10/26.
//

#ifndef OJ_OFOBIKE_H
#define OJ_OFOBIKE_H

#include "Bike.h"

class OfoBike: public Bike {
public:
    OfoBike(const char* id, int l_x, int l_y, int comfort_rating): Bike(id, l_x, l_y, comfort_rating) {}
    ~OfoBike() {}
    bool unlock();
    int lock();
    int compute_cost();
};


#endif //OJ_OFOBIKE_H
