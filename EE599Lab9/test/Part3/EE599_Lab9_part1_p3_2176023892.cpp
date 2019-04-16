
// part 3
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<time.h>
#include<stdlib.h>
#include<pthread.h>

//you can include more files
using namespace std;

struct args{
	int init;
	int end;
};

// string *menu;
vector<string> menu;
int num = 0;

//you can add more functions here
void initialize_menu(istream & infile) {
	/*load data for menu*/
	string temp;
	while(getline(infile, temp)){
		menu.push_back(temp);
		num++;
	}

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
			cur += decodePure(s,index,nextmulti);
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
	for(int i=0;i<num;i++){
		int n=0;
		menu[i]=decode(menu[i],n,1);
	}

}


//hint: you may need a function pointer here, void* decodeString(void *arg){/**/}
void* decodeString(void *arg){
	args* myargs = (args*)arg;
	int initNum = myargs->init;
	int endNum = myargs->end;

	for(int i=initNum;i<endNum;i++){
		int n=0;
		menu[i] = decode(menu[i],n,1);
	}

	pthread_exit(NULL);
}

void print_menu(ofstream & outfile) {
	/*write menu to output file*/
	/*your code*/
	for(int i=0;i<menu.size();i++){
		outfile<<menu[i]<<"\n";
	}
}



//arr[divisor +1 ]
int* devideNum(int num,int divisor){
    int *arr = new int[divisor+1];
		int remain = num%divisor;
		int factor = num/divisor;
		for(int i=0;i<divisor+1;i++){
			arr[i]=factor*i;
		}
		if(remain!=0){
			for(int i=0;i<remain;i++){
				arr[divisor-remain+1+i]+=1+i;
			}
		}
		return arr;
}

void onlyonethread(){
	if(!menu.empty()){
		menu.clear();
	}
	num = 0;
	ifstream infile;
	infile.open("input1.txt");
	initialize_menu(infile);

    decodeString();
		

    // infile.close();
    // ofstream outfile;
    // outfile.open("part1_q2_out1.txt");
    // print_menu(outfile);
    // outfile.close();

}
void multithread(int threadNum){
	int i;
	time_t start,end;
	ifstream infile;
	infile.open("input.txt");
	initialize_menu(infile);
	infile.close();

	int *arr = devideNum(menu.size(),threadNum);
		start  = clock();

	pthread_t threads[threadNum];
	for( i=0;i<threadNum;i++){
		args* a = new args;
		a->init = arr[i];
		a->end = arr[i+1];
		// cout<<"main: creating thread 00"<<i<<endl;
		int error = pthread_create(&threads[i],NULL,decodeString,(void *) a);
		if(error){
			cout << "Error: unable to create thread," << error <<endl;
			exit(-1);
		}
	}
	for (i = 0; i < threadNum; i++) {
      //  cout << "main: joining thread 00" << i << endl;
       pthread_join(threads[i], NULL);
   }
		end = clock();
	double time1 = double(end - start)/CLOCKS_PER_SEC ;
	// cout<<"time consuming : "<<time1<<endl;



    // ofstream outfile;
    // outfile.open("part1_q2_out1.txt");
    // print_menu(outfile);
    // outfile.close();

}

int main(int argc, char* argv[]) {
	string s = argv[1];
	int multinum = atoi(s.c_str());
	if(multinum>=1 && multinum <=10 ){
		multithread(multinum);
	}

	// onlyonethread();
	return 0;
}
