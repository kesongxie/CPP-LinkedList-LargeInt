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

class LargeInt{
    /*
     * overload the insertion and extraction operators
     */
    friend std::ostream& operator << (std::ostream&, LargeInt&);
    friend std::istream& operator >> (std::istream&, LargeInt&);
public:
    /*
     * default constructor
     */
    LargeInt();
    
    /* static member function abs
     * Get the absolute value
     * return LargeInt
     * param LargeInt
    */
    static LargeInt abs(LargeInt &lar);
    
    /* static member function negative
     * check whether the given interger is greater or equal to zero or not
     * return bool
     * param LargeInt lar
     */
    static bool negative(LargeInt &lar);
    
    /* static member function basic_sum
     * this function caculate the sum of the two parameters, which are non-negative integers
     * return LargeInt
     * param LargeInt lar_1, LargeInt lar_2
     */
    static LargeInt basic_sum(LargeInt &lar_1, LargeInt &lar_2);
    
    
    
    /* static member function basic_diff
     * this function caculate the difference between the two parameters, which are non-negative integers, and the result is always return non-negative, since lar_1 is greater than lar_2
     * return LargeInt
     * param LargeInt lar_1, LargeInt lar_2
     */
    static LargeInt basic_diff(LargeInt &lar_1, LargeInt &lar_2);
    

    
    
    /* operator +,-
     * overload the arithmatic operators
     * return LargeInt
     * param LargeInt
     */
    LargeInt operator +(LargeInt &);
    LargeInt operator -(LargeInt &);
   
    /* operator =
     * overload the assignment operator
     * return LargeInt
     * param LargeInt
     */
    LargeInt& operator =(const LargeInt &);
    
    /* operator ==
     * overload the comparison operator ==
     * return bool
     * param LargeInt
     */
    bool operator ==(LargeInt &);
    
    /* operator >
     * overload the comparison operator >
     * return bool
     * param LargeInt
     */
    bool operator >(LargeInt &);
    
    
private:
    /*
     * Use LinkedList to implement LargeInt
     * Every digits are represented by individual nodes
     */
    LinkedList<int> largeInt;
};

#endif /* defined(__LinkedList__LargeInt__) */
