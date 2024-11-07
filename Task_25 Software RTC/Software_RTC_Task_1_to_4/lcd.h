#define port0 P0

// Define LCD commands
#define LCD_CLEAR_DISPLAY 0x01
#define LCD_RETURN_HOME 0x02
#define LCD_ENTRY_MODE_SET 0x03
#define LCD_DISPLAY_ON_OFF_CONTROL 0x0C
#define LCD_CURSOR_DISPLAY_SHIFT 0x10
#define LCD_FUNCTION_SET 0x38
#define LCD_SET_CGRAM_ADDRESS 0x40
#define LCD_SET_DDRAM_ADDRESS 0x80

// Define LCD function set bits
#define LCD_FUNCTION_SET_8BIT 0x10
#define LCD_FUNCTION_SET_2LINE 0x08
#define LCD_FUNCTION_SET_5X8DOTS 0x00

// Define LCD display on/off control bits
#define LCD_DISPLAY_ON 0x04
#define LCD_CURSOR_ON 0x02
#define LCD_CURSOR_ON 0x02
#define LCD_BLINK_ON 0x01

// Define LCD entry mode set bits
#define LCD_ENTRY_MODE_SET_INCREMENT 0x02
#define LCD_ENTRY_MODE_SET_SHIFT_DISPLAY 0x01

// Define LCD cursor/display shift bits
#define LCD_CURSOR_DISPLAY_SHIFT_DISPLAY_MOVE 0x08
#define LCD_CURSOR_DISPLAY_SHIFT_RIGHT_LEFT 0x04


void lcd_write_byte(unsigned char dataa, unsigned char rs);
void lcd_write_command(unsigned char command);
void lcd_write_data(unsigned char daata);
void lcd_clear(void);
void lcd_init(void);
void lcd_set_cursor(unsigned char row, unsigned char col);
void lcd_write_string( char *str);
void delay_ms(unsigned int ms);
void lcd_write_symbol(unsigned char location, const unsigned char* scharacter);
void lcd_disp_numb(unsigned int num, unsigned int width); 
void lcd_Custom_Char(unsigned char loc , unsigned char *symb);  


