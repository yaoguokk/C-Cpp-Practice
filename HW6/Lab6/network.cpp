
#include "network.h"

Network::Network(){
    head = NULL;
    tail = NULL;
    count = 0;
}


Network::~Network(){
    // Destructure delete all the Connections
    // TODO: Complete this method
    
}


void Network::push_front(Connection* newEntry){
    // Adds a new Connection (newEntry) to the front of LL
  
    newEntry->prev = NULL;
    newEntry->next = head;//store the original 1st item address
    // cout<<"newentry next"<<head<<endl;
    if (head != NULL)
        head->prev = newEntry;
    else
        tail = newEntry;
    
        
    
    head = newEntry;
    // cout<<"tail prev  "<<tail->prev<<endl;
    // cout<<"tail next  "<<tail->next<<endl;

    // cout<<"head pre "<<head<<endl;
    // cout<<"head next "<<head->next<<endl;
  
    count++;
    

}


void Network::push_back(Connection* newEntry){
    // Adds a new Connection (newEntry) to the back of LL
    //TODO: Complete this method!
    newEntry->next = NULL;
    newEntry->prev = tail; //store the original final item address

    if (tail != NULL){
        tail->next = newEntry;//the last one's next store the newentry address 
    }else{
        head = newEntry;//in the first term, Head=tail = 0;
        //we put head for this newentry so next pushback this else 
        //statement will never touch , so the head is stick with the first newentry
        
    }
    tail = newEntry;
  
    count++;
}


Connection* Network::search(Connection* searchEntry){
    // Searches the Network for searchEntry
    // Use == overloaded operator for connection
    // if found, returns a pointer to it, else returns NULL
    // TODO: Complete this method!
    Connection* temp = head;
    while(temp->next != NULL){
        if(temp == searchEntry)
            return temp;
        else 
            temp = temp->next;
    }
    return NULL;
    
}


void Network::printDB(){
    cout << "Number of connections: " << count << endl;
    Connection* ptr = head;
    while(ptr != NULL){
        ptr->print_connection();
        cout << "------------------" << endl;
        ptr = ptr->next;
    }
}


void Network::saveDB(string filename){
    // Saves the netwrok in file <filename>
    // The format of the output file is similar to printDB()
    // Look at networkDB.txt as a template
    // TODO: Complete this method
    // TODO: Understand why it would be necessary to modify Date class now! 
    // TODO: Go back and uncomment get_date method in Date class (both .h and .cpp) 
    ofstream outfile(filename);
    Connection* ptr = head;
    while (ptr != NULL){
        outfile << ptr->l_name<<", "<< ptr->f_name <<endl;
        outfile << ptr->birthdate->get_date()<<endl;
        outfile << "------------------" << endl;
        ptr = ptr->next;
    }
    
}


void Network::loadDB(string filename){
    // Loads the netwrok from file <filename>
    // The format of the input file is similar to saveDB
    // Look at network networkDB.txt as a template
    // The order of connections in LL does not matter
    // TODO: Understand this code! 

    Connection* ptr = head;
    while(head != NULL){
        // cout<<"head is ";
        // head->print_connection();
        ptr = head->next;
        delete head;
        head = ptr;
        count--;
        
    }
    
    head = NULL;//<<pay attention
    tail = NULL;
    ifstream infile;
    infile.open(filename.c_str());
    string buff, fname, lname, bdate;
    while(getline(infile, buff)){
        lname = buff.substr(0, buff.find(','));
        fname = buff.substr(buff.find(',')+2);
        getline(infile, bdate);
        getline(infile, buff);
        Connection* newEntry = new Connection(fname, lname, bdate);
        this->push_back(newEntry);
    }
}


bool Network::remove(string fname, string lname, string bdate){
    // TODO: Complete this method! Follow these steps:
    // Create a new connection with the the give arguments ..
    // .. think about what Connection constructor will be helpful with these arguments 
    // Search if this connection exists using search method
    // If it does not exist just return false!
    // Else, remove the connection from LL, make the other connections connected
    // Don't forget to delete allocated memory, change count  and returning values!
    Connection *temp =new Connection(fname,lname,bdate);
    Connection *result = search(temp);
    if(!result){
      //  delete temp;
        return false;
    }else{
        (result->prev)->next = result->next;
        (result->next)->prev = result->prev;
        count--;
        return true;
    }
    
}

