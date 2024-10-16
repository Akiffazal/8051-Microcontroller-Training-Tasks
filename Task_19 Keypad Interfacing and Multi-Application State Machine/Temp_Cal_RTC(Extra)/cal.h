void lcdcmd(unsigned char);
void lcddata(unsigned char);
void Del(unsigned int);
void disp_num(float num);
int get_num(char ch);
void lcdinit();
char scan_key(void);
void	string (char *str)	;

int calc (void);
sbit rs = P2^6;
sbit rw = P2^5;
sbit en = P2^7;

sbit r0=P1^0;
sbit r1=P1^1;
sbit r2=P1^2;
sbit r3=P1^3;
sbit c0=P1^4;
sbit c1=P1^5;
sbit c2=P1^6;
sbit c3=P1^7;
