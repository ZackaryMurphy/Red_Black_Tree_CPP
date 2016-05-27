#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED

class node {

    private:

    protected:
        unsigned int num_children;
        unsigned int next_free_child;
        bool is_full;
        node* parent;
        node* children;

    public:
        node(int num_children) {

        }
}

#endif // NODE_H_INCLUDED
