#ifndef TREE_INTERFACE_H
#define TREE_INTERFACE_H
#include <iostream>
#include "binarytreenode.h"
template <class k, class v>
class BinaryTreeInterface {
    private:
        
    protected:
        
        virtual void left_rotate(BinaryTreeNode<k,v>* rotate_about) = 0;
        
        virtual void right_rotate(BinaryTreeNode<k,v>* rotate_about) = 0;
        
        virtual void traverse_preorder_helper(BinaryTreeNode<k,v>* trav_node);
        
        virtual void traverse_postorder_helper(BinaryTreeNode<k,v>* trav_node);
        
        virtual void traverse_inorder_helper(BinaryTreeNode<k,v>* trav_node);
        
    public:
        
        BinaryTreeInterface(k root_key, v root_value);
        
        virtual ~BinaryTreeInterface();
        
        virtual void insert(k key, v value) = 0;
        
        virtual void remove(k key) = 0;
        
        virtual void traverse_preorder();
        
        virtual void traverse_postorder();
        
        virtual void traverse_inorder();
        
        virtual void get_root_value();
        
        virtual void get_root_key();
};

#endif /* TREE_INTERFACE_H */

