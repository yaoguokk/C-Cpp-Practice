/*Yuntao Song 03/06/2019*/
#include<iostream>
#include<fstream>
#include<string>
//you can include more files
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

int main() {
	ifstream infile;
	infile.open("input.txt");
	initialize_menu(infile);
	decodeString();
	infile.close();
	ofstream outfile;
	outfile.open("part1_q1_out.txt");
	print_menu(outfile);
	outfile.close();
	delete[]menu;
	return 0;
}