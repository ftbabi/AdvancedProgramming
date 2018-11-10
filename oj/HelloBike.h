//
// Created by 邵一迪 on 2018/10/27.
//

#ifndef OJ_HELLOBIKE_H
#define OJ_HELLOBIKE_H
#define HMAXLEN 100

#include "Bike.h"

class HelloBike: public Bike {
public:
    HelloBike(const char* id, const char* elk_id, int l_x, int l_y, int comfort_rating): Bike(id, l_x, l_y, comfort_rating) {
        strcpy(elock_id, elk_id);
    }
    ~HelloBike() {}
    bool unlock();
    int lock();
    int compute_cost();

private:
    char elock_id[HMAXLEN];
};


#endif //OJ_HELLOBIKE_H
