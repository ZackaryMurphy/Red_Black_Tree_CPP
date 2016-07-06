#ifndef REDBLACKTREE_H
#define REDBLACKTREE_H
#include "redblacknode.h"
#include "traversal_enum.h"

template <class k, class v>
class Red_Black_Tree {
    private:
        Red_Black_Tree(const Red_Black_Tree& orig);
    protected:
        RedBlackNode<k,v>* root;
        
        void rotate_left(RedBlackNode<k,v>* about_node);
        
        void rotate_right(RedBlackNode<k,v>* about_node);
        
        void rebalance(RedBlackNode<k,v>* added_node);
            
    public:
        Red_Black_Tree();
        
        Red_Black_Tree(k root_key, v root_value);
        
        Red_Black_Tree(RedBlackNode<k,v>* new_root);
        
        void insert(RedBlackNode<k,v>* new_node);
        
        void insert(k key, v value);
        
        v get(k key);
        
        v remove(k key);
        
        void traverse(TraversalType t);
};

template <class k, class v>
Red_Black_Tree<k,v>::Red_Black_Tree() {
    root = nullptr;
}

template <class k, class v>
Red_Black_Tree<k,v>::Red_Black_Tree(k root_key, v root_value) {
    root = new RedBlackNode<k,v>(root_key, root_value);
}

template <class k, class v>
Red_Black_Tree<k,v>::Red_Black_Tree(RedBlackNode<k,v>* new_root) {
    root = new_root;
}

template <class k, class v>
void Red_Black_Tree<k,v>::rotate_left(RedBlackNode<k,v>* about_node) {
    RedBlackNode<k,v>* r_child = about_node->get_right();
    about_node->set_right(r_child->get_left());
    if (r_child->get_left() != nullptr) {
        r_child->get_left()->set_parent(about_node);
    }
    if (about_node->get_parent() == nullptr) {
        r_child->set_parent(nullptr);
        root = r_child;
    }
    else {
        if (about_node == (about_node->get_parent()->get_left())) {
            about_node->get_parent()->set_left(r_child);
            r_child->set_parent(about_node->get_parent());
        }
        else {
            about_node->get_parent()->set_right(r_child);
            r_child->set_parent(about_node->get_parent());
        }
        r_child->set_left(about_node);
        about_node->set_parent(r_child);
    }
}

template <class k, class v>
void Red_Black_Tree<k,v>::rotate_right(RedBlackNode<k,v>* about_node) {
    RedBlackNode<k,v>* l_child = about_node->get_left();
    about_node->set_left(l_child->get_right());
    if (l_child->get_right() != nullptr) {
        l_child->get_right()->set_parent(about_node);
    }
    if (about_node->get_parent() == nullptr) {
        l_child->set_parent(nullptr);
        root = l_child;
    }
    else {
        if (about_node == (about_node->get_parent()->get_right())) {
            about_node->get_parent()->set_right(l_child);
            l_child->set_parent(about_node->get_parent());
        }
        else {
            about_node->get_parent()->set_left(l_child);
            l_child->set_parent(about_node->get_parent());
        }
        l_child->set_right(about_node);
        about_node->set_parent(l_child);
    }
}

template <class k, class v>
void Red_Black_Tree<k,v>::rebalance(RedBlackNode<k,v>* added_node) {
    //Added node is the root
    if (added_node->get_parent() == nullptr) {
        added_node->set_color(RedBlackColor::BLACK);
        return;
    }
    //Added node has a black parent, tree is still valid
    if (added_node->get_parent()->get_color() == RedBlackColor::BLACK) {
        return;
    }
    //Added node's parent and uncle is red, so recolor parent, uncle,and
    //grandparent, then recurse on grandparent
    if ((added_node->get_uncle() != nullptr) && (added_node->get_uncle()->get_color() == RedBlackColor::RED)) {
        added_node->get_parent()->set_color(RedBlackColor::BLACK);
        added_node->get_uncle()->set_color(RedBlackColor::BLACK);
        added_node->get_grandparent()->set_color(RedBlackColor::RED);
        rebalance(added_node->get_grandparent());
        return;
    }
    //Nodes aren't linear
    if ((added_node == (added_node->get_parent()->get_right())) && ((added_node->get_parent()) == (added_node->get_grandparent()->get_left()))) {
        rotate_left(added_node->get_parent());
        added_node = added_node->get_left();
    }
    else if ((added_node == (added_node->get_parent()->get_left())) && ((added_node->get_parent()) == (added_node->get_grandparent()->get_right()))) {
        rotate_right(added_node->get_parent());
        added_node = added_node->get_right();
    }
    //Nodes are linear
    added_node->get_parent()->set_color(RedBlackColor::BLACK);
    if (added_node->get_grandparent() != nullptr) {
        added_node->get_grandparent()->set_color(RedBlackColor::RED);
    }
    if (added_node == (added_node->get_parent()->get_left())) {
        rotate_right(added_node->get_grandparent());
    }
    else {
        rotate_left(added_node->get_grandparent());
    }
}

template <class k, class v>
void Red_Black_Tree<k,v>::insert(RedBlackNode<k,v>* new_node) {
    if (root = nullptr) {
        root = new_node;
    }
    else {
        root->insert(new_node);
    }
    rebalance(new_node);
    root->set_color(RedBlackColor::BLACK);
}

template <class k, class v>
void Red_Black_Tree<k,v>::insert(k key, v value) {
    insert(new RedBlackNode<k,v>(key, value ));
}

template <class k, class v>
v Red_Black_Tree<k,v>::get(k key) {
    RedBlackNode<k,v>* search_node = root;
    while (search_node != nullptr) {
        if (search_node->get_key() == key) {
            return search_node->get_value();
        }
        if (key < search_node->get_key()) {
            search_node = search_node->get_left();
        }
        else {
            search_node = search_node->get_right();
        }
    }
    return nullptr;
}


#endif /* REDBLACKTREE_H */

