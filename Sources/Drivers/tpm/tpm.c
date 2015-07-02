/*
 * tpm.c
 *
 *  Created on: Jul 16, 2013
 *      Author: B34443
 */

#include "main.h"

extern int mcg_clk_hz;

int TPM_init_IC(TPM_MemMapPtr TPMx, int  clock_source, int modulo, int clock_mode, int ps)
{
	int val = 1;
	int i;
	if(TPMx == TPM0_BASE_PTR)
		SIM_SCGC6	|= SIM_SCGC6_TPM0_MASK;
	else if(TPMx == TPM1_BASE_PTR)
		SIM_SCGC6	|= SIM_SCGC6_TPM1_MASK;
	else
		SIM_SCGC6	|= SIM_SCGC6_TPM2_MASK;
	
	SIM_SOPT2	|= SIM_SOPT2_TPMSRC(clock_source);
	
	TPM_MOD_REG(TPMx)  	=  modulo;
	
	TPM_SC_REG(TPMx)	= TPM_SC_TOIE_MASK | TPM_SC_CMOD(clock_mode) | TPM_SC_PS(ps);
	
	i= ps;
	
	while(i--)
	{
		val += val;
	}
	
	val=(mcg_clk_hz/2)/val;
	
	return val;
}

void TPM_CLK_MODE (TPM_MemMapPtr TPMx, int clock_mode)
{
	int temp;
	temp = TPM_SC_REG(TPMx);
	temp &= ~TPM_SC_CMOD(3);
	temp |= TPM_SC_CMOD(clock_mode);
	TPM_SC_REG(TPMx) =	temp;
}

void TPM_clear_counter(TPM_MemMapPtr TPMx)
{
	TPM_CNT_REG(TPMx) = 0;
}

void TPM_CH_init(TPM_MemMapPtr TPMx, int channel, int mode)
{
	TPM_CnSC_REG(TPMx, channel) = mode | TPM_CnSC_CHIE_MASK;
}

void TPM_init_PWM(TPM_MemMapPtr TPMx, int  clock_source, int module, int clock_mode, int ps, int counting_mode)
{
	if(TPMx == TPM0_BASE_PTR)
		SIM_SCGC6	|= SIM_SCGC6_TPM0_MASK;
	else if(TPMx == TPM1_BASE_PTR)
		SIM_SCGC6	|= SIM_SCGC6_TPM1_MASK;
	else
		SIM_SCGC6	|= SIM_SCGC6_TPM2_MASK;
	
	SIM_SOPT2	|= SIM_SOPT2_TPMSRC(clock_source);
	
	TPM_MOD_REG(TPMx)  	=  module;
	
	TPM_SC_REG(TPMx)	|= TPM_SC_CMOD(clock_mode) | TPM_SC_PS(ps);
	
	if(counting_mode)
		TPM_SC_REG(TPMx) |= TPM_SC_CPWMS_MASK;
}

void TPM_CH_init_PWM(TPM_MemMapPtr TPMx, int channel, int mode)
{
	TPM_CnSC_REG(TPMx, channel) |= mode;
}

void set_TPM_CnV(TPM_MemMapPtr TPMx, int channel, int value)
{
	TPM_CnV_REG(TPMx, channel) = value;
}


