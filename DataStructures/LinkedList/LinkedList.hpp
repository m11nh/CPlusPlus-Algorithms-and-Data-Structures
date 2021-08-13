#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <ostream>
class Node {
public: 
    Node(int value, Node* next) : value_{value}, next_{next} {}
    Node(int value) : Node(value, nullptr) {} 

private: 
    int value_;
    Node* next_; 
};

class LinkedList {
public:
    // Constructors
    LinkedList();

    // Methods
    auto insertFront(int val) -> void; 
    auto insertBack(int val) -> void; 
    auto deleteFront() -> void; 
    auto deleteBack() -> void; 
    auto deletePos(int i) -> void; 
    auto clear() -> void; 

    // Member operator overloads
    auto operator==(LinkedList& const) -> bool; 
    auto operator+=(LinkedList& const) -> void; 

    // Friend operator overloads
    auto friend operator<<(std::ostream& os, const LinkedList) -> std::ostream; 
    auto friend operator+(LinkedList& const l1, LinkedList& const l2) -> LinkedList; 

    int size(); 

private:
    // Find a way to use better pointers than raw pointers
    Node* head_; 
    Node* tail_;
};

#endif