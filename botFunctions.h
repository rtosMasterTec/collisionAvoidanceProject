#ifndef __botFunctions__h__
#define __botFunctions__h__

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
