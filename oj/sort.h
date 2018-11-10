//
// Created by 邵一迪 on 2018/9/22.
//

#ifndef OJ_MYSORT_TEMPLATE_H
#define OJ_MYSORT_TEMPLATE_H

#include<iostream>
using namespace std;

template <class T>
void sort(T *array, int length)
{
    for(int i = 0; i < length; ++i){
        int min_index = i;
        for(int j = i+1; j < length; ++j){
            if(array[j] < array[min_index])
            {
                min_index = j;
            }
        }
        if(min_index != i){
            T temp = array[i];
            array[i] = array[min_index];
            array[min_index] = temp;
        }
    }
}

#endif //OJ_MYSORT_TEMPLATE_H
