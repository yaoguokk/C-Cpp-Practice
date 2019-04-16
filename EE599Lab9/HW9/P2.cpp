#include <iostream>
using namespace std;

int & exampleb(){
    static int x= 599;
    return x;
}

int main(){
    exampleb() = 595;
    cout<< exampleb();
    return 0;
}

/*

b) Argue how the type of the variable (as static) results in the final value as 595, not 599. (3 points)

beacuse the function "exampleb()" return type is a c++ reference, so 
it returns the static x. 
As the interger x a static type, 
its working scaler is the whole program and it gets allocated for the lifetime of the program
so we declare the static variable in function, and can modify the variable in the main function.

what is boxing and unboxing in programming 

c) boxing is to wrap a value type to reference type. 
unboxing is to unwrap a reference object to a value type.
value type stores in stack however reference type is storing in heap.

d) Explain the motivation behind C++ "inline" functions. (3 points).
for small and commonly used function, the time needed to make the
function call is often a lot more than the time needed to actually 
execute the function's code. Using inline function counld reduce the function call
overhead.

e) Explain what C++ Functors are and the motivation behind them
a c++ function object allows an instance of a class to be invoked as if it were oridinary function.
when inheritance hierarchy were modeling connections to a database, the functors is useful. when 

*/
