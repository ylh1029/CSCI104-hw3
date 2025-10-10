#include "stack.h"
#include <iostream>

int main(){
    Stack<int> my_stack = Stack<int>();

    my_stack.push(3);
    my_stack.push(4);
    my_stack.print();

    std::cout << my_stack.top() << std::endl;
    my_stack.pop();
    my_stack.push(10);
    my_stack.push(15);
    std::cout << my_stack.top() << std::endl;
    my_stack.print();
    my_stack.pop();
    my_stack.print();
    return 0;
}