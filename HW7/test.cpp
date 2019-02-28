#include<iostream>
using namespace std;
int& printi(int &x){
    (x)++;

    return x;
}
int main(){
    int i=8;
  

    // printi(i);
    cout<< printi(i);


}