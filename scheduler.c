#include "scheduler.h"

//variables
unsigned timeInst; // global to synchronize time accross tasks

volatile pth_t pt[MAX_THREADS]; // this is volatile to not let the compiler assume anything about the value

/************************************************** 
 *
 * Scheduler
 *
 ***************************************************/
int scheduler(void)
{
   long numthreads;
   int pth_ret;
   int i;

   timeInst = 0; // beggining at time 0
   pth_ret = pth_init();
   if (pth_ret != TRUE) 
   {
      fprintf(stderr, "Could not initialize GNU Pth, exiting.\n");
      return(EXIT_FAILURE);
   } 
   pt[0] = pth_self();


   while (1) 
   {
      printf("yielding\n");

      pt[1] = pth_spawn(PTH_ATTR_DEFAULT, mcastSubscribe, NULL);
      pt[2] = pth_spawn(PTH_ATTR_DEFAULT, mcastUnSubscribe, NULL);
      pt[3] = pth_spawn(PTH_ATTR_DEFAULT, receiveData, NULL);
      pt[4] = pth_spawn(PTH_ATTR_DEFAULT, dataSelection, NULL);
      pt[5] = pth_spawn(PTH_ATTR_DEFAULT, dataProcessing, NULL);

      pt[6] = pth_spawn(PTH_ATTR_DEFAULT, decisionMaking, NULL);
      pt[7] = pth_spawn(PTH_ATTR_DEFAULT, sendData, NULL);

      for(i =1; i< MAX_THREADS; i++)
      {
         pth_yield(pt[i]);
      }
      if(timeInst >=41) {return;}
      timeInst++;// inc time to proceed to next batch of data
   }

   return(EXIT_SUCCESS);
 }
// thread examples
// threads always yield to pt[0] as it is our scheduler

void *thread_1(void *ptr)
{
   int i;
   for (i = 0; i < 10; i++) {
      printf("thread1\n  ");
      pth_yield(pt[0]);
   }

   pth_exit(NULL);
   return(NULL);
}
void *thread_2(void *ptr)
{
   int i;

   for (i = 0; i < 10; i++) {
      printf("thread2\n  ");
      pth_yield(pt[0]);
   }

   pth_exit(NULL);
   return(NULL);
}

