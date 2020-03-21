#include <iostream>
#include <cstdlib>
#include "stack_pair.h"


using namespace std;

void test1() {
    stack_pair<int> pair;
    pair.push_a(1);
    pair.push_a(2);
    pair.push_a(15);
    pair.push_b(10);
    pair.push_b(20);

    if(pair.pop_a() != 15){
        cout << "Wrong value popped from a" << endl;
        exit(1);
    }

    if(pair.pop_a() != 2){
        cout << "Wrong value popped from a" << endl;
        exit(1);
    }

    if(pair.pop_a() != 1){
        cout << "Wrong value popped from a" << endl;
        exit(1);
    }

    if(pair.pop_b() != 20){
        cout << "Wrong value popped from b" << endl;
        exit(1);
    }

    if(pair.pop_b() != 10){
        cout << "Wrong value popped from b" << endl;
        exit(1);
    }

    cout << "Test 1 passed! " << endl;
}

