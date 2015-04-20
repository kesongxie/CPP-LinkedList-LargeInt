/*
    LinkedList.h
    The linked list and the nodes must be implemented as C++ templates
    The list is a generic – it should not implement arithmetic/logic functions.
    It includes a destructor, a copy constructor and an operator=
    It includes all the basic functions
    It includes functions to insert at the front and at the back of the list
    It includes a function to return the length of the list
    It provides an iterator-based interface for the user from front to back
    It includes an iterator-based interface for the user from back to front

    Created by Xie kesong on 3/25/15.
    Copyright (c) 2015 ___kesong___. All rights reserved.
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
int compareItemDefault(T item1, T item2){
    if(item1 == item2)
        return 0;
    return (item1 > item2 ? 1 : -1);
}

template <class T>
class LinkedList{
public:
    /* define an iterator within the class itself
    */
    typedef LinkedList_Iterator<node<T>> iterator;
    
    /* default constructor and will set the head and tail to NULL, length to 0
     */
    LinkedList();
    
    /* copy constructor, deep copy all the data in the param's nodes
     */
    LinkedList(const LinkedList &list);
    
    /* destructor for deleting nodes in the list
     */
    ~LinkedList();
    
    /* funciton deallocate is a recurssive function for deleting nodes from the param to the end
     * param node<T> *node
     */
    void deallocate(node<T>* node);
    
    /* function insertItemAtFirstPosition will insert the new item at the first position of the list
     * param T item
     */
    void insertItemAtFirstPosition(T item);
    
    /* function insertItemAtLastPosition will insert the new item at the last position of the list
     * param T item
     */
    void insertItemAtLastPosition(T item);
    
    /* function isEmpty checks whether the list is empty or not
     * return bool
     */
    bool isEmpty();
   
    /* function isFull checks whether there is memory for inserting node
     * return bool
     */
    bool isFull();
    
    /* function getLength is going to return the length of the private member length
     * return int
     */
    int  getLength();
    
    /* function printlist is a recussive function for printing the information of nodes
     * in the list
     * param node<T>* &node
     */
    void printList(node<T>* &node);
    
    /* function print is a helper function for the recussive function printList
     * and used by the client side.
     */
    void print();
   
    /* function searchItem
     * param T item, param function compare
     */
    void removeItem(T item, int(compare)(T item1, T item2) = compareItemDefault);
    
    /* function searchItem
     * param T item
     * return bool
     */
    bool searchItem(T item);
    
    /* overload the assignment operator =
     * param LinkedList &list
     * return LinkedList&
     */
    LinkedList& operator = (const LinkedList &list);
   
    /* function iteratorInitToFront, return the head of Linkedlist
     * return LinkedList_Iterator<node<T>>
     */
    LinkedList_Iterator<node<T>> iteratorInitToFront();
   
    /* function iteratorInitToBack, return the tail of Linkedlist
     * return LinkedList_Iterator<node<T>>
     */
    LinkedList_Iterator<node<T>> iteratorInitToBack();
    
    /* function iteratorEnd is repsonsible for setting the iterator to NULL
     * and would signal the end of the iterator
     * return LinkedList_Iterator<node<T>>
     */
    LinkedList_Iterator<node<T>> iteratorEnd();
private:
    int length;
    node<T> *head;
    node<T> *tail;
};


#endif /* defined(__LinkedList__LinkedList__) */

