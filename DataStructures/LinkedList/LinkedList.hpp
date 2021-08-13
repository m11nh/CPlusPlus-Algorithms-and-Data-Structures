#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <ostream>
class Node {
public: 
    Node(int, Node*);
    Node(int);  

    ~Node(); 

    auto getValue() -> int;
    auto setValue(int) -> void;
    auto getNext() -> Node*; 
    auto setNext(Node*) -> void; 

private:
    int value_;
    Node* next_; 
};

class LinkedList {
public:
    // Constructors
    LinkedList();

    // Methods
    auto insertFront(int) -> void; 
    auto insertBack(int) -> void; 
    auto deleteFront() -> Node*; 
    auto deleteBack() -> Node*; 
    auto deletePos(int) -> Node*; 
    auto clear() -> void; 

    // Member operator overloads
    auto operator==(const LinkedList&) -> bool; 
    auto operator+=(const LinkedList&) -> void; 

    // Friend operator overloads
    auto friend operator<<(std::ostream&, const LinkedList) -> std::ostream; 
    auto friend operator+(const LinkedList&, const LinkedList&) -> LinkedList; 

    int size(); 

private:
    // Find a way to use better pointers than raw pointers
    Node* head_; 
    Node* tail_;
    int size_; 
};

#endif