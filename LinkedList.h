//
//  LinkedList.h
//  LinkedList
//
//  Created by Xie kesong on 3/25/15.
//  Copyright (c) 2015 ___kesong___. All rights reserved.
//


/*
 The linked list and the nodes must be implemented as C++ templates
 The list must be generic – it should not implement arithmetic/logic functions.
 It must include a destructor, a copy constructor and an operator=
 It must include all the basic functions
 It must include functions to insert at the front and at the back of the list
 It must include a function to return the length of the list
 It must provide an iterator-based interface for the user from front to back
 It must include an iterator-based interface for the user from back to front
 
 */


#ifndef __LinkedList__LinkedList__
#define __LinkedList__LinkedList__

#include <stdio.h>
#include <iostream>
#include "LinkedList_Iterator.cpp"
template<class T>
struct node{
    T data;
    node<T> *prev;
    node<T> *next;
};


template<class T>
int compareItem(T item1, T item2){
    if(item1 == item2)
        return 0;
    return (item1 > item2 ? 1 : -1);
}

template <class T>
class LinkedList{
public:
    typedef LinkedList_Iterator<node<T>> iterator; //define an iterator within the class itself
    LinkedList(); //defualt constuctor
    LinkedList(const LinkedList &list);// copy constructor
    ~LinkedList(); //destructor
    void insertItemAtFirstPosition(T item);
    void insertItemAtLastPosition(T item);
    bool isEmpty();
    bool isFull();
    int  getLength();
    void printList(node<T>*);
    void print();
    void removeItem(T item, int(compare)(T item1, T item2) = compareItem);
    bool searchItem(T);
    LinkedList& operator = (const LinkedList &list); //overload the assignment operator
    LinkedList_Iterator<node<T>> iteratorInitToFront();
    LinkedList_Iterator<node<T>> iteratorInitToBack();
    LinkedList_Iterator<node<T>> iteratorEnd();
    void deallocate(node<T>* node);
private:
    int length;
    node<T> *head;
    node<T> *tail;
};


#endif /* defined(__LinkedList__LinkedList__) */

