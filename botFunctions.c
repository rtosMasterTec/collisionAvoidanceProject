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
    botData_t * robotData;
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
   
	// move  file ptr to last read position
//	fseek(fr, filePos, SEEK_SET);
 
	// read subscribed bots for time instant
   	while(fgets(line, 80, fr) != NULL)
	{   
	
		
		if(0 < strncmp(line," ", 3)) //if line at least bigger than empty space, then read
		{	
			// split string into tokens
			ptrChar = strtok_r(line, " ", &ctrlPtr);
 	     	strcpy(robotData->botName,ptrChar);
			printf(" RName: %s\n", robotData->botName);	

			// IF  NOT SUBCRIBED, ABORT READING
			i = 0;
/*			while(strncmp(robotData->botName, subscriberArr[i]) != 0)
			{
				i++;  //increment i until match is found

				if(i == sizeof(subscriberArr/4))
				{
					//subcriber not found
					bool subscribed = false;
					break;
				}
			}
			
			if (subscribed == true) */
			ptrChar = strtok_r(NULL, " ",&ctrlPtr);	
       		robotData->botData.location.x = atoi(ptrChar);
			printf(" RX: %d\n", robotData->botData.location.x);	
	
			ptrChar = strtok_r(NULL, " ",&ctrlPtr);	
       		robotData->botData.location.y = atoi(ptrChar);
			printf(" RY: %d\n", robotData->botData.location.y);	
	
			ptrChar = strtok_r(NULL, " ",&ctrlPtr);	
       		robotData->botData.speed = atoi(ptrChar);
			printf(" RVel: %d\n", robotData->botData.speed);	
	
			// Tokenize obstacle 0
			ptrChar = strtok_r(NULL, " ",&ctrlPtr);	
       		robotData->botData.obstacle[0] = atoi(ptrChar);
			printf(" RObst0: %d\n", robotData->botData.obstacle[0]);

			// Tokenize obstacle 1
			ptrChar = strtok_r(NULL, " ",&ctrlPtr);	
       		robotData->botData.obstacle[1] = atoi(ptrChar);
			printf(" RObst1: %d\n", robotData->botData.obstacle[1]);	

			// Tokenize obstacle 2
			ptrChar = strtok_r(NULL, " ",&ctrlPtr);	
       		robotData->botData.obstacle[2] = atoi(ptrChar);
			printf(" RObst2: %d\n", robotData->botData.obstacle[2]);	

			// Tokenize obstacle 3
			ptrChar = strtok_r(NULL, " ",&ctrlPtr);	
       		robotData->botData.obstacle[3] = atoi(ptrChar);
			printf(" RObst3: %d\n", robotData->botData.obstacle[3]);	

		} //end if
		else 
		{   //will read until empty line
			// now save reading location on file
			filePos = ftell(fr);			
			break; //break off the while loop
		}
	} // end Reading while

}
