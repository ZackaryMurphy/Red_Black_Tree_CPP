/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   RedBlackNodeTestClass.cpp
 * Author: MBlock
 *
 * Created on Jul 1, 2016, 12:59:35 PM
 */

#include "RedBlackNodeTestClass.h"
#include <iostream>


CPPUNIT_TEST_SUITE_REGISTRATION(RedBlackNodeTestClass);

RedBlackNodeTestClass::RedBlackNodeTestClass() {
}

RedBlackNodeTestClass::~RedBlackNodeTestClass() {
}

void RedBlackNodeTestClass::setUp() {
    int testSet = 1000;
    std::string testString = "ThisIsATest";
    char testChar = '?';
    int_int_node = new RedBlackNode<int,int>(100, -100);
    second_int_int_node = new RedBlackNode<int,int>(200, -200);
    third_int_int_node = new RedBlackNode<int, int>(-100, 100);
    fourth_int_int_node = new RedBlackNode<int, int>(-200, 200);
    char_int_node = new RedBlackNode<char, int>('X', testSet);
    string_char_node = new RedBlackNode<std::string, char>("A_Test", '!');
    second_string_char_node = new RedBlackNode<std::string, char>(testString, testChar);
    third_string_char_node = new RedBlackNode<std::string, char>("B_Test", 'B');
}

void RedBlackNodeTestClass::tearDown() {
    delete int_int_node;
    delete second_int_int_node;
    delete third_int_int_node;
    delete fourth_int_int_node;
    delete char_int_node;
    delete string_char_node;
    delete second_string_char_node;
    delete third_string_char_node;
}

void RedBlackNodeTestClass::testRedBlackNode() {
    int contained_key = 42;
    int contained_value = -42;
    RedBlackNode<int, int> redBlackNode(contained_key, contained_value);
    if (redBlackNode.get_key() != 42 || redBlackNode.get_value() != -42) {
        CPPUNIT_ASSERT(false);
    }
}

void RedBlackNodeTestClass::testGet_parent() {
    RedBlackNode<int, int>* result = int_int_node->get_parent();
    if (result != nullptr) {
        CPPUNIT_ASSERT(false);
    }
    int_int_node->insert(second_int_int_node);
    int_int_node->insert(third_int_int_node);
    result = second_int_int_node->get_parent();
    if (result != int_int_node) {
        CPPUNIT_ASSERT(false);
    }
}

void RedBlackNodeTestClass::testGet_left() {
    int_int_node->insert(second_int_int_node);
    int_int_node->insert(third_int_int_node);
    RedBlackNode<int, int>* result = int_int_node->get_left();
    if (result != third_int_int_node) {
        CPPUNIT_ASSERT(false);
    }
}

void RedBlackNodeTestClass::testGet_right() {
    int_int_node->insert(second_int_int_node);
    int_int_node->insert(third_int_int_node);
    RedBlackNode<int, int>* result = int_int_node->get_right();
    if (result != second_int_int_node) {
        CPPUNIT_ASSERT(false);
    }
}

void RedBlackNodeTestClass::testGet_key() {
    if (string_char_node->get_key() != "A_Test") {
        CPPUNIT_ASSERT(false);
    }
}

void RedBlackNodeTestClass::testGet_value() {
    if (char_int_node->get_value() != 1000) {
        CPPUNIT_ASSERT(false);
    }
}

void RedBlackNodeTestClass::testSet_parent() {
    RedBlackNode<int, int>* par_node = new RedBlackNode<int, int>(7,7);
    RedBlackNode<int, int> redBlackNode(13, 13);
    redBlackNode.set_parent(par_node);
    if (redBlackNode.get_parent() != par_node) {
        CPPUNIT_ASSERT(false);
    }
}

void RedBlackNodeTestClass::testSet_left() {
    RedBlackNode<char, char>* l_node = new RedBlackNode<char, char>('A', 'B');
    RedBlackNode<char, char> redBlackNode('B', 'C');
    redBlackNode.set_left(l_node);
    if (redBlackNode.get_left() != l_node) {
        CPPUNIT_ASSERT(false);
    }
}

void RedBlackNodeTestClass::testSet_right() {
    RedBlackNode<int, int>* r_node = new RedBlackNode<int, int>(9,9);
    RedBlackNode<int, int> redBlackNode(6,9);
    redBlackNode.set_right(r_node);
    if (redBlackNode.get_right() != r_node) {
        CPPUNIT_ASSERT(false);
    }
}

void RedBlackNodeTestClass::testSet_value() {
    second_string_char_node->set_value('$');
    if (second_string_char_node->get_value() != '$') {
        CPPUNIT_ASSERT(false);
    }
}

void RedBlackNodeTestClass::testInsert() {
    int_int_node->insert(second_int_int_node);
    int_int_node->insert(third_int_int_node);
    int_int_node->insert(fourth_int_int_node);
    if (int_int_node->get_left()->get_left() != fourth_int_int_node) {
        CPPUNIT_ASSERT(false);
    }
}

void RedBlackNodeTestClass::testSet_color() {
    RedBlackColor new_color = RedBlackColor::RED;
    RedBlackNode<char, char> redBlackNode('U', 'S');
    redBlackNode.set_color(new_color);
    if (redBlackNode.get_color() != RedBlackColor::RED) {
        CPPUNIT_ASSERT(false);
    }
}

void RedBlackNodeTestClass::testGet_color() {
    if (int_int_node->get_color() != RedBlackColor::RED) {
        CPPUNIT_ASSERT(false);
    }
}

