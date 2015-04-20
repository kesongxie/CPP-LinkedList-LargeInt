//
//  LargeInt.cpp
//  LinkedList
//
//  Created by Xie kesong on 4/10/15.
//  Copyright (c) 2015 ___kesong___. All rights reserved.
//

#include "LargeInt.h"

LargeInt::LargeInt(){
    largeInt = *new LinkedList<int>;
}

std::istream& operator >> (std::istream& istr, LargeInt &myLargeInt){
    std::string input;
    istr >> input;
    int len = (int)input.length();
    int insert;
    if(len > 0){
        for(int i = 0; i < len; i++){
            insert = (input.substr(i,1) != "-")?stoi(input.substr(i,1)):0;
            myLargeInt.largeInt.insertItemAtFirstPosition(insert);
        }
    }
    return istr;
}

std::ostream& operator << (std::ostream& ostr,  LargeInt& myLargeInt){
    for(LinkedList<int>::iterator itr = myLargeInt.largeInt.iteratorInitToBack(); itr!=myLargeInt.largeInt.iteratorEnd();--itr){
        if(itr ==  myLargeInt.largeInt.iteratorInitToBack() && (*itr).data == 0){
            if(myLargeInt.largeInt.getLength() == 1 ){
                ostr<<"0";
            }else{
                ostr<<"-";
            }
        }else{
            ostr<<(*itr).data;
        }
    }
    return ostr;
}


LargeInt LargeInt::operator +(LargeInt &lar){
    LargeInt result;
    LargeInt ab1,ab2;
    if(negative(*this) && negative(lar)){
        ab1 = abs(*this);
        ab2 = abs(lar);
        result = basic_sum(ab1,ab2);
        result.largeInt.insertItemAtLastPosition(0); //for negaitive sign
    }else if(negative(*this)){
        ab1 = abs(*this);
        if(ab1 > lar){
            result = basic_diff(ab1, lar);
            result.largeInt.insertItemAtLastPosition(0); //for negaitive sign
        }else{
            result = basic_diff(lar, ab1);
        }
    }else if(negative(lar)){
        ab1 = abs(lar);
        if(ab1 > *this){
            result = basic_diff(ab1, *this);
            result.largeInt.insertItemAtLastPosition(0); //for negaitive sign
        }else{
            result = basic_diff(*this, ab1);
        }
    }else{
        //both are non-negative
        result = basic_sum(*this,lar);
    }
    return result;
}

LargeInt LargeInt::operator -(LargeInt &lar){
    LargeInt result;
    LargeInt ab1,ab2;
    if(negative(*this)){
        if(negative(lar)){
            ab1 = abs(*this);
            ab2 = abs(lar);
            if(ab1 > ab2){
                result = basic_diff(ab1, ab2);
                result.largeInt.insertItemAtLastPosition(0);
            }else{
                result = basic_diff(ab2, ab1);
            }
        }else{
            ab1 = abs(*this);
            ab2 = abs(lar);
            result = basic_sum(ab1, ab2);
            result.largeInt.insertItemAtLastPosition(0);
        }
    
    }else{
        if(negative(lar)){
            ab1 = abs(lar);
            result = basic_sum(*this, ab1);
        }else{
            if(*this > lar){
                result = basic_diff(*this, lar);
            }else{
                result = basic_diff(lar, *this);
                result.largeInt.insertItemAtLastPosition(0);
            }
        }

    }
     return result;
}


LargeInt& LargeInt::operator =(const LargeInt &myLargeInt){
    largeInt = myLargeInt.largeInt;
    return *this;
}

