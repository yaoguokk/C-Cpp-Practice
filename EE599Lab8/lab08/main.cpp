#include "MemberTester.h"
#include "MemberListTester.h"
#include <iostream>
using namespace std;
 
int main()
{
    MemberTester MemberTester;
    MemberTester.runTests();
    MemberListTester aMemberListTester;
    aMemberListTester.runTests();    

}