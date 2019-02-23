#include "sort.h"
using namespace std;

Sort :: Sort(){
    A = new int;

}
Sort::~Sort(){
    delete A;
}
void print(int* A,int num){
    for(int i=0;i<num;i++){
        cout<<A[i]<<endl;
    }
}

Sort :: Sort (string inputfile,string outfile, int num,string method){
     A = new int[num];
    // cout<<"initial A arr"<<endl;
    getData(inputfile);
    if(method == "bubbleSort"){
        bubbleSort(num);
    }else if(method == "selectionSort"){
        selectionSort(num);
    }else if(method == "mergeSort"){
        mergeSort(A,num);
    }else if(method == "quickSort"){
        quickSort(A,0,num-1);
    }else if(method == "radixSort"){
        radixSort(A,num);
    }else{
        cout<<"input method wrong"<<endl;
    }
    outData(outfile,num);
}

void Sort:: getData (string filename){
    ifstream infile;
    infile.open(filename.c_str());
    string buff;
    int i=0;
    while(getline(infile,buff)){
        A[i]=atoi(buff.c_str());
        i++;
    }

} 

void Sort :: outData (string filename,int num){
    ofstream outfile(filename.c_str());
    for(int i=0;i<num;i++){
        outfile<<A[i]<<endl;
    }
}

void Sort:: bubbleSort(int num){
    int i,newn;
   while(num!=0){
        newn=0;
        for(i=1;i<num;i++){
            if(A[i]<A[i-1]){
                swap(A[i-1],A[i]);
                newn=i;
            } 
        }
        num=newn;
    }
   
}

void Sort:: selectionSort(int num){
    int i,j,smallest;

    for(i=0;i<num-1;i++){
        smallest=i;
        //following is to get the smallest number index
        for(j=i;j<num;j++){
            if(A[smallest]>A[j]){
                smallest=j;
            }
        }
        if(smallest != i)
            swap(A[smallest],A[i]);
    }
}

void Sort :: mergeSort(int* A,int num){
    void Merge(int*,int*,int,int*,int);
    int *left,*right;
    int i,mid;
    if(num<=1)
        return;
    mid = num/2;
    left = new int[mid];
    right = new int[num-mid];

    for(i=0;i<num;i++){
        if(i<mid)
            left[i]=A[i];
        else
            right[i-mid]=A[i];
    }

    //recursive sort
    mergeSort(left,mid);
    mergeSort(right,num-mid);
    //merge the now-sorted sublist
    Merge(A,left,mid,right,num-mid);

    delete []left;
    delete []right;
}

void Merge(int* A,int* left,int Lnum,int* right,int Rnum){
    int i=0,j=0,k=0;

    while(i<Lnum && j<Rnum){
        if(left[i]<right[j]) {
            A[k]=left[i];
            k++;i++;
        }else{
            A[k]=right[j];
            k++;j++;
        }
    }
    while(i<Lnum){
        A[k]=left[i];
        k++;i++;
    }
    while(j<Rnum){
        A[k]=right[j];
        k++;j++;
    }

}


void Sort::quickSort(int* A,int p,int r){
    int partition(int* ,int ,int );
    if(p<=r){
        int q=partition(A,p,r);
        quickSort(A,p,q-1);
        quickSort(A,q+1,r);
    }
}

int partition(int* A,int p,int r){
    int x=A[r];
    int i=p-1;
    for(int j=p;j<r;j++){
        if(A[j]<x){
            i++;
            swap(A[i],A[j]);
        }
    }
    swap(A[i+1],A[r]);
    return i+1;
}


// Get maximum value from array.
int getMax(int* arr, int n)
{
	int max = arr[0];
	for (int i = 1; i < n; i++)
		if (arr[i] > max)
			max = arr[i];
	return max;
}
 
// Count sort of arr[].
void countSort(int* arr, int n, int exp)
{
	int output[n], i, count[10] = {0};
	for (i = 0; i < n; i++)
		count[(arr[i] / exp) % 10]++;
 
	for (i = 1; i < 10; i++)
		count[i] += count[i-1];
 
	for (i = n - 1; i >= 0; i--){
		output[count[(arr[i] / exp) % 10] - 1] = arr[i];
		count[(arr[i] / exp) % 10]--;
	}
 
	for (i = 0; i < n; i++)
		arr[i] = output[i];
}
 
// Sort arr[] of size n using Radix Sort.
void Sort::radixSort(int *A, int n)
{
	int exp, m;
	m = getMax(A, n);
 
	for (exp = 1; m/exp > 0; exp *= 10)
		countSort(A, n, exp);
}

