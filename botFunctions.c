#include "botFunctions.h"

// Static Variables
int filePos = 0;  // used to seek back to position

/* Send data to interested listeners, position, speed, obstacles */
int sendData(botData_t * botData)
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
int receiveData(botData_t * botData)
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
        }   
  */ 

}


