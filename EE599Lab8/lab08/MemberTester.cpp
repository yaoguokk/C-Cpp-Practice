//
// `MemberTester.cpp`
//
 
#include "MemberTester.h"
#include "Member.h"
#include <iostream>
#include <cassert>
using namespace std;

void MemberTester::runTests() {
    cout << "Testing class Member..." << endl;
    testConstructors();
    testReadFrom();
    testWriteTo();
    cout << "All tests passed!" << endl;
}
void MemberTester::testConstructors() {
    cout << "- constructors... " << flush;
    // default constructor
    Member member;
    assert( member.getUsername() == "" );
    assert( member.getName() == "" );
    assert( member.getDateBirth() == "" );
    assert( member.getEmail() == "" );
    assert( member.getPhoneNumber() == "" );
    assert( member.getYear() == 0 );
    cout << " 0 " << flush;
 
    // explicit constructor
    Member member1("Spiderman", "Jane Scott", "02/17/1998", "janescott@gmail.com", "2133770909", 2017);
    assert( member1.getUsername() == "Spiderman" );
    assert( member1.getName() == "Jane Scott" );
    assert( member1.getDateBirth() == "02/17/1998" );
    assert( member1.getEmail() == "janescott@gmail.com" );
    assert( member1.getPhoneNumber() == "2133770909" );
    assert( member1.getYear() == 2017 );
    cout << " 1 " << flush;
 
    cout << " Passed!" << endl;
}

void MemberTester::testReadFrom() {
    cout << "- readFrom()... " << flush;
    ifstream fin("input.txt");
    assert( fin.is_open() );
    Member member;
    
    // read first Member in input file
    member.readFrom(fin);
    assert( member.getUsername() == "Spiderman" );
    assert( member.getName() == "Jane Scott" );
    assert( member.getDateBirth() == "02/17/1998" );
    assert( member.getEmail() == "janescott@gmail.com" );
    assert( member.getPhoneNumber() == "2133770909"  );
    assert( member.getYear() == 2017);
    cout << " 0 " << flush;
    
    // read second Member in input file
    string separator;
    getline(fin, separator);
    member.readFrom(fin);
    assert( member.getUsername() == "superman" );
    assert( member.getName() == "Tony Lee" );
    assert( member.getDateBirth() == "01/11/1996" );
    assert( member.getEmail() == "tony11@gmail.com" );
    assert( member.getPhoneNumber() == "2131237700"  );
    assert( member.getYear() == 2017);
    cout << " 1 " << flush;
    
    // read third Member in input file
    getline(fin, separator);
    member.readFrom(fin);
    assert( member.getUsername() == "clubusername" );
    assert( member.getName() == "Alice Flores" );
    assert( member.getDateBirth() == "05/22/1990" );
    assert( member.getEmail() == "alice1990@gmail.com" );
    assert( member.getPhoneNumber() == "2133306677"  );
    assert( member.getYear() == 2016);
    cout << " 2 " << flush;
               
    
    // read fourth Member in input file
    getline(fin, separator);
    member.readFrom(fin);
    assert( member.getUsername() == "newmembers" );
    assert( member.getName() == "Mark Brown" );
    assert( member.getDateBirth() == "03/20/1990" );
    assert( member.getEmail() == "mark320@gmail.com" );
    assert( member.getPhoneNumber() == "2133900110"  );
    assert( member.getYear() == 2015);
    cout << " 3 " << flush;
    
    // read fifth Member in input file
    getline(fin, separator);
    member.readFrom(fin);
    assert( member.getUsername() == "davidclubname" );
    assert( member.getName() == "David Smith" );
    assert( member.getDateBirth() == "01/10/1989" );
    assert( member.getEmail() == "davidsmith@gmail.com" );
    assert( member.getPhoneNumber() == "2551020510"  );
    assert( member.getYear() == 2018);
    cout << " 4 " << flush;
               
    fin.close();
    cout << "Passed!" << endl;
}
void MemberTester::testWriteTo() {
    cout << "- writeTo()... " << flush;
    
    // declare three Members
    Member member1("Spiderman", "Jane Scott", "02/17/1998", "janescott@gmail.com", "2133770909", 2017);
    Member member2("superman", "Tony Lee", "01/11/1996", "tony11@gmail.com", "2131237700", 2017);
    Member member3("clubusername", "Alice Flores", "05/22/1990", "alice1990@gmail.com", "2133306677", 2016);
 
    
    // write the three Members to an output file
    ofstream fout("testOutput.txt");
    assert( fout.is_open() );
    member1.writeTo(fout);
    member2.writeTo(fout);
    member3.writeTo(fout);
    fout.close();
    
    // use readFrom() to see if writeTo() worked
    ifstream fin("testOutput.txt");
    assert( fin.is_open() );
    Member member4, member5, member6;
    
    // read and check the first Member
    member4.readFrom(fin);
    assert( member4.getUsername() == "Spiderman" );
    assert( member4.getName() == "Jane Scott" );
    assert( member4.getDateBirth() == "02/17/1998" );
    assert( member4.getEmail() == "janescott@gmail.com" );
    assert( member4.getPhoneNumber() == "2133770909"  );
    assert( member4.getYear() == 2017);
 
    cout << " 0 " << flush;
    
    // read and check the second Member
    member5.readFrom(fin);
    assert( member5.getUsername() == "superman" );
    assert( member5.getName() == "Tony Lee" );
    assert( member5.getDateBirth() == "01/11/1996" );
    assert( member5.getEmail() == "tony11@gmail.com" );
    assert( member5.getPhoneNumber() == "2131237700"  );
    assert( member5.getYear() == 2017);
    cout << " 1 " << flush;
    
    // read and check the third Member
    member6.readFrom(fin);
    assert( member6.getUsername() == "clubusername" );
    assert( member6.getName() == "Alice Flores" );
    assert( member6.getDateBirth() == "05/22/1990" );
    assert( member6.getEmail() == "alice1990@gmail.com" );
    assert( member6.getPhoneNumber() == "2133306677"  );
    assert( member6.getYear() == 2016);
 
    cout << " 2 " << flush;
    


    fin.close();
    cout << " Passed!" << endl;
}
