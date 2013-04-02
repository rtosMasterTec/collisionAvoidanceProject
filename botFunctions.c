#include "botFunctions.h"
#include "inputVector.h"

// Static Variables
botData_t * botData;
int move = E;  // move east is defautl behavior
int exitFunc = 0;
int nextMoveX = 0;
int nextMoveY = 0;

int obstacleMap[NUM_OBST][COORD] =
{  // X  Y  X  Y 
    {80, 50, 82, 60}, {87, 45, 88, 46} , {100, 54, 105, 55}, {122, 58, 127, 61} 
};
 
/* Send data to interested listeners, position, speed, obstacles */
void* sendData(void* ptr)
{
   // variables
   botData_t * robotData;
   FILE *fwa;
   char line[80];
   char buf[6]; // buffer to store integer conversions

   memset(&robotData, 0, sizeof(botData_t));
   robotData = botData;

   // Open file ready to append current position and velocity
   fwa = fopen("ourBotData.txt", "a+");
   if (fwa == NULL)
   {
      printf("Couldn't open file!!\n");
      exit(0);
   }

   // preapare string = posx pos y vel obstN obtsW obstE obstS
   strcpy(line,"R0");
   snprintf(buf, sizeof(buf), " %d ", robotData->botData.location.x);
   strcat(line, buf);
   snprintf(buf, sizeof(buf), " %d ", robotData->botData.location.y);
   strcat(line, buf);
   snprintf(buf, sizeof(buf), " %d ", robotData->botData.speed);
   strcat(line, buf);
   snprintf(buf, sizeof(buf), " %d ", robotData->botData.obstacle[0]);
   strcat(line, buf);
   snprintf(buf, sizeof(buf), " %d ", robotData->botData.obstacle[1]);
   strcat(line, buf);
   snprintf(buf, sizeof(buf), " %d ", robotData->botData.obstacle[2]);
   strcat(line, buf);
   snprintf(buf, sizeof(buf), " %d ", robotData->botData.obstacle[3]);
   strcat(line, buf);
   strcat(line, " \n");

   // write current position, vel, nextDir and if obstacles present
   fprintf(fwa, "%s", line);
   fclose(fwa);  /* close the file */

}


/* Receive data from other bots, position, speed, obstacles at a time instant*/
void* receiveData(void *ptr)
{
    // variables
/*    botData_t * robotData;
    FILE *fr;
    char line[80];
    char buf[6]; // buffer to store integer conversions
	char * ptrChar;
	char * ctrlPtr;
	int i = 0;
    
        memset(&robotData, 0, sizeof(botData_t));
        robotData = botData;

        // Open file ready to append current position and velocity
        fr = fopen("vector.txt", "r");
        if (fr == NULL)
        {   
                 printf("Couldn't open file!!\n");
                 exit(0);
        }  */ 
}

void* mcastSubscribe(void* ptr)
{
   int j;
   int my_coord_x;
   int my_coord_y;
   int coord_x;
   int coord_y;

   my_coord_x = botData->botData.location.x;
   my_coord_y = botData->botData.location.y;

   printf("My position R%d = X=%d,Y=%d\n",0 ,my_coord_x,my_coord_y);
   for(j=1; j<= TOTAL_BOTS; j++)
   {
     coord_x = timeInstMatrix[timeInst][j][1];
     coord_y = timeInstMatrix[timeInst][j][2];
     printf("Check position of robot R%d = X=%d,Y=%d\n",j ,coord_x,coord_y);
     if(my_coord_x - coord_x < MAX_RANGE_X)
     {
 	//suscribe
	subscribeArr[j] = 1;
     }
   }
}

void* mcastUnSubscribe(void* ptr)
{
   int j;
   int my_coord_x;
   int my_coord_y;
   int coord_x;
   int coord_y;

   my_coord_x = botData->botData.location.x;
   my_coord_y = botData->botData.location.y;

   printf("My position R%d = X=%d,Y=%d\n",0 ,my_coord_x,my_coord_y);
   for(j=1; j<= TOTAL_BOTS; j++)
   {
     coord_x = timeInstMatrix[timeInst][j][1];
     coord_y = timeInstMatrix[timeInst][j][2];
     printf("Check position of robot R%d = X=%d,Y=%d\n",j ,coord_x,coord_y);
     if(my_coord_x - coord_x >= MAX_RANGE_X)
     {
        //Unsuscribe
        subscribeArr[j] = 0;
     }
   }
}


void* decisionMaking(void* ptr)
{
    int j = 0;
    int currentTimeInst = 4; // This is a global variable, will move later
    bool collision = false;

    nextMoveX = botData->botData.location.x + 1;
    nextMoveY = botData->botData.location.y;

    // Check if obstacles are in my next move

    // Check if other robots are in my way
    for(j = 0; j < TOTAL_BOTS; j++)
    {

        if(subscribeArr[j] == 1)
        {
            // check I can move East
            switch(timeInstMatrix[currentTimeInst][j][4])
            {
               case N:
                {  // North means adding Y+1
                  if((timeInstMatrix[currentTimeInst][j][1] == nextMoveX)
                         && (timeInstMatrix[currentTimeInst][j][2]+1 == nextMoveY))
                  {
                        // If true we are going to collide, change direction, nextMoveX and nextMoveY
                        changeDirection();
                        if(exitFunc == 1) { return 0; } // exiting and not moving
                        break;
                  }
                } 
               case E:
                {  // East means adding X+1
                  if((timeInstMatrix[currentTimeInst][j][1]+1 == nextMoveX)
                         && (timeInstMatrix[currentTimeInst][j][2] == nextMoveY))
                  {
                        // If true we are going to collide, change direction, nextMoveX and nextMoveY
                        changeDirection();
                        if(exitFunc == 1) { return 0; } // exiting and not moving
                        break;
                  }
                } 
               case S:
                {  // South means substracting Y-1
                  if((timeInstMatrix[currentTimeInst][j][1] == nextMoveX)
                         && (timeInstMatrix[currentTimeInst][j][2]-1 == nextMoveY))
                  {
                        // If true we are going to collide, change direction, nextMoveX and nextMoveY
                        changeDirection();
                        if(exitFunc == 1) { return 0; } // exiting and not moving
                        break;
                  }
                } 

            } // end switch

        } // end if

    } // end for

} // end decisionMaking

void static changeDirection()
{
    // Try E --> Try N --> Try W or Wait    

    if(move == E)
    { //try North
       move = N;
       nextMoveX = botData->botData.location.x;
       nextMoveY = botData->botData.location.y + 1; 
    }
    else if (move == N)
    { //try South 
       move = S;
       nextMoveX = botData->botData.location.x;
       nextMoveY = botData->botData.location.y - 1; 
    }
    else
    { // tried E,N, S, not gonna try W (going back) so just wait.
        exitFunc = 1;      
    }

}



void *dataProcessing(void* ptr)
{
}

void* dataSelection(void* ptr)
{
} 

