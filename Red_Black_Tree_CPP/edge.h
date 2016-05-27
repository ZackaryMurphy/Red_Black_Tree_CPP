#ifndef EDGE_H_INCLUDED
#define EDGE_H_INCLUDED

#include <memory>

template <class connectee>
class Edge {

    private:
    protected:
        std::shared_ptr<connectee> left;
        std::shared_ptr<connectee> right;
    public:
        Edge();

        Edge(connectee* left_connect);

        Edge(connectee* left_connect, connectee* right_connect);

        std::shared_ptr<connectee> get_left() const;

        std::shared_ptr<connectee> get_right() const;

        void set_left(connectee* new_left);

        void set_right(connectee* new_right);
};

template <class connectee>
Edge<connectee>::Edge() : left(), right()
{}

template <class connectee>
Edge<connectee>::Edge(connectee* left_connect) : left(left_connect), right()
{}

template <class connectee>
Edge<connectee>::Edge(connectee* left_connect, connectee* right_connect) : left(left_connect), right(right_connect)
{}

template <class connectee>
std::shared_ptr<connectee> Edge<connectee>::get_left() const {
    return left;
}

template <class connectee>
std::shared_ptr<connectee> Edge<connectee>::get_right() const {
    return right;
}

template <class connectee>
void Edge<connectee>::set_left(connectee* new_left) {
    left = new std::shared_ptr<connectee>(new_left);
}

template <class connectee>
void Edge<connectee>::set_right(connectee* new_right) {
    right = new std::shared_ptr<connectee>(new_right);
}

template <class connectee>
inline bool operator==(const Edge<connectee>& lhs, const Edge<connectee>& rhs) {
    return lhs.get_left() == rhs.get_left() && lhs.get_right() == rhs.get_right();
}

#endif // EDGE_H_INCLUDED
