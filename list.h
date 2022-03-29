#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED
#include <string>
#include "node.h"
#include <functional>
#include <iostream>
#include <iomanip>
//Definicion

using namespace std;

template <class T>
class List {
    private:
        Node<T>* head;
        bool isValidPos(Node<T>*);
        void copyAll(List<T>);

    public:
        typedef Node<T>* position;

        List();
        ~List();

        bool isEmpty();

        void insertElem(Node<T>*,  T&);
        void deleteElem(Node<T>*);

        Node<T>* getFirstPos();
        Node<T>* getLastPos();
        Node<T>* getPrevPos(Node<T>*);
        Node<T>* getNextPos(Node<T>*);

        Node<T>* findElem(const T&);
        Node<T>*findElemByIndex(int);

        T retrieveElemByIndex(int);
        T retrieve(Node<T>*);

        void modifyElem(int,T);

        void sortElem(bool);

        void deleteAll();

        List<T>& operator = (List<T>&);

        template<typename U>
        friend std::ostream& operator<<( std::ostream& os, const List<U>& l );


    };

template<typename U>
std::ostream& operator<<( std::ostream& out, const List<U>& l ) {
    Node<U>* aux(l.head);
    out<<left;
    out << setw(10)<<"Index ";
    out<< setw(10)<<" | Element";
    out<<endl;
    out<<"-----------|----------";
    out<<endl;
    do {
        out<<setw(11)<<aux->index;
        out<<"| "<<setw(10)<<aux->data;
        out<<endl;
        aux=aux->next;
        }
    while(aux!=l.head);
    return out;
    }

//Implementacion
template <class T>
List<T>::List() : head(nullptr) {

    }

template <class T>
List<T>::~List() {
    deleteAll();
    }

template <class T>
bool List<T>::isValidPos(Node<T>* p) {
    if(!isEmpty()) {
        Node<T>* aux(head);

        do {
            if(aux==p)
                return true;
            aux=aux->next;
            }
        while(aux!=head);
        }
    return false;
    }

template <class T>
void List<T>::copyAll(List<T> l) {
    if(l.isEmpty())
        return;

    Node<T>* aux(l.head);
    Node<T>* last(nullptr);
    Node<T>* newNode;

    do {
        if((newNode = new Node<T>(aux->data)) == nullptr)
            throw("Exp");///Exception
        if(last == nullptr)
            head = newNode;
        else {
            newNode->prev=last;
            last->next=newNode;
            }

        last=newNode;
        aux=aux->next;
        }
    while(aux!=l.head);

    head->prev=last;
    last->next=head;

    }


template <class T>
bool List<T>::isEmpty() {
    return head==nullptr;
    }

template <class T>
void List<T>::insertElem(Node<T>* p,  T& e) {
    if(p!=nullptr and !isValidPos(p))
        return;
    Node<T>* aux(new Node<T>(e));

    if(aux == nullptr)
        return;///Exception
    if(p==nullptr) {
        if(head == nullptr) { //Insertar al principio, no hay mas nodos
            aux->next=aux;
            aux->prev=aux;
            aux->index = 0;
            }
        else {//Ya hay mas nodos
            aux->prev=head->prev;
            aux->next=head;

            head->prev->next=aux;
            head->prev=aux;

            }
        head=aux;
        }
    else {//Insertar en cualquier lugar
        aux->prev=p;
        aux->next=p->next;

        p->next->prev=aux;
        p->next=aux;
        }
    ///Add indexes
    Node<T>* ptrIndex(head);
    int i(0);
    do {
        ptrIndex->index = i;
        ptrIndex=ptrIndex->next;
        i++;
        }
    while(ptrIndex!=head);
    }

template <class T>
void List<T>::deleteElem(Node<T>* p) {
    if(!isValidPos(p))
        return;///Exception


    p->prev->next=p->next;
    p->next->prev=p->prev;

    if(p==head) {
        if(p->next==p)
            head=nullptr;
        else
            head=head->next;
        }

    delete p;

    ///Add indexes
    if(!isEmpty()) {
        Node<T>* ptrIndex(head);
        int i(0);
        do {
            ptrIndex->index = i;
            ptrIndex=ptrIndex->next;
            i++;
            }
        while(ptrIndex!=head);
        }


    }

template <class T>
Node<T>* List<T>::getFirstPos() {
    return head;
    }

template <class T>
Node<T>* List<T>::getLastPos() {
    if(isEmpty())
        return nullptr;

    return head->prev;
    }

template <class T>
Node<T>* List<T>::getPrevPos(Node<T>* p) {
    if(!isValidPos(p))
        return nullptr;

    return p->prev;
    }

template <class T>
Node<T>* List<T>::getNextPos(Node<T>* p) {
    if(!isValidPos(p))
        return nullptr;

    return p->next;
    }

template <class T>
Node<T>* List<T>::findElem(const T& e) {
    if(!isEmpty()) {
        Node<T>* aux(head);

        do {
            if(aux->data == e) {
                return aux;
                }

            aux=aux->next;
            }
        while(aux!=head);
        }
    return nullptr;

    }

template <class T>
Node<T>* List<T>::findElemByIndex(int i) {

    if(!isEmpty()) {
        Node<T>* aux(head);

        do {
            if(aux->index == i) {
                return aux;
                }

            aux=aux->next;
            }
        while(aux!=head);
        }
    return nullptr;
    }


template <class T>
T List<T>::retrieve(Node<T>* p) {
    if(!isValidPos(p)) {
        throw("Posicion invalida,retrieve");///Exception
        }

    return p->data;

    }

template <class T>
T List<T>::retrieveElemByIndex(int i) {
    if(!isEmpty() and isValidPos(findElemByIndex(i)) ) {
        return findElemByIndex(i)->data;
        }
    throw("exp");///Exception
    }

template <class T>
void List<T>::modifyElem(int i,T d) {
    if(isEmpty() )
        return;
    findElemByIndex(i)->data=d;

    }

template <class T>
void List<T>::sortElem(bool order) {
    Node<T> *current = nullptr, *index = NULL;
    T temp;

    if(isEmpty()) {
        return;
        }
    else {

        for(current = head; current->next != NULL; current = current->next) {

            for(index = current->next; index != NULL; index = index->next) {

                if(order) { //Ascendente
                    if(current->data > index->data) {
                        temp = current->data;
                        current->data = index->data;
                        index->data = temp;
                        }
                    }
                else {//Desendente
                    if(current->data < index->data) {
                        temp = current->data;
                        current->data = index->data;
                        index->data = temp;
                        }
                    }


                }
            }
        }
    }



template <class T>
void List<T>::deleteAll() {
    if(isEmpty())
        return;
    Node<T>* mark(head);
    Node<T>* aux;

    do {
        aux=head;
        head=head->next;

        delete aux;
        }
    while(head != mark);

    head = nullptr;
    }


template <class T>
List<T>& List<T>::operator=(List<T>& l) {
    deleteAll();
    copyAll();
    return *this;
    }

#endif // LIST_H_INCLUDED

