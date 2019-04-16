#include <iostream>
#include <cstdlib>
#include <pthread.h>

using namespace std;

#define NTHREADS 8

void *helloWorld(void *threadid)
{
   int tid;
   tid = (long)threadid;
   cout << "Hello world! It is me, 00" << tid << endl;
   pthread_exit(NULL);
}

int main ()
{
   pthread_t threads[NTHREADS];
   int rc;
   int i;
   for( i=0; i < NTHREADS; i++ ){
      cout << "main: creating thread 00" << i << endl;
      int error = pthread_create(&threads[i], NULL, helloWorld, (void *) i);
      if (error) {
         cout << "Error: unable to create thread," << error << endl;
         exit(-1);
      }
   }
   
   pthread_exit(NULL);
}

