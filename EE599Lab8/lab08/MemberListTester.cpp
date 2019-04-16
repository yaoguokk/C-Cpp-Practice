//
// MemberListTester.cpp
//
 
#include "MemberListTester.h"
#include "MemberList.h"
#include <iostream>
#include <cassert>
using namespace std;

// void MemberListTester::runTests() {
//     cout << "\nTesting class MemberList..." << endl;

//     cout << "All tests passed!" << endl;
// }
void MemberListTester::runTests() {
    cout << "\nTesting class MemberList..." << endl;
    testConstructors();
    testSearchByUsername();
    testSearchByEmail();
    testSearchByYear();
    cout << "All tests passed!" << endl;
}
void MemberListTester::testConstructors() {
    cout << "- constructors..." << flush;
    MemberList bList("input.txt");
    assert( bList.getNumMembers() == 5 );
    cout << " 0 " << flush;
 
    cout << " Passed!" << endl;
}

void MemberListTester::testSearchByUsername(){
    cout <<"- Testing search by username..." <<flush;
    MemberList bList("input.txt");

    Member *member = bList.searchByUsername("Spiderman");
    assert( member->getUsername() == "Spiderman" );
    assert( member->getName() == "Jane Scott" );
    assert( member->getDateBirth() == "02/17/1998" );
    assert( member->getEmail() == "janescott@gmail.com" );
    assert( member->getPhoneNumber() == "2133770909"  );
    assert( member->getYear() == 2017);
    cout<< " 0 " <<flush;

    Member *member1 = bList.searchByUsername("superman");
    assert( member1->getUsername() == "superman" );
    assert( member1->getName() == "Tony Lee" );
    assert( member1->getDateBirth() == "01/11/1996" );
    assert( member1->getEmail() == "tony11@gmail.com" );
    assert( member1->getPhoneNumber() == "2131237700"  );
    assert( member1->getYear() == 2017);
    assert( member1->getUsername() == "superman" );
    cout<< " 1 " <<flush;

    Member *member2 = bList.searchByUsername("clubusername");
    assert( member2->getUsername() == "clubusername" );
    assert( member2->getName() == "Alice Flores" );
    assert( member2->getDateBirth() == "05/22/1990" );
    assert( member2->getEmail() == "alice1990@gmail.com" );
    assert( member2->getPhoneNumber() == "2133306677"  );
    assert( member2->getYear() == 2016);
    cout<< " 2 " <<flush;

    Member *member3 = bList.searchByUsername("clubuername");
    assert( member3 == NULL );
    cout<< " 3 " <<flush;

    cout<< " Passed!" << endl;
}

void MemberListTester::testSearchByEmail(){
    cout <<"- Testing search by Email..." <<flush;
    MemberList bList("input.txt");

    Member *member = bList.searchByEmail("janescott@gmail.com");
    assert( member->getUsername() == "Spiderman" );
    assert( member->getName() == "Jane Scott" );
    assert( member->getDateBirth() == "02/17/1998" );
    assert( member->getEmail() == "janescott@gmail.com" );
    assert( member->getPhoneNumber() == "2133770909"  );
    assert( member->getYear() == 2017);
    cout<< " 0 " <<flush;

    Member *member1 = bList.searchByEmail("tony11@gmail.com");
    assert( member1->getUsername() == "superman" );
    assert( member1->getName() == "Tony Lee" );
    assert( member1->getDateBirth() == "01/11/1996" );
    assert( member1->getEmail() == "tony11@gmail.com" );
    assert( member1->getPhoneNumber() == "2131237700"  );
    assert( member1->getYear() == 2017);
    assert( member1->getUsername() == "superman" );    
    cout<< " 1 " <<flush;

    Member *member2 = bList.searchByEmail("alice1990@gmail.com");
    assert( member2->getUsername() == "clubusername" );
    assert( member2->getName() == "Alice Flores" );
    assert( member2->getDateBirth() == "05/22/1990" );
    assert( member2->getEmail() == "alice1990@gmail.com" );
    assert( member2->getPhoneNumber() == "2133306677"  );
    assert( member2->getYear() == 2016);
    cout<< " 2 " <<flush;

    Member *member3 = bList.searchByEmail("clubuername");
    assert( member3 == NULL );
    cout<< " 3 " <<flush;

    cout<< " Passed!" << endl;
}

void MemberListTester::testSearchByYear(){
    cout <<"- Testing search by Registered Year..." <<flush;
    MemberList bList("input.txt");

    vector<Member> *result;
    result = bList.searchByYear( 2017 );
    assert(result->size() == 2);
    cout<< " 0 " <<flush;

    vector<Member> *result2;
    result2 = bList.searchByYear( 2015 );
    assert(result2->size() == 1);
    cout<< " 1 " <<flush;  

    vector<Member> *result3;
    result3 = bList.searchByYear( 1999 );
    assert(result3->empty() == 1);
    cout<< " 2 " <<flush;

    cout<< " Passed!" << endl;
}
