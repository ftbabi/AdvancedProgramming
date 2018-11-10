#include <iostream>
#include "Manage.h"

using namespace std;

int main() {
    Manage m;

    bool run = true;
    while(run) {
        run = m.execute();
    }
    return 0;
}