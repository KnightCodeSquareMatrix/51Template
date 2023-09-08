#if !defined(__MATRIX_PAD__)
#define __MATRIX_PAD__

#define MAX_X 4
#define MAX_Y 4

extern unsigned char MatrixPad_x[MAX_X];//初始化函数里修改对应的引脚
extern unsigned char MatrixPad_x[MAX_X];//初始化函数里修改对应的引脚

extern unsigned char PressedKey[2];//按下按键的坐标

void MatrixPad_Init();
void MatrixPad_Get_Pressed();
unsigned char Get_Pin_Status(unsigned char pin);
void Set_Pin_Status(unsigned char pin, unsigned char status);

#endif
