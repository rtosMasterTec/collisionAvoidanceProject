#include "botFunctions.h"
#include "inputVector.h"

// Static Variables
int filePos = 0;  // used to seek back to position
botData_t * botData;

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
	suscribeArr[j] = 1;
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
        suscribeArr[j] = 0;
     }
   }
}


void* decisionMaking(void* ptr)
{


//empty for now




}

void *dataProcessing(void* ptr)
{
}
void* dataSelection(void* ptr)
{
}
