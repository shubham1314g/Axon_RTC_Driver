// File Name    : spi_rtcc_drivers.h 
// RTCC = MCP795W20, PIC18 family, C language.
// Dependencies : p18f87j11.h, lcd_drivers.h 
// Processor    : PIC18F87J11   
// Hardware     : EVB  =  PIC18 EXPLORER
//                RTCC =  MCP795W20  
// I.D.E.       : MPLABX(V3.55) + XC8 compiler(V1.34.)
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
//.......................................................................................
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//                     GLOBAL CONSTANTS SPI COMMANDS
//...................................................................................
    #define  SPI_RTCC_READ      0x13       // SPI READ  RTCC COMMAND  
    #define  SPI_RTCC_WRITE     0x12       // SPI WRITE RTCC COMMAND 
    #define  SPI_RTCC_CLRWDT    0x44       // SPI CLEAR WDT  COMMAND
    #define  SPI_RTCC_CLRRAM    0x54       // SPI CLEAR RAM  COMMAND 
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//                     SPI RTCC REGISTERS ADDRESSES
// ..................................................................................
     #define  RTCHSEC           0x00       //  address of hundredth of  
                                           //             SECONDS      register    
     #define  RTCSEC            0x01       //  address of SECONDS      register     
     #define  RTCMIN            0x02       //  address of MINUTES      register     
     #define  RTCHOUR           0x03       //  address of HOURS        register     
     #define  RTCWKDAY          0x04       //  address of DAY OF WK    register      
     #define  RTCDATE           0x05       //  address of DATE         register      
     #define  RTCMTH            0x06       //  address of MONTH        register    
     #define  RTCYEAR           0x07       //  address of YEAR         register    
     #define  CONTROL           0x08       //  address of CONTROL      register     
     #define  OSCTRIM           0x09       //  address of OSC TRIMMING register            
//...................................................................................
     #define  ALM0SEC           0x0C       //  address of ALARMO SEC   register    
     #define  ALM0MIN           0x0D       //  address of ALARMO MIN   register   
     #define  ALM0HOUR          0x0E       //  address of ALARMO HOUR  register    
     #define  ALM0WKDAY         0x0F       //  address of ALARM0 CONTR register   
     #define  ALM0DATE          0x10       //  address of ALARMO DATE  register   
     #define  ALM0MTH           0x11       //  address of ALARMO MONTH register 
//...................................................................................
     #define  ALM1HSEC          0x12       //  address of hundredth of
                                           //             ALARM1 SEC   register      
     #define  ALM1SEC           0x13       //  address of ALARM1 SEC   register 
     #define  ADDR_ALM1MIN      0x14       //  address of ALARM1 MIN   register    
     #define  ALM1HOUR          0x15       //  address of ALARM1 HOUR  register    
     #define  ALM1WKDAY         0x16       //  address of ALARM1 CONTR register    
     #define  ALM1DATE          0x17       //  address of ALARM1 DATE  register      
//...................................................................................        
     #define  PWRDNMIN          0x18       //  address of T_SAVER MIN(VDD->BAT)    
     #define  PWRDNHOUR         0x19       //  address of T_SAVER HR (VDD->BAT)    
     #define  PWRDNDATE         0x1A       //  address of T_SAVER DAT(VDD->BAT)    
     #define  PWRDNMTH          0x1B       //  address of T_SAVER MTH(VDD->BAT)     
//...................................................................................
     #define  PWRUPMIN          0x1C       //  address of T_SAVER MIN(BAT->VDD)    
     #define  PWRUPHOUR         0x1D       //  address of T_SAVER HR (BAT->VDD)     
     #define  PWRUPDATE         0x1E       //  address of T_SAVER DAT(BAT->VDD)     
     #define  PWRUPMTH          0x1F       //  address of T_SAVER MTH(BAT->VDD)      

