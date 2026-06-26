
#include "stm32f10x.h"

/************************LED PA8初始化函数************************/
/*
void LED0_Config(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;
    // 开启GPIOA APB2外设时钟
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
    // PA8推挽输出、速度2MHz
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
    GPIO_Init(GPIOA, &GPIO_InitStructure);
    // 初始默认熄灭（SetBits高电平熄灭，你的电路逻辑）
    GPIO_SetBits(GPIOA, GPIO_Pin_8);
}

/************************点亮PA8 LED（低电平点亮）************************/
void LED0_On(void)
{
    GPIO_ResetBits(GPIOA, GPIO_Pin_8);
}

/************************熄灭PA8 LED（高电平熄灭）************************/
void LED0_Off(void)
{
    GPIO_SetBits(GPIOA, GPIO_Pin_8);
}

/************************简单空循环延时函数************************/
void Delay(unsigned long x)
{
    unsigned long i;
    for(i = 0; i < x; i++);
}

/************************实验一：按键控制LED************************/


int main(void)
{
    LED0_Config();   // 先初始化PA8 LED
    while(1)         // 死循环持续闪烁
    {
        LED0_On();                // 点亮LED
        Delay(0x3FFFFF);          // 延时一段时间
        LED0_Off();               // 熄灭LED
        Delay(0x3FFFFF);          // 再延时，循环形成闪烁
    }
}

