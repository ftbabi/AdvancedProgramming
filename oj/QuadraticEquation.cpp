//
// Created by 邵一迪 on 2018/9/11.
//

#include "QuadraticEquation.h"
#include <cmath>

QuadraticEquation::QuadraticEquation(int i_a, int i_b, int i_c) :a(i_a), b(i_b), c(i_c){}

const double EPS = 0.0000001;

int QuadraticEquation::getA() const {
    cout << a << endl;

    return a;
}

int QuadraticEquation::getB() const {
    cout << b << endl;

    return b;
}

int QuadraticEquation::getC() const {
    cout << c << endl;

    return c;
}

int QuadraticEquation::getDiscriminant() {
    int delta = b*b-4*a*c;
    cout << delta << endl;

    return delta;
}

double QuadraticEquation::getRoot1() {
    int delta = b*b-4*a*c;
    double root = 0;
    if(delta < 0)
    {
        root = 0;
    }
    else if(delta == 0)
    {
        root = -b/(double(2*a));
    }
    else
    {
        if(a > 0)
            root = (-b + sqrt(double(delta)))/(2*a);
        else
            root = (-b - sqrt(double(delta)))/(2*a);
    }

    if(fabs(root) < EPS)
    {
        root = 0;
    }

    cout << root << endl;

    return root;
}

double QuadraticEquation::getRoot2() {
    int delta = b*b-4*a*c;
    double root = 0;
    if(delta < 0)
    {
        root = 0;
    }
    else if(delta == 0)
    {
        root = -b/(double(2*a));
    }
    else
    {
        if(a > 0)
            root = (-b - sqrt(double(delta)))/(2*a);
        else
            root = (-b + sqrt(double(delta)))/(2*a);
    }

    if(fabs(root) < EPS)
    {
        root = 0;
    }

    cout << root << endl;

    return root;
}