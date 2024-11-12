#ifndef SERVO_H
#define SERVO_H



void timer_init();
void set_duty_cycle (float duty_cycle);
void lcd_disp_num ( unsigned int number, unsigned int width);
void lcd_custom_char(unsigned char loc, unsigned char *msg);
void servo (unsigned int servo_position);

#endif