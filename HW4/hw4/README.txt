File: BrokenASan.cpp  
Author: yaoguo  
USCID: 2176023892  
Email: yaog@usc.edu  
Description: This readfile is to describe how to use ASAN to debug the BrokenASan.cpp file  

Process:  
First, in the terminal, input:
g++ -fsanitize=address -ggdb -o a BrokenASan.cpp 
and the terminal will show the error variable 
 [32, 56) 'arr' <== Memory access at offset 56 overflows this variable
So back to the code, the error is about an array, so first thing to check if the array index is out of boundary.   
We can find that when first invoking the function, the variable input is the length of this array, which is n=6.  
However, in the partition funciton, "int pivot = arr[high]", arr[6] is out of the boundary.  so the error came out;  
To fix this error, " quickSort(arr, 0, n-1); "
also, the same error happened again  
"SUMMARY: AddressSanitizer: stack-buffer-overflow /home/student/ee599/lab4/ee599-lab4-yaoguokk/BrokenASan.cpp:41 printArray(int*, int)"
this message show the printArray function also suffer the memory leaking issue  
so in order to fix these problem, "printArray(arr, n-1); "  
