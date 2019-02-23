#include "sort.h"

int main(int argc, char** argv) {
  
    string inputfilename,outputfilename,method,num;
    int num1;
    inputfilename = argv[1];
    outputfilename = argv[2];
    num = argv[3];
    num1 = atoi(num.c_str());
    method = argv[4];

    Sort *a=new Sort(inputfilename,outputfilename,num1,method);
}