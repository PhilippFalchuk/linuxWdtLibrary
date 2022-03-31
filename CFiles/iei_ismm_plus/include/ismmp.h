#include <stdint.h>

/*==ERROR CODE==*/
#define EALMEM	1
#define EACPIOPT  2
#define ENOMOD  3
#define EOPEN	4
#define EFLOPT	5
#define ENULLP	6

typedef uint8_t uchar;
typedef uint16_t uint16;
typedef uint32_t uint32;

/*==WDT STRUCTURE==*/
typedef struct WDTO{
	uchar support;
	uchar timeout;
	uchar timeunit;
	uchar act;
}WDTO_t;

/*==DIO STRUCTURE==*/
//Used for model of 4-IN/4-OUT 
typedef struct DIOF{
	uchar dInBits;
	uchar dOutBits;
}DIOF_t;
//Used for model of 8-IN/8-OUT
typedef struct DIOE{
	uchar dInBits;
	uchar dOutBis;
}DIOE_t;
//Used for model of 12-IN/12-OUT
typedef struct DIOT{
	uint16 dInBits;
	uint16 dOutBits;
}DIOT_t;

/*==ACPI CALL STRUCTURE==*/
typedef struct ACPICMD{
	uchar command;
	uint32 arg0;
	uint32 arg1;
	uint32 arg2;
	uchar callback[12];
}ACPICMD_t;

/*==DIO ENUM DEFINITION==*/
typedef enum{
	pin0 = 0,
	pin1,
	pin2,
	pin3,
	pin4,
	pin5,
	pin6,
	pin7,
	pin8,
	pin9,
	pin10,
	pin11,
	nosupport
}DIO_PIN;


int ismmp_WDT_support(struct WDTO *wdt);
int ismmp_WDT_set_time(struct WDTO *wdt, uchar time, uchar unit);
int ismmp_WDT_stop(struct WDTO *wdt);
int ismmp_WDT_start(struct WDTO *wdt, uchar time, uchar unit);
int ismmp_DIO_get_4dio_status(struct DIOF *dio);
int ismmp_DIO_set_4dout_data(struct DIOF *dio);
 
