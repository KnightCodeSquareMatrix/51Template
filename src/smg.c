#include <STC89C5xRC.H>
#include "delay.h"
/***静态七段数码管组相关定义***/
#define SMG_PIN   P20 // P22-P24是数码管组三八译码器的输入引脚，如果更改为别的引脚需要连同CONTROL_SMG(x)宏一同修改，保证位移正确的位数
#define SMG_STATE P0  // 用来存储数码管亮灭情况的寄存器

/**
 * @brief 用来选择要操作的数码管
 * @param index 操作的数码管编号，从右向左从0递增
 */
#define SELECT_SMG(index) (P2 = ((index) << 2) % 0xFF) //

/**
 * @brief 更改单个七段数码管的内部LED亮灭情况
 * @param digit 要显示的数字
 */
#define CONTROL_SMG(digit) ((SMG_STATE) = (displayEncoderValue[digit]))

char displayEncoderValue[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x6F}; // 使用七段数码管显示数字时，取得显示索引数字所的对应寄存器代码

/**
 * @brief 控制某个七段数码管的显示
 * @param index 要控制的数码管编号，从右到左分别为0-7
 * @param digit 要显示的数字
 */
void sevenSegmentDisplay(int index, char digit)
{
    SMG_STATE = 0x00; // 消影
    SELECT_SMG(index);
    CONTROL_SMG(digit);
    delay(1);
}
