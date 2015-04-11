//
//  LargeInt.cpp
//  LinkedList
//
//  Created by Xie kesong on 4/10/15.
//  Copyright (c) 2015 ___kesong___. All rights reserved.
//

#include "LargeInt.h"

LargetInt::LargetInt(){
    largeInt = *new LinkedList<int>;
}

std::istream& operator >> (std::istream& istr, LargetInt &myLargeInt){
    std::string input;
    istr >> input;
    int len = (int)input.length();
    if(len > 0){
        for(int i = 0; i < len; i++){
            myLargeInt.largeInt.insertItemAtFirstPosition(stoi(input.substr(i,1)));
        }
    }
    return istr;
}

std::ostream& operator << (std::ostream& ostr,  LargetInt& myLargeInt){
    for(LinkedList<int>::iterator i = myLargeInt.largeInt.iteratorInitToBack(); i!=myLargeInt.largeInt.iteratorEnd();--i){
        ostr<<(*i).data;
    }
    return ostr;
}

LargetInt LargetInt::operator +(LargetInt &myLargeInt){
    LargetInt result;
    int carry = 0;
    int num_self, num_param, num_result; //individual digit
    
    LinkedList<int>::iterator itr_self = largeInt.iteratorInitToFront();
    LinkedList<int>::iterator itr_param = myLargeInt.largeInt.iteratorInitToFront();
    
    while(itr_self != largeInt.iteratorEnd() && itr_param != myLargeInt.largeInt.iteratorEnd() ){
        num_self = (*itr_self).data;
        num_param = (*itr_param).data;
        num_result = num_self + num_param + carry;
        if(num_result > 9){
            num_result -= 10;
            carry = 1;
        }else{
            carry = 0;
        }
        result.largeInt.insertItemAtLastPosition(num_result);
        ++itr_self;
        ++itr_param;
    }
    if(itr_self == largeInt.iteratorEnd() && itr_param == myLargeInt.largeInt.iteratorEnd()){
        if(carry > 0){
            result.largeInt.insertItemAtLastPosition(carry);
        }
    }else{
        //after this function returns, itr_remain will be freed, and itr_param and itr_self would try to free it again. 
        LinkedList<int>::iterator itr_remain = (itr_self == largeInt.iteratorEnd())?itr_param:itr_self;
        
        while(itr_remain != myLargeInt.largeInt.iteratorEnd()){
            num_result = (*itr_remain).data + carry;
            if(num_result > 9){
                num_result -= 10;
                carry = 1;
            }else{
                carry = 0;
            }
            result.largeInt.insertItemAtLastPosition(num_result);
            ++itr_remain;
        }
        if(carry > 0){
            result.largeInt.insertItemAtLastPosition(carry);
        }
    }
    return result;

}

LargetInt& LargetInt::operator =(const LargetInt &myLargeInt){
    largeInt = myLargeInt.largeInt;
    return *this;
}





