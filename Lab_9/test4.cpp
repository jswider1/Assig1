#include <cstdlib>
#include "stack_pair.h"

using namespace std;

void test4() {
    stack_pair<int> stack;

    cout << "Test 4! Program should fail: \n" << flush;

    stack.pop_a();
}
