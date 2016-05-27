#include <iostream>

#include "edge.h"

void edge_test();

int main() {

    edge_test();

    return 0;
}

void edge_test() {
    Edge<int> test_edge1;
    Edge<int> test_edge2;

    test_edge1 == test_edge2 ? std::cout<<"Success\n" : std::cout<<"Failure\n";
}
