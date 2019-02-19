#include "sort.h"
#include <iostream>

int main(int argc, char** argv) {
  
    string inputfilename,outputfilename,method;
    int num;
    inputfilename = argv[1];
    outputfilename = argv[2];
    num = atoi(argv[3]);
    method = argv[4];
    // cout<<inputfilename<<endl;
    // cout<<outputfilename<<endl;
    // cout<<num<<endl;
    // cout<<method<<endl;
    Sort *a=new Sort(inputfilename,outputfilename,num,method);
    
//      g++ --std=c++11 sort.cpp -o test
//    ./test input.txt  output.txt   32   bubbleSort

}