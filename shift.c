#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<time.h>
#include "functions.h"

int SRNshift(char *ptr)
{
	int srn=0;
	for(int i=3;i<=5;i++)
		srn=(srn*10)+(ptr[i]-'0');
	int shiftamt=specialfunct(srn);
	return shiftamt;
}

int Adminshift()
{
	int i=2*3*5+1;
	return i;
}

int specialfunct(int srn)
{
	int val=(srn+100-srn*2-4+(232+srn))%256;
	return val;
}