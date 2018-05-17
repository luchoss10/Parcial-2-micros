#include <16f887.h>
#device adc=10 //Seleccion de cantidad de bits para el ADC
#use delay (internal=8M)
#fuses xt,nowdt,noput,noprotect,nobrownout,nolvp
#use RS232(BAUD=2400, XMIT=PIN_C6,RCV=PIN_C7, BITS=8, PARITY=N)

#include <lcd.c>
#include <KBD4x4_1.c> 

//declaracion de las varibales  del programa
float Temperatura, Res=0.00488;//Res es el valor de la resolucion con 10 bits
void main(){
   set_tris_d(0);
   
   //Se configura e� reloj del conversor
   
   lcd_init();//Inicializaci�n de la LCD
   
   lcd_gotoxy(1,1);
   printf(lcd_putc,"Temperatura");
   
   while(true){
      //Se realiza la lectura de los canales analogos
      Temperatura = ((read_adc())*(Res)/(0.01));//Formula T=ADC*RES/LM35VP
      delay_us(50);//Delay de lectura
      lcd_gotoxy(2,2);
      printf(lcd_putc,"%f",Temperatura);
      printf("%f \r",Temperatura);
   }
}
