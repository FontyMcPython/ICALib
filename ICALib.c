/*-----------------------------------------¬
 *ICALib: Libreria para el PIC32           |
 *15/3/2018         3ºGITT                 |
 *Jose Antonio Font                        |
 *Emplea:                                  |
 *  Pic32Ini.c                             |
 *  UART1.c                                |
 *-----------------------------------------+
 */
// INCLUDES
#include <xc.h>
#include <stdint.h>
#include "Pic32Ini.h"
#include "UART1.h"
/*  METODOS IMPORTADOS:
 *    UART1:
 *      void InterrupcionUART1(void)
 *      void putsUART(char *ps)
 *      char getcUART(void)
 *      void inicializar(int baudios)
 *     Pic32Ini:
 *      void InicializarReloj(void)
 */

void configurarPinIn(int address, int port){
    if(port == 1){
       //Configurar Pin en puerto A 
        ANSELA &= ~(1<<address);
        TRISA |= (1<<address);
    }
    if(port==2){
        //Configurar Pin en puerto B 
        ANSELB &= ~(1<<address);
        TRISB |= (1<<address);
    }
    if(port==3){
        //Configurar Pin en puerto C 
        ANSELC &= ~(1<<address);
        TRISC |= (1<<address);
    }
}

void configurarPinOut(int address, int port){
    if(port == 1){
       //Configurar Pin en puerto A 
        ANSELA &= ~(1<<address);
        TRISA &= ~(1<<address);
    }
    if(port==2){
        //Configurar Pin en puerto B 
        ANSELB &= ~(1<<address);
        TRISB &= ~(1<<address);
    }
    if(port==3){
        //Configurar Pin en puerto C 
        ANSELC &= ~(1<<address);
        TRISC &= ~(1<<address);
    }
}

int configurarTMR2(uint16_t esperams) {
    T2CON = 0;
    TMR2 = 0;
    IFS0bits.T2IF = 0;
    int valido = 0;
    if(esperams > 3335) {
        valido = 1;
    }
    else if(esperams > 0){
        int divisor = 1;
        int TCKPS = 0;
        uint32_t periodo = (esperams*5000)/divisor;
        while((periodo > 65535) && (divisor < 256)){
            divisor *= 2;
            TCKPS++;
            if(divisor==128){
                divisor *= 2;
            }
            periodo = (esperams*5000)/divisor;
        }
        PR2 = periodo;
        T2CON |= TCKPS<<4;
        T2CON |= 1<<15;
        
    }
   return valido; 
   /*
    * while(IFS0bits.T2IF == 0)
    * ;
    * T2CON &= ~(1<<15);
    */
}

int configurarTMR1(uint16_t esperams){
    T1CON = 0;
    TMR1 = 0;
    IFS0bits.T1IF = 0;
    int valido = 0;
    if(esperams > 3335) {
        valido = 1;
    }
    else if(esperams > 0){
        int divisor = 1;
        int TCKPS = 0;
        uint32_t periodo = (esperams*5000)/divisor;
        while((periodo > 65535) && (divisor < 256)){
            divisor *= 8;
            TCKPS++;
            periodo = (esperams*5000)/divisor;
        }
        PR1 = periodo;
        T1CON |= TCKPS<<4;
        T2CON |= 0x8000;
        
    }
   return valido; 
   /*
    * while(IFS0bits.T1IF == 0)
    * ;
    * T1CON &= ~(1<<15);
    */
}