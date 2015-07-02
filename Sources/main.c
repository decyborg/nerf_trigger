#include "main.h"
#include "sysinit.h"

int read = 0;
int cm= 0;
int mm=0;
#define THRESHOLD	30

int main(void)
{
	char average_count = 0;
	unsigned int average = 0;
	int cm_average = 0;
	
	sysinit();
	
	put("\r\nHello World! TPM Lab - Input Capture\r\n");

	hc_sr04_init();
	
	for(;average_count < 51;average_count++)
	{
		read = hc_sr04_read();
		average += read;
		time_delay_ms(50);
	}
	
	average /= 50;
	put("\n\r Average: \n\r");
	put(int_to_ascii(average));
	put("\n\r");
	cm_average = average/RSLTN;
	mm=average-cm*RSLTN;
	put(int_to_ascii(cm));
	put(".");
	put(int_to_ascii(mm));
	put(" cm\r\n");
	
	while(TRUE)
	{
		read = hc_sr04_read();
		cm=read/RSLTN;
		mm=read-cm*RSLTN;
		put(int_to_ascii(cm));
		put(".");
		put(int_to_ascii(mm));
		put(" cm\r\n");
		time_delay_ms(500);
		if(cm < (cm_average - THRESHOLD))
			put("\r\nFIRE!\r\n");
	}
	return 0;
}


