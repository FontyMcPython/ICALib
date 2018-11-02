/* 
 * File:   UART1.h
 * Author: 201503470
 *
 * Created on 14 de marzo de 2018, 18:59
 */

#ifndef UART1_H
#define	UART1_H

#ifdef	__cplusplus
extern "C" {
#endif

void inicializar(int baudios);
char getcUART(void);
void putsUART(char *ps);

#ifdef	__cplusplus
}
#endif

#endif	/* UART1_H */

