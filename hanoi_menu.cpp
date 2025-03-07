 /* 信16 2251654 付宝莹 */
#include <iostream>
#include <windows.h>
#include <iomanip>
#include <conio.h>
#include "hanoi.h"
#include "cmd_console_tools.h"
using namespace std;

/* ----------------------------------------------------------------------------------

     本文件功能：
	1、放被 hanoi_main.cpp 调用的菜单函数，要求显示各菜单项，读入正确的选项后返回

     本文件要求：
	1、不允许定义外部全局变量（const及#define不在限制范围内）
	2、不允许定义静态全局变量（全局变量的使用准则是：少用、慎用、能不用尽量不用）
	3、静态局部变量的数量不限制，但使用准则也是：少用、慎用、能不用尽量不用
	4、按需加入系统头文件、自定义头文件、命名空间等

   ----------------------------------------------------------------------------------- */


/***************************************************************************
  函数名称：show_menu
  功    能：清屏、展示菜单、读入正确选项后返回
  输入参数：char number
  返 回 值：若退出，则有返回值，用以判断是否结束程序
  说    明：此函数仅用于显示和判断
***************************************************************************/

int show_menu()
{

	cct_cls();
	cout << "---------------------------------" << endl;
	cout << "1.基本解" << endl;
	cout << "2.基本解(步数记录)" << endl;
	cout << "3.内部数组显示(横向)" << endl;
	cout << "4.内部数组显示(纵向+横向)" << endl;
	cout << "5.图形解-预备-画三个圆柱" << endl;
	cout << "6.图形解-预备-在起始柱上画n个盘子" << endl;
	cout << "7.图形解-预备-第一次移动" << endl;
	cout << "8.图形解-自动移动版本" << endl;
	cout << "9.图形解-游戏版" << endl;
	cout << "0.退出" << endl;
	cout << "---------------------------------" << endl;
	cout << "[请选择:]";
	int number;

	while(1)
	{
		number = _getch()-48;
		if (number >= 0 && number <= 9)
		{
			cct_gotoxy(10, 12);
			cout << number;
			break;
		}
		else
			;
	}
		return number;

}

