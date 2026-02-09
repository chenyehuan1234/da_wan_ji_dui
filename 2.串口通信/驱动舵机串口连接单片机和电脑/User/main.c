#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "Servo.h"
#include "Key.h"
#include "Serial.h"
#include "PWM.h"


extern uint8_t Serial_RxData;		//定义串口接收的数据变量
extern uint8_t Serial_RxFlag;		//定义串口接收的标志位变量
int main(void)
{
	Servo_Init();
  Serial_Init();		//串口初始化
	
	GPIO_InitTypeDef GPIO_InitStructure_1;
	GPIO_InitStructure_1.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStructure_1.GPIO_Pin = GPIO_Pin_1;
	GPIO_InitStructure_1.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure_1);

	while (1)
	{
	  
		if(Serial_RxFlag==1)
		{
	  Serial_RxFlag=0;
		uint16_t RxData = Serial_GetRxData();	
		uint16_t angle=RxData;
		uint16_t i=angle*100/9+500;
		PWM_SetCompare2(i);
	  printf("finished");

		}
	}									
	
	
}
