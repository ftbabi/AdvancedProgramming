//
// Created by 邵一迪 on 2018/10/26.
//

#ifndef OJ_BIKE_H
#define OJ_BIKE_H
#define MAX_LEN 100

#include <iostream>
#include <cstring>

class Bike {
public:
    Bike(const char* i_s, int i_x=0, int i_y=0, int i_comfort=10): occupied(false), distance(0), x(i_x), y(i_y), comfort(i_comfort) {
        strcpy(serial, i_s);
        if(x > 100) {
            x = 100;
        }
        else if(x < 0)
            x = 0;

        if(y > 100)
            y = 100;
        else if(y < 0)
            y = 0;
        if(comfort > 10)
            comfort = 10;
        else if(comfort < 1)
            comfort = 1;
    }
    virtual ~Bike() {}
    virtual bool unlock();
    virtual int lock();
    virtual int move_to(int des_x, int des_y);
    virtual int compute_cost();
    int get_comfort() const { return comfort; }
    int compute_dis(int dx, int dy);
    const char *get_serial() const { return serial; }
    const bool is_occupied() const { return occupied; }

protected:
    char serial[MAX_LEN];
    bool occupied;
    int distance;
    int x;
    int y;
    int comfort;
};


#endif //OJ_BIKE_H
