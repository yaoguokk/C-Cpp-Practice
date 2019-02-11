#include <iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h>
#include <math.h>


using namespace std;

class Pancake{
protected:
    int sizepk;
    bool Burnt;
public:
    int order;
    void flip_pancake(){
        Burnt=!Burnt;
    };
    void setSize(int x){
        sizepk=x;
    }
    int getSize(){
        return sizepk;
    }
    void setBurnt(bool flag){
        Burnt=flag;
    }
    bool getBurnt(){
        return Burnt;
    }
};


class PancakePile{
protected:
    int sizeZ;
public:
    bool hasFibonacci;
    Pancake *pancake;
    PancakePile pancake_sort_ascending_burnt_down(PancakePile pancakepile, int sizeZ);
    virtual void pancake_sort_descending_burnt_up(PancakePile pancakepile, int sizeZ){};
    void setSizeZ(int z){
        sizeZ=z;
    }
    int getSizeZ(){
        return sizeZ;
    }
};



//get the largest pancake index   flag-True->find largests
int search(PancakePile pancakepile,int sizeZ,int flag){
    int index=0,i;
    Pancake temp;
    temp=pancakepile.pancake[0];
    if(flag==1){
        for(i=0; i<sizeZ;i++){
            if(temp.getSize()<pancakepile.pancake[i].getSize()){
                temp=pancakepile.pancake[i];
                index=i;}
        }
    }else if(flag==0){
        for(i=0; i<sizeZ;i++){
            if(temp.getSize()>pancakepile.pancake[i].getSize()){
                temp=pancakepile.pancake[i];
                index=i;}
        }
    }else{
        //this is search in terms of order
        for(i=0; i<sizeZ;i++){
            if(temp.order>pancakepile.pancake[i].order){
                temp=pancakepile.pancake[i];
                index=i;
            }
        }
    }
    return index;
}

//flip the first index'th pancake;
void flip(PancakePile pancakepile,int index){
    Pancake temp;
    if(index>0){
        for(int i=0;i<(index/2.0);i++){//0;0 1;1 2;1 3;2 4;2 5;3 6;3
            temp=pancakepile.pancake[i];
            pancakepile.pancake[i]=pancakepile.pancake[index-i];
            pancakepile.pancake[index-i]=temp;
        }
        for(int i=0;i<=index;i++){

            pancakepile.pancake[i].flip_pancake();
        }
    }

}



//burn down means burn=0;
PancakePile PancakePile::pancake_sort_ascending_burnt_down(PancakePile pancakepile, int sizeZ){
    int search(PancakePile,int,int);
    void flip(PancakePile,int);
    int max;
    if (sizeZ==0){
        if(pancakepile.pancake[0].getBurnt()==1){
        pancakepile.pancake[0].flip_pancake();
    }
        return pancakepile;
    }

    max=search(pancakepile,sizeZ,1);
    flip(pancakepile,max);

    //if the 1st pancake which is the largest is burned down, then flip this one
    //so that the next flip will make this largest one face down in the botton
    if(pancakepile.pancake[0].getBurnt()==0){
        pancakepile.pancake[0].flip_pancake();
    }
    flip(pancakepile,sizeZ-1);


    return pancake_sort_ascending_burnt_down(pancakepile,(sizeZ-1));
}


class FibPancakePile: public PancakePile{
public:
    void pancake_sort_descending_burnt_up(PancakePile pancakepile, int sizeZ);
};

bool isPerfectSquare(int x){
    int s=sqrt(x);
    return (s*s == x);

}

bool isFibonacci(int n){
    return isPerfectSquare(5*n*n + 4) || isPerfectSquare(5*n*n - 4);
}

//if one pancakepile has fib pancake, this funciton return the index of the largest fib pancake,
int searchFib(PancakePile pancakepile,int sizeZ){
    int i,j,index=-1;
    Pancake temp;
    for(j=0; j<sizeZ;j++){
        if(pancakepile.pancake[j].order<0){
            temp=pancakepile.pancake[j];
            index=j;
            break;
        }
    }

    for(i=j; i<sizeZ;i++){
        if(temp.getSize()<pancakepile.pancake[i].getSize() && pancakepile.pancake[i].order<0) {
            temp = pancakepile.pancake[i];
            index = i;
            // cout<<temp.getSize()<<" ";
        }
    }
    return index;
}


