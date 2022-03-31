#include <stdio.h>
#include <stdlib.h>
#include "ismmp.h"

int main()
{
   int ret=0, time=0, unit=0;
   uchar ch=0;
   struct WDTO *wdt;
   char *stat;
   
   wdt = malloc(sizeof(struct WDTO));
   if(!wdt)
   {
	printf("Allocate Memory Fail\n");
	return 0;
   }

   while(ch != '5')
   {
	if (ch == '1')
	{
	   printf("Setup Timeout Value(1-255):");
	   scanf(" %d", &time);
	   fflush(stdin);
	   printf("\n");
	   printf("Setup Time Unit(sec:0,min:1):");
	   scanf(" %d", &unit);
	   fflush(stdin);
	   printf("\n");
	   if(time>255)
		time=255;
	   if(unit>0)
		unit=1;
	   ret = ismmp_WDT_set_time(wdt, (uchar)time, (uchar)unit);
   	   if (!ret)
	   {
		printf("SET Watchdog Time %d\n",wdt->timeout);
		printf("SET Watchdog Time unit %s\n",(wdt->timeunit?"min":"sec"));
		printf("Setup Successfully\n");
	   }
	}
	if (ch == '2')
	{
	   ret = ismmp_WDT_stop(wdt);
	   if (!ret)
		printf("Watchdog STATUS is %s\n",(wdt->act?"Start":"Stop"));
	}
	if (ch == '3')
	{
	   ret = ismmp_WDT_start(wdt, wdt->timeout, wdt->timeunit);
	   if (!ret)
	   {
		stat = (wdt->timeunit ? "min":"sec");
		printf("Countdown %d %s\n",wdt->timeout,stat);
		printf("Watchdog STATUS is %s\n",(wdt->act?"Start":"Stop"));
	   }
	}
	if (ch =='4')
	{
	   ret = ismmp_WDT_support(wdt);
	   if (!ret)
	   {
		if(wdt->support)
		   printf("Watchdog function is support\n");
		else
		   printf("Watchdog function is not support\n");
	   }
	}

	printf("========Watchdog ISMM+ Test========\n");
	printf("1:Setup Timeout value\n");
	printf("2:Stop Watchdog Countdown\n");
	printf("3:Start Watchdog Countdown\n");
	printf("4:Check Watchdog Support\n");
	printf("5:Close Test\n");
	printf("SELECT:");

	scanf(" %1c",&ch);
	printf("\n");
	fflush(stdin);
   }
   
   free(wdt);
   printf("Close Test\n");

   return 0;
}
