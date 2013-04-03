#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "pth.h"

#ifndef __SCHEDULER_H__
#define __SCHEDULER_H__

// variables
unsigned timeInst; // global to synchronize time accross tasks
unsigned dataCollectionCtr; // global used to count robots processed

// constants
#define MAX_THREADS 7

void *thread_1(void *ptr);
void *thread_2(void *ptr);
int scheduler(void);

// external functions

// send data to the interested listeners, position, speed, obstables, etc.
void* sendData(void* ptr);
// receive data from liek  position, speed, obstables, etc from members I have subscribed
void* receiveData(void* ptr);

// makes the subscriptions
void* mcastSubscribe(void* ptr);

// makes the unsubscriptions
void* mcastUnSubscribe(void* ptr);

// selects the near neighbors to subscribe to their transmitted data
void* dataSelection(void* ptr);

// process the data from selected bots
void* dataProcessing(void* ptr);

// makes decision based on processed data
void* decisionMaking(void* ptr);
#endif // __SCHEDULER_H__