LargeInt LargeInt::basic_sum(LargeInt &lar_1,LargeInt &lar_2){
    LargeInt result;
    int carry = 0;
    int num_self, num_param, num_result; //individual digit
    LinkedList<int>::iterator itr_self = lar_1.largeInt.iteratorInitToFront();
    LinkedList<int>::iterator itr_param = lar_2.largeInt.iteratorInitToFront();
    
    while(itr_self != lar_1.largeInt.iteratorEnd() && itr_param != lar_2.largeInt.iteratorEnd() ){
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
    
    if(itr_self == lar_1.largeInt.iteratorEnd() && itr_param == lar_2.largeInt.iteratorEnd()){
        if(carry > 0){
            result.largeInt.insertItemAtLastPosition(carry);
        }
    }else{
        //after this function returns, itr_remain will be freed, and itr_param or itr_self would try to free it again.
        LinkedList<int>::iterator itr_remain = (itr_self == lar_1.largeInt.iteratorEnd())?itr_param:itr_self;
        while(itr_remain != lar_2.largeInt.iteratorEnd()){
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

LargeInt LargeInt::basic_diff(LargeInt &lar_1, LargeInt &lar_2){
     LargeInt result;
     int compensate = 0, num_self, num_param, num_result;
     LinkedList<int>::iterator itr_self = lar_1.largeInt.iteratorInitToFront();
     LinkedList<int>::iterator itr_param = lar_2.largeInt.iteratorInitToFront();
     while(itr_self != lar_1.largeInt.iteratorEnd() && itr_param != lar_2.largeInt.iteratorEnd()){
         num_self = (*itr_self).data;
         num_param = (*itr_param).data;
         if(num_self - num_param - compensate >= 0){
             num_result = num_self - num_param - compensate;
             compensate = 0;
         }else{
             num_result = 10 + num_self - num_param - compensate;
             compensate = 1;
         }
         //don't add the preceeding zero
         if(itr_self != lar_1.largeInt.iteratorInitToBack() || num_result != 0){
             result.largeInt.insertItemAtLastPosition(num_result);
         }
         ++itr_self;
         ++itr_param;
     }
     while(itr_self != lar_1.largeInt.iteratorEnd()){
         num_result = (*itr_self).data - compensate;
         //don't add the preceeding zero
         if(itr_self != lar_1.largeInt.iteratorInitToBack() || num_result != 0){
             result.largeInt.insertItemAtLastPosition(num_result);
         }
         ++itr_self;
     }
     return result;
}


LargeInt LargeInt::abs(LargeInt &lar){
    LargeInt result;
    LinkedList<int>::iterator itr = lar.largeInt.iteratorInitToFront();
    while(itr != lar.largeInt.iteratorEnd()){
        if(itr != lar.largeInt.iteratorInitToBack() || (*itr).data!=0 || lar.largeInt.getLength() == 1){
            result.largeInt.insertItemAtLastPosition((*itr).data);
        }
        ++itr;
    }
    return result;
}

bool LargeInt::negative(LargeInt &myLargeInt){
    LinkedList<int>::iterator itr = myLargeInt.largeInt.iteratorInitToBack();
    if((*itr).data == 0 && myLargeInt.largeInt.getLength()!=1){
        return true;
    }
    return false;
}


bool LargeInt::operator ==(LargeInt &lar){
    if(largeInt.getLength() != lar.largeInt.getLength()){
        return false;
    }else{
        LinkedList<int>::iterator itr_self = largeInt.iteratorInitToFront();
        LinkedList<int>::iterator itr_param = lar.largeInt.iteratorInitToFront();
        while(itr_self != largeInt.iteratorEnd() && itr_param != lar.largeInt.iteratorEnd()){
            if( (*itr_self).data != (*itr_param).data ){
                return false;
            }
            ++itr_self;
            ++itr_param;
        }
    }
    return true;
}


bool LargeInt::operator >(LargeInt &lar){
    if(*this == lar){
        return false;
    }else{
        if(negative(*this) && negative(lar)){
            LargeInt ab1 = abs(*this);
            LargeInt ab2 = abs(lar);
            if(ab1.largeInt.getLength() < ab2.largeInt.getLength()){
                return true;
            }
            else if(ab1.largeInt.getLength() > ab2.largeInt.getLength()){
                return false;
            }
            
            //lengths are euqal
            LinkedList<int>::iterator itr_self = ab1.largeInt.iteratorInitToBack();
            LinkedList<int>::iterator itr_param = ab2.largeInt.iteratorInitToBack();
            while(itr_self != ab1.largeInt.iteratorEnd() && itr_param != ab2.largeInt.iteratorEnd()){
                if((*itr_self).data > (*itr_param).data){
                    return false;
                }else if((*itr_self).data < (*itr_param).data){
                    return true;
                }
                --itr_self;
                --itr_param;
            }
            return false; //two numbers are equals
        }else if(negative(*this)){
            return false;
        }else if(negative(lar)){
            return true;
        }else{
            if(largeInt.getLength() > lar.largeInt.getLength()){
                return true;
            }
            else if(largeInt.getLength() < lar.largeInt.getLength()){
                return false;
            }
            
            //lengths are euqal
            LinkedList<int>::iterator itr_self = largeInt.iteratorInitToBack();
            LinkedList<int>::iterator itr_param = lar.largeInt.iteratorInitToBack();
            while(itr_self != largeInt.iteratorEnd() && itr_param != lar.largeInt.iteratorEnd()){
                if((*itr_self).data > (*itr_param).data){
                    return true;
                }else if((*itr_self).data < (*itr_param).data){
                    return false;
                }
                --itr_self;
                --itr_param;
            }
            return false; //two numbers are equals
        }
    }
    return false;
}


