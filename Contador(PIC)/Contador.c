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
 
char contador=0,texto[4], respaldo; 
 
 void main(){ 
	GIE_bit=1;                  //Interrupciones habilitadas. 
	NOT_RBPU_bit=0;             //Pull ups habilitados. 
	INTEDG_bit=0;               //INT por flanco descendente. 
	 
	Lcd_Init();                 //Inicializa el LCD. 
	Lcd_Cmd(_LCD_CLEAR);        //Borra el display. 
	Lcd_Cmd(_LCD_CURSOR_OFF);   //Apaga el cursor. 
	Lcd_Out(1,2,"No. de Pulsos"); 
	ByteToStr(contador,texto); 
	Lcd_Out(2,6,texto); 
	
	 
	respaldo=TRISB;             //Guardar el estado de TRISB. 
	TRISB0_bit=1;               //RB0 como entrada. 
	INTE_bit=1;                 //Interrupción INT habilitada. 
	
	while (1) 
		{ 
		 //asm SLEEP                  //Entra en modo SLEEP. 
		 asm NOP                    //Se despierta por INT, ejecuta NOP y 
		                            //salta a "interrupt". 
		 ByteToStr(contador,texto); //Retorna de "interrupt" y continúa. 
		 TRISB=respaldo;            //Restaurar TRISB. 
		 Lcd_Out(2,6,texto); 
		 respaldo=TRISB;            //Guardar el estado de TRISB. 
		 TRISB0_bit=1;              //RB0 como entrada. 
		} 
 } 
 
 void interrupt(void) 
 { 
	 Delay_ms(20); 
	 if (RB0_bit==0) contador++;  //Pulsador presionado. 
	 while (RB0_bit==0);          //Esperar mientras siga presionado. 
	 if (contador >100) contador=0; 
	 INTF_bit=0; 
 } 
 
 
