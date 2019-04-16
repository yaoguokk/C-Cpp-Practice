#include <stdio.h>
#include <random>
#include <time.h>
#include <iostream>
#define INTERVAL 10000
using namespace std;
double montecarno(){
    int interval, i; 
    double rand_x, rand_y, origin_dist, pi;
    int circle_points = 0, square_points = 0;

    srand (time(NULL));
    for(i = 0; i<(INTERVAL * INTERVAL); i++){

        rand_x = double(rand() % (INTERVAL + 1)) / INTERVAL;
        rand_y = double(rand() % (INTERVAL + 1)) / INTERVAL;
        
        origin_dist = rand_x * rand_x + rand_y * rand_y;

        if(origin_dist <= 1)
            circle_points++;
        square_points++;
        
        pi = double(4 * circle_points)/square_points;

    }
    return pi;
}

int main(){
    double calculate(int);
    double pi = calculate(10000);
    cout<< "\nFinal Estimation of Pi ="<<pi<<endl;
    cout<<"another montencarno Pi is "<<montecarno();
    return 0;
}
 
double calculate(int n){
    int i,point_in_circle=0,point_total=0;
    double x,y,dist;
    srand(time(NULL));
    for(i=0;i<n*n;i++){
        x = double(rand()%(n+1))/n;
        y = double(rand()%(n+1))/n;
        dist = x*x+y*y;
        if(dist <= 1)
            point_in_circle ++;
        point_total++;   
    }
    double pi = double(4*point_in_circle)/point_total;
    return pi;
}