/*Yuntao Song 03/06/2019*/
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<time.h>
//you can include more files
using namespace std;
// string *menu;
vector<string> menu;

//you can add more functions here
void initialize_menu(istream & infile) {
	/*load data for menu*/
	string temp;
	while(getline(infile, temp)){
		menu.push_back(temp);
	}
	// for(int i=0;i<menu.size();i++){
	// 	cout<<menu[i]<<endl;
	// }

}
bool isletter(char a){
	if(a>='a'&&a<='z')
	return true;
	else
	return false;
}
string decodePure(const string& s,int& index, int mult){
	string cur = "";
    while(!isdigit(s[index]) && s[index]!=']' && index<s.length()-1){
		cur+= s[index];
		// cout<<"curr inside "<<cur<<endl;
		index++;
	}
	index--;
	string result = "";
	for(int i=0;i<mult;i++)
		result += cur;

	// cout<<"result is "<<result<<" mult is "<<mult<<endl;
	return result;
}


string decode(const string& s,int& index, int mult){
	string cur = "";
	int nextmulti = 0;
	while(index < s.length() && (s[index] != ']')){
		if(isdigit(s[index])){
			nextmulti = 10*nextmulti + s[index] - '0';
		}else if(s[index] == '[' ){
			index++;
			cur += decode(s,index,nextmulti);
			nextmulti = 0;
		}
		else if(isletter(s[index]) && isdigit(s[index-1])){
			// cout<<"nextmulti:"<<nextmulti<<endl;
			// cout<<"index = "<<index<<endl;
			cur += decodePure(s,index,nextmulti);
			// cout<<"index = "<<index<<" cur = "<<cur<<endl;
			nextmulti = 0;
		}
		else{
			cur += s[index];
		}
		index++;

	}
	string result = "";
	for(int i=0;i<mult;i++)
		result += cur;
	return result;
}

void decodeString() {
	/*Decode operation for string*/
	/*your code*/
	int m=0;
	for(int i=0;i<menu.size();i++){
		int n=0;
		menu[i]=decode(menu[i],n,1);
	}
	int index = 2;
}


//hint: you may need a function pointer here, void* decodeString(void *arg){/**/}
void print_menu(ofstream & outfile) {
	/*write menu to output file*/
	/*your code*/
	for(int i=0;i<menu.size();i++){
		outfile<<menu[i]<<"\n";
	}
}

int main() {
	time_t start,end;
	start  = clock();
	ifstream infile;
	infile.open("input.txt");
	initialize_menu(infile);
    decodeString();
    infile.close();
    ofstream outfile;
    outfile.open("part1_q1_out.txt");
    print_menu(outfile);
    outfile.close();
	end = clock();
	double time1 = double(end - start)/CLOCKS_PER_SEC ;
	// cout<<"time consuming : "<<time1<<endl;


	return 0;
}
