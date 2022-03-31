#include <stdio.h>
#include <stdlib.h>
#include "ismmp.h"

int main()
{
   int ret=0;
   uchar ch=0, outbit=0;
   struct DIOF *dio;
   char *stat;
   DIO_PIN pin;

   dio = malloc(sizeof(struct DIOF));
   if(!dio)
   {
	printf("Allocate Memory Fail\n");
	return 0;
   }

   while(ch != '3')
   {
	if (ch == '1')
	{
	   ret = ismmp_DIO_get_4dio_status(dio);
	   if(!ret)
	   {
		printf("***** 4 DIN Status:\n");
		for(pin=pin0; pin<pin4; pin++)
		{
		   stat = dio->dInBits & (1<<pin) ? "High":"Low";
		   printf("PIN%d is %s\n",pin,stat);
		}
		printf("***** 4 DOUT Status:\n");
		for(pin=pin0; pin<pin4; pin++)
		{
		   stat = dio->dOutBits & (1<<pin) ? "High":"Low";
		   printf("PIN%d is %s\n",pin,stat);
		}
	   }
	   else
		printf("ISMM+ DIO API return Error %d\n",-ret);
	}
	if (ch == '2')
	{
	   printf("***** Enter data for each pin(High=1,Low=0)\n");
	   for(pin=pin0; pin<pin4; pin++)
	   {
		printf("PIN%d set:",pin);
		scanf(" %1c",&outbit);
		fflush(stdin);
		if (outbit == '0')
		   dio->dOutBits &= ~(1<<pin);
		else
		   dio->dOutBits |= 1<<pin;
	   }
	   printf("\n");
	   ret = ismmp_DIO_set_4dout_data(dio);
	   if(!ret)
		printf("Setup Successfully\n");
	   else
		printf("ISMM+ DIO API return Error %d\n",-ret);
	}

	printf("========DIO ISMM+ Test========\n");
	printf("1:Read Input and Output pin Status\n");
	printf("2:Write Output pin Data\n");
	printf("3:Close Test\n");
	printf("SELECT:");

	scanf(" %1c",&ch);
	printf("\n");
	fflush(stdin);
   }
   
   free(dio);
   printf("Close Test\n");

   return 0;
}
