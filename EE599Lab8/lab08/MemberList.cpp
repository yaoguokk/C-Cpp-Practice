//
// MemberList.cpp
//
#include "MemberList.h"
using namespace std;
#include <iostream>

/*  MemberList constructor
    * @param: fileName, a string
    * Precondition: fileName contains the name of a input file.
    */
MemberList::MemberList(const string& fileName) {
    // open a stream to the Memberlist file
    ifstream fin( fileName.c_str() );
    assert( fin.is_open() );
 
    // read each Member and append it to totalMembers
    Member Member;
    string separator;
    while (true) {
        Member.readFrom(fin);
        if ( !fin ) { break; }
        getline(fin, separator);
        totalMembers.push_back(Member);
    }
 
    // close the stream
    fin.close();
}

/* Retrieve length of the Member list
 * Return: the number of Members in the list.
 */
unsigned MemberList::getNumMembers() const {
 
    return totalMembers.size();
}
Member* MemberList::searchByUsername(string name){
    unsigned num = getNumMembers();
    int i;
    for(i=0; i<num; i++){
        if(totalMembers[i].getUsername() == name){
            return &totalMembers[i];
        }
    }
    return NULL;
}

Member* MemberList::searchByEmail(string email){
    unsigned num = getNumMembers();
    int i;
    for(i=0; i<num; i++){
        if(totalMembers[i].getEmail() == email){
            return &totalMembers[i];
        }
    }
    return NULL;
}

vector<Member>* MemberList::searchByYear(unsigned year){
    unsigned num = getNumMembers();
    int i;
    vector<Member> *matchYear=new vector<Member>;
    for(i=0; i<num; i++){
        if(totalMembers[i].getYear() == year){
            matchYear->push_back(totalMembers[i]);
        }
    }
    return matchYear;
}