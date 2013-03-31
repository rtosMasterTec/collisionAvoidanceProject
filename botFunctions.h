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
#define SIMULATION_TIME 100
#define TOTAL_BOTS 100

typedef struct location_s
{
   uint32_t x;
   uint32_t y;

}location_t;

typedef struct trasmitData
{
   location_t location;
   location_t obstacle[10];
   uint32_t speed;
}transmitData_t;

typedef struct botData_s
{
   transmitData_t botData;
}botData_t;


uint32_t matrixData[TOTAL_BOTS][SIMULATION_TIME];

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
