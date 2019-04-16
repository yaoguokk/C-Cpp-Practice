// CPP program to demonstrate the given task 
#include <iostream> 
#include <pthread.h> 
#include <queue> 
#include <stdlib.h> 
#include <unistd.h>


#define p1loop 100  


using namespace std; 
  
// Declaring global variables 
static int totalterm = 0;
int glindex=-1;
int producer1count=0;
int producer2count=0;
int consumecoun0=0;
int capacity;
// Shared queue 
struct item{
    int index;//the index 
    int No; // the global index which is the i'th item
    int val;
};
struct id{
    int noid;
};
item *arr = new item[capacity];

// Fuction declaration of all required functions 
void* producerFun(void*); 
void* consume(void*); 
  
// Getting the mutex 
pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;  
pthread_cond_t notfull = PTHREAD_COND_INITIALIZER; 
pthread_cond_t notempty = PTHREAD_COND_INITIALIZER; 


void *producerFun(void* arg) 
{   
    id *idno = (id*)arg;
    int ido = idno->noid;
    // Initialising the seed 
    srand(time(NULL)); 
while(producer1count<p1loop){
 // Getting the lock on queue using mutex 
    pthread_mutex_lock(&mutex1); 
    if(glindex+1>capacity-1){
        std::cout << "no space Producer"<<ido<<" is in wait.." << endl; 
        pthread_cond_wait(&notfull, &mutex1); 
    }else{
    glindex ++;
    // Getting the random number 
    int num = rand() % 100; 
    item it;
    it.val = num;
    it.index = glindex;
    it.No = totalterm;
    // Pushing the number into queue 

    // Q[glindex].push(it); 
    arr[glindex]=it;
    std::cout << "Producer"<<ido<<" produced:  " << totalterm <<"th item \""<< num <<"\" at index "<< glindex <<endl; 
    producer1count++;
    totalterm++;    
                // sleep(1);

    pthread_cond_signal(&notempty);
    }

    pthread_mutex_unlock(&mutex1);

}   
    
     pthread_exit(NULL);     
}  


// Function definition for consumer thread
void* consume(void*arg) 
{      
    while (1) { 
        // Getting the lock on queue using mutex 

        pthread_mutex_lock(&mutex1); 
        
        if(glindex<0){
            cout<<"data consume all"<<endl;
            if(consumecoun0==p1loop){
            pthread_mutex_unlock(&mutex1);
            return NULL;
            }
            pthread_cond_wait(&notempty, &mutex1); 
        } 
        consumecoun0++;
        item data = arr[glindex];
        std::cout << "Consumer consums " << data.No << "th item \""<< data.val <<"\" from index "<< data.index <<endl; 
        //Consumer consumes 1th item "83" from index 0
        // Pop the consumed data from queue 
        glindex--;
        pthread_cond_signal(&notfull);
    
        // sleep(1);

        pthread_mutex_unlock(&mutex1); 
    }
} 
  
  
// Driver code 
int main(int argc, char** argv) 
{   
    string s =argv[1];
    capacity = atoi(s.c_str());
    id *id1 = new id;
    id *id2 = new id;
    id1->noid = 1;
    id2->noid = 2;
    // Declaring integers used to 
    // identify the thread in the system 
    pthread_t producerThread, producerThread1, consumerThread; 
  
    // Function to create a threads 
    int retProducer = pthread_create(&producerThread, NULL, producerFun, (void*)id1); 
    int retProducer1 = pthread_create(&producerThread1, NULL, producerFun, (void*)id2);
    int retConsumer = pthread_create(&consumerThread, NULL, consume,NULL); 
  
    // pthread_join suspends execution of the calling 
    // thread until the target thread terminates 
    if (!retProducer) 
        pthread_join(producerThread, NULL); 
    if (!retProducer1)
        pthread_join(producerThread1, NULL);
    if (!retConsumer) 
        pthread_join(consumerThread, NULL); 

      
    return 0; 
} 