//we need label the pancake, if the size is fibonacci, label it with '-1'
//if the pancake size is not fibonacci, the label is as the order
//the reason we label each pancake is to sorted it after we pick up the fibonacci size pancake at the original order
PancakePile labelpancake(PancakePile pancakepile, int sizeZ){
    bool isFibonacci(int);
    for(int i=0; i<sizeZ;i++){
        if(isFibonacci(pancakepile.pancake[i].getSize())){
            pancakepile.pancake[i].order=-i-1;
            pancakepile.hasFibonacci=true;
        }else{
            pancakepile.pancake[i].order=i;
        }
    }
    return pancakepile;
}

//first label each pancakepile,then sort fibonacci
PancakePile sortFibonacci(PancakePile pancakepile, int sizeZ){
    int searchFib(PancakePile,int);
    void flip(PancakePile,int);
    int max;
    if(pancakepile.hasFibonacci){
        //flip the largest fib pancake to the botton
        max=searchFib(pancakepile,sizeZ);

        if(max==-1){

            return pancakepile;
        }
        flip(pancakepile,max);
        //flip the burned side to face up, so when flip,
        if(pancakepile.pancake[0].getBurnt()==0){
            pancakepile.pancake[0].flip_pancake();
        }
        flip(pancakepile,sizeZ-1);
        return sortFibonacci(pancakepile,sizeZ-1);

    }else{
        //if this pancakepile dont has size of fibonacci, return it, donnot sort
        return pancakepile;
    }

}

//if after sorting the fib pancake, no oridinary pancake, newsize should be 0;
//else newsize should be the size of pancake without febonacci size
PancakePile sortOridinary(PancakePile pancakepile, int newsize){
    int search(PancakePile,int,int);
    void flip(PancakePile,int);
    int max;
    if(newsize==0) {
        //the late iteration, make the top one is face up(burn=0)
        //so the final whole flip, all will face down
        if(pancakepile.pancake[0].getBurnt()==1){
            pancakepile.pancake[0].flip_pancake();
        }
        return pancakepile;
    }
    
    max=search(pancakepile,newsize,-1);
    flip(pancakepile,max);
    if(pancakepile.pancake[0].getBurnt()==0){
        pancakepile.pancake[0].flip_pancake();
    }
    flip(pancakepile,newsize-1);

    return sortOridinary(pancakepile,newsize-1);

}

void FibPancakePile::pancake_sort_descending_burnt_up(PancakePile pancakepile, int sizeZ){
    int fibcount=0;
    pancakepile=labelpancake(pancakepile, sizeZ);
    pancakepile = sortFibonacci(pancakepile,sizeZ);
    for(int i=0;i<sizeZ;i++){
        if(pancakepile.pancake[i].order<0){
            fibcount++;
        }
    }
    
    pancakepile=sortOridinary(pancakepile,sizeZ-fibcount);
    flip(pancakepile,sizeZ-1);

}



class MPancakePiles{
public:
//    int x,y;
    void sort_interior(MPancakePiles **mypancakepile,int x, int y,int z);
    void sort_exterior(MPancakePiles **mypancakepile,int x, int y,int z);
    // PancakePile *pancakepile;
    FibPancakePile *fibPancakePile;

};

void MPancakePiles::sort_interior(MPancakePiles **mypancakepile, int x, int y,int z){

    if(!(x==1&&y==1)){
            for(int i=1;i<x-1;i++)
        {
            for(int j=1;j<y-1;j++)
            {
            mypancakepile[i][j].fibPancakePile->pancake_sort_ascending_burnt_down(*(mypancakepile[i][j].fibPancakePile),z);
            }
        }


    }

}

void MPancakePiles::sort_exterior(MPancakePiles **mypancakepile,int x, int y,int z){
    int i,j;

     for(i=0,j=0;j<y;j++){
         mypancakepile[i][j].fibPancakePile->pancake_sort_descending_burnt_up(*(mypancakepile[i][j].fibPancakePile),z);
     }
     for(i=x-1,j=0;j<y;j++){
         mypancakepile[i][j].fibPancakePile->pancake_sort_descending_burnt_up(*(mypancakepile[i][j].fibPancakePile),z);
     }
     for(j=0,i=1;i<x-1;i++){
         mypancakepile[i][j].fibPancakePile->pancake_sort_descending_burnt_up(*(mypancakepile[i][j].fibPancakePile),z);
     }
     for(j=y-1,i=1;i<x-1;i++){
         mypancakepile[i][j].fibPancakePile->pancake_sort_descending_burnt_up(*(mypancakepile[i][j].fibPancakePile),z);
     }
}

