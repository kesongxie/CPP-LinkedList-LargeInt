//
//  main.cpp
//  LinkedList
//
//  Created by Xie kesong on 3/25/15.
//  Copyright (c) 2015 ___kesong___. All rights reserved.
//

#include <iostream>
#include <string>
#include "LargeInt.h"
//#include "LinkedList.cpp"
using namespace std;

int main(int argc, const char * argv[]) {
    LinkedList<string> myLinkedList;
    myLinkedList.insertItemAtLastPosition("How are u?");
    myLinkedList.insertItemAtLastPosition("Finally, figured out the iterator");
   
    LinkedList<string> secondLinkedList;
    secondLinkedList.insertItemAtLastPosition("Kesong!");
    
    myLinkedList = secondLinkedList;
   
    for(LinkedList<string>::iterator i = myLinkedList.iteratorInitToFront(); i!=myLinkedList.iteratorEnd();++i){
        cout<<((*i).data)<<endl;
    }
   
    
   
    LargetInt myLargeInt1,myLargeInt2,resultInt;
    cout<<"Enter an integer"<<endl;
    cin>>myLargeInt1;
    cout<<"Enter another integer"<<endl;
    cin>>myLargeInt2;
    
    resultInt = (myLargeInt1 + myLargeInt2);
    
    cout<<"The sum of "<<myLargeInt1<<" and "<<myLargeInt2<<" is "<<resultInt<<endl;
    
    return 0;
}

