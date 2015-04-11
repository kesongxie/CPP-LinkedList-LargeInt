//
//  LinkedList.cpp
//  LinkedList
//
//  Created by Xie kesong on 3/25/15.
//  Copyright (c) 2015 ___kesong___. All rights reserved.
//


#include "LinkedList.h"

template<class T>
LinkedList<T>::LinkedList(){
    head = tail =  NULL;
    length = 0;
}

template<class T>
LinkedList<T>::LinkedList(const LinkedList<T> &list){
    length = list.length;
    if(length > 0){
        head = new node<T>;
        head->data = list.head->data;
        head->prev = NULL;
        node<T> *iter = list.head->next;
        node<T> *walk = head;
        while( iter != NULL){
            walk->next = new node<T>;
            walk->next->data = iter->data;
            walk->next->prev = walk;
            iter = iter->next;
            walk = walk->next;
        }
        walk = NULL;
    }
    else{
        head = tail = NULL;
    }
}

template<class T>
LinkedList<T>::~LinkedList(){
    deallocate(head);
}

template<class T>
void LinkedList<T>::deallocate(node<T>* node){
    if(node != NULL){
        deallocate(node->next);
        delete node;
    }
}


template<class T>
void LinkedList<T>::insertItemAtFirstPosition(T item){
    node<T> *p = new node<T>;
    if(p != NULL){
        p->data = item;
        if(head == NULL){
            tail = p;
        }else{
            p->next = head;
            p->next->prev = p;
        }
        p->prev = NULL;
        head = p;
        length++;
    }
}

template<class T>
void LinkedList<T>::insertItemAtLastPosition(T item){
    node<T> *p = new node<T>;
    if(p != NULL){
        p->data = item;
        if(head == NULL){
            p->prev = NULL;
            head = p;
        }else{
            p->prev = tail;
            p->prev->next = p;
        }
        p->next = NULL;
        tail = p;
        length++;
    }
}

template<class T>
bool LinkedList<T>::isEmpty(){
    return head == NULL;
}

template<class T>
bool LinkedList<T>::isFull(){
    node<T> *p = new node<T>;
    if(p != NULL){
        delete p ;
        p = NULL;
        return false;
    }
    return true;
}

template<class T>
int  LinkedList<T>::getLength(){
    return length;
}

template<class T>
void LinkedList<T>::printList(node<T>* node){
    if(node != NULL){
        std::cout<<node->data<<std::endl;
        printList(node->next);
    }
}

template<class T>
void LinkedList<T>::print(){
    printList(head);
}

template<class T>
void LinkedList<T>::removeItem(T item, int(compare)(T item1, T item2) )
{
    if(head != NULL){
        node<T> *p = head;
        if(compare(p->data,item) == 0){
            if(p->next!=NULL){
                //more than one node in the list
                p->next->prev = NULL;
            }else{
               //only one node in the list
               tail = NULL;
            }
            head = p->next;
            delete p;
            length--;
        }else{
            while(p != NULL){
                if(compare(p->data,item) == 0){
                    p->prev->next = p->next;
                    if(p->next != NULL){
                        p->next->prev = p->prev;
                    }else{
                        tail = p->prev;
                    }
                    delete p;
                    length--;
                    break;
                }
                p = p->next;
            }
        }
    }
}

template<class T>
bool LinkedList<T>::searchItem(T item){
    if(head != NULL){
        node<T> *p = head;
        while(p != NULL){
            if(p->data == item)
                return true;
            p = p->next;
        }
        delete p;
        p = NULL;
    }
    return false;
}

template<class T>
LinkedList<T>& LinkedList<T>::operator = (const LinkedList<T> &list){
    if(list.head == NULL)
    {
        //The param list is empty
        deallocate(head);
        head = NULL;
        tail = NULL;
        length = 0;
        return *this;
    }
    
    length = list.length;
    node<T> *self_itr;
    if(head == NULL){
        head = new node<T>;
    }
    self_itr = head;
    node<T> *param_itr = list.head;
    node<T> *remained_itr = head;
    while(true){
        self_itr->data = param_itr->data;
        if(param_itr->next != NULL && self_itr->next == NULL){
            //Need to add new node to the self-LinkedList
            self_itr->next = new node<T>;
            self_itr->next->prev = self_itr;
            
        }
        else if(param_itr->next == NULL){
            //There is no node need to be copied from param-LinkedList
            tail = self_itr;
            remained_itr = self_itr->next;
            self_itr->next = NULL;
            break;
        }
        param_itr = param_itr->next;
        self_itr = self_itr->next;
    }
    //delete redundant nodes of self-LinkedList
    deallocate(remained_itr);
    
    return *this;

 }

template<class T>
LinkedList_Iterator<node<T>> LinkedList<T>::iteratorInitToFront(){
    return *new LinkedList_Iterator<node<T>>(head);
}

template<class T>
LinkedList_Iterator<node<T>> LinkedList<T>::iteratorInitToBack(){
    return *new LinkedList_Iterator<node<T>>(tail);
}

template<class T>
LinkedList_Iterator<node<T>> LinkedList<T>::iteratorEnd(){
    return *new LinkedList_Iterator<node<T>>(NULL);
}







