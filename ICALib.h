/* 
 * File:   ICALib.h
 * Author: Jose Font
 *
 * Created on 21 de marzo de 2018, 18:59
 */

#ifndef ICALib_H
#define	ICALib_H

#ifdef	__cplusplus
extern "C" {
#endif

void configurarPinIn(int address, int port);
void configurarPinOut(int address, int port);
int configurarTMR2(uint16_t esperams);
int configurarTMR1(uint16_t esperams);

#ifdef	__cplusplus
}
#endif

#endif	/* UART1_H */