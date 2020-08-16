/*
 * File:   teclado.c
 * Author: josewrpereira
 *
 * Created on 15 de Agosto de 2020, 21:21
 * 
 * -------------------------------------------------
 *          MAPA DE ENTRADAS E SAIDAS
 * -------------------------------------------------
 *  Pinos   |nº     | Conexão
 * ---------|-------|-------------------------------
 *  RB0     |33     | Teclado Saída   L0
 *  RB1     |34     | Teclado Saída   L1
 *  RB2     |35     | Teclado Saída   L2
 *  RB3     |36     | Teclado Saída   L3
 *  RB4     |37     | Teclado Entrada C0
 *  RB5     |38     | Teclado Entrada C1
 *  RB6     |39     | Teclado Entrada C2
 *  RB7     |40     | Teclado Entrada C3
 * -------------------------------------------------
 */


#include <xc.h>
#include "delay.h"

#define NUM_COL         4
#define NUM_LIN         4

#define L0_MASK         0x01
#define C0_MASK         0x10

void teclado_init( void )
{
    TRISB = 0xF0;
    ANSELH = 0x00;
    OPTION_REGbits.nRBPU = 0;
    WPUB = 0xFF;
    PORTB = 0xFF;
}

const char tecladoMatriz[4][4] = {  {'1','2','3','A'},
                                    {'4','5','6','B'},
                                    {'7','8','9','C'},
                                    {'*','0','#','D'} };

char teclaAtual, teclaAnterior;


unsigned char teclado_scan( void )
{
    unsigned char aux = 0;
    unsigned char l,c;
    
    for( l=0; l<NUM_LIN; l++ )
    {
        PORTB = ~(L0_MASK << l);
        for( c=0; c<NUM_COL; c++ )
        {
            if( ~PORTB & (C0_MASK<<c) )
                aux = tecladoMatriz[l][c];
        }
    }   
    return( aux );
}
