#include "platform_RTC_config_.h" 

#include "spi_drivers.h"
#include "spi_rtcc_drivers.h"

static void init_RTC(void);

unsigned char platform_RTC_read(enum RTC_CMD cmd)
{   
#if MCP7951X
    return spi_rtcc_rd(cmd);
#elif
    // Reserved for other RTC modules
#endif
}

void platform_RTC_write(enum RTC_CMD cmd, unsigned char time_var)
{   
#if MCP7951X
    spi_rtcc_wr(cmd,time_var);
#elif
    // Reserved for other RTC modules
#endif
}

void platform_RTC_init(void)
{
#if MCP7951X
    init_RTC(); // GPIO init
    ini_spi_rtcc();
    ini_spi_time();
#endif
}


void main()
{
    ini_spi_rtcc();
    ini_spi_time();

    // Read Time
    yr  = spi_rtcc_rd(RTCYEAR); // read YEAR        
    mon = spi_rtcc_rd(RTCMTH); // read MONTH
    //mon = mon & (~LPYR); // mask the leap year bit  
    dat = spi_rtcc_rd(RTCDATE); // read DATE 
    hr  = spi_rtcc_rd(RTCHOUR); // read HOUR
    min = spi_rtcc_rd(RTCMIN); // read MIN
    sec = spi_rtcc_rd(RTCSEC);



    // Write time
    spi_rtcc_wr(RTCYEAR,yr); // update YEAR    value in RTCC
    spi_rtcc_wr(RTCMTH,mon)                       ; // update MONTH   value in RTCC
                                                     // LPYR bit is read only; you may clear it. 
    spi_rtcc_wr(RTCDATE,dat)                      ; // update DATE    value in RTCC
    spi_rtcc_wr(RTCHOUR,hr)                       ; // update HOUR    value in RTCC                
    spi_rtcc_wr(RTCMIN,min)                       ; // update MINUTES value in RTCC
    //sec = sec | ST                                ; // restore oscillator START bit
    spi_rtcc_wr(RTCSEC,sec)                       ; // update SECONDS value in RTCC   

}


static void init_RTC(void)
{
    TRISA=0xfb           		 ; // RA2 = OUT (for SPI); all other pins = IN
    NCS_SPI = 1          	     ; // rise-up the chip_select signal(SPI DEMUX chip)
    NCS_SPI_RTCC =1              ; // rise-up the chip_select signal(SPI RTCC)
}