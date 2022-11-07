// File Name    : spi_drivers.h 
// RTCC = MCP795W20, PIC18 family, C language.
// Dependencies : p18f87j11.h 
// Processor    : PIC18F87J11   
// Hardware     : EVB  =  PIC18 EXPLORER
//                RTCC =  MCP795W20  
// I.D.E.       : MPLABX(V3.55) + XC8 compiler(V1.34)
// Company      : Microchip Technology , Inc. 
// Author       : Alexandru Valeanu 
//.................................................................................
//                   SOFTWARE  LICENSE AGREEMENT    
//.................................................................................
// "Microchip Technology Inc." ("Microchip") licenses this software to you 
// solely for use with Microchip's Serial RTCC products.  
// The software is owned by Microchip and/or its licensors, and is protected 
// under applicable copyright laws.  All rights reserved.
// SOFTWARE IS PROVIDED "AS IS."  MICROCHIP AND ITS LICENSOR EXPRESSLY 
// DISCLAIM ANY WARRANTY OF ANY KIND, WHETHER EXPRESS OR IMPLIED, INCLUDING 
// BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS 
// FOR A PARTICULAR PURPOSE,OR NON-INFRINGEMENT. IN NO EVENT SHALL MICROCHIP 
// AND ITS LICENSORS BE LIABLE FOR ANY INCIDENTAL, SPECIAL, INDIRECT OR 
// CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, HARM TO YOUR EQUIPMENT, 
// COST OF PROCUREMENT OF SUBSTITUTE GOODS, TECHNOLOGY OR SERVICES, ANY 
// CLAIMS BY THIRD PARTIES (INCLUDING BUT NOT LIMITED TO ANY DEFENSE 
// THEREOF), ANY CLAIMS FOR INDEMNITY OR CONTRIBUTION, OR OTHER SIMILAR COSTS."
//*********************************************************************************
//                    GLOBAL CONSTANTS SPI COMMANDS
//.................................................................................
unsigned char rtcc_buf       ;           // global data buffer for the RTCC 
// ................................................................................
//                     BASIC COMMUNICATION FUNCTIONS 
//.................................................................................
void stop_mssp1(void) 
{ SSP1CON1bits.SSPEN = 0 ; }         // disable MSSP1 module

void ini_spi1(void)                  // init the SPI module on MSSP1
   { TRISC = 0xd3    ;               // C4 = SDI1 = SDA1 = in
                                     // C5 = SDO1 = out,   C3 = SCK1 = SCL1 = out
                                     // C2 = NCS_SPI_RTCC
     SSP1STAT = 0x40 ;               // CKE = 1 ; CK=iddle_low, shift on CK+
 //  SSP1CON1 = 0x20 ;               // CKP = 0, FOSC/4  ;
     SSP1CON1 = 0x22 ;               // CKP = 0, FOSC/64 ; see the SPI_expander's datasheet
                            }
void spi_wrbyte(unsigned char spi_data) // writes a byte on the SPI bus (for LCD)
 { SSP1BUF = spi_data;                  // load data buffer 
   while(!PIR1bits.SSP1IF)  ;           // poll the SPI interrupt flag
   PIR1bits.SSP1IF = 0;     }           // clear the flag after end of transmission

unsigned char spi_rdbyte (void)         // reads a byte from the SPI bus
{
unsigned char aux;
SSP1BUF = 0x55               ;          // start ck generator.
while(!PIR1bits.SSP1IF)      ;          // poll the SPI interrupt flag
aux=SSP1BUF;                            // temporary variable to store the received value 
PIR1bits.SSP1IF = 0          ;          // clear the flag after end of receiving
return aux                   ;          // return the SPI received value
}
void spi_rtcc_start(void)               // start of the SPI comm with the RTCC
  { NCS_SPI_RTCC = 1         ;          // deactivate /CS
    NCS_SPI_RTCC = 0         ;   }      // toggle     /CS
//.......................................................................................                        
  void spi_rtcc_stop(void)              // stop  of the SPI comm with the RTCC
  { NCS_SPI_RTCC = 0             ;      // activate /CS
    NCS_SPI_RTCC = 1         ;   }      // toggle   /CS
//.......................................................................................                         
 

