#include <iostream>
#include <cstdlib>
#include "stack_pair.h"

using namespace std;

void test2() {
    stack_pair<int> pair;
    pair.push_a(1);
    pair.push_a(2);
    pair.push_a(15);
    pair.push_b(10);
    pair.push_b(20);
    pair.push_a(15);
    pair.push_b(10);
    pair.push_b(20);
    pair.push_a(15);
    pair.push_b(10);
    pair.push_b(20);
    pair.push_a(15);
    pair.push_b(10);
    pair.push_b(20);
    pair.push_a(15);
    pair.push_b(10);
    pair.push_b(20);
    pair.push_a(15);
    pair.push_b(10);
    pair.push_b(20);
    pair.push_a(15);
    pair.push_b(10);
    pair.push_b(20);
    pair.push_a(15);
    pair.push_b(10);
    pair.push_b(20);
    pair.push_a(15);
    pair.push_b(10);
    pair.push_b(20);
    pair.push_b(13);

    if(!pair.is_full_a()){
        cout << "Stack full function for a should return true" << endl;
        exit(1);
    }

    if(!pair.is_full_b()){
        cout << "Stack full function for b should return true" << endl;
        exit(1);
    }

    cout << "Test 2 passed! " << endl;
}
