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
using namespace std;

int main(int argc, const char * argv[]) {
   
    LargeInt largeInt1, largeInt2,resultIntSum,resultIntDiff;
    cout<<"Enter first num"<<endl;
    cin>>largeInt1;
    cout<<"Enter second num"<<endl;
    cin>>largeInt2;
    resultIntSum = largeInt1 + largeInt2;
    resultIntDiff = largeInt1 - largeInt2;
    cout<<largeInt1<<" + "<<largeInt2<<" = "<<resultIntSum<<endl;
    cout<<largeInt1<<" - "<<largeInt2<<" = "<<resultIntDiff<<endl;
   return 0;
}

