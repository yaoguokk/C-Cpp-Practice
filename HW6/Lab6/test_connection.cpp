
#include <iostream>
#include "connection.h"

int main(){

    Connection c1;
    c1.print_connection();
    cout << "----------------\n";
    
    Connection c2("connection_template.txt");
    c2.print_connection();
    cout << "----------------\n";
    
    cout << "Is c1 equal to c2: " << (c1==c2) << endl;
    cout << "Is c1 not equal to c2: " << (c1!=c2) << endl;

    return 0;
}
