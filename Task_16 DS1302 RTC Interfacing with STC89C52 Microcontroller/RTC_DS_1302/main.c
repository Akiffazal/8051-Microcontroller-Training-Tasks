#include <reg52.h>
#include "Ds1302.h"
#include "LCD1602.h"

void main() {
    LCD_Init();
    DS1302_Init();

    // Initialize the LCD with labels and placeholders
    LCD_ShowString(1, 1, "Date: ");
    LCD_ShowString(2, 1, "Time: ");

    DS1302_SetTime();

    while (1) {
        DS1302_ReadTime();

        // Display Date
        LCD_ShowNum(1, 7, DS1302_Time[2], 2);   // Day
        LCD_ShowChar(1, 9, '/');
        LCD_ShowNum(1, 10, DS1302_Time[1], 2);  // Month
        LCD_ShowChar(1, 12, '/');
        LCD_ShowNum(1, 13, DS1302_Time[0], 2);  // Year

        // Display Time
        LCD_ShowNum(2, 7, DS1302_Time[3], 2);   // Hour
        LCD_ShowChar(2, 9, ':');
        LCD_ShowNum(2, 10, DS1302_Time[4], 2);  // Minute
        LCD_ShowChar(2, 12, ':');
        LCD_ShowNum(2, 13, DS1302_Time[5], 2);  // Second
    }
}




















//#include <reg52.H>
//#include "Ds1302.h"
//#include "LCD1602.h"

//void main() {
//  LCD_Init();
//  DS1302_Init();
//	LCD_ShowString(1, 1, "  /  /  ");
//	LCD_ShowString(2, 1, "  :  :  ");
//  DS1302_SetTime();

//  while (1) {
//    DS1302_ReadTime();

//    LCD_ShowNum(1, 1, DS1302_Time[0], 2);
//    LCD_ShowNum(1, 4, DS1302_Time[1], 2);
//    LCD_ShowNum(1, 7, DS1302_Time[2], 2);
//    LCD_ShowNum(2, 1, DS1302_Time[3], 2);
//    LCD_ShowNum(2, 4, DS1302_Time[4], 2);
//    LCD_ShowNum(2, 7, DS1302_Time[5], 2);
//  }
//}






