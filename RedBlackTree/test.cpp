#include <iostream>
#include <string>
#include "node.h"

void node_test();

template <class k, class v>
void node_get_test(Node<k, v>& test);

template <class k, class v>
void node_add_child_test(Node<k, v>& par, Node<k, v>& child);

int main() {

    node_test();
    return 0;
}


void node_test() {
    Node<int, int> intintNode(0,0);
    Node<int, int> childintintNode(1023, 1023);
    Node<std::string, int> strintNode("TestString", 255);
    Node<std::string, int> childStrintNode("ChildString", 42);
    node_get_test(intintNode);
    node_get_test(strintNode);
    node_add_child_test(intintNode, childintintNode);
    node_add_child_test(strintNode, childStrintNode);
}

template <class k, class v>
void node_get_test(Node<k,v>& test) {
    std::cout<<test.get_key() << std::endl;
    std::cout<<test.get_value() << std::endl;
}

template <class k, class v>
void node_add_child_test(Node<k,v>& par, Node<k,v>& child) {
    par.add_child(&child);
    std::cout<< par.get_child(child.get_key())->get_value() << std::endl;
    std::cout<< child.get_parent(par.get_key())->get_value() << std::endl;
}

