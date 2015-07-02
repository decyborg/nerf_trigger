/*
 * tpm.h
 *
 *  Created on: Jul 16, 2013
 *      Author: B34443
 */

#ifndef TPM_H_
#define TPM_H_

#define TPM_PLLFLL 		1
#define TPM_OSCERCLK 	2
#define TPM_MCGIRCLK	3

#define	TPM_CNT_DIS	0
#define	TPM_CLK		1
#define	TPM_EXT_CLK	2

#define PS_1	0
#define PS_2	1
#define PS_4	2
#define PS_8	3
#define PS_16	4
#define PS_32	5
#define PS_64	6
#define PS_128	7

#define TPM_IC_RISING		TPM_CnSC_ELSA_MASK
#define TPM_IC_FALLING		TPM_CnSC_ELSB_MASK
#define TPM_IC_BOTH			TPM_CnSC_ELSA_MASK|TPM_CnSC_ELSB_MASK


extern int TPM_init_IC(TPM_MemMapPtr TPMx, int  clock_source, int modulo, int clock_mode, int ps);
extern void TPM_CLK_MODE (TPM_MemMapPtr TPMx, int clock_mode);
extern void TPM_clear_counter(TPM_MemMapPtr TPMx);
extern void TPM_CH_init(TPM_MemMapPtr TPMx, int channel, int mode);

#endif /* TPM_H_ */
