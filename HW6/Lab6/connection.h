
#ifndef CONNECTION_H
#define CONNECTION_H

#include "date.h"
#include "fstream"
class Connection{
    // Its always OK to discuss your private issues with good friends, at least in C++! 
    friend class Network;

private:
	string f_name;
	string l_name;
	Date *birthdate;
    Connection* next;
    Connection* prev;

public: 
 
    Connection();
    Connection(string filename);
    Connection(string f_name, string l_name, string bdate);
    ~Connection();
	void print_connection();
	void set_connection();
	void set_connection(string filename);
    bool operator==(const Connection& rhs);
    bool operator!=(const Connection& rhs);
};


#endif
