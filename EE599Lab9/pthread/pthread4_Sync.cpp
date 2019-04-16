// Make sure you run this program in your duo-core system
// If you use virtual machine, you can assign one more core to it
// to see the problem. If you run this program in one-core system,
// you won't see any problems.

#include <iostream>
#include <cstdlib>
#include <pthread.h>

using namespace std;

#define NTHREADS 8

pthread_mutex_t IOlock;
struct args {
  int tid;
};

void *hello(void *a)
{
  args* myargs = (args*) a;
  int tid = myargs->tid;

  pthread_mutex_lock(&IOlock);
  cout << "Hello world! It is me, Thread " << tid << endl;
  pthread_mutex_unlock(&IOlock);

  pthread_exit(NULL);
}

int main (int argc, char* argv[])
{
  pthread_t threads[NTHREADS];

  for(int i=0; i < NTHREADS; i++ ){
    args* a = new args;
    a->tid = i;
    pthread_mutex_lock(&IOlock);
    cout << "main: creating thread 00" << i << endl;
    pthread_mutex_unlock(&IOlock);
    int error = pthread_create(&threads[i], NULL, hello, (void *) a);
    if (error) {
      cout << "Error: unable to create thread," << error << endl;
      exit(-1);
    }
  }
  pthread_exit(NULL);
}