int getSecretNum(MPancakePiles **mypancakepile,int x, int y,int z){
    int i,j;
    int sum=0;
     for(i=0,j=0;j<y;j++){
         for(int k=0;k<z;k=k+2){
             if(mypancakepile[i][j].fibPancakePile->pancake[k].order<0){
                 sum=sum+mypancakepile[i][j].fibPancakePile->pancake[k].getSize();
             }
         } 
     }
     for(i=x-1,j=0;j<y;j++){
        for(int k=0;k<z;k=k+2){
             if(mypancakepile[i][j].fibPancakePile->pancake[k].order<0){
                 sum=sum+mypancakepile[i][j].fibPancakePile->pancake[k].getSize();
             }
         } 
      }
     for(j=0,i=1;i<x-1;i++){
         for(int k=0;k<z;k=k+2){
             if(mypancakepile[i][j].fibPancakePile->pancake[k].order<0){
                 sum=sum+mypancakepile[i][j].fibPancakePile->pancake[k].getSize();
             }
         } 
    }
     for(j=y-1,i=1;i<x-1;i++){
        for(int k=0;k<z;k=k+2){
             if(mypancakepile[i][j].fibPancakePile->pancake[k].order<0){
                 sum=sum+mypancakepile[i][j].fibPancakePile->pancake[k].getSize();
             }
         } 
     }
     return sum;
}
int main(){
    void Free(MPancakePiles**,int,int);
    int x,y,z;
    

    ifstream readFile("input.txt");
    char temp[1024]={0};
    readFile>>x;
    readFile>>y;
    readFile>>z;

    //read the blank first line
    readFile.getline(temp,1024);

    //initial pancake

    MPancakePiles** mypancakepile = new MPancakePiles*[x];
    for(int i=0;i<x;i++){
        mypancakepile[i]=new MPancakePiles [y];
        for(int j=0;j<y;j++){
            mypancakepile[i][j].fibPancakePile=new FibPancakePile();
            mypancakepile[i][j].fibPancakePile->pancake=new Pancake[z+1];
            //reference https://www.cnblogs.com/boluo007/p/6755540.html

            readFile.getline(temp,1024);
            char *p=strtok(temp," ,");
            int count=0;
            while(p!=NULL){
                int a;
                a=atoi(p);
                if(count%2==0){
                    mypancakepile[i][j].fibPancakePile->pancake[count/2].setSize(a);
                }else{
                    mypancakepile[i][j].fibPancakePile->pancake[count/2].setBurnt(a);
                }
                count++;
                p=strtok(NULL," ,");//reference https://www.cnblogs.com/xunbu7/p/4309246.html
            }
        }
    }
    
    readFile.close();
    MPancakePiles cakeIn,cakeOut;
 cakeIn.sort_interior(mypancakepile,x,y,z);
cakeOut.sort_exterior(mypancakepile,x,y,z);
 

    int getSecretNum(MPancakePiles**,int , int ,int );
    int sum=getSecretNum(mypancakepile,x,y,z);
    cout<<sum%512;
   ofstream outfile("output.txt");
   outfile<<x<<" "<<y<<" "<<z<<"\n";

   for(int i=0;i<x;i++){
       for(int j=0;j<y;j++){
           for(int k=0;k<z;k++){
               outfile<<mypancakepile[i][j].fibPancakePile->pancake[k].getSize()<<","<<mypancakepile[i][j].fibPancakePile->pancake[k].getBurnt()<<" ";
           }
           outfile<<"\n";
       }
   }
    outfile.close();

    Free(mypancakepile,x,y);

    return 0;
}





void Free(MPancakePiles **pancakepile,int x,int y){
    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
            delete[] pancakepile[i][j].fibPancakePile;
        }
        delete[] pancakepile[i];
        
    }
    delete []pancakepile;
}
