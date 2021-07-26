/*
 * File:   INJETORA8.c
 * Author: israel
 *
 * Created on 3 de Maio de 2016, 09:03
 */

/*
 * File:   INJETORA6.c
 * Author: israel
 *
 * Created on 24 de Abril de 2016, 11:33
 */

#include <stdio.h>
#include <stdlib.h>
#include <p18f4550.h>
#include <plib/delays.h>
#include <stdio.h>
#include "C:/h/config_PIC18F4550.h"
#include "C:/h/biblioteca_lcd_2x16.h"

#define Fosc 20 // Define a freqüência do oscilador. Necessário para a bib delays.h
#define motorabre PORTBbits.RB1
#define botao  PORTCbits.RC0
#define motorfecha   PORTBbits.RB4
#define fca   PORTCbits.RC1
#define fdf   PORTCbits.RC2
#define rb7   PORTBbits.RB7
#define b0 PORTBbits.RB0  // interopção






// função de configuração do conversor A/D
void config_AD (void) {
	ADCON0 = 0b00000001;	/* canal AN0 selecionado <5:2> 0000
                                   Flag GO - /DONE desligado <1> 0
				   Módulo conversor ligado <0> 1 */
	ADCON1 = 0b00001110;	/* Vref- = VSS <5> 0
				   Vref+ = VDD <4> 0
				   pino RA0/AN0 analógico e demais digitais <3:0> 1110 */
	ADCON2 = 0b10110010;	/* Resultado justificado a direita <7> 1
				   Tempo de Aquisição de 16 TDA <5:3> 110
				   TDA = 1,6us <2:0> 010 */
	}

// função que efeuta uma conversão A/D e retorna um inteiro com o valor convertido
int conv_AD (void) {
	int result_AD;		// Variável local para armazenar o resultado da conv
	ADCON0bits.GO=1;	// inicia a conversão
	while (ADCON0bits.GO);	// Aguarda a o fim da conversão
	result_AD = (((int)ADRESH)<<8)|(ADRESL);
	return result_AD;
}
// função que gera atraso em segundos
void gera_atraso_segundos (unsigned char tempo){
    int i;
    do{
         for (i=0; i<5; i++){ // Gera um delay de 1s
            Delay10KTCYx (20*Fosc/4); // Gera um delay de 0,2s
        }
         tempo--;
    }while (tempo>0);
}


int main(void) {
    // variáveis locais
    int valor_convertido;
    unsigned char buffer[16];
    float tensao;

    // define os pinos de IO
    TRISA = 0b00000001;
    TRISB = 0b00000001;
    TRISC = 0x11111111;
    TRISD = 0x00;
    TRISE = 0x00;

    config_AD (); // configura e inicializa o conversor AD

    lcd_inicia (0x28, 0x0f, 0x06); // incializa o LCD com 4 linhas
    lcd_LD_cursor (0); // Desliga o cursor
    lcd_posicao (1,3);
    imprime_string_lcd ("INJETORA");
        valor_convertido = conv_AD();
        // mostra no lcd o valor convertido (0-1023)
        //lcd_posicao(1, 1);
        //sprintf(buffer, "Conversao = %04i", valor_convertido);
        //imprime_buffer_lcd(buffer, 16);
        // calcula o valor em tensão e mostra no lcd
        tensao = (float) valor_convertido * 5 / 1024;



  while  (  tensao <= 3.80)


{
      void interrupt ISR_alta_prioridade(void) { // função de interrupção de alta prioridade

        while(b0 == 0);
    }
    INTCONbits.INT0IF = 0; // Limpa o flag de ativação da interrupção
}
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
void config_ISR (void){  // configurações gerais a todas as interrupções
    RCONbits.IPEN = 1;   // Habilita interrupção com nível de prioridade. End 0x08 - alta e 0x18 - baixo
    INTCONbits.GIEH = 1; // Habilita todas as interrupções de alta prioridade
    INTCONbits.GIEL = 0; // Desabilita todas as interrupções de baixa prioridade
}
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
void config_int0 (void){     // configurações específicas a INT0
    INTCONbits.INT0IE = 1;   // Ativa a inerrupção externa INT0 (RB0)
    INTCON2bits.INTEDG0 = 0; // Interrupção externa INT0 na borda de descida
    INTCONbits.INT0IF = 0;   // Limpa o flag bit da interrupção externa INT0





}








        if(motorabre==0)
       {



            lcd_posicao(2, 1);
            imprime_string_lcd("   ABRINDO      ");


 motorabre=1;
 motorfecha=0;
  gera_atraso_segundos(4);

   lcd_posicao(2, 1);
            imprime_string_lcd("   ABERTA        ");



 motorabre=0;
 motorfecha=0;
  gera_atraso_segundos(4);







  motorfecha=1;
  motorabre=0;






}

  while  (  tensao <= 3.80)

{
     lcd_posicao(2, 1);
            imprime_string_lcd(" STOP        ");
            motorabre=0;
            motorfecha=0;
            rb7=1;

   lcd_posicao(2, 1);
            imprime_string_lcd("   PARADA    ");




}



        if (motorfecha==1)
        {






  lcd_posicao(2, 1);
            imprime_string_lcd("      FECHANDO        ");


 motorabre=0;
 motorfecha=1;

     gera_atraso_segundos(4);
   lcd_posicao(2, 1);
            imprime_string_lcd("   FECHADA       ");

 motorabre=0;
 motorfecha=0;

            gera_atraso_segundos(4);


        }








}

