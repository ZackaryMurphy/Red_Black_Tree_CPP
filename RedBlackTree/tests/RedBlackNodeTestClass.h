/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   RedBlackNodeTestClass.h
 * Author: MBlock
 *
 * Created on Jul 1, 2016, 12:59:34 PM
 */

#ifndef REDBLACKNODETESTCLASS_H
#define REDBLACKNODETESTCLASS_H
#include<string>
#include <cppunit/extensions/HelperMacros.h>
#include "redblacknode.h"

class RedBlackNodeTestClass : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(RedBlackNodeTestClass);

    CPPUNIT_TEST(testRedBlackNode);
    CPPUNIT_TEST(testGet_parent);
    CPPUNIT_TEST(testGet_left);
    CPPUNIT_TEST(testGet_right);
    CPPUNIT_TEST(testGet_key);
    CPPUNIT_TEST(testGet_value);
    CPPUNIT_TEST(testSet_parent);
    CPPUNIT_TEST(testSet_left);
    CPPUNIT_TEST(testSet_right);
    CPPUNIT_TEST(testSet_value);
    CPPUNIT_TEST(testInsert);
    CPPUNIT_TEST(testSet_color);
    CPPUNIT_TEST(testGet_color);

    CPPUNIT_TEST_SUITE_END();

public:
    RedBlackNodeTestClass();
    virtual ~RedBlackNodeTestClass();
    void setUp();
    void tearDown();

private:
    void testRedBlackNode();
    void testGet_parent();
    void testGet_left();
    void testGet_right();
    void testGet_key();
    void testGet_value();
    void testSet_parent();
    void testSet_left();
    void testSet_right();
    void testSet_value();
    void testInsert();
    void testSet_color();
    void testGet_color();
    RedBlackNode<int, int>* int_int_node;
    RedBlackNode<char, int>* char_int_node;
    RedBlackNode<int, int>* second_int_int_node;
    RedBlackNode<int, int>* third_int_int_node;
    RedBlackNode<int, int>* fourth_int_int_node;
    RedBlackNode<std::string, char>* string_char_node;
    RedBlackNode<std::string, char>* second_string_char_node;
    RedBlackNode<std::string, char>* third_string_char_node;

};

#endif /* REDBLACKNODETESTCLASS_H */

