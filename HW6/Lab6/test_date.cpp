
#include <iostream>
#include "date.h"
using namespace std;

int main(){

    Date d1(11, 2, 1990);
    d1.print_date("Month D, YYYY");
    d1.print_date("M/D/YYYY");
    d1.print_date("D-Month-YYYY");
    cout << "------------------\n";

    Date d2(13, 13, 1968);
    d2.print_date("Month D, YYYY");
    cout << "------------------\n";

    Date d3("2/11/1990");
    d3.print_date("Month D, YYYY");
    cout << "------------------\n";

    cout << "Is d3 equal to d1? " << (d3==d1) << endl;
    cout << "Is d3 not equal to d1? " << (d3!=d1) << endl;
    return 0;
}

