#ifndef __SCHEDULING_H__
#define __SCHEDULING_H__

#include <stdio.h>   /* required for file operations */
#include <stdlib.h>
#include <stdbool.h>

typedef struct sch_config_s
{
   unsigned tickets[5];
   unsigned priority[5];
   bool threadbuffer[5];
   unsigned ThreadID;
} sch_config_t;

extern sch_config_t config;

unsigned lottery(void);
unsigned priorityScheduling(void);
#endif //__CONFIGLOAD_H__
