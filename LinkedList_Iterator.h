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
    //don't need destrutor,otherwise would have error, pointer being freed was not allocated since p always point to other nodes(those nodes would be deleted)
    LinkedList_Iterator(T*);
    T& operator *();
    LinkedList_Iterator& operator =(const LinkedList_Iterator &itr);
    LinkedList_Iterator& operator ++();
    LinkedList_Iterator& operator --();
    bool operator ==(LinkedList_Iterator<T>);
    bool operator !=(LinkedList_Iterator<T>);
private:
    T *p; // T is of a node<T> type
};



#endif /* defined(__LinkedList__LinkedList_Iterator__) */
