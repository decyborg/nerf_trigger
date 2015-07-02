#include "main.h"
#include "sysinit.h"

int read = 0;
int cm= 0;
int mm=0;

int main(void)
{
	int counter = 0;
	
	sysinit();
	
	put("\r\nHello World! TPM Lab - Input Capture\r\n");

	hc_sr04_init();
	
	while(TRUE)
	{
		counter++;
		read = hc_sr04_read();
		cm=read/RSLTN;
		mm=read-cm*RSLTN;
		put(int_to_ascii(counter));
		put(" - ");
		put(int_to_ascii(cm));
		put(".");
		put(int_to_ascii(mm));
		put(" cm\r\n");
		time_delay_ms(500);
	}
	return 0;
}


