#include <iostream>
#include <fstream>
#include <unistd.h>
#include <string>
#include <cstdlib>
#include <ctime>


using namespace std;

string getTime(){
    time_t rawtime;
    time (&rawtime);
    char temp [64];
    strftime(temp, sizeof(temp),"%Y%m%d-%H%M%S",localtime(&rawtime));
    return temp;
}
//https://stackoverflow.com/questions/16357999/current-date-and-time-as-string

int main(){
    string *a =new string[4];
    a[0] = "INFO";
    a[1] = "WARN";
    a[2] = "ERROR";
    a[3] = "FATAL";
    int filenum = 20;
    
    for(int i=0;i<filenum;i++){
    srand(unsigned(time(0)));
    int randint = rand()%1000+1;
    string time1 = getTime();
    string name = "logfile-"+time1+".txt";
    ofstream outfile(name);
    outfile<<a[randint%4]<<endl;
    outfile<<randint;
    outfile.close();
    sleep(5);
    }
    
}