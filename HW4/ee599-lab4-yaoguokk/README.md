###File: BrokenASan.cpp & EE599_Lab4_2176023892.cpp  
Author: YaoGuo  
USCID: 2176023892  
Email: yaog@usc.edu  
Description: This first part of readfile is to describe how to use ASAN to debug the BrokenASan.cpp file. 
The second part is to describe a sorting criteria which apply to pancake sorting. 


####Process:  
#####BrokenASan.cpp   
First, in the terminal, input:  
"g++ -fsanitize=address -ggdb -o a BrokenASan.cpp"  
and the terminal will show the error variable  
" [32, 56) 'arr' <== Memory access at offset 56 overflows this variable"  
So back to the code, the error is about an array, so first thing to check if the array index is out of boundary. 
We can find that when first invoking the function, the variable input is the length of this array, which is n=6.  
However, in the partition funciton, "int pivot = arr[high]", arr[6] is out of the boundary.  so the error came out; 
To fix this error, " quickSort(arr, 0, n-1); "
also, the same error happened again  
"SUMMARY: AddressSanitizer: stack-buffer-overflow /home/student/ee599/lab4/ee599-lab4-yaoguokk/BrokenASan.cpp:41 printArray(int*, int)"
this message show the printArray function also suffer the memory leaking issue  
so in order to fix these problem, "printArray(arr, n-1); "  

#####EE599_Lab4_2176023892.cpp  
This file is to applied a new sorting criteria which is as following:  
You have to find each pancake in pancakepile with the fibonacci size, and flip it to the top in a descending order, and the rest part should remain the same order. 
Then you need to sum up all the exterior pancakepile's pancake with the odd order's fibonacci size, then make a mod operation.   

######Design Instruction:
1. Read data into each pancake, include size and burned.   
2. In order to find the fibonacci size of a pancake, we define a function to check if the given number is fibonacci or not.     
3. Because we have to sort the rest to the original order, so I define a attribute of pancake "order", which record the order of this pancake in unsorted situation.    
4. Then we sort the fibonacci size pancake, flip it at the bottom.    
5. Next we sorted the rest pancake using the attribute "order" to flip these pancakes to the original order.   
6. Finally, we get the reverse original order of rest pancakes at the upper part of pancake, the fabonacci pancakes at the botton, we finally flip the whole pancakepile. We get the sorted pancake we wanted.    


#####Reference:
line 127-140    
https://www.geeksforgeeks.org/check-number-fibonacci-number/    
This website give us instruction how to check if a given number is fibonacci number or not.    
    
line 348-350:   
https://www.cnblogs.com/boluo007/p/6755540.html   
This describe how to generate 2d array of pointer. Also in the lecture, we know how to use the pointer array, which is the same as this website said.   

line 355-366:   
https://www.cnblogs.com/xunbu7/p/4309246.html   
This website describe how to use strtok function. This function is to cut the string into pieces. So we can assign the value to our valuables.   

