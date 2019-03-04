#include<iostream>
#include <iomanip>


int main(){
    using namespace std;
    int x=2,y=2,z=3,p=9,count=0;
    int ****arr=new int***[x];

    for(int i=0;i<x;i++){
        arr[i] = new int **[y];
        for(int j=0;j<y;j++){
            arr[i][j]=new int *[z];
            for(int k=0;k<z;k++){
                arr[i][j][k]=new int [p];
            }
        }
    }

     for(int i=0;i<x;i++){
         for(int j=0;j<y;j++){
             for(int k=0;k<z;k++){
                for(int m=0;m<p;m++){
                    arr[i][j][k][m]=1000*i+100*j+10*k+m+1;
                    count++;
                }
             }
         }
     }
     
     cout<<"there are totally "<<count<<" of arr elements"<<endl;

     for(int i=0;i<x;i++){
         for(int j=0;j<y;j++){
             for(int k=0;k<z;k++){
                for(int m=0;m<p;m++){
                    cout<<setw(5)<<arr[i][j][k][m];
                    
                }
                cout<<endl;
             }
             cout<<endl;
         }
         cout <<endl;
     }

    count=0;
    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
            for(int k=0;k<z;k++){
                delete[] arr[i][j][k];
                cout<< "success ";
                count++;
            }
            delete[] arr[i][j];
        }
        delete[] arr[i];
    }
    delete [] arr;
    cout<<"totally delete "<<count<<"times "<<endl;

    return 0;
}