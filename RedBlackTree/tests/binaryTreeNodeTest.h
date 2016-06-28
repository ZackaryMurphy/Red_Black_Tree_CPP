
#ifndef BINARYTREENODETEST_H
#define BINARYTREENODETEST_H

#include <cppunit/extensions/HelperMacros.h>
#include "binarytreenode.h"

class binaryTreeNodeTest : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(binaryTreeNodeTest);

    CPPUNIT_TEST(testBinaryTreeNode);
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

    CPPUNIT_TEST_SUITE_END();

public:
    binaryTreeNodeTest();
    virtual ~binaryTreeNodeTest();
    void setUp();
    void tearDown();

private:
    void testBinaryTreeNode();
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
    
    BinaryTreeNode<int, int>* int_int_test_node;
    BinaryTreeNode<char, int>* char_int_test_node;
    BinaryTreeNode<int, char>* int_char_test_node;
};

#endif /* BINARYTREENODETEST_H */

