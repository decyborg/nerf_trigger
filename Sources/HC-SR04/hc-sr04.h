#ifndef HC_SR04_H_
#define HC_SR04_H_

#define TPM_MODULE    0xFFFF
#define SNSR_1CM_hz	18518
#define RSLTN	1000

extern void hc_sr04_init (void);
extern int hc_sr04_read (void);
extern void hc_sr04_trigger(void);

#endif /* HC_SR04_H_ */
