#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
static int *storenum = new int[1024];
static int totaliter = 0;

void problem1a()
{
    ifstream infile;
    infile.open("text.txt");
    char temp[512];
    string s[100];
    char *ch[100];
    int count = 0, i;
    while (infile>>temp)
    {
        
        ch[count]=new char[strlen(temp)+1];
        strcpy(ch[count],temp);
        // cout<<ch[count]<<" ";
        count++;
        if(infile.eof()||count>=10)
            break;
    } 
    infile.close();
    for(i=0;i<count;i++){
        s[i]=ch[i];
    }
    for(int i=0;i<count;i++){
        cout<<s[i]<<" ";
    }
   
}
void problem1b(){
    ifstream infile;
    infile.open("in.txt");
    char temp[512];
    char *ch[100];
    int count = 0, i;
    while (infile>>temp)
    {
         if(infile.eof())
            break;
        
        
        ch[count]=new char[strlen(temp)+1];
        strcpy(ch[count],temp);
        // cout<<ch[count]<<" ";
        count++;
    } 
    infile.close();
    
    //It prints the strings in the input file into an output file, but with reverse order of strings. 
    ofstream outputfile("out1b.txt");
    for (i = count - 1; i >= 0; i--)
    {
        outputfile << ch[i] << " ";
    }
    
    outputfile.close();
}

int comp(string s1,string s2){
    // cout<<"s1 start"<<s1[0]<<endl;
    // cout<<"s2 start"<<s2[0]<<endl;
    int s1a=int(s1[0]);
    int s2a=int(s2[0]);
    //if s1a s2a are number, add beyond "z"
    if(s1a<=57&&s1a>=48)
        s1a+=122-48;
    
    if(s2a<=57&&s2a>=48)
        s2a+=122-48;
    if(s1a>=65 && s1a<=90)
        s1a+=97-65;
    if(s2a>=65 && s2a<=90)
        s2a+=97-65;
            
    return s1a-s2a;
}

void sortBubble(string *s, int length){
    if(length<=0)
        return;
   //https://blog.csdn.net/bajianxiaofendui/article/details/83011314 
    for(int i=0;i<length-1;i++){
        int flag=0;
        for(int j=0;j<length-1-i;j++){
            if(comp(s[j],s[j+1])>0){
                s[j].swap(s[j+1]);
                flag=1;
            }
        }
        if(flag==0){
            break;
        }
    }
}

void problem1c(){

    ifstream infile;
    infile.open("in.txt");
    char temp[512];
    string s[100];
    char *ch[100];
    int count = 0, i;
    while (infile>>temp)
    {
          if(infile.eof())
            break;
        ch[count]=new char[strlen(temp)+1];
        strcpy(ch[count],temp);
        // cout<<ch[count]<<" ";
        count++;
      
    } 
    infile.close();
    for(i=0;i<count;i++){
        s[i]=ch[i];
    }
    sortBubble(s,count);
   
    ofstream outputfile("out1c.txt");
    for (i = 0; i<count; i++)
    {
        outputfile << s[i] << " ";
    }

    outputfile.close();



}



void choose(int *arr, int len, int k, int store[], int size, string s2, ofstream &outfile)
{
    int i;
    char ptr[80];
    if (k == 0)
    {
        string temp(s2);

        for (i = 0; i < size; i++)
        {
            temp.insert(store[i] + i, ":");
        }
        outfile << temp << " ";
        int *gltemp = new int;
        if (size == 1)
        {
            storenum[totaliter] = stol(s2.substr(store[0]));
        }
        else if (size > 1)
        {
            gltemp[0] = stol(s2.substr(0, store[0]));
            for (i = 1; i < size; i++)
            {
                gltemp[i] = stol(s2.substr(store[i - 1], store[i] - store[i - 1]));
            }
            gltemp[size] = stol(s2.substr(store[size - 1]));
            int temp = gltemp[0];
            for (i = 0; i <= size; i++)
            {
                if (temp < gltemp[i])
                    temp = gltemp[i];
            }
            storenum[totaliter] = temp;
        }

        delete gltemp;

        totaliter += 1;
        return;
    }

    for (i = len; i >= k; --i)
    {
        store[k - 1] = arr[i - 1];
        choose(arr, i - 1, k - 1, store, size, s2, outfile);
    }
}

void problem2(string str){
    int K;
    cout<<"\nplease input K(smaller than the length of string"<<endl;
    cin>>K;
    
    int len = str.length();
    int *store = new int[len];
    ofstream outfile("out2.txt");
    if (K > len - 1)
    {
        cout << "k should smaller than length of string";
    }
    else
    {
        int *arr = new int[len];
        for (int i = 0; i < len; i++)
        {
            arr[i] = i + 1;
        }
        string s2(str);

        choose(arr, len - 1, K, store, K, s2, outfile);

        //compare to get the max
        int temp = storenum[0];
        for (int i = 0; i < totaliter; i++)
        {
            if (storenum[i] > temp)
                temp = storenum[i];
        }
        outfile << "Max:" << temp;
        outfile.close();
        delete[] arr;
    }

    delete[] store;
    delete[] storenum;

}

int main()
{
    string str = "56899";
    
    problem1a();
    problem1b();
    problem2(str);
    problem1c();

   
    
    return 0;
}
