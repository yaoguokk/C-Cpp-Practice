/*Yuntao Song 03/06/2019*/
#include<iostream>
#include<fstream>
#include<string>
#include<pthread.h>
#include<time.h>
//you can include more files except thread.h or other relative multi-threading package files
using namespace std;
string *menu;
/*your code*/
/*...*///you can add more functions here
void initialize_menu(istream & infile) {
	/*load data for menu*/
}
void decodeString() {
	/*Decode operation for string*/
	/*your code*/
}
//hint: you may need a function pointer here, void* decodeString(void *arg){/**/}
void print_menu(ofstream & outfile) {
	/*write menu to output file*/
	/*your code*/
}

int main(int argc, char *argv[]) {//input of main function is the number of cores, range is 1 to 10
	ifstream infile;
	infile.open("input.txt");
	initialize_menu(infile);
	infile.close();
	/*your code*/
	//multi_threading, creat & join + time measurement
	//screenshot your viterbi-scf2 command line to report time, paste it in your readme file.
	delete[]menu;
	return 0;
}
