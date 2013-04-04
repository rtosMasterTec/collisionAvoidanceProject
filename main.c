#include <stdio.h>
#include <stdint.h>
#include "botFunctions.h"
#include "inputVector.h"

// Local Functions
static void initRobot();
static void print3dArray();

// Init Variables
botData_t robotData;

int main(int argc, char **argv)
{
   initRobot();  	
   return scheduler();
}

static void initRobot()
{
   // Initialize struct
   memset(&robotData, 0, sizeof(botData_t));

   // Initialize robot
   robotData.botData.location.x = 0;
   robotData.botData.location.y = 0;
   robotData.botData.speed = 0;
   strcpy(robotData.botData.direction,"E");
   robotData.botData.obstacle[0] = 0;
   robotData.botData.obstacle[1] = 0;
   robotData.botData.obstacle[2] = 0;
   robotData.botData.obstacle[3] = 0;
   
   // Test sendData
   sendData(&robotData);
   loadVector();
    
    //print something from vector to check it was read correctly
                             //[timeInst][RX][Data 0-8: Rx X Y Sp Dir ObstN ObstW ObstE ObstS]
    printf("Check timeInst 1, R2 = %d\n", timeInstMatrix[40][1][0]);
    printf("Check timeInst 1, X = %d\n", timeInstMatrix[40][1][1]);
    printf("Check timeInst 1, Y = %d\n", timeInstMatrix[40][1][2]);

  //  printf("Printing read 3d array\n");
   // print3dArray();

}

static void print3dArray()
{
    int i = 0;
    int j = 0;
    int k = 0;

    for(i = 0; i < TIME_INSTANTS+1; i++)
    {
        for(j = 0; j < TOTAL_BOTS; j++)
        {
            for(k = 0; k < 9; k++)
            {
                printf(" %d " , timeInstMatrix[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }

}

