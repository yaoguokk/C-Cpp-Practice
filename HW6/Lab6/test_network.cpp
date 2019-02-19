
#include "network.h"


int main(){

    Network myNet;

    // Part #1
    // TODO: Create sample connection files
    Connection* c1 = new Connection("connection_template.txt");
    Connection* c2 = new Connection("AnotherConnection.txt"); 
    Connection* c3 = new Connection("OneOtherConnection.txt");
    Connection* c4 = new Connection("AndAnotherConnection.txt");

    cout << "[Empty network:] " << endl;
    myNet.printDB();

    myNet.push_front(c1);
    myNet.push_front(c2);
    cout << endl << "[After adding first two contact:] " << endl;
    myNet.printDB();
    myNet.push_front(c3);
    cout << endl << "[After adding another contact:] " << endl;
    myNet.printDB();

    // Part #2:
    // TODO: Test save and load, and push_back 
    myNet.saveDB("myNetwork.txt");
    myNet.push_back(c4);

    cout << endl << "[After adding the 4th connection:] " << endl;
    myNet.printDB();
    myNet.loadDB("myNetwork.txt");
    cout << endl << "[After loading networkDB:] " << endl;
    myNet.printDB();
  

    // Part #3: 
    // TODO: Search is called in remove, just test remove
    myNet.remove("Julia Scarlett Elizabeth", "Louis-Dreyfus", "1/13/1961");
    cout << endl << "[After removing the vice president:] " << endl;
    myNet.printDB();
    return 0;
}
