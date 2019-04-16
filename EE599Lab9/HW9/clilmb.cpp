#include <iostream>
using namespace std;
int step2(int n){
    if(n<3)
        return n;
    return step2(n-1)+step2(n-2);

}

int step3(int n){
    if(n<4)
        return n;
    return step3(n-1)+step3(n-2)+step3(n-3);
}

int step3no1(int n,bool flag){
    if(n==1)
        return 1;
    else if(n==2 && flag == 1)
        return 1;
    else if(n==2 && flag == 0)
        return 2;
    else if(n==3 && flag == 0)
        return 4;
    else if(n==3 && flag == 1)
        return 1;
    else
    {
        if(flag == 1) return step3no1(n-1,0);
        else return step3no1(n-1,0) + step3no1(n-2,0) + step3no1(n-3,1);
    }
    
}

int main(){
    cout << step2(5)<<endl;
    cout << step3(10) << endl;
    cout << step3no1(10,0) << endl;

}