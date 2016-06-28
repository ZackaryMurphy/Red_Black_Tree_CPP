#ifndef BINARYTREENODE_H
#define BINARYTREENODE_H

template <class k, class v>
class BinaryTreeNode {
    private:
        BinaryTreeNode(const BinaryTreeNode& orig);
    protected:
        BinaryTreeNode* parent;
        BinaryTreeNode* left;
        BinaryTreeNode* right;
        k key;
        v value;
    public:
        BinaryTreeNode(k contained_key, v contained_value);
        
        BinaryTreeNode* get_parent();
        
        BinaryTreeNode* get_left();
        
        BinaryTreeNode* get_right();
        
        k get_key();
        
        v get_value();
        
        void set_parent(BinaryTreeNode* par_node);
        
        void set_left(BinaryTreeNode* l_node);
        
        void set_right(BinaryTreeNode* r_node);
        
        void set_value(v new_value);
        
        virtual void insert(BinaryTreeNode<k,v>* in_node);
};

template <class k, class v>
BinaryTreeNode<k,v>::BinaryTreeNode(k contained_key, v contained_value) :
parent(nullptr), left(nullptr), right(nullptr), key(contained_key), value(contained_value) { 
}

template <class k, class v>
BinaryTreeNode<k,v>::BinaryTreeNode(const BinaryTreeNode& orig) {}

template <class k, class v>
BinaryTreeNode<k,v>* BinaryTreeNode<k,v>::get_parent() {
    return parent;
}

template <class k, class v>
BinaryTreeNode<k,v>* BinaryTreeNode<k,v>::get_left() {
    return left;
}

template <class k, class v>
BinaryTreeNode<k,v>* BinaryTreeNode<k,v>::get_right() {
    return right;
}

template <class k, class v>
k BinaryTreeNode<k,v>::get_key() {
    return key;
}

template <class k, class v>
v BinaryTreeNode<k,v>::get_value() {
    return value;
}

template <class k, class v>
void BinaryTreeNode<k,v>::insert(BinaryTreeNode<k,v>* in_node) {
    if (in_node->get_key() <= key) {
        if (left == nullptr) {
            left = in_node;
            in_node->set_parent(this);
            return;
        }
        left->insert(in_node);
        return;
    }
    if (right == nullptr) {
        right = in_node;
        in_node->set_parent(this);
        return;
    }
    right->insert(in_node);
}

template <class k, class v>
void BinaryTreeNode<k,v>::set_left(BinaryTreeNode* l_node) {
    left = l_node;
}

template <class k, class v>
void BinaryTreeNode<k,v>::set_parent(BinaryTreeNode* par_node) {
    parent = par_node;
}

template <class k, class v>
void BinaryTreeNode<k,v>::set_right(BinaryTreeNode* r_node) {
    right = r_node;
}

template <class k, class v>
void BinaryTreeNode<k,v>::set_value(v new_value) {
    value = new_value;
}

#endif /* BINARYTREENODE_H */

