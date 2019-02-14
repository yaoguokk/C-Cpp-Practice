#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<math.h>
#include<time.h>
// #include<unistd.h>

using namespace std;
int random(int ,int );
double sumDist(double **,int *,int);
#define MAX 512

class City {
	
    private:
        string CityName;
        int Xcorr; 
        int Ycorr;
    public:
        void setCityName(int s1){
			CityName="CityNo"+to_string(s1);	
		};
        string getCityName(){
			return CityName;
		};
        void setXcorr(int x){
            Xcorr = x;
        }
        int getXcorr(){
            return Xcorr;
        }
        void setYcorr(int y){
            Ycorr = y;
        }
        int getYcorr(){
            return Ycorr;
        }
		City(){};
        City(int No, int x, int y){
            setCityName(No);
            setXcorr(x);
            setYcorr(y);
        }

};




int random(int a,int b)//generate random num between [a,b)
{
 	
	if(a==b)
		return a;
	return (a+rand()%(b-a));
}
double sumDist(double **dist,int a[],int num){
	int distsum=0;
	for(int i=0;i<num;i++){
		distsum+=dist[a[i]][a[i+1]];
	}
	return distsum;
}

class Greedy {
private:
	int num;
	City **cities;
	double **dist;
	int *b;
public:
	Greedy() {
		cities = NULL;
	}
	Greedy(istream & infile) {
	
		int x,y,z;
		infile >> num;
		cities = new City* [num];
		int count=0;
		//initialize the City Object
		while(!infile.fail()){
			infile>>x>>y>>z;
			if(count<num){
				cities[count]=new City(x,y,z);
			}
			count++;
		}

		//initial the distance betweek city[i] to city[j]
		dist=new double*[num];
		for(int i=0;i<num;i++){
			dist[i]=new double[num];
			for(int j=0;j<num;j++){
				double temp=sqrt(pow(cities[i]->getXcorr()-cities[j]->getXcorr(),2)+pow(cities[i]->getYcorr()-cities[j]->getYcorr(),2));
				dist[i][j]=temp;
			}
			
		}
	}

	void HC(int a[MAX]){
		int i,j,start,nextcity,flag[num],mindist,begin;
		//to record if one city have only passed once 
		for( i=0;i<num;i++){
			flag[i]=0;
		}
		a[0]=0;//start from the 1st city
		start = 0;
		flag[0]=1;
		begin=0;
		for(i=0;i < num;i++){
			mindist=99999;
			for(j=0;j<num;j++){
				if((flag[j]==0)&&(dist[start][j]<mindist)&&(dist[start][j]!=0)){
					mindist=dist[start][j];
					nextcity=j;
				}//get smallest distance
			}
			flag[nextcity]=1;
			start = nextcity;
			a[i+1]=start;
		}
		
		a[num]=0;//back to 1;
		
		//reference:https://blog.csdn.net/shujian_tianya/article/details/80885029

		ofstream outfile("Lab5_partI_task2_output.txt");
		outfile<<"Final Distance of Greedy Method: "<<sumDist(dist,a,num)<<"\n";
		for(int i=0;i<=num;i++){
		outfile<<a[i]+1<<"\n";
		}
		outfile.close();

	}

	~Greedy() {
		
	}

};


int main() {
	srand((unsigned)time(NULL));
	int a[MAX],i,times;
	double sum=0,avgmini;
	
	ifstream infile;
	infile.open ("Lab5_partI_input.txt");
	Greedy g1(infile);
	g1.HC(a);

	return 0;
}
