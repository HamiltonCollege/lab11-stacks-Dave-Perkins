#include <iostream>
#include "Stack.h"
#include "SLLBasedStack.h"

using namespace std;

void run_stack_test(Stack & stack) {
    cout << "Pushing:";
    for (int element = 1; element <= 5; element++) {
        stack.push(element);
        cout << " " << element;
    }
    cout << endl;

    cout << "Popping:";
    while (stack.size() != 0) {
        cout << " " << stack.pop();
    }
    cout << endl;
}

int main() {
    SLLBasedStack stack;
    run_stack_test(stack);
    return 0;
}
