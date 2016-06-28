#include "binaryTreeNodeTest.h"
#include "binarytreenode.h"


CPPUNIT_TEST_SUITE_REGISTRATION(binaryTreeNodeTest);

binaryTreeNodeTest::binaryTreeNodeTest() {
}

binaryTreeNodeTest::~binaryTreeNodeTest() {
}

void binaryTreeNodeTest::setUp() {
    /*int_int_test_node = new BinaryTreeNode<int,int>(0, 42);
    char_int_test_node = new BinaryTreeNode<char, int>('!', 255);
    int_char_test_node = new BinaryTreeNode<int, char>(1, '%');*/
}

void binaryTreeNodeTest::tearDown() {
    /*delete int_int_test_node;
    delete char_int_test_node;
    delete int_char_test_node;*/
}

void binaryTreeNodeTest::testBinaryTreeNode() {
    char contained_key = '?';
    int contained_value = 99;
    BinaryTreeNode<char, int> binaryTreeNode(contained_key, contained_value);
    if (binaryTreeNode.get_key() != '?' || binaryTreeNode.get_value() != 99) {
        CPPUNIT_ASSERT(false);
    }
    //CPPUNIT_ASSERT(true);
}

void binaryTreeNodeTest::testGet_parent() {
    BinaryTreeNode<int, int> binaryTreeNode(10, 9999);
    BinaryTreeNode<int,int>* result = binaryTreeNode.get_parent();
    if (result != nullptr) {
        CPPUNIT_ASSERT(false);
    }
    BinaryTreeNode<int, int> par_node(11, 65555);
    binaryTreeNode.set_parent(&par_node);
    if (binaryTreeNode.get_parent() != &par_node) {
        CPPUNIT_ASSERT(false);
    }
    //CPPUNIT_ASSERT(true);
}

void binaryTreeNodeTest::testGet_left() {
    BinaryTreeNode<char, char> binaryTreeNode('a', 'A');
    BinaryTreeNode<char, char>* result = binaryTreeNode.get_left();
    if (result != nullptr) {
        CPPUNIT_ASSERT(false);
    }
    BinaryTreeNode<char, char> left_node('a', 'B');
    binaryTreeNode.insert(&left_node);
    if (binaryTreeNode.get_left() != &left_node) {
        CPPUNIT_ASSERT(false);
    }
    //CPPUNIT_ASSERT(true);
}

void binaryTreeNodeTest::testGet_right() {
    BinaryTreeNode<int, int> binaryTreeNode(0, 99);
    BinaryTreeNode<int, int>* result = binaryTreeNode.get_right();
    if (result != nullptr) {
        CPPUNIT_ASSERT(false);
    }
    BinaryTreeNode<int, int> right_node(1, 100);
    binaryTreeNode.insert(&right_node);
    if (binaryTreeNode.get_right() != &right_node) {
        CPPUNIT_ASSERT(false);
    }
    //CPPUNIT_ASSERT(true);
}

void binaryTreeNodeTest::testGet_key() {
    BinaryTreeNode<char, int> binaryTreeNode('*', 655555);
    char result = binaryTreeNode.get_key();
    if (result != '*') {
        CPPUNIT_ASSERT(false);
    }
}

void binaryTreeNodeTest::testGet_value() {
    BinaryTreeNode<char, char> binaryTreeNode('/', '\\');
    char result = binaryTreeNode.get_value();
    if (result != '\\') {
        CPPUNIT_ASSERT(false);
    }
}

void binaryTreeNodeTest::testSet_parent() {
    BinaryTreeNode<int, int> par_node(42,42);
    BinaryTreeNode<int, int> binaryTreeNode(43, 43);
    binaryTreeNode.set_parent(&par_node);
    if (binaryTreeNode.get_parent() != &par_node) {
        CPPUNIT_ASSERT(false);
    }
}

void binaryTreeNodeTest::testSet_left() {
    BinaryTreeNode<int, int> l_node(9,9);
    BinaryTreeNode<int, int> binaryTreeNode(10, 10);
    binaryTreeNode.set_left(&l_node);
    if (binaryTreeNode.get_left() != &l_node) {
        CPPUNIT_ASSERT(false);
    }
}

void binaryTreeNodeTest::testSet_right() {
    BinaryTreeNode<int, int> r_node(9, 9);
    BinaryTreeNode<int, int> binaryTreeNode(8, 8);
    binaryTreeNode.set_right(&r_node);
    if (binaryTreeNode.get_right() != &r_node) {
        CPPUNIT_ASSERT(false);
    }
}

void binaryTreeNodeTest::testSet_value() {
    char new_value = '#';
    BinaryTreeNode<int, char> binaryTreeNode(10, '$');
    binaryTreeNode.set_value(new_value);
    if (binaryTreeNode.get_value() != '#') {
        CPPUNIT_ASSERT(false);
    }
}

void binaryTreeNodeTest::testInsert() {
    BinaryTreeNode<int, int> in_node(0, 42);
    BinaryTreeNode<int, int> other_node(2, 19);
    BinaryTreeNode<int, int> binaryTreeNode(1, 40);
    binaryTreeNode.insert(&in_node);
    binaryTreeNode.insert(&other_node);
    if (binaryTreeNode.get_left()->get_value() != 42) {
        CPPUNIT_ASSERT(false);
    }
    if (binaryTreeNode.get_right()->get_value() != 19) {
        CPPUNIT_ASSERT(false);
    }
}

