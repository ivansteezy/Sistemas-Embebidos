sbit LCD_RS at RD4_bit;
sbit LCD_EN at RD5_bit;
sbit LCD_D4 at RD0_bit;
sbit LCD_D5 at RD1_bit;
sbit LCD_D6 at RD2_bit;
sbit LCD_D7 at RD3_bit;

sbit LCD_RS_Direction at TRISD4_bit;
sbit LCD_EN_Direction at TRISD5_bit;
sbit LCD_D4_Direction at TRISD0_bit;
sbit LCD_D5_Direction at TRISD1_bit;
sbit LCD_D6_Direction at TRISD2_bit;
sbit LCD_D7_Direction at TRISD3_bit;

unsigned long Valor;              //se almacena el valor del canal0
unsigned char Pos1, Pos2, Pos3, Pos4;   //estas son mis posiciones del decimal mas y menos significativos

void main() {
     ADCON1 = 0b10000010;         // habilito la conversion A/D
     TRISA = 1;
     Lcd_Init();
     Lcd_Cmd(_LCD_CURSOR_OFF);
     Lcd_Cmd(_LCD_CLEAR);
     Lcd_Out(1,2,"Temperatura: ");
     
     while(1){
       Valor = adc_read(0);
       Valor = (Valor * 50000)/1023;
       Pos4 = (Valor / 1000);
       Pos3 = (Valor / 100) % 10;     //Esta es la primera posicion de izquierda a derecha
       Pos2 = (Valor/10) % 10;        //Esta es la segunda posicion
       Pos1 = (Valor % 10);       //Esta es la tercera posicion
       Lcd_chr(2,5,48 + Pos4);         // 48 es el codigo ASCI del numero '0' entonces le sumamos el caracter a mostrar lol
       Lcd_chr_CP(48 + Pos3);
       Lcd_chr_CP('.');
       Lcd_chr_CP(48 + Pos2);         //0 mas el valor de la segunda posicion
       Lcd_chr_CP(48 + Pos1);         //0 mas el valor de la primera posicion
        delay_ms(40);
       }
}

