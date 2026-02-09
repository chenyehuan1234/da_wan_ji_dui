#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "Motor.h"
#include "Key.h"

uint8_t KeyNum;		//定义用于接收按键键码的变量
int8_t Speed;		//定义速度变量
int8_t ans;
int main(void)
{
	/*模块初始化*/
	OLED_Init();		//OLED初始化
	Motor_Init();		//直流电机初始化
	Key_Init();			//按键初始化
	
	/*显示静态字符串*/
	OLED_ShowString(1, 1, "Speed:");		//1行1列显示字符串Speed:
	ans=1;
	while (1)
	{
		Delay_ms(50);
		if (ans==1){
			Speed += 2;
			if (Speed > 100)				//速度变量超过100后
			{
				ans=0;						//改为减速模式	
			}
		}
		if (ans==0){
			Speed -= 2;
			if (Speed < 0)				//速度变量低于0后
			{
				ans=1;				//改为加速模式			
			}
		}
	
		Motor_SetSpeed(Speed);				//设置直流电机的速度为速度变量
		OLED_ShowSignedNum(1, 7, Speed, 3);	//OLED显示速度变量
	}
}
