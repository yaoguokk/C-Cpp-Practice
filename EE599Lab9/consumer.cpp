#include <pthread.h>
#include <iostream>
#include <deque>
#include <unistd.h>
using namespace std;
pthread_mutex_t IOlock =PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond =PTHREAD_COND_INITIALIZER;

int buffer[100];
deque<int> queue;
int loops = 5;
int length = 0;

void *producer(void *arg) {
    int i;
    while(1){
        pthread_mutex_lock(&IOlock);
        length++;
        buffer[length++] = i;
        cout<<"producer length "<< length<<endl;
        sleep(1);        
        pthread_mutex_unlock(&IOlock);
        pthread_cond_signal(&cond);
    }
    pthread_exit(NULL);

}

void *consumer(void *arg) {
    int i;
    while (1) {
        pthread_mutex_lock(&IOlock);
        while(length == 0) {
            cout<<"consumer waiting... "<<endl;
            pthread_cond_wait(&cond, &IOlock);
        }
        int item = queue[--length];
        cout<<"Consumer "<< item<<endl;
        pthread_mutex_unlock(&IOlock);
    }

    pthread_exit(NULL);
}


int main(int argc, char *argv[])
{

    pthread_mutex_init(&IOlock, NULL);
    pthread_cond_init(&cond, NULL);

    pthread_t pThread, cThread;
    pthread_create(&pThread, NULL, producer, NULL);
    pthread_create(&cThread, NULL, consumer, NULL);
    pthread_join(pThread, NULL);
    pthread_join(cThread, NULL);

    pthread_mutex_destroy(&IOlock);
    pthread_cond_destroy(&cond);
    return 0;
}

