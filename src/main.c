/**
 * @file main.c
 * @brief STC89C5RC MCU 自制模板,使用VS Code，安装EIDE插件，在左侧EIDE边栏中单击新建项目，选择“本地项目模板”
 *
 * @date 2023-08-30 21:11:41
 * @version 1.0
 *
 */

#include <STC89C5xRC.H>
#include <INTRINS.H>

/***开关定义***/
#define K1 P31
#define K2 P30
#define K3 P32
#define K4 P33

/***LED相关定义***/
#define LED_PIN  P2
#define LED1_PIN P20
#define LED2_PIN P21
#define LED3_PIN P22
#define LED4_PIN P23
#define LED5_PIN P24
#define LED6_PIN P25
#define LED7_PIN P26
#define LED8_PIN P27

/***静态七段数码管组相关定义***/
#define SMG_PIN   P20 // P22-P24是数码管组三八译码器的输入引脚，如果更改为别的引脚需要连同CONTROL_SMG(x)宏一同修改，保证位移正确的位数
#define SMG_STATE P0  // 用来存储数码管亮灭情况的寄存器

/**
 * @brief 用来选择要操作的数码管
 * @param index 操作的数码管编号，从右向左从0递增
 */
#define SELECT_SMG(index) (P2 = ((Index) << 2) % 0xFF) //

/**
 * @brief 更改单个七段数码管的内部LED亮灭情况
 * @param digit 要显示的数字
 */
#define CONTROL_SMG(digit) ((SMG_STATE) = (displayEncoderValue[digit]))
char displayEncoderValue[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x6F}; // 使用七段数码管显示数字时，取得显示索引数字所的对应寄存器代码

void delay(unsigned char xms); //@11.0592MHz
void myMemcpy(unsigned char *dest, unsigned char *src, unsigned int count);
void sevenSegmentDisplay(int index, char digit);

void main()
{

    while (1) {
        /* */
    }
}

/**
 * @brief 延时函数
 * @param xms 挂起时长，单位ms
 */
void delay(unsigned char xms) //@11.0592MHz
{
    unsigned char data i, j;
    while (xms--) {
        _nop_();
        i = 2;
        j = 199;
        do {
            while (--j)
                ;
        } while (--i);
    }
}

/**
 * @brief 控制某个七段数码管的显示
 * @param index 要控制的数码管编号，从右到左分别为0-7
 * @param digit 要显示的数字
 */
void sevenSegmentDisplay(int index, char digit)
{
    SMG_STATE = 0x00; // 消除残影，如果注释掉会更亮，但是有残影
    SELECT_SMG(index);
    CONTROL_SMG(digit);
}

/**
 * @brief ChatGPT写的memcpy
 * @param dest 目标地址
 * @param src 源数据地址
 * @param count 拷贝长度
 */
void myMemcpy(unsigned char *dest, unsigned char *src, unsigned int count)
{
    unsigned int i;
    for (i = 0; i < count; i++) {
        dest[i] = src[i];
    }
}