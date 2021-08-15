#include "LinkedList.hpp"

#include <iostream>
#include <stdexcept>

Node::Node(int value, Node* next) : value_{value}, next_{next} {} 
Node::Node(int value) : Node(value, nullptr) {} 

Node::~Node() = default; 

auto Node::getValue() -> int { return value_; }
auto Node::setValue(int value) -> void { value_ = value; }
auto Node::getNext() -> Node* { return next_; }
auto Node::setNext(Node* next) -> void { next_ = next; }

LinkedList::LinkedList() : head_{nullptr}, tail_{nullptr}, size_{0} {}  

auto LinkedList::insertFront(int value) -> void  
{
    auto new_node = new Node(value); 
    if (size == 0) {
        head_ = new_node; 
        tail_ = new_node;
    } else {
        new_node->setNext(head_); 
        head_ = new_node;    
    }
    ++size_; 
}

auto LinkedList::insertBack(int value) -> void 
{
    auto new_node = new Node(value); 
    if (size == 0) {
        head_ = new_node; 
        tail_ = new_node;
    } else {
        tail_ = new_node;
    }
    ++size_; 
}

auto LinkedList::deleteFront() -> Node* 
{
    if (size == 0) {
        throw std::runtime_error("cannot delete from empty list"); 
    } else {
        return deletePos(0); 
    }
}

auto LinkedList::deleteBack() -> Node* 
{
    if (size == 0) {
        throw std::runtime_error("cannot delete from empty list"); 
    } else {
        return deletePos(size_ - 1); 
    }
}

auto LinkedList::deletePos(int pos) -> Node*
{
    if (pos < 0 or pos >= size_) {
        throw std::runtime_error("position provided out of bounds"); 
    } 
    auto curr = head_; 
    auto prev = static_cast<Node*>(nullptr);
    for (int i = 0; i < pos; ++i) {
        prev = curr; 
        curr = curr->getNext(); 
    }
    if (prev == nullptr) {
        head_ = head_->getNext(); 
    } else if (curr = tail_) {
        prev->setNext(nullptr);
        tail_ = prev; 
    } else {
        prev->setNext(curr->getNext());
    }
    --size_;
    return curr; 
}

auto LinkedList::clear() -> void 
{
    head_ = nullptr; 
    tail_ = nullptr;
    size_ = 0; 
}

auto LinkedList::isEmpty() -> bool
{
    return size_ == 0; 
}

auto operator<<(std::ostream& os, const LinkedList ll) -> std::ostream&
{
    auto curr = ll.head_; 
    for (auto curr = ll.head_; curr != nullptr; curr = curr->getNext()) {
        os << curr->getValue() << " -> "; 
    }
    os << " X\n"; 
    return os;
}

auto operator+(LinkedList& l1, LinkedList& l2) -> LinkedList
{
    auto new_ll = LinkedList(); 
    if (l1.size_ > 0) {
        new_ll.head_ = l1.head_; 
        l1.tail_->setNext(l2.head_);
        new_ll.tail_ = l2.tail_;
        new_ll.size_ = l1.size_ + l2.size_; 
    } else {
        new_ll.head_ = l2.head_; 
        new_ll.tail_ = l2.tail_; 
        new_ll.size_ = l2.size_; 
    }
    return new_ll;
}

int main() {
    auto list = LinkedList(); 
    list.insertFront(5); 
}