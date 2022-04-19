#include <iostream>
#include <iomanip>
#include <chrono>
#include <cstring>
#include "Stack.h"
#include "SLLBasedStack.h"
//Uncomment for experiment with SLLBasedStackSlow
//#include "SLLBasedStackSlow.h"

using namespace std;

/**
 * Sort the given linked list using upsort_with_list,
 * print out the time it takes in milliseconds, and
 * output the sorted linked list.
 * @param list (a reference to) the linked list to sort.
 */
double time_stack_operations(Stack & stack, const size_t num_elements) { 
    std::chrono::time_point<std::chrono::high_resolution_clock> start_time = 
        std::chrono::high_resolution_clock::now();

    for (size_t element = 0; element < num_elements; element++) {
        stack.push(element);
    }
    for (size_t element = 0; element < num_elements; element++) {
        stack.pop();
    }

    std::chrono::time_point<std::chrono::high_resolution_clock> end_time = 
        std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> run_time = end_time - start_time;
    return chrono::duration_cast<chrono::milliseconds>(run_time).count();
}

void time_experiment(Stack & stack) {
    cout << "Legend:" << endl;
    cout << "    n    - the number of elements in the stack" << endl;
    cout << "    time - the running time (in ms) of n pushes and pops" << endl;
    cout << setw(10) << "n" << setw(10) << "time" << endl;
    for (size_t size = 1; size < 100000000; size *= 2) {
        cout << setw(10) << size << setw(10) << time_stack_operations(stack, size) << endl;
    }
}

void time_experiment(Stack & fast, Stack & slow) {
    cout << "Legend:" << endl;
    cout << "    n    - the number of elements in the stack" << endl;
    cout << "    fast - the running time (in ms) of n fast pushes and pops" << endl;
    cout << "    slow - the running time (in ms) of n slow pushes and pops" << endl;
    cout << setw(10) << "n" << setw(10) << "fast" << setw(10) << "slow" << endl;
    for (size_t size = 1; size < 100000000; size *= 2) {
        cout << setw(10) << size 
             << setw(10) << time_stack_operations(fast, size) 
             << setw(10) << time_stack_operations(slow, size) 
             << endl;
    }
}

// Controls operation of program
int main(int argc, char ** argv) {

    // Comment out these two lines for experiment with SLLBasedStackSlow.
    SLLBasedStack stack;
    time_experiment(stack);

    // Uncomment these lines for experiment with SLLBasedStackSlow.
    /*
    SLLBasedStack fast;
    SLLBasedStackSlow slow;
    time_experiment(fast, slow);
    */

    return 0;
}
