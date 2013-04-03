#include <stdio.h>
#include <stdint.h>
#include "botFunctions.h"
#include "inputVector.h"

// Local Functions
//static void initRobot();
static void print3dArray();

// Init Variables
//botData_t robotData;

int main(int argc, char **argv)
{
   initRobot();  	
   loadVector();
    //print something from vector to check it was read correctly
                             //[timeInst][RX][Data 0-8: Rx X Y Sp Dir ObstN ObstW ObstE ObstS]
 //   printf("Check timeInst 1, R2 = %d\n", timeInstMatrix[40][1][0]);
   
    return scheduler();
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

