#include<reg52.h> 
#include "I2C.h"
#include "delay.h"
#include "LCD8bit.h"


unsigned int  i;


void EepromWriteByte( unsigned char Data,unsigned char Address, unsigned char Page)
{

    I2CStart(); 
   	I2CSend(0xA0|(Page<<1));	
   	I2CSend(Address); 
   	I2CSend(Data);    
    I2CStop();           	 
	  Delay_ms(5);        
}



unsigned char EepromReadByte(unsigned char Address,unsigned char Page)
{
  unsigned char Data;

    I2CStart();            
   	I2CSend(0xA0|(Page<<1));	  
   	I2CSend(Address); 
    I2CStart();		   
    I2CSend(0xA1|(Page<<1));           
	  Data = I2CRead(); 
	  I2CNak();
    I2CStop();		        
	  Delay_us(10);
    return Data;          
}


	void EepromWriteNBytes(unsigned char Location, unsigned char *Pointer, char N, unsigned char Page)
	 {
		while(N !=  0)
		 {
		EepromWriteByte(Location,*Pointer,Page);
		Location++;Pointer++;N--;		
		 }
	 }



	void EepromReadNBytes(unsigned char Location, unsigned char *Pointer, char N,unsigned char Page)
	 {
		 while(N !=  0)
		{
		 *Pointer = EepromReadByte(Location,Page);
			Location++;Pointer++;N--;
		 }
	 }

   void EepromErasePage(unsigned char Page)
   {
		unsigned char i;
		for(i=0;i<255;i++)
		EepromWriteByte(0x00,i,Page);	
   }



  void EepromEraseAll()
   {
		unsigned char i;
		for(i=0;i<255;i++){
		EepromWriteByte(0x00,i,0);
		EepromWriteByte(0x00,i,1);}	
   }




void main()
{
	char Name[]=" Akif Fazal   ";
	
	initializeLCD();
	setCursor(0,0);
	
	Disp("EEPROM 24C04");
	
	for(i =0; i<14; i++)
	EepromWriteByte(Name[i],i,0);
	
  setCursor(0,1);	
	for(i =0; i<14; i++)
	{				             	
	Data(EepromReadByte(i,0));
	Delay_ms(500);
	}
	while(1);
}

