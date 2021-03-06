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
    auto getFront() -> Node*; 
    auto getBack() -> Node*; 
    auto clear() -> void; 
    auto isEmpty() -> bool;

    // Member operator overloads
    auto operator==(const LinkedList&) -> bool; 

    // Friend operator overloads
    auto friend operator<<(std::ostream&, const LinkedList) -> std::ostream&; 
    auto friend operator+(LinkedList&, LinkedList&) -> LinkedList; 

    int size(); 

private:
    // Find a way to use better pointers than raw pointers
    Node* head_; 
    Node* tail_;
    int size_; 
};

#endif