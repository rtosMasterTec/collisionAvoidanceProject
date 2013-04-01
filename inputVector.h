#ifndef __inputVector__h__
#define __inputVector__h__


#include <stdio.h>   /* required for file operations */
#include <stdlib.h>
#include <stdbool.h>

#define TIME_INSTANTS 2
#define NUM_ROBOTS 4
#define N 1
#define W 2
#define E 3
#define S 4
#define R1 1
#define R2 2
#define R3 3
#define R4 4

int instMatrix[TIME_INSTANTS][NUM_ROBOTS][9] =   //[timeInstant][]
{
{
{R1, 1, 2, 10, N, 1, 0, 1, 0},
{R2, 4, 6, 10, E, 1, 0, 1, 0},
{R3, 4, 3, 10, S, 1, 0, 1, 0},
{R4, 3, 7, 10, W, 1, 0, 1, 0},
},
{
{R1, 1, 2, 10, N, 1, 0, 1, 0},
{R2, 4, 6, 10, E, 1, 0, 1, 0},
{R3, 4, 3, 10, S, 1, 0, 1, 0},
{R4, 3, 7, 10, W, 1, 0, 1, 0},
}

};


int loadVector(void);

 #endif // __inputVector__h__

