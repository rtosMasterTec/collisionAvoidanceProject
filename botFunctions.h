#ifndef __botFunctions__h__
#define __botFunctions__h__

// Includes
#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

// Data structures

// assumed the bot size is 1 unit in length and width
// these are the limits of the simulation space
#define MAX_X 1200
#define MAX_Y 800
#define TOTAL_BOTS 3   
#define TIME_INSTANTS 41

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

// send data to the interested listeners, position, speed, obstables, etc.
int sendData(botData_t * botData);


// receive data from liek  position, speed, obstables, etc from members I have subscribed
int receiveData(botData_t * botData);

// makes the subscriptions
int mcastSubscribe();

// makes the unsubscriptions
int mcastUnSubscribe();

// selects the near neighbors to subscribe to their transmitted data
int dataSelection();

// process the data from selected bots
int dataProcessing();

// makes decision based on processed data
int decisionMaking();





#endif // __botFunctions__h__
