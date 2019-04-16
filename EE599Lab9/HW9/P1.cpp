#include <iostream>
using namespace std;

class svc{
    public:
    static int num;
    int sam;
    svc(){
        sam = 0;
        num++;
        cout<<"num is "<<num<<endl;
    }
};

int svc::num = 44;

int main(){
    svc a; //num is 45
    svc b; //num is 46
    a.num = 33;// num can also be modified 
    cout<<"after set a.num is 33 in main , a.main="<<a.num<<endl;
    svc *c;
    c = NULL;
    svc &d=*c;
    cout<<d.num<<endl;
    return 0;
}

/*
1) Short Answer: 

a) Explain why a reference cannot be NULL (as opposed to a pointer which can be NULL). (2 points)
because a reference is an alias of a variable, so the right hand side when declare a c++ reference should be a variable 
in this way, the c++ reference cannot be a NULL; also the right hand side variable cannot be a null vairable 
In the wiki, "A reference shall be initialized to refer to a valid object or function. "

b) Argue how the type of the variable (as static) results in the final value as 595, not 599. (3 points)

*/
