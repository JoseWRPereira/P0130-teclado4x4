/*
 * File:   main.c
 * Author: josewrpereira
 *
 * Created on 15 de Agosto de 2020, 21:18:21
 *
 * -------------------------------------------------
 *          MAPA DE ENTRADAS E SAIDAS
 * -------------------------------------------------
 *  Pinos   |nº     | Conexão
 * ---------|-------|-------------------------------
 *  RD2     |21     | LCD_RS
 *  RD3     |22     | LCD_EN
 *  RD4     |27     | LCD_D4
 *  RD5     |28     | LCD_D5
 *  RD6     |29     | LCD_D6
 *  RD7     |30     | LCD_D7
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
 * -------------------------------------------------
 */

#include <xc.h>
#include "config.h"
#include "delay.h"
#include "dispLCD4vias.h"
#include "teclado.h"

void main(void)
{
    char str[] = "Tecla   ";
    
    dispLCD_init();
    teclado_init();

    while( 1 )
    {
        str[6] = teclado_scan();
        if(str[6]==0)
            str[6] = ' ';
        dispLCD(0,0, str );
    }
    return;
}
