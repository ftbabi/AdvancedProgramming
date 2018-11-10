#include <iostream>
#include "QuadraticEquation.h"
#include "sort.h"
#include "Queue.h"
#include <iomanip>
#include "Manager.h"
#include "Set.h"
#include "Bike.h"
#include "OfoBike.h"
#include "HelloBike.h"
#include "BikeSystem.h"
#include "Shell.h"


typedef int Data[4];

void process(Data d) {
    std::cout << sizeof(d);
}

int func(int n) {
    int ans;
    if(n > 0)
    {
        if(n == 1){
            ans = 0x19;
            return ans;
        }
        else{
            int tmp = func(n-1);
            int tmp2 = func(n-2);
            if(tmp2 < 0)
                tmp2 = tmp2 / 2 - 1;
            else
                tmp2 /= 2;
            ans = tmp + tmp2;
            return ans;
        }
    }
    else{
        ans = 2;
        return ans;
    }


}

int main() {
//    QuadraticEquation p(-1, 0, 0);
//
//    int a = p.getDiscriminant();
//
//    double result1 = p.getRoot1();
//    double result2 = p.getRoot2();

//    unsigned char data[] = {0x5F, 0xA0, 0xc7, 0xf0, 0x80, 0x7f, 0x07, 0x55};
//
//    for(int i = 0; i < 8; i += 2){
//        unsigned char a = data[i];
//        unsigned char b = data[i+1];
//        printf("x = %x, y = %x, %02x  %02x  %02x  %02x  %02x  %02x  %02x  %02x  %02x\n", a, b, a^b, a&b, a|b, ~a | ~b, a & ~b,
//            a && b, a || b, !a || !b, a && ~b);
//    }

//    int int_array[] = {4, 2 ,1 ,3};
//    sort(int_array, 4);
//    for( int i = 0 ; i < 4 ; i ++)
//        cout << int_array[i] << endl;
//
//    char char_array[] = {'c', 'd', 'a'};
//    sort(char_array, 3);
//    for( int i = 0 ; i < 3 ; i ++)
//        cout << char_array[i] << endl;
//    double double_array[] = {1.2, 0.3, 5.8, 1.9, 2.0};
//    sort(double_array , 5) ;
//    for( int i = 0 ; i < 5 ; i ++)
//        cout << double_array[i] << endl;

//    Queue<int> q;
//    q.push(1);
//    q.push(2);
//    q.push(3);
//    q.push(4);
//    q.pop();
//    q.show();
//
//    Queue<string> q2;
//    q2.push("test");
//    q2.push("queue");
//    q2.push("template");
//    cout << q2.front() << endl;
//    q2.pop();
//    q2.show();

//    int a = 213;
//    for(int i = 0; i < 17; ++i)
//    {
//        int b = a * 2 / 1000;
//        a = (a*2) % 1000;
//        cout << b << '\t' << a << endl;
//    }

//    float test = 12.345678;
//    cout << setiosflags(ios_base::fixed)<< setprecision(2) << test << endl << test;


//    char a[] = {0x56, 0x69, 0x72, 0x74,
//                0x75, 0x61, 0x6c, 0x20,
//                0x6d, 0x65, 0x6d, 0x6f,
//                0x72, 0x79, 0x20, 0x69,
//                0x73, 0x20, 0x61, 0x6e,
//                0x20, 0x61, 0x62, 0x73,
//                0x74, 0x72, 0x61, 0x63,
//                0x74, 0x69, 0x6f, 0x6e,
//                0X20, 0X6F, 0X66, 0X20,
//                0x6d, 0X61, 0X69, 0X6E,
//                0x20, 0x6d, 0x65, 0x6d,
//                0x6f, 0x72, 0x79, 0x2e,
//                0x00, 0x25, 0x64, 0x20};
//    char b[] = { 0x2c, 0x20, 0x09, 0x00};
//    char c[] = {0x25, 0x64, 0x00};

//    char d[] = {0x25, 0x64, 0x20, 0x25, 0x63, 0x20, 0x25, 0x64, 0x00};
//    char e[] = {0x25, 0x64, 0x20, 0x25, 0x64, 0x00};
//    char f[] = {0x57, 0x6f, 0x77, 0x21, 0x20, 0x59, 0x6f, 0x75, 0x27, 0x76, 0x65, 0x20,
//    0x64, 0x65, 0x66, 0x75, 0x73, 0x65, 0x64, 0x20, 0x74, 0x68, 0x65, 0x20, 0x73, 0x65,
//    0x63, 0x72, 0x65, 0x74, 0x20, 0x73, 0x74, 0x61, 0x67, 0x65, 0x21, 0x00};
//    char g[] = {0x65, 0x6e, 0x6d, 0x61, 0x64, 0x30, 0x00};
//    char h[] = {0x57, 0x74, 0x4f, 0x54, 0x4f, 0x00};
//    float a = 1.2;
//    float b = 1;
//    float c = a-b;
//    cout << c;

//    Data d;
//    process(d);

//    List<int> l;
//    List<int>::iterator it = l.begin();
//    it = l.insert(it, 0);
//    it = l.insert(it, 1);
//    it = l.insert(it, 2);
//    ++it;
//    it = l.erase(it);
//    for(it = l.begin(); it != l.end(); it++){
//        cout << *it << endl;
//    }

//    Bike *tmp = new OfoBike("ofo10", 40, 15, 4);
//    tmp->unlock();
//    tmp->unlock();
//    cout << tmp->lock() << endl;
//    cout << tmp->lock() << endl;
//
//    Bike *tmp2 = new OfoBike("ofobike09", 15, 55, 3);
//    tmp2->unlock();
//    tmp2->move_to(90, 85);
//    cout << tmp2->lock() << endl;
//
//    BikeSystem bs;
//    bs.add(new OfoBike("ofo05", 30, 60, 6));
//    bs.add(new HelloBike("hellobike01", "hellobike_elock15", 0, 40, 4));
//    bs.add(new HelloBike("hellobike02", "hellobike_elock15", 30, 60, 7));
//    bs.add(new HelloBike("hellobike03", "hellobike_elock15", 40, 0, 6));
//    bs.add(new HelloBike("hellobike04", "hellobike_elock15", 0, 12, 5));
//    bs.add(new OfoBike("ofo01", 100, 100, 5));
//    bs.add(new OfoBike("ofo02", 90, 0, 6));
//    bs.add(new OfoBike("ofo03", 40, 70, 7));
//    bs.add(new OfoBike("ofo04", 70, 0, 8));
//
//    int idx1 = bs.search("xiaoming", 50, 50, 7);
//    int idx2 = bs.search("xiaohong", 50, 50, 9);
//    bs.unlock_bike(idx1);
//    bs.unlock_bike(idx2);
//    bs.ride_record(idx1, 100, 100);
//    bs.ride_record(idx2, 100, 80);
//    int cost = bs.lock_bike(idx1);
//    cout << cost << endl;

//    Shell *s = new Shell();
//    s->pwd();
//    delete s;

//    Shell *s = new Shell();
//    s->pwd();
//    s->cd("~/user/name/..");
//    s->pwd();
//    s->cd("/usr/local/bash");
//    s->cd("././../.../../hello/./");
//    s->pwd();
//    s->cd("hello/./hello");
//    s->pwd();
//    delete s;

//    Shell *s = new Shell();
//    s->distance("./Hello/World/Bash");
//    s->distance("/local/user/name");
//    delete s;

    string homedir = "/../../../../../././../homehomehomehome";
    Shell *s = new Shell(homedir);
    s->pwd();
    s->distance("~/.../.");
    s->cd("./~/./~/./.");
    s->pwd();
    s->cd("..");
    s->pwd();
    s->cd("/");
    s->pwd();
    s->distance("/");
    s->cd("../../../../../../../../..");
    s->pwd();
    s->cd("~/user/name/..");
    s->pwd();
    s->cd("/../usr/local/include/");
    s->pwd();
    s->distance("./usr/local/././include/");
    s->distance("/../../../../../../../../../usr/~/./././kk");
    s->distance("");
    s->distance("/");
    s->distance("../a/b");
    s->cd("/");
    s->pwd();
    s->distance("~");
    s->cd();
    s->pwd();

//    int ele[] = {-1, 2, 0, 3, -5, 3};
//    int length = sizeof(ele)/ sizeof(int);
//    Set set(ele, length);
//    cout << set.size() << endl;
//    cout << set.contains(5) << endl;
//    cout << set << endl;
//    set.add(6);
//    cout << set << endl;
//    cout << set.erase(0) << endl;
//    cout << set << endl;
//    cout << set.erase(1) << endl;
//    cout << set << endl;
//    int ele1[] = {-2, -1, 0, 1, 2};
//    int length1 = sizeof(ele1)/ sizeof(int);
//    int ele2[] = {1, 2, 3, 4, 5};
//    int length2 = sizeof(ele2)/ sizeof(int);
//    Set set1(ele1, length1);
//    Set set2(ele2, length2);
//    cout << set1+set2 << endl;
//    cout << set1-set2 << endl;
//    cout << (set1|set2) << endl;
////    cout << "size: " << set3.cur_size << " ";
////    for(int i = 0; i < set3.cur_size; ++i){
////        cout << set3.array[i] << " ";
////    }
////    cout << "hello\n";
//    cout << (set1&set2) << endl;
//    set1 += set2;
//
//    cout << set1 << endl;
//    set1 -= set2;
//    cout << set1 << endl;

//    int ele3[] = {0, 1, 2};
//    int length3 = sizeof(ele3)/ sizeof(int);
//    Set set3(ele3, length3);
//    Set set4;
//    cout << (set1 == set3) << endl;
//    cout << (set1 != set3) << endl;
//    cout << (set1 > set3) << endl;
//    cout << (set1 >= set3) << endl;
//    cout << (set1 < set3) << endl;
//    cout << (set1 <= set3) << endl;
//    cout << (set1 > set4) << endl;

    return 0;
}