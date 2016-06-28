#ifndef REDBLACKNODE_H
#define REDBLACKNODE_H

enum class RedBlackColor {RED, BLACK};

template <class k, class v>
class RedBlackNode {
    private:
        RedBlackNode(const RedBlackNode& orig);
    protected:
        RedBlackNode* parent;
        RedBlackNode* left;
        RedBlackNode* right;
        k key;
        v value;
        RedBlackColor color;
    public:
        RedBlackNode(k contained_key, v contained_value);
        
        RedBlackNode* get_parent();
        
        RedBlackNode* get_left();
        
        RedBlackNode* get_right();
        
        k get_key();
        
        v get_value();
        
        void set_parent(RedBlackNode* par_node);
        
        void set_left(RedBlackNode* l_node);
        
        void set_right(RedBlackNode* r_node);
        
        void set_value(v new_value);
        
        virtual void insert(RedBlackNode<k,v>* in_node);
        
        void set_color(RedBlackColor new_color);
        
        RedBlackColor get_color();
};

template <class k, class v>
RedBlackNode<k,v>::RedBlackNode(k contained_key, v contained_value) :
parent(nullptr), left(nullptr), right(nullptr), key(contained_key), value(contained_value), color(RedBlackColor::BLACK) { 
}

template <class k, class v>
RedBlackNode<k,v>::RedBlackNode(const RedBlackNode& orig) {}

template <class k, class v>
RedBlackNode<k,v>* RedBlackNode<k,v>::get_parent() {
    return parent;
}

template <class k, class v>
RedBlackNode<k,v>* RedBlackNode<k,v>::get_left() {
    return left;
}

template <class k, class v>
RedBlackNode<k,v>* RedBlackNode<k,v>::get_right() {
    return right;
}

template <class k, class v>
k RedBlackNode<k,v>::get_key() {
    return key;
}

template <class k, class v>
v RedBlackNode<k,v>::get_value() {
    return value;
}

template <class k, class v>
void RedBlackNode<k,v>::insert(RedBlackNode<k,v>* in_node) {
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
void RedBlackNode<k,v>::set_left(RedBlackNode* l_node) {
    left = l_node;
}

template <class k, class v>
void RedBlackNode<k,v>::set_parent(RedBlackNode* par_node) {
    parent = par_node;
}

template <class k, class v>
void RedBlackNode<k,v>::set_right(RedBlackNode* r_node) {
    right = r_node;
}

template <class k, class v>
void RedBlackNode<k,v>::set_value(v new_value) {
    value = new_value;
}

template <class k, class v>
void RedBlackNode<k,v>::set_color(RedBlackColor new_color) {
    color = new_color;
}

template <class k, class v>
RedBlackColor RedBlackNode<k,v>::get_color() {
    return color;
}

#endif /* REDBLACKNODE_H */

