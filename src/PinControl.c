#include <STC89C5xRC.H>
#include "intrins.h"
/**
 * @brief 获得对应单个引脚的状态
 * @param pin 引脚编号，如0对应P00,15对应P15
 * @retval 0-低电平，1-高电平
 */
unsigned char Get_Pin_Status(unsigned char pin)
{
    switch (pin) {
        case 0:
            return P00;

        case 1:
            return P01;

        case 2:
            return P02;

        case 3:
            return P03;

        case 4:
            return P04;

        case 5:
            return P05;

        case 6:
            return P06;

        case 7:
            return P07;

        case 10:
            return P10;

        case 11:
            return P11;

        case 12:
            return P12;

        case 13:
            return P13;

        case 14:
            return P14;

        case 15:
            return P15;

        case 16:
            return P16;

        case 17:
            return P17;

        case 20:
            return P20;

        case 21:
            return P21;

        case 22:
            return P22;

        case 23:
            return P23;

        case 24:
            return P24;

        case 25:
            return P25;

        case 26:
            return P26;

        case 27:
            return P27;

        case 30:
            return P30;

        case 31:
            return P31;

        case 32:
            return P32;

        case 33:
            return P33;

        case 34:
            return P34;

        case 35:
            return P35;

        case 36:
            return P36;

        case 37:
            return P37;
    }
    return 1;
}
/**
 * @brief 设置对应引脚的状态
 * @param pin 引脚编号，如0对应P00,15对应P15
 * @param status 0-低电平 1-高电平
 */
void Set_Pin_Status(unsigned char pin, unsigned char status)
{
    switch (pin) {
        case 0:
            P00 = status;
            return;
        case 1:
            P01 = status;
            return;
        case 2:
            P02 = status;
            return;
        case 3:
            P03 = status;
            return;
        case 4:
            P04 = status;
            return;
        case 5:
            P05 = status;
            return;
        case 6:
            P06 = status;
            return;
        case 7:
            P07 = status;
            return;
        case 10:
            P10 = status;
            return;
        case 11:
            P11 = status;
            return;
        case 12:
            P12 = status;
            return;
        case 13:
            P13 = status;
            return;
        case 14:
            P14 = status;
            return;
        case 15:
            P15 = status;
            return;
        case 16:
            P16 = status;
            return;
        case 17:
            P17 = status;
            return;
        case 20:
            P20 = status;
            return;
        case 21:
            P21 = status;
            return;
        case 22:
            P22 = status;
            return;
        case 23:
            P23 = status;
            return;
        case 24:
            P24 = status;
            return;
        case 25:
            P25 = status;
            return;
        case 26:
            P26 = status;
            return;
        case 27:
            P27 = status;
            return;
        case 30:
            P30 = status;
            return;
        case 31:
            P31 = status;
            return;
        case 32:
            P32 = status;
            return;
        case 33:
            P33 = status;
            return;
        case 34:
            P34 = status;
            return;
        case 35:
            P35 = status;
            return;
        case 36:
            P36 = status;
            return;
        case 37:
            P37 = status;
            return;
    }
}