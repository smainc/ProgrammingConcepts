
#pragma once
#include "StackADT.h"
#include <stdint.h> 
// for printf function used below
/*
    The Stack is a LIFO data structure. The last element added to the stack is the first element to be removed. 
    Stack is a linear data structure.
    They are used when the order of the elements is important.
    Stacks are most commonly used in computer programming for undoing actions.
    
    The following are the operations that can be performed on a stack:
    push(value) – adds a new element to the top of the stack
    pop() – removes the top element from the stack
    isEmpty() – checks if the stack is empty
    top() – returns the top element of the stack
    print() – prints the stack

    The following are the characteristics of a stack:
    LIFO – Last In First Out
    Linear – Linear in time and space
    Push – O(1)
    Pop – O(1)
    Search – O(n)
    Insert – O(n)
    Delete – O(n)

*/
#define DEFAULT_STACK_SIZE 100
template <typename type>
class Stack: public StackADT<type>{
public:
    Stack(){
        stack = new type[DEFAULT_STACK_SIZE];
        top = -1;
        capacity = DEFAULT_STACK_SIZE;
    }
    Stack(int size){
        this->capacity = size;
        this->stack = new type[size];
        this->top = -1;
    }
    Stack(const Stack<type>& other){
        this->capacity = other.capacity;
        this->stack = new type[other.capacity];
        this->top = other.top;
        for(int i=0; i<=this->top; i++){
            this->stack[i] = other.stack[i];
        }
    }
    virtual void push(type value) override{
        if(top==capacity){
            //throw "Stack is full";
            std::cout << "Stack is full" << std::endl;
            return;
        }
        stack[++top] = value;
    }
    virtual type pop() override{
        if(top==-1){
            //throw "Stack is empty";
            std::cout << "Stack is empty" << std::endl;
            return NULL;
        }
        return stack[top--];

    }
    virtual bool isEmpty() override{
        return top==-1;
    }
    virtual type top() override{
        return stack[top];
    }
    virtual ~Stack(){
        if (stack != nullptr)
            delete[] stack;
    }
    virtual void print() override{
        if(top==-1){
            std::cout << "Stack is empty" << std::endl;
        }
        else
            for (int i = 0; i <= top; i++){
                //using printf to print the value
                printf("%d ", stack[i]);
            }
        printf("\n");
    }
protected:
    type* stack;
    int top;
    int capacity;
};

