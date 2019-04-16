//
// Member.h
//
 
#ifndef EE599_LAB8_MEMBER_H
#define EE599_LAB8_MEMBER_H
 
#include <string>
#include <cstdlib>
#include <fstream>

using namespace std;
 
class Member {
public:
    Member();
    Member(const string& username, const string& name, const string& datebirth, const string& email, const string& phonenumber, unsigned year);
    string getUsername();
    string getName();
    string getDateBirth();
    string getEmail();
    string getPhoneNumber();
    unsigned getYear();
    void readFrom(istream&);
    void writeTo(ostream&) const;
private:
    string username;
    string name;
    string datebirth;
    string email;
    string phonenumber;
    unsigned year;
};
#endif //EE599_LAB8_MEMBER_H