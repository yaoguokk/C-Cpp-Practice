#ifndef SORT_H
#define SORT_H

#include <iostream>
#include <fstream>
#include <string>
using namespace std;
/*
In this part you are supposed to write a class called Sort. The Sort class gets the integer data from an input file,
 sorts it with an specified algorithm (among bubble, merge, quick, selection, radix sorts) in ascending order and writes
  the result (sorted data) in an output file with the same format of the input file (each integer in a separate line). 
  The skeleton for the class has been provided for you in sort.h, you are allowed to add to the class declaration. The 
  definitions of methods in Sort should be written in sort.cpp. 

The main function (main.cpp) gets 4 arguments (using argv), in this order: name of the input file, name of the output 
file, number of integer values, and the name of the algorithm (the same as the name of the methods in Sort). You are 
supposed to create an object of class Sort, call the specified sort algorithm, and store the results in the output. 
Here is an example of the command for running main:

./mySortProgramm.out   input.txt    output.txt   32   bubbleSort


The result of this part would be 3 different files: main.cpp, sort.cpp, sort.h
*/


class Sort{
    // always sorts ascending
    private:
        void bubbleSort(int num);
        void selectionSort(int num);
        void mergeSort(int* A,int num);
        void quickSort(int* A,int l,int num);
        void radixSort(int* A ,int num);
        // You may add other stuff here
        // Size of data in unknown in compile time
        int *A;
    public:
        // You may need other stuff here
        // What about a constructor?
        // What about a sort function calling other sort algorithms?
        // If you have dynamic data, don't forget destructor
        
        Sort(); 
        Sort(string inputfile,string outfile, int num,string method);
        ~Sort();
        void getData(string filename);
        void outData(string filename,int num);

};

#endif