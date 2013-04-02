#ifndef __botFunctions__h__
#define __botFunctions__h__

// Includes
#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "scheduler.h"

// Data structures

// assumed the bot size is 1 unit in length and width
// these are the limits of the simulation space
#define MAX_X 1200
#define MAX_Y 800
#define TOTAL_BOTS 3   
#define TIME_INSTANTS 41
#define NUM_OBST 4
#define MAX_RANGE_X 10
#define COORD 4 // X Y X Y

extern int obstacleMap[NUM_OBST][COORD];
int subscribeArr[TOTAL_BOTS];


typedef struct location_s
{
   uint32_t x;
   uint32_t y;

}location_t;

typedef struct trasmitData
{
   location_t location;
   uint32_t obstacle[5];
   uint32_t speed;
   char direction[3];
}transmitData_t;

typedef struct botData_s
{
   char botName[4];
   transmitData_t botData;
}botData_t;


//extern botData_t * botData;

// send data to the interested listeners, position, speed, obstables, etc.
void* sendData(void* ptr);

// receive data from liek  position, speed, obstables, etc from members I have subscribed
void* receiveData(void* ptr);

// makes the subscriptions
void* mcastSubscribe(void* ptr);

// makes the unsubscriptions
void* mcastUnSubscribe(void* ptr);
void* dataSelection(void* ptr);

// process the data from selected bots
void* dataProcessing(void* ptr);

// makes decision based on processed data
void* decisionMaking(void* ptr);

void static changeDirection(void);

#endif // __botFunctions__h__
