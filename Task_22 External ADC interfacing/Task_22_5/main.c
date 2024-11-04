#include <reg51.h>
#include "LCD.h"
#include "ADC.h"

void main()
{
	lcd_init();
	while(1)
	{
		 AC_Controller();
	}
}