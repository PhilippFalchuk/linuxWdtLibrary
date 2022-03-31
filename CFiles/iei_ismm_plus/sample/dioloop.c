#include <stdio.h>
#include <stdlib.h>
#include "ismmp.h"

int main()
{
   int ret=0;
   struct DIOF *dio;
   int i,j;

   printf("DIO LOOP TEST\n");
   dio = malloc(sizeof(struct DIOF));
   if(!dio)
   {
	printf("Allocate Memory Fail\n");
	return 0;
   }

   printf("LOOPing...........\n");
   //for (;;)
   for (i=0;i<3000; i++)
   {
	for(j=0;j<3000; j++)
	{
	   //sleep(1);
	   ret = ismmp_DIO_set_4dout_data(dio);
	   if(!ret)
	   {
		//printf("Setup Successfully\n");
	   }
	   else
	   {
		printf("ISMM+ DIO API return Error %d\n",-ret);
	   }
	}
   }
   
   free(dio);
   printf("Close Test\n");

   return 0;
}
