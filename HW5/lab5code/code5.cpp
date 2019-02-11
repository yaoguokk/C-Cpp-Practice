#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<iomanip>  
#include <unistd.h>    
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

class SimulatedAnnealing {
private:
	double T_start;//intial temperature
	double T_end;//end temperature
	/*...*/
	City **cities;//we want you to practice pointer in this lab
	double **dist;
	int num;
	int *a;
	double result[];
	
public:
	double **getDist(){
		return dist;
	}
	SimulatedAnnealing() {
		cities = NULL;
	}
	SimulatedAnnealing(double value1, double value2,  istream & infile) {
		T_start = value1;
		T_end = value2;
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
			// cout<<"x= "<<x<<" y="<<y<<" z="<<z<<endl;
		}

		//initial the distance betweek city[i] to city[j]
		dist=new double*[num];
		for(int i=0;i<num;i++){
			dist[i]=new double[num];
			for(int j=0;j<num;j++){
				double temp=sqrt(pow(cities[i]->getXcorr()-cities[j]->getXcorr(),2)+pow(cities[i]->getYcorr()-cities[j]->getYcorr(),2));
				dist[i][j]=temp;
				// cout<<dist[i][j]<<"  ";
			}
			// cout<<endl;
		}
	}
	
	void showInfo(){
		for(int i=0;i<10;i++){
			cout<<cities[i]->getCityName()<<" x="<<cities[i]->getXcorr()<<" y="<<cities[i]->getYcorr()<<endl;
		}
	}

	double CA(int a[MAX],int Iteration,double coolRate){
		srand((unsigned)time(NULL));
		double sum0=0;
		int set[num],index,i,count;
		//generate a sequence as the initial route
		for( i=0;i<num;i++){
			set[i]=i;
		}

		for( i=0;i<num;i++){
			index=random(0,num-i);
			a[i]=set[index];
			set[index]=set[num-i-1];
		}

		a[num]=a[0];//the last tour is back to the deparature point
		
		sum0=sumDist(dist,a,num);
		// cout<<"the original is "<<sum0<<endl;

		int r1,r2,sumdist;

		int countNo=0;
		for(count=0;count<Iteration;count++){
			
			r1=random(1,num);
			r2=random(1,num);
			// cout<<"r1= "<<r1<<" r2= "<<r2<<endl;
			if(r1==r2)
				continue;
			
			swap(a[r1],a[r2]);

			sumdist=sumDist(dist, a, num);

			double sigma=(sumdist-sum0)/sum0;
			// cout<<"sigma is "<<sigma<<endl;
			bool judge=(exp(-sigma/T_start)>((double)rand()/RAND_MAX));
			// cout<<"judge is "<<judge<<endl;
			if(sigma<=0){
				sum0=sumdist;
			}else if(judge){
				sum0=sumdist;
			}else{
				countNo++;
				int temp=a[r1];
				a[r1]=a[r2];
				a[r2]=temp;
				sum0=sumDist(dist,a,num);
			}
			
			T_start=T_start*coolRate;

			if(T_start<T_end){
				// cout<<"break with iteration :"<<count<<endl;
				break;
			}
				
		}

		ofstream outfile("Lab5_partI_task1_output.txt.txt");
		outfile<<"Final Distance of SA Method: "<<sum0<<"\n";
		for(int i=0;i<=num;i++){
		outfile<<a[i]+1<<"\n";
		}
		outfile.close();

		return sum0;
	}

	double CAT0(int a[MAX],int Iteration,double coolRate){
		srand((unsigned)time(NULL));
		double sum0=0;
		int set[num],index,i,count;
		//generate a sequence as the initial route
		for( i=0;i<num;i++){
			set[i]=i;
		}

		for( i=0;i<num;i++){
			index=random(0,num-i);
			a[i]=set[index];
			set[index]=set[num-i-1];
		}

		a[num]=a[0];//the last tour is back to the deparature point
		
		sum0=sumDist(dist,a,num);
		// cout<<"the original is "<<sum0<<endl;

		int r1,r2,sumdist;
		double sumsigma=0;

		int countSigmaLarge=0;
		for(count=0;count<Iteration;count++){
			
			r1=random(1,num);
			r2=random(1,num);
			// cout<<"r1= "<<r1<<" r2= "<<r2<<endl;
			if(r1==r2)
				continue;
			
			swap(a[r1],a[r2]);

			sumdist=sumDist(dist, a, num);

			double sigma=(sumdist-sum0)/sum0;
			// cout<<"sigma is "<<sigma<<endl;
			// bool judge=(exp(-sigma/T_start)>((double)rand()/RAND_MAX));
			// cout<<"judge is "<<judge<<endl;
			if(sigma<=0){
				sum0=sumdist;
			}else{
				sumsigma=sumsigma+sigma;
				countSigmaLarge++;
				sum0=sumdist;
			}
			
				
		}
		
		double avgSigma=sumsigma/countSigmaLarge;
		cout<<"avgSigma="<<avgSigma<<" sumsigma:"<<sumsigma<<" countsigma:"<<countSigmaLarge<<endl;
		double T0=-avgSigma*1000/(log(0.8));
		cout<<"estimate T0 is "<<T0<<endl;
		return sum0;
	}

	double* CABETA(int a[MAX],int Iteration,double coolRate,double beta){
		srand((unsigned)time(NULL));
		//redefine the T_start
		T_start=beta;
		double sum0=0;
		int set[num],index,i,count;
		//generate a sequence as the initial route
		for( i=0;i<num;i++){
			set[i]=i;
		}

		for( i=0;i<num;i++){
			index=random(0,num-i);
			a[i]=set[index];
			set[index]=set[num-i-1];
		}

		a[num]=a[0];//the last tour is back to the deparature point
		
		sum0=sumDist(dist,a,num);
		// cout<<"the original is "<<sum0<<endl;

		int r1,r2,sumdist,countNo=0;
		double sumsigma=0;

		int countSigmaLarge=0;
		for(count=0;count<Iteration;count++){
			
			r1=random(1,num);
			r2=random(1,num);
			// cout<<"r1= "<<r1<<" r2= "<<r2<<endl;
			if(r1==r2)
				continue;
			
			swap(a[r1],a[r2]);

			sumdist=sumDist(dist, a, num);

			double sigma=(sumdist-sum0)/sum0;
			// cout<<"sigma is "<<sigma<<endl;
			bool judge=(exp(-sigma/T_start)>((double)rand()/RAND_MAX));
			// cout<<"judge is "<<judge<<endl;
			if(sigma<=0){
				sum0=sumdist;
			}else if(judge){
				sum0=sumdist;
			}else{
				
				int temp=a[r1];
				a[r1]=a[r2];
				a[r2]=temp;
				sum0=sumDist(dist,a,num);
			}
			countNo++;
			T_start=T_start*coolRate;

			if(T_start<T_end){
				break;
			}
				
		}
		result[2]=coolRate;
		result[0]=sum0;
		result[1]=countNo;
		return result;
	}

	~SimulatedAnnealing() {
		delete[] cities;
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
		for( i=0;i<num;i++){
			flag[i]=0;//to record if one city have only passed once 
		}
		a[0]=0;//start from 1
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
		
		for(i=0;i<=num;i++)
			cout<<a[i]<<" " ;
		
		//reference:https://blog.csdn.net/shujian_tianya/article/details/80885029

		ofstream outfile("Lab5_partI_task2_output.txt.txt");
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
	int a[MAX],i,times;
	double sum=0,avgmini;
	ifstream infile;
 
	infile.open ("Lab5_partI_input.txt");
	SimulatedAnnealing s1(100,1e-6,infile);
	// double sum1=s1.CAT0(a,50000,0.95);
	double *result=s1.CABETA(a,50000,0.999,380);
	cout<<" the beta is "<<result[2]<<"\n the total iteration times is "<<result[1]<<"\n the distance is "<<result[0]<<endl;
	
	// Greedy gd(infile);
	// gd.HC(a);
	
	
	
	// double sigma=0.2;

	// bool judge=(exp(-sigma/T_start)>((double)rand()/RAND_MAX));
	
	// cout<<(double)rand()/RAND_MAX;
	// cout<<"judge is "<<judge<<exp(-0.1/0.03)<<endl;
			
	// int a[11]={5 ,9 ,1, 6, 2, 3, 7, 4, 8, 0, 5},i;
	// int b[11]={1,9,3,7,2,10,4,8,5,6,1};
	// double **dist;
	// for(int i=0;i<=10;i++){
	// 	b[i]=b[i]-1;
	// }
	// dist=s1.getDist();
	// cout<<sumDist(dist,b,10);
	

	return 0;
}
