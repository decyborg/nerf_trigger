
#include "main.h"

volatile char ready = 0;
volatile int start = 0;
volatile int end = 0;
volatile int OvF = 0;
int tpm_clk_hz = 0;


void hc_sr04_init (void)
{
	/* Set PTC1 as GPIO output to trigger the sensor*/
	GPIOC_PCOR |= PIN(1);
	PORTC_PCR1 = PORT_PCR_MUX(1) | PORT_PCR_PE_MASK;
	GPIOC_PDDR |= PIN(1);
	/* Set the PTC2 pin multiplexer to TPM0_CH1 mode */
	PORTC_PCR2 = PORT_PCR_MUX(4) | PORT_PCR_PE_MASK;
	/*Enable TPM0 Interrupt*/
	EnableInterrupts;
	enable_irq(INT_TPM0 -16);
	set_irq_priority((INT_TPM0 -16), 1);
	/*Configure TPMO in Interrupt Mode*/
	tpm_clk_hz = TPM_init_IC(TPM0_BASE_PTR, TPM_PLLFLL, TPM_MODULE, TPM_CLK, PS_16);
	/* Configure Channel 1 from TPM0 as Input Capture for Both edges*/
	TPM_CH_init(TPM0_BASE_PTR, 1, TPM_IC_BOTH);
	/* Disable CLK mode to avoid any interrupt trigger*/
	TPM_CLK_MODE(TPM0_BASE_PTR, TPM_CNT_DIS);
}

int hc_sr04_read (void)
{
	float value = 0;
	/*Enable Clock Source to the TPM0 Module*/
	TPM_CLK_MODE(TPM0_BASE_PTR, TPM_CLK);
	/* Send a trigger pulse to the HC-SR04 */
	hc_sr04_trigger();
	ready = 0;
	while(!ready){};
	value = end - start;
	start = 0;
	value = value*(SNSR_1CM_hz/(tpm_clk_hz/RSLTN));
	/* Disable CLK mode to avoid any interrupt trigger*/
	TPM_CLK_MODE(TPM0_BASE_PTR, TPM_CNT_DIS);
	OvF = 0;
	return value;
}

void hc_sr04_trigger(void)
{
	int i;
	GPIOC_PSOR |= PIN(1);
	for (i = 0 ; i < 40 ; i++)
		asm("NOP");
	GPIOC_PCOR |= PIN(1);
}

void TPM0_IRQHandler (void)
{
	if(TPM0_C1SC & TPM_CnSC_CHF_MASK)
	{
		TPM0_C1SC |= TPM_CnSC_CHF_MASK;
		if(!start)
		{
			/*Clear the TPM0 counter register to start with ~0 */
			TPM_clear_counter(TPM0_BASE_PTR);
			start = 1;
		}
		else
		{
			end = TPM0_CNT + OvF*TPM_MODULE;
			ready = 1;
		}
	}
	if(TPM0_SC & TPM_SC_TOF_MASK)
	{
		TPM0_SC   |= TPM_SC_TOF_MASK;
		OvF++;
	}
}

void TPM1_IRQHandler (void)
{
	RED_TOGGLE;
	TPM1_SC |= TPM_SC_TOF_MASK;
}

void TPM2_IRQHandler (void)
{
	GREEN_TOGGLE;
	TPM2_SC |= TPM_SC_TOF_MASK;
}
