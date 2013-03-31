#include "inputVector.h"

int inputVector(void){

   FILE *fr;
   char line[80];
   int linea;

   fr = fopen("ram.txt", "r");

   if (fr == NULL) {
        printf("Couldn't open file!!\n");
        exit(0);
   }

   while(fgets(line, 80, fr) != NULL)
   {
         /* get a line, up to 80 chars from fr.  done if NULL */
        printf("%s",line);

   }
   fclose(fr);  /* close the file */

};
