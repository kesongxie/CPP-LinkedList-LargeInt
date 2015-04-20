//
//  LinkedList_Iterator.h
//  LinkedList
//
//  Created by Xie kesong on 4/8/15.
//  Copyright (c) 2015 ___kesong___. All rights reserved.
//

#ifndef __LinkedList__LinkedList_Iterator__
#define __LinkedList__LinkedList_Iterator__


#include <stdio.h>
#include <iterator>

template <class T>
class LinkedList_Iterator:public std::iterator<std::input_iterator_tag, int>
{
public:
    //don't need destrutor,otherwise since p always point to other nodes(those nodes would be deleted)
    
    /* default constuctor
     */
    LinkedList_Iterator(T *node);
    
    /* overload the dereference operator *
     * return the data member T *p
     */
    T& operator *();
    
    /* overload the assigment operator =
     * param LinkedList_Iterator &itr
     * return LinkedList_Iterator&
     */
    LinkedList_Iterator& operator =(const LinkedList_Iterator &itr);
    
    /* overload the incresement operator ++ which would set the current iterator pointing to the next node
     * return LinkedList_Iterator&
     */
    LinkedList_Iterator& operator ++();
    
    /* overload the pre-decreasement operator -- which would set the current iterator pointing to the previous node
     * return LinkedList_Iterator&
     */
    LinkedList_Iterator& operator --();
    
    /* overload the comparison operator ==
     * return bool
     */
    bool operator ==(LinkedList_Iterator<T>);
    
    /* overload the comparison operator !=
     * return bool
     */
    bool operator !=(LinkedList_Iterator<T>);
private:
    T *p; // T is a node<T> type
};



#endif /* defined(__LinkedList__LinkedList_Iterator__) */
