//
// Created by 邵一迪 on 2018/10/27.
//

#include "BikeSystem.h"
#include "BikeSystem.h"
#include <iostream>
using namespace std;

int BikeSystem::search(const char *user_name, int start_x, int start_y, int acceptive_comfort_rating) const {
//请在此输入实现，请不要更改其余已有api
    int ans_index = -1;
    for(int i = 0; i < size; ++i) {
        if(!bikes[i]->is_occupied() && bikes[i]->get_comfort() >= acceptive_comfort_rating) {
            if(ans_index == -1) {
                ans_index = i;
            }
            else{
                if(bikes[i]->compute_dis(start_x, start_y) < bikes[ans_index]->compute_dis(start_x, start_y)) {
                    ans_index = i;
                }
                else if(bikes[i]->compute_dis(start_x, start_y) == bikes[ans_index]->compute_dis(start_x, start_y) &&
                        bikes[i]->get_comfort() > bikes[ans_index]->get_comfort()) {
                    ans_index = i;
                }
            }

        }
    }
    if(ans_index != -1) {
        cout << user_name << " selected " << bikes[ans_index]->get_serial() << endl;
    }
    else{
        cout << user_name << " found no bikes available\n";
    }
    return ans_index;
}

BikeSystem::BikeSystem(){
    this->capability = INIT_CAP;
    this->bikes = new Bike*[this->capability];
    this->size = 0;
    this->incremental = this->capability / 2;
    for(int i = 0; i < this->capability; ++i){
        this->bikes[i] = nullptr;
    }
}
BikeSystem::~BikeSystem() {
    release(this->bikes, this->size);
}
bool BikeSystem::unlock_bike(int bike_indicator) {
    if(bike_indicator >= this->size || this->bikes[bike_indicator] == NULL){
        cerr << "fail to unlock with bike indicator " << bike_indicator << endl;
        return false;
    }
    return this->bikes[bike_indicator]->unlock();
}
int BikeSystem::ride_record(int bike_indicator, int destination_x, int destination_y) {
    if(bike_indicator >= this->size || this->bikes[bike_indicator] == NULL){
        cerr << "fail to ride with bike indicator " << bike_indicator << endl;
        return 0;
    }
    return this->bikes[bike_indicator]->move_to(destination_x, destination_y);
}
int BikeSystem::lock_bike(int bike_indicator) {
    if(bike_indicator >= this->size || this->bikes[bike_indicator] == NULL){
        cerr << "fail to lock with bike indicator " << bike_indicator << endl;
        return 0;
    }
    return this->bikes[bike_indicator]->lock();
}

void BikeSystem::add(Bike *bike) {
    if(this->size == this->capability){ // realloc
        cout << "realloc" << endl;
        this->capability += this->incremental;
        if(INIT_CAP / this->incremental < 8) {
            this->incremental /= 2;
            if(this->incremental < 1) this->incremental = 1;
        }
        Bike** new_bikes = new Bike*[this->capability];
        memcpy(new_bikes, this->bikes, this->size * sizeof(Bike*));
        for(int i = this->size; i < this->capability; ++i){
            new_bikes[i] = nullptr;
        }
        delete []this->bikes;
        this->bikes = new_bikes;
    }
    this->bikes[this->size] = bike;
    ++this->size;
}
void BikeSystem::release(Bike **bike_list, int num) {
    if(bike_list == nullptr){
        return;
    }
    for(int i = 0; i < num; ++i){
        if(bike_list[i] != nullptr){
            delete bike_list[i];
        }
    }
    delete []bike_list;
    bike_list = nullptr;
}