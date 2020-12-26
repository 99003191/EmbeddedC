#include<stdio.h>
#include "Fibonaaci.h"
void fibonaaci(int n)
{
 int i, t1 = 0, t2 = 1, t3;
 for (i = 1; i <= n; ++i) 
	{
        printf("%d, ", t1);
        t3 = t1 + t2;
        t1 = t2;
        t2 = t3;
    }

    //return 0;
}