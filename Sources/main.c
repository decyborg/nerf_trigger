#include "main.h"
#include "sysinit.h"

int read = 0;
int cm= 0;
int mm=0;
int test = 260;
#define THRESHOLD	30
#define OPEN 260
#define CLOSED 440
#define TPM_MODULE_PWM  3750

int main(void)
{
	char average_count = 0;
	unsigned int average = 0;
	int cm_average = 0;
	unsigned int count;
	
	sysinit();
	
	put("\r\nHello World! TPM Lab - Input Capture\r\n");

	hc_sr04_init();
	
	PORTB_PCR0 = PORT_PCR_MUX(3);
	TPM_init_PWM(TPM1_BASE_PTR, TPM_PLLFLL, TPM_MODULE_PWM, TPM_CLK, PS_128, EDGE_PWM);
	TPM_CH_init(TPM1_BASE_PTR, 0, TPM_PWM_H);
	set_TPM_CnV(TPM1_BASE_PTR, 0, OPEN);
	
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
		time_delay_ms(50);
		if(cm < (cm_average - THRESHOLD))
		{
			DisableInterrupts;
			put("\r\nFIRE!\r\n");
			set_TPM_CnV(TPM1_BASE_PTR, 0, CLOSED);
			time_delay_ms(500);
			EnableInterrupts;
		}
		
		set_TPM_CnV(TPM1_BASE_PTR, 0, OPEN);
	}
	return 0;
}


