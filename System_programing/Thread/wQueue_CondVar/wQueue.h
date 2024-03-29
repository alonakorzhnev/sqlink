#ifndef WQUEUE_H
#define WQUEUE_H
#include <semaphore.h>
#include <pthread.h> 
#include <unistd.h> 

struct wQueue
{
    void **arr;
    int read;
    int write;
    int size;
    int count;
    pthread_cond_t condEmpty;
    pthread_cond_t condFull;
    pthread_mutex_t lock; 
};

typedef struct wQueue wQueue;

wQueue* createWQueue(int count);

void* readWQueue(wQueue *queue);

void writeWQueue(wQueue *queue, void *writeVal);

int isEmpty(wQueue *queue);

int isFull(wQueue *queue);

void destroyWQueue(wQueue *queue);

#endif