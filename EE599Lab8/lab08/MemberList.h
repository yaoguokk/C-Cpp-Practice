//
// MemberList.h
//
 
#ifndef EE599_LAB8_MEMBERLIST_H
#define EE599_LAB8_MEMBERLIST_H
 
#include "Member.h"
#include <vector> // STL vector
#include <string>
 
using namespace std;
 
class MemberList {
public:
    MemberList(const string& fileName);
    unsigned getNumMembers() const;
    Member* searchByUsername(string name);
    Member* searchByEmail(string email);
    vector<Member>* searchByYear(unsigned year);

private:
    vector<Member> totalMembers;
};
#endif //EE599_LAB8_MEMBERLIST_H