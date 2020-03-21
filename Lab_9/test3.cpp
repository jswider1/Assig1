#include <iostream>
#include <cstdlib>
#include "stack_pair.h"

using namespace std;

void test3() {
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

    cout << "Test 3! Program should fail: \n" << flush;

    pair.push_a(12);
}

