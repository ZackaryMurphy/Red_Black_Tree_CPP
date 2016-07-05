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
        Red_Black_Tree(k root_key, v root_value);
        
        Red_Black_Tree(RedBlackNode<k,v>* root);
        
        void insert(RedBlackNode<k,v>* new_node);
        
        void insert(k key, v value);
        
        v get(k key);
        
        v remove(k key);
        
        void traverse(TraversalType t);
};

template <class k, class v>
Red_Black_Tree<k,v>::Red_Black_Tree(k root_key, v root_value) {
    root = new RedBlackNode(root_key, root_value);
}


#endif /* REDBLACKTREE_H */

