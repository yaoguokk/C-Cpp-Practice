#include <iostream> 
#include <fstream>
#include <string>
 
using namespace std;
 
void strins(int g, int m,int k, string b,int len, ofstream &file1);
int findmax(int k, int len, string a);
 
int main(){
 
string num;
int k;
cout<<" Give S2: "<<endl;
cin>>num;
cout<<" Give k: "<<endl;
cin>>k;
 
int len=num.length();
 
while (len <= k || k <=0)
{
      cout<<"Give different k: "<<endl;
      cin >>k;
}
 
ofstream file1("out2.txt");
 
string ap;
 
if(k==len-1)
{
      for(int i=0;i<len;i++)
      {
            ap+=num[i];
            ap+=':';
      }
      file1<<ap<<endl;
}
 
else 
{
      strins(1,0,k,num,len,file1);
}
 
int max=findmax(k,len,num);
file1<<"\nMax is: "<<max<<endl;
 
file1.close();

}

void strins(int g, int m,int k, string b,int len, ofstream &file1)
{     
      for(int i=g;i < len-k+1+m; i++)
      {     
            cout<<"i="<<i<<" len-k+1+m="<<len-k+1+m<<endl;
            string a=b;
            a.insert(i,":");
            cout<<"m+2="<<m+2<<" 2*k="<<2*k<<endl;
            if(m+2 < 2*k)
            {
                  int n=m+2;
                  strins(i+2,n,k,a,len,file1);}
            else
            {     cout<<a<<endl;
                  file1<<a<<endl;
            }
      }
}
 
int findmax(int k, int len, string a)
{
      int max=0;
      for (int i=0;i<k+1;i++) 
      {
            int b=stoi(a.substr(i,len-k));
            if(b>max)
                  max=b;
      }
      return max;
}
