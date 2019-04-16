#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#define SIZE 3
#define loop 100

struct product
{
    pthread_mutex_t mutux;
    pthread_cond_t notfull;
    pthread_cond_t notempty;
    int pos;
    int buf[SIZE];
 
};
struct product pdt;
void init(struct product * t)
{
    pthread_mutex_init(&t->mutux,NULL);
    pthread_cond_init(&t->notfull,NULL);
    pthread_cond_init(&t->notempty,NULL);
    t->pos=-1;
 
}
void put(struct product * t,int data)
{
    pthread_mutex_lock(&t->mutux);
    if(t->pos+1>SIZE-1)//the array is full
    {        
        printf("no more space--- wait \n");
       pthread_cond_wait(&t->notfull,&t->mutux);
    }
    t->pos=t->pos+1;
    t->buf[t->pos]=data;
    printf("1 thread %d put a data %d  to  pos %d\n",pthread_self(),data,t->pos);
    pthread_cond_signal(&t->notempty);
    pthread_mutex_unlock(&t->mutux);
}

void put1(struct product * t,int data)
{
    pthread_mutex_lock(&t->mutux);
    if(t->pos+1>SIZE-1)//the  array is full
    {
        printf("no more space--- wait \n");
        pthread_cond_wait(&t->notfull,&t->mutux);
    }
    t->pos=t->pos+1;
    t->buf[t->pos]=data;
    printf("2 thread %d put a data %d  to  pos %d\n",pthread_self(),data,t->pos);
    pthread_cond_signal(&t->notempty);
    pthread_mutex_unlock(&t->mutux);
}
 
 
void* get(void*a)
{   

    struct product * t= &pdt;
    int n=0;
    while(n<20){
        n++;
    pthread_mutex_lock(&t->mutux);
    if(t->pos<0)//the  array is full
    {
        printf("no more consume--- wait \n");
        pthread_cond_wait(&t->notempty,&t->mutux);
    }
    printf("thread %d get a data %d  to  pos %d\n",pthread_self(),t->buf[t->pos],t->pos);
    t->pos=t->pos-1;
    pthread_cond_signal(&t->notfull);
    pthread_mutex_unlock(&t->mutux);
    }
    
}
void * putter(void *)
{
    int n;
    for(n=0;n<loop;n++)
    {
       put(&pdt,n);
    }
}

void * putter1(void *)
{
    int n;
    for(n=0;n<loop;n++)
    {
       put1(&pdt,n);
    }
}
void * getter(void *)
{
    int n;
    for(n=0;n<loop;n++)
    {
       get(&pdt);
    }
}
//1 2 3 4
int main(void )
{
   int err;
   pthread_t pt1,pt2,gt1,gt2;
   void * retval;
   init(&pdt);
   err=pthread_create(&pt1,NULL,putter,0);
   err=pthread_create(&pt2,NULL,putter1,0);
   err=pthread_create(&gt1,NULL,get,0);
//    err=pthread_create(&gt2,NULL,getter,0);
   //主线程等待这四个线程结束
 
        pthread_join(pt1,&retval);
 
        pthread_join(pt2,&retval);
 
        pthread_join(gt1,&retval);
 
        // pthread_join(gt2,&retval);
 
        return 0;
 
}