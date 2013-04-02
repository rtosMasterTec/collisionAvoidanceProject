#ifndef __inputVector__h__
#define __inputVector__h__


#include <stdio.h>   /* required for file operations */
#include <stdlib.h>
#include <stdbool.h>
#include <strings.h>
#include "botFunctions.h"

#define N 1
#define W 2
#define E 3
#define S 4
#define R1 1
#define R2 2
#define R3 3
#define R4 4

extern int timeInstMatrix[TIME_INSTANTS][TOTAL_BOTS][9];  

void loadVector();

#endif // __inputVector__h__

