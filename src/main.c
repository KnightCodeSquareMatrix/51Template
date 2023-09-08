/**
 * @file main.c
 * @brief 添加了矩阵键盘、自制引脚读写（方便使用数组操作）、LCD1602驱动
 *
 * @date 2023-09-09 00:03:37
 * @version 1.1
 *
 */

#include <STC89C5xRC.H>
#include <INTRINS.H>
#include "smg.h"
#include "delay.h"
#include "LCD1602.h"
#include "PinControl.h"
#include "MatrixPad.h"
// #include "Lcd12864.h"

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

void myMemcpy(unsigned char *dest, unsigned char *src, unsigned int count);

void main()
{
    LCD_Init();
    LCD_ShowString(1, 1, "Hello, LCD1602");
    MatrixPad_Init();
    while (1) {
        /* */
    }
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