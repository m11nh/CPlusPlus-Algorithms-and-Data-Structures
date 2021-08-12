#ifndef LINKEDLIST_H
#define LINKEDLIST_H

class Node {
public: 
    Node(int value, Node* next) : value_{value}, next_{next} {}
    Node(int value) : Node(value, nullptr) {} 

private: 
    int value_;
    Node* next_; 
}

// Linked list, only takes in integers
class LinkedList {
public:
    // Constructors
    LinkedList() : head_{nullptr}, tail_{nullptr} {}

    // Methods
    auto insertFront(int val) -> void; 
    auto insertBack(int val) -> void; 
    auto deleteFront() -> void; 
    auto deleteBack() -> void; 

    void operator<<(std::stream) {

    }

    size_t size(); 
    /*
        insertFront
        insertBack
        size
        deleteFront
        deleteEnd
        deletePos
        clear
        
        << 
    */

private:
    Node head_; 
    Node tail_;
}

#endif