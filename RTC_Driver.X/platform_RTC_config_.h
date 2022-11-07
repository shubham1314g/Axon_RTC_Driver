
//------------------------Select the target device--------------------------------//
#define PIC18f87j11 1

// Add New target devices when need in the future
//--------------------------------------------------------------------------------//




//---------------------------select the RTC HW------------------------------------//
#define MCP7951X    1

// Add new macros when new RTC modules are added in the future
//--------------------------------------------------------------------------------//


//---------------------------GPIO configs required by platform--------------------//
#if PIC18f87j11
#define  NCS_SPI_RTCC  PORTCbits.RC2     // /CS for the SPI RTCC
#define  NCS_SPI       PORTAbits.RA2     // /CS for the SPI_DEMUX (MCP23S17)
#endif
//--------------------------------------------------------------------------------//



//------------------------Header files required--------------------------------//
#if  PIC18f87j11
#include "pic18f87j11.h"
#endif
//--------------------------------------------------------------------------------//


//----------------------- Data structure and cmds that application can use--------//
enum RTC_CMD{HSEC ,SEC, MIN, HOUR, WKDAY, DATE, MONTH,YEAR};
unsigned char platform_RTC_read(enum RTC_CMD cmd);
void platform_RTC_write(enum RTC_CMD cmd, unsigned char time_var);
void platform_RTC_init(void);