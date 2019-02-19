
#ifndef NETWORK_H
#define NETWORK_H

#include "connection.h"
#include "date.h"

class Network{

    private:
        Connection* head;
        Connection* tail;
        int count; // TODO: Don't forget to count me as an attribute! 
        Connection* search(Connection* searchEntry);

    public:
        Network();
        ~Network();
        void push_front(Connection* newEntry);
        void push_back(Connection* newEntry);
        bool remove(string fname, string lname, string bdate);
        void saveDB(string filename);
        void loadDB(string filename);
        void printDB();
};

#endif
