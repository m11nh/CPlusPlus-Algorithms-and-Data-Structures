#include "LinkedList.hpp"
#include <assert.h>
#include <sstream>
#include <iostream>

auto testDefaultConstructor() -> void;
auto testInsertFront() -> void; 
auto testDefaultConstructor() -> void; 
auto testInsertFront() -> void; 
auto testInsertBack() -> void; 
auto testDeleteFront() -> void; 
auto testDeletePos() -> void; 
auto testGetFront() -> void; 
auto testGetBack() -> void; 
auto testClear() -> void; 
auto testIsEmpty() -> void; 
auto testOperatorPlus() -> void;
auto testOperatorOStream() -> void;
auto testSize() -> void;

auto main() -> int {
    testDefaultConstructor(); 
    testInsertFront(); 
    testInsertBack(); 
    testDeleteFront(); 
    testDeletePos(); 
    testGetFront(); 
    testGetBack(); 
    testClear(); 
    testIsEmpty(); 
    testOperatorPlus();
    testOperatorOStream();
    testSize();
    std::cout << "All tests passed\n"; 
}

auto testDefaultConstructor() -> void {
    auto ll = LinkedList(); 
    assert(ll.getFront() == nullptr); 
}

auto testInsertFront() -> void {
    auto ll = LinkedList(); 
    ll.insertFront(3); 
    auto n = ll.getFront(); 
    assert(n->getValue() == 3); 
    assert(n->getNext() == nullptr); 
    ll.insertFront(4); 
    n = ll.getFront(); 
    assert(n->getValue() == 4); 
    assert(n->getNext()->getValue() == 3); 
}

auto testInsertBack() -> void {
    auto ll = LinkedList(); 
    ll.insertFront(3); 
    ll.insertFront(4); 
    ll.insertBack(5); 
    assert(ll.getBack()->getValue() == 5);  
}

auto testDeleteFront() -> void {
    auto ll = LinkedList(); 
    ll.insertFront(3);
    ll.deleteFront(); 
    assert(ll.size() == 0); 
}

auto testDeletePos() -> void {
    auto ll = LinkedList(); 
    ll.insertFront(1); 
    ll.deletePos(0);
    assert(ll.size() == 0); 
}

auto testGetFront() -> void {
    auto ll = LinkedList(); 
    ll.insertFront(1); 
    assert(ll.getFront()->getValue() == 1); 
}

auto testGetBack() -> void {
    auto ll = LinkedList(); 
    ll.insertBack(1); 
    assert(ll.getBack()->getValue() == 1); 
}

auto testClear() -> void {
    auto ll = LinkedList(); 
    ll.insertFront(1); 
    ll.insertFront(1); 
    ll.insertFront(1); 
    ll.clear(); 
    assert(ll.size() == 0); 
}

auto testIsEmpty() -> void {
    auto ll = LinkedList(); 
    assert(ll.isEmpty() == true); 
    ll.insertFront(4); 
    assert(ll.isEmpty() == false); 
}

auto testOperatorPlus() -> void {
    auto ll1 = LinkedList(); 
    auto ll2 = LinkedList(); 
    ll1.insertFront(1); 
    ll1.insertBack(2); 
    ll2.insertFront(3); 
    ll2.insertBack(4); 
    auto ll3 = ll1 + ll2;
    assert(ll3.getFront()->getValue() == 1); 
    assert(ll3.getBack()->getValue() == 4); 
    assert(ll3.size() == 4);
}

auto testOperatorOStream() -> void {
    auto ll = LinkedList(); 
    auto ss = std::stringstream(); 
    ll.insertFront(1); 
    ll.insertBack(2); 
    ss << ll; 
    assert(ss.str() == "1 -> 2 -> X\n");
}

auto testSize() -> void {
    auto ll = LinkedList(); 
    assert(ll.size() == 0); 
    ll.insertFront(1); 
    assert(ll.size() == 1); 
}