#include "stm32f10x.h"                  // Device header

void gpioConfig(){

  GPIO_InitTypeDef GPIO_InitStructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;  //pull - push seklinde tanimladik
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_0;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	
	GPIO_Init(GPIOB,&GPIO_InitStructure);

}

void delay(uint32_t time){

  while(time--);
}

int main(){
  gpioConfig();
	
 while(1)
 {
     GPIO_SetBits(GPIOB,GPIO_Pin_0);  //led yakan komut
	   delay(3600000);	    
	   GPIO_ResetBits (GPIOB,GPIO_Pin_0); //LED SOND�REN KOMUT 
     delay(3600000);
	 
	   GPIO_WriteBit(GPIOB,GPIO_Pin_0,Bit_SET);  //bu sekildede led yakilir. 
	   delay(3600000);
	   GPIO_WriteBit(GPIOB,GPIO_Pin_0,Bit_RESET);
	   delay(3600000);
	 
 }

}
