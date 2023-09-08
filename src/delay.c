#include <INTRINS.H>
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