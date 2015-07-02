/*
 * libs.c
 *
 *  Created on: Jul 15, 2013
 *      Author: B34443
 */
#include "main.h"

void put(char *ptr_str)
{
	while(*ptr_str)
		out_char(*ptr_str++);
}

char * int_to_ascii (int num)
{
	static char str[11];
	char *ptr = &str[10];
	if(!num) 
		*--ptr = 0x30;
	else
	{
		for(;num;num/=10) 
		 *--ptr = 0x30 + num%10;
	}
	return ptr;
}