//***********************************************************************************
//                     GLOBAL CONSTANTS RTCC : MASKS / BITS
//...................................................................................
     #define  ST           0x80            //  START OSC               (RTCSEC REG)     
     #define  LPYR         0x20            //  MASK FOR LEAP YEAR      (RTCMTH REG)           
     #define  PM           0x20            //  post-meridian bit (RTCHOUR REG)         
     #define  H12          0x40            //  12 HOURS FORMAT   (RTCHOUR REG)                 
     #define  TRIMSIGN     0x80            //  minus sign for the calibration reg       
     //#define  OUT          0x80            //  = SET CLKO PIN          (CONTROL REG)   
     #define  SQWEN        0x40            //  enable SQWAVE ON CLKOUT (CONTROL REG)    
     #define  ALM_NO       0x00            //  no alarm activated      (CONTROL REG)    
     #define  ALM0EN       0x10            //  ALARM0 enabled          (CONTROL REG)   
     #define  ALM1EN       0x20            //  ALARM1 enabled          (CONTROL REG)   
     #define  ALM_01       0x30            //  both alarms are enabled (CONTROL REG)   
     #define  CLKO_01H     0x00            //  CLKO = SQWAV(01 HERTZ)  (CONTROL REG)   
     #define  CLKO_04K     0x01            //  CLKO = SQWAV(04 KHZ)    (CONTROL REG)   
     #define  CLKO_08K     0x02            //  CLKO = SQWAV(08 KHZ)    (CONTROL REG)   
     #define  CLKO_32K     0x03            //  CLKO = SQWAV(32 KHZ)    (CONTROL REG)   
     #define  CLKO_64H     0x04            //  CLKO = SQVAW(64 HERTZ)  (CONTROL REG)   
     #define  ALMxPIN      0x80            //  CLKO polarity on alarm  (ALMxWKDAY)       
     #define  ALMx_SEC     0x00            //  ALARM compare on SEC    (ALMxWKDAY)                  
     #define  ALMx_MIN     0x10            //  ALARM compare on MIN    (ALMxWKDAY)       
     #define  ALMx_HR      0x20            //  ALARM compare on HOUR   (ALMxWKDAY)    
     #define  ALMx_DAY     0x30            //  ALARM compare on DAY    (ALMxWKDAY)     
     #define  ALMx_DAT     0x40            //  ALARM compare on DATE   (ALMxWKDAY)        
     #define  ALMx_ALL     0x70            //  ALARM compare on all    (ALMxWKDAY)         
     #define  ALMx_IF      0x08            //  MASK of the ALARM_IF    (ALMxWKDAY)     
     #define  OSCRUN       0x20            //  state of the oscillator (running/not)  
                                           //                          (RTCWKDAY REG)   
     #define  VBATEN       0x08            //  enable battery BACKUP   (RTCWKDAY REG)     s
//************************************************************************************
//                             SPI RTCC DRIVERS 
//********************************************************************************************

unsigned char sec, min, hr, day, dat, mon, yr ; //  time variables, BCD format
//............................................................................................
void spi_rtcc_wr(unsigned char rtcc_reg, unsigned char time_var) 
                                       // SPI write to the SPI RTCC   
  { spi_rtcc_start()            ;      // start SPI comm with the SPI RTCC
    spi_wrbyte(SPI_RTCC_WRITE)  ;      // send the SPI WRITE command
    spi_wrbyte(rtcc_reg)        ;      // send the register's address
    spi_wrbyte(time_var)        ;      // send SPI data
    spi_rtcc_stop()       ;     }      // stop SPI comm
//...........................................................................................
unsigned char spi_rtcc_rd(unsigned char rtcc_reg) // SPI read from the SPI RTCC
  { spi_rtcc_start()            ;      // start the SPI comm with the SPI RTCC
    spi_wrbyte(SPI_RTCC_READ)   ;      //  send the SPI READ command
    spi_wrbyte(rtcc_reg)        ;      //  send the register's address
    rtcc_buf = spi_rdbyte()     ;      //  read the result and store it
    spi_rtcc_stop()             ;      //  stop the SPI comm with the SPI RTCC
    return rtcc_buf     ;       }      //  return the read result
//...........................................................................................
void ini_spi_rtcc(void){               // initialization of the SPI RTCC
day = spi_rtcc_rd(RTCWKDAY)          ; // read day register 
spi_rtcc_wr(RTCWKDAY,day|VBATEN)     ; // enable the battery back-up  
spi_rtcc_wr(CONTROL,ALM_NO); 
                                       // write in the general control register: 
                                       // no alarms, CLKO = SQWAVE = 1HZ
//spi_rtcc_wr(ADDR_SEC, 0x00)        ; // initialize the �seconds� register
//spi_rtcc_wr(ADDR_MIN, 0x00)        ; // initialize the �minutes� register
//spi_rtcc_wr(ADDR_SEC,START_32KHZ) ;} //  start the oscillator keeping seconds = 00
                                     }
//......................................................................................
void ini_spi_time(void)                // initialization of time/date vars on the SPI RTCC
  {                                    // it initializes also START OSC.
    if((day&OSCRUN)==OSCRUN) {;}       // if oscillator = already running, do nothing.
    else {                             // if oscillator = not running, set time/date(arbitrary)
                                       // and SART oscillator/ crystal
 spi_rtcc_wr(RTCYEAR,0x17)      ;      // initialize YEAR  register
 spi_rtcc_wr(RTCMTH,0x02)       ;      // initialize MONTH register
 spi_rtcc_wr(RTCDATE,0x01)      ;      // initialize DATE  register
 spi_rtcc_wr(RTCHOUR,0x05)      ;      // initialize HOUR  register
 spi_rtcc_wr(RTCMIN,0x00)       ;      // initialize MIN   register
 spi_rtcc_wr(RTCSEC,ST) ; }            // initialize SEC   register, start OSC (if not already)
                                 }                                              


