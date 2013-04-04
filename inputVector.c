#include "inputVector.h"

int timeInstMatrix[TIME_INSTANTS][TOTAL_BOTS][9]; //=
/* {   {   {R1, 1, 2, 10, N, 1, 0, 1, 0},
         {R2, 4, 6, 10, E, 1, 0, 1, 0},
         {R3, 4, 3, 10, S, 1, 0, 1, 0}
     },
     {
         {R1, 1, 2, 10, N, 1, 0, 1, 0},
         {R2, 4, 6, 10, E, 1, 0, 1, 0},
         {R3, 4, 3, 10, S, 1, 0, 1, 0}
     }
 };*/


void loadVector()
{
  // variables
    botData_t robotData;
    FILE *fr;
    char line[80];
    char buf[6]; // buffer to store integer conversions
    char * ptrChar;
    char * ctrlPtr;
    int i = 0;
    int j = 0;
    int timeInstCtr;

    // init robot data
    memset(&robotData, 0, sizeof(botData_t));

        // Open file ready to append current position and velocity
        fr = fopen("vector.txt", "r");
        if (fr == NULL)
        {
                 printf("Couldn't open file!!\n");
                 exit(0);
        }

    // read subscribed bots for time instant
    while(fgets(line, 80, fr) != NULL)
    {
        if(0 < strncmp(line," ", 3)) //if line at least bigger than empty space, then read
        {
            // split string into tokens
            ptrChar = strtok_r(line, " ", &ctrlPtr);
            strcpy(robotData.botName, ptrChar);
            if(!strncmp(robotData.botName, "R1", 3))
            {
                timeInstMatrix[i][j][0] = R1; 
            }
            else if(!strncmp(robotData.botName, "R2", 3))
            {
                timeInstMatrix[i][j][0] = R2;
            } 
            else if(!strncmp(robotData.botName, "R3", 3))
            {
                timeInstMatrix[i][j][0] = R3;
            }
         //   printf("RName %d=%s ", timeInstMatrix[i][j][0], robotData.botName);
            
            ptrChar = strtok_r(NULL, " ",&ctrlPtr);
            robotData.botData.location.x = atoi(ptrChar);
            timeInstMatrix[i][j][1] = robotData.botData.location.x; 
        //    printf("RX: %d=%dS ", timeInstMatrix[i][j][1], robotData.botData.location.x);

            ptrChar = strtok_r(NULL, " ",&ctrlPtr);
            robotData.botData.location.y = atoi(ptrChar);
            timeInstMatrix[i][j][2] = robotData.botData.location.y; 
      //      printf("RY: %d=%dS ", timeInstMatrix[i][j][2], robotData.botData.location.y);

            ptrChar = strtok_r(NULL, " ",&ctrlPtr);
            robotData.botData.speed = atoi(ptrChar);
            timeInstMatrix[i][j][3] = robotData.botData.speed; 
    //        printf("RVel: %d=%dS ", timeInstMatrix[i][j][3], robotData.botData.speed);
            
            ptrChar = strtok_r(NULL, " ",&ctrlPtr);
            strcpy(robotData.botData.direction, ptrChar);
            if(!strncmp(robotData.botData.direction, "N", 3))
            {
                timeInstMatrix[i][j][4] = N;
            } 
            else if(!strncmp(robotData.botData.direction, "W", 3))
            {
                timeInstMatrix[i][j][4] = W;
            } 
            else if(!strncmp(robotData.botData.direction, "E", 3))
            {
                timeInstMatrix[i][j][4] = E;
            } 
            else if(!strncmp(robotData.botData.direction, "S", 3))
            {
                timeInstMatrix[i][j][4] = S;
            } 
  //          printf("RDir: %d=%sS ",timeInstMatrix[i][j][4], robotData.botData.direction);

            // Tokenize obstacle 0
            ptrChar = strtok_r(NULL, " ",&ctrlPtr);
            robotData.botData.obstacle[0] = atoi(ptrChar);
            timeInstMatrix[i][j][5] = robotData.botData.obstacle[0]; 
//            printf("RObst0: %d=%dS ", timeInstMatrix[i][j][5], robotData.botData.obstacle[0]);

            // Tokenize obstacle 1
            ptrChar = strtok_r(NULL, " ",&ctrlPtr);
            robotData.botData.obstacle[1] = atoi(ptrChar);
            timeInstMatrix[i][j][6] = robotData.botData.obstacle[1]; 
//            printf("RObst1: %d=%dS ", timeInstMatrix[i][j][6], robotData.botData.obstacle[1]);

            // Tokenize obstacle 2
            ptrChar = strtok_r(NULL, " ",&ctrlPtr);
            robotData.botData.obstacle[2] = atoi(ptrChar);
            timeInstMatrix[i][j][7] = robotData.botData.obstacle[2]; 
  //          printf("RObst2: %d ", robotData.botData.obstacle[2]);

            // Tokenize obstacle 3
            ptrChar = strtok_r(NULL, " ",&ctrlPtr);
            robotData.botData.obstacle[3] = atoi(ptrChar);
            timeInstMatrix[i][j][8] = robotData.botData.obstacle[3]; 
    //        printf("RObst3: %d\n", robotData.botData.obstacle[3]);
        
            timeInstCtr++;

        } //end if
        else 
        { // reached another time instant
            i++;
        }
        // after looping once, read next robot
        if(j == TOTAL_BOTS)
        {
            j = 0;

        } else {  j++; }

        if(i==TIME_INSTANTS) { break ; }


    } // end Reading while

fclose(fr);
     

//    printf("------TI = %d-------- \n",timeInstCtr);
    printf("--Data read into timeInstMatrix vector--\n");
};


