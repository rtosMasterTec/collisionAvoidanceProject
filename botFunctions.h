#ifndef __botFunctions__h__
#define __botFunctions__h__

// Data structures

// assumed the bot size is 1 unit in length and width
// these are the limits of the simulation space
#define MAX_X 1200
#define MAX_Y 800
#define SIMULATION_TIME 100
#define TOTAL_BOTS 100

typedef location_s
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


uint32_t matrixData[TOTAL_BOTS][TIME];

// send data to the interested listeners, position, speed, obstables, etc.
int sendData();
// makes the subscriptions
int mcastSubscrition();
// selects the near neighbors to subscribe to their transmitted data
int dataSelection();
// process the data from selected bots
int dataProcessing();
// makes decision based on processed data
int decisionMaking();





#endif // __botFunctions__h__
