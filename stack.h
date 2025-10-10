#ifndef STACK_H
#define STACK_H

#include <vector>
#include <stdexcept>
#include <iostream>

// Use inheritance from std::vector (choose public/private) as appropriate
template <typename T>
class Stack : private std::vector<T>
{
public:
    Stack():std::vector<T>(){}
    ~Stack(){}
    bool empty() const{
        return std::vector<T>::empty();
    }
    size_t size() const{
        return std::vector<T>::size();
    }
    void push(const T& item){
        std::vector<T>::push_back(item);
    }
    void pop(){
        if(!Stack<T>::empty()){
            std::vector<T>::pop_back();
        }
        else{
            throw std::underflow_error("Empty stack");
        }
    } // throws std::underflow_error if empty
    const T& top() const{
        if(!Stack<T>::empty()){
            return std::vector<T>::back();
        }
        else{
            throw std::underflow_error("Empty stack");
        }
    } // throws std::underflow_error if empty
    // Add other members only if necessary

    void print(){
        typename std::vector<T>::iterator it;
        for(it = this -> begin(); it != this -> end(); ++it){
            std::cout << *it << " ";
        }
        std::cout << std::endl;
    }
};


#endif