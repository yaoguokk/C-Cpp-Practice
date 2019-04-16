#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> num;
    int i,total =10;
    for(int i=0;i<total;i++){
        num.push_back(i);
    }
    num.clear();
    cout<<"is num empty? "<<num.empty()<<endl;
    cout<<"num size "<<num.size()<<endl;
    num.push_back(234);
    num.push_back(4);
    cout<<" after push back num size "<<num.size()<<endl;
}