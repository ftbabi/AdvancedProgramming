//
// Created by 邵一迪 on 2018/9/11.
//

#ifndef OJ_QUADRATICEQUATION_H
#define OJ_QUADRATICEQUATION_H

#include <iostream>
using std::cout;
using std::endl;

class QuadraticEquation {
private:
    int a,b,c;
//    int array[8];

public:
    QuadraticEquation(int a,int b,int c);//构造函数，a不为0
    int getA()const;//获取参数a，并打印出来，需要输出换行
    int getB()const;//获取参数b，并打印出来，需要输出换行
    int getC()const;//获取参数c，并打印出来，需要输出换行
    int getDiscriminant();//获取判别式，并打印出来，需要输出换行
    double getRoot1();//larger ans
    double getRoot2();//打印结果，需要输出换行

//    void show();
//    char &operator[](int n);
};


#endif //OJ_QUADRATICEQUATION_H
