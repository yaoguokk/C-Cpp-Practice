#include <stdio.h>
#include <time.h>
#include <stdlib.h>
 char str[]= "input.txt";
int main(){
   
    
    double n;
    int i,j,k;
    FILE *fp=fopen(str,"w");
    //输入生成的矩阵大小s
    int p = 500;
    int range=10;
    srand(time(NULL));   // Initialization, should only be called once.
    int r ; 
    fprintf(fp,"%d\n",p);
    
    
    for (i=0;i<p;i++){
        for(j=0;j<p;j++){
            r= rand()%range;
            fprintf(fp,"%d ",r);
        }
        fprintf(fp,"\n");
    }
    for (i=0;i<p;i++){
        for(j=0;j<p;j++){
            r= rand()%range;
            fprintf(fp,"%d ",r);
        }
        fprintf(fp,"\n");
    }
    fclose(fp);
}
