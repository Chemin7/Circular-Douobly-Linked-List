#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED

template <class T>
class Node{
public:
    Node();
    Node(T&);

    T data;
    int index;
    Node* next;
    Node* prev;


};

template <class T>
Node<T>::Node() : next(nullptr) , prev(nullptr) {}

template <class T>
Node<T>::Node(T& d) : data(d) , next(nullptr) , prev(nullptr) {}

#endif // NODE_H_INCLUDED
