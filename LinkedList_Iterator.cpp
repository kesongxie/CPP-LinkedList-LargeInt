//
//  LinkedList_Iterator.cpp
//  LinkedList
//
//  Created by Xie kesong on 4/8/15.
//  Copyright (c) 2015 ___kesong___. All rights reserved.
//

#include "LinkedList_Iterator.h"

template<class T>
LinkedList_Iterator<T>::LinkedList_Iterator(T *node){
    p = node;
}

template<class T>
T& LinkedList_Iterator<T>::operator *(){
    return *p;
}
template<class T>
LinkedList_Iterator<T>& LinkedList_Iterator<T>::operator =(const LinkedList_Iterator<T> &itr){
    p = itr.p;
    return  *this;
}


template<class T>
LinkedList_Iterator<T>& LinkedList_Iterator<T>::operator ++(){
    p = p->next;
    return *this;
}
template<class T>
LinkedList_Iterator<T>& LinkedList_Iterator<T>::operator --(){
    p = p->prev;
    return *this;
}

template<class T>
bool LinkedList_Iterator<T>::operator ==(LinkedList_Iterator<T> itr){
    return p == itr.p;
}


template<class T>
bool LinkedList_Iterator<T>::operator !=(LinkedList_Iterator<T> itr){
    return p != itr.p; 
}


