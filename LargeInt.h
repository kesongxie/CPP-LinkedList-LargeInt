//
//  LargeInt.h
//  LinkedList
//
//  Created by Xie kesong on 4/10/15.
//  Copyright (c) 2015 ___kesong___. All rights reserved.
//

#ifndef __LinkedList__LargeInt__
#define __LinkedList__LargeInt__

#include <stdio.h>
#include <iostream>
#include "LinkedList.cpp"

class LargetInt{
    friend std::ostream& operator << (std::ostream&, LargetInt&);
    friend std::istream& operator >> (std::istream&, LargetInt&);
public:
    LargetInt();
    LargetInt operator +(LargetInt &);
    LargetInt& operator =(const LargetInt &);
    bool operator ==(const LargetInt &);
private:
    LinkedList<int> largeInt;
};

#endif /* defined(__LinkedList__LargeInt__) */
