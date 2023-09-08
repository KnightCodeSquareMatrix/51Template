#include <STC89C5xRC.H>
#include "intrins.h"
#include "MatrixPad.h"
#include "delay.h"
#include "PinControl.h"
unsigned char PressedKey[2];
unsigned char MatrixPad_x[MAX_X];
unsigned char MatrixPad_y[MAX_Y];

/**
  * @brief  矩阵键盘读取按键键码
  * @param  无
  * @retval KeyNumber 按下按键的键码值
            如果按键按下不放，程序会停留在此函数，松手的一瞬间，返回按键键码，没有按键按下时，返回0
  */
void MatrixPad_Get_Pressed()
{
    int i, j;
    PressedKey[0]=0;
    PressedKey[1]=0;
    for (i = 0; i < MAX_X; i++) {
        Set_Pin_Status(i, 1);
    }
    for (j = 0; j < MAX_Y; j++) {
        Set_Pin_Status(j, 1);
    }
    for (i = 0; i < MAX_Y; i++) {
        Set_Pin_Status(MatrixPad_y[i], 0);
        for (j = 0; j < MAX_X; j++) {
            if (!Get_Pin_Status(MatrixPad_x[j])) {
                delay(20);
                while (!Get_Pin_Status(MatrixPad_x[j]))
                    ;
                delay(20);
                PressedKey[0] = i+1;
                PressedKey[1] = j+1;
            }
        }
        Set_Pin_Status(MatrixPad_y[i], 1);
    }
}
/**
 * @brief 初始化，调用一次就行了
*/
void MatrixPad_Init()
{
    MatrixPad_x[0] = 17;
    MatrixPad_x[1] = 16;
    MatrixPad_x[2] = 15;
    MatrixPad_x[3] = 14;
    MatrixPad_y[0] = 13;
    MatrixPad_y[1] = 12;
    MatrixPad_y[2] = 11;
    MatrixPad_y[3] = 10;
    PressedKey[0]  = MAX_X;
    PressedKey[1]  = MAX_Y;
}
