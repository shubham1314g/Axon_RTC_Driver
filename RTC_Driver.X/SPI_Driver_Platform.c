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

static void init_RTC(void)
{
    TRISA=0xfb           		 ; // RA2 = OUT (for SPI); all other pins = IN
    NCS_SPI = 1          	     ; // rise-up the chip_select signal(SPI DEMUX chip)
    NCS_SPI_RTCC =1              ; // rise-up the chip_select signal(SPI RTCC)
}