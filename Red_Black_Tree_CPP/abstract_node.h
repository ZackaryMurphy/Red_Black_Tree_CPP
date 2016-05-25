#ifndef ABSTRACT_NODE_H
#define ABSTRACT_NODE_H
template <class T>
class Abstract_Node {
    private:
    protected:
        int num_children;
        Abstract_Node* parent;
        Abstract_Node* children;
        T data;
    public:
        virtual Abstract_Node* clone() const = 0;

        int get_num_children() {
            return num_children;
        }

        T get_data() {
            return data;
        }

        void set_data(T new_data) {
            data = new_data;
        }

}

#endif //ABSTRACT_NODE_H
