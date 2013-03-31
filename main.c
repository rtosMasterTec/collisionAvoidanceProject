
// Includes

#include <stdio.h>
#include <stdint.h>
#include "inputVector.h"
#include "botFunctions.h"

// Local Functions
static void initRobot();


// Init Variables
botData_t robotData;

int main(int argc, char **argv)
{
   inputVector();
   
   initRobot();  	
   return 0;
}

static void initRobot()
{
   // Initialize struct
   memset(&robotData, 0, sizeof(botData_t));

   // Initialize robot
   robotData.botData.location.x = 0;
   robotData.botData.location.y = 0;

   // Test sendData
   sendData(&robotData);
}



