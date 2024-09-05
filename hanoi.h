/* 信16 2251654 付宝莹 */
#pragma once

/* ------------------------------------------------------------------------------------------------------

     本文件功能：
	1、为了保证 hanoi_main.cpp/hanoi_menu.cpp/hanoi_multiple_solutions.cpp 能相互访问函数的函数声明
	2、一个以上的cpp中用到的宏定义（#define）或全局只读（const）变量，个数不限
	3、可以参考 cmd_console_tools.h 的写法（认真阅读并体会）
   ------------------------------------------------------------------------------------------------------ */
/*递归函数、数组进出栈函数、清空缓冲函数、延时函数*/
void hanoi(int number, int n, char src, char tmp, char dst);
void change(char src, char dst);
void clean();
void yanshi(int speed);

/*菜单函数、实现不同选项函数*/
int show_menu();
int basic_judge(int number);

/*画图函数*/
void zhuzi();
void pan_pic(int n, char src);
void move_pan(int n, char src, char dst);

/*文字输出函数*/
void shuchu(int number, int n, char src, char tmp, char dst);
void zong_shuchu(int number);
void heng_shuchu(int number);

/*游戏功能函数*/
void solution_9(int n, char src, char tmp, char dst);
