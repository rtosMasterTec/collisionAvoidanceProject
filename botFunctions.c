#include "botFunctions.h"

obstacle_t obstacle;
// Static Variables
botData_t botData;
int move = E;  // move east is defautl behavior
int exitFunc = 0;
int nextMoveX = 0;
int nextMoveY = 0;

int obstacleMap[NUM_OBST][COORD] =
{  // X  Y  X  Y 
    {80, 50, 82, 60}, {87, 45, 88, 46} , {100, 54, 105, 55}, {122, 58, 127, 61} 
};

/* Initializes R0 starting point in the grid */
int initRobot() 
{

    // Initialize robot
    botData.botData.location.x = 0;
    botData.botData.location.y = 0;
    botData.botData.speed = 0;
    strcpy(botData.botData.direction,"E");
    botData.botData.obstacle[0] = 0;
    botData.botData.obstacle[1] = 0;
    botData.botData.obstacle[2] = 0;
    botData.botData.obstacle[3] = 0; 
}
 
/* Send data to interested listeners, position, speed, obstacles */
void* sendData(void* ptr)
{
 printf("SendingData() started\n");
   // variables
//   botData_t * robotData;
   FILE *fwa;
   char line[80];
   char buf[6]; // buffer to store integer conversions

  // memset(&robotData, 0, sizeof(botData_t));
  // robotData = botData;

   // Open file ready to append current position and velocity
   fwa = fopen("ourBotData.txt", "a+");
   if (fwa == NULL)
   {
      printf("Couldn't open file!!\n");
      exit(0);
   }

   // preapare string = posx pos y vel obstN obtsW obstE obstS
   strcpy(line,"R0");
   snprintf(buf, sizeof(buf), " %d ", botData.botData.location.x);
   strcat(line, buf);
   snprintf(buf, sizeof(buf), " %d ", botData.botData.location.y);
   strcat(line, buf);
   snprintf(buf, sizeof(buf), " %d ", botData.botData.speed);
   strcat(line, buf);
   strcpy(line, botData.botData.direction);
   strcat(line, buf);
   snprintf(buf, sizeof(buf), " %d ", botData.botData.obstacle[0]);
   strcat(line, buf);
   snprintf(buf, sizeof(buf), " %d ", botData.botData.obstacle[1]);
   strcat(line, buf);
   snprintf(buf, sizeof(buf), " %d ", botData.botData.obstacle[2]);
   strcat(line, buf);
   snprintf(buf, sizeof(buf), " %d ", botData.botData.obstacle[3]);
   strcat(line, buf);
   strcat(line, " \n");

   // write current position, vel, nextDir and if obstacles present
   fprintf(fwa, "%s", line);
   fclose(fwa);  /* close the file */
   
 printf("SendingData() correctly run\n");

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
    printf("receivingData() correctly run\n");
}

void* mcastSubscribe(void* ptr)
{
   printf("mcastSubscribe() started\n");
   int j;
   int my_coord_x;
   int my_coord_y;
   int coord_x;
   int coord_y;

   my_coord_x = botData.botData.location.x;
   my_coord_y = botData.botData.location.y;

   printf("My position R%d = X=%d,Y=%d\n",0 ,my_coord_x,my_coord_y);
   for(j=0; j< TOTAL_BOTS; j++)
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
   printf("mcastSubscribe() correctly run\n");
}

void* mcastUnSubscribe(void* ptr)
{
   printf("mcastUnSubscribe() started\n");
   int j;
   int my_coord_x;
   int my_coord_y;
   int coord_x;
   int coord_y;

   my_coord_x = botData.botData.location.x;
   my_coord_y = botData.botData.location.y;

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
   printf("mcastUnSubscribe() correctly run\n");
}


void* decisionMaking(void* ptr)
{
   printf("decisionMaking() started\n");
   if(!obstacle.e)
   {
      move = E;
   }
   else if(!obstacle.n)
   {
      move = N;
   }
   else if(!obstacle.s)
   {
      move = S;
   }
   else
   {
   }

   printf("decisionMaking() correctly run\n");

} // end decisionMaking


void *dataProcessing(void* ptr)
{
   int j = 0;
   int currentTimeInst = 4; // This is a global variable, will move later
   bool collision = false;
   int xi, yi, xf, yf,i;
   int xactual, yactual;
   int dx, dy;
  

   // Check if obstacles are in my next move
   xactual = botData.botData.location.x;
   yactual = botData.botData.location.y;

   obstacle.n = 0;
   obstacle.s = 0;
   obstacle.e = 0;

   // this emulates sensor reads to detect static obstacles
   for( i = 0; i < NUM_OBST ; i++)
   {
      xi = obstacleMap[i][0];
      yi = obstacleMap[i][1];
      xf = obstacleMap[i][2];
      yf = obstacleMap[i][3];
      // check for collision at north
      if( xactual >= xi && xactual <= xf && yactual+1 >= yi && yactual+1 <= yf)
      {
         obstacle.n = true;
      }
      // collision at east
      if( xactual+1 >= xi && xactual+1 <= xf && yactual >= yi && yactual <= yf)
      {
         obstacle.e = true;
      }
      // collision at south
      if( xactual-1 >= xi && xactual-1 <= xf && yactual >= yi && yactual <= yf)
      {
         obstacle.s = true;
      }
   }

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
                  dx = 0;
                  dy = 1;

                  break;
               } 
            case E:
               {  // East means adding X+1
                  dx = 1;
                  dy = 0;
                  break;
               } 
            case S:
               {  // South means substracting Y-1
                  dx = 0;
                  dy = -1;
               } 

         } // end switch

         // if moving east
         if((timeInstMatrix[currentTimeInst][j][1] + dx == xactual+1)
               && (timeInstMatrix[currentTimeInst][j][2]+dy == yactual ))
         {
            // If true we are going to collide invalidate the option
            obstacle.e = true;
         }
         // if moving north
         else if((timeInstMatrix[currentTimeInst][j][1] + dx == xactual)
               && (timeInstMatrix[currentTimeInst][j][2]+dy == yactual+1 ))
         {
            obstacle.n = true;
         }
         // if moving south
         else if((timeInstMatrix[currentTimeInst][j][1] + dx == xactual)
               && (timeInstMatrix[currentTimeInst][j][2]+ dy == yactual-1 ))
         {
            obstacle.s = true;
         }

      } // end if

    // update
    updateRobot();

   } // end for
    printf("dataProcessing() correctly run\n");
}

void* dataSelection(void* ptr)
{
    printf("dataSelection() correctly run\n");
} 

int updateRobot() 
{

    // Initialize robot
    botData.botData.location.x = nextMoveX;
    botData.botData.location.y = nextMoveY;
    botData.botData.speed = 0;
    if(move == N) {  strcpy(botData.botData.direction, "N");};
    if(move == S) {  strcpy(botData.botData.direction, "S");};
    if(move == E) {  strcpy(botData.botData.direction, "E");};
    botData.botData.obstacle[0] = 0;
    botData.botData.obstacle[1] = 0;
    botData.botData.obstacle[2] = 0;
    botData.botData.obstacle[3] = 0;  
}

