/* ��16 2251654 ����Ө */
#pragma once

/* ------------------------------------------------------------------------------------------------------

     ���ļ����ܣ�
	1��Ϊ�˱�֤ hanoi_main.cpp/hanoi_menu.cpp/hanoi_multiple_solutions.cpp ���໥���ʺ����ĺ�������
	2��һ�����ϵ�cpp���õ��ĺ궨�壨#define����ȫ��ֻ����const����������������
	3�����Բο� cmd_console_tools.h ��д���������Ķ�����ᣩ
   ------------------------------------------------------------------------------------------------------ */
/*�ݹ麯�����������ջ��������ջ��庯������ʱ����*/
void hanoi(int number, int n, char src, char tmp, char dst);
void change(char src, char dst);
void clean();
void yanshi(int speed);

/*�˵�������ʵ�ֲ�ͬѡ���*/
int show_menu();
int basic_judge(int number);

/*��ͼ����*/
void zhuzi();
void pan_pic(int n, char src);
void move_pan(int n, char src, char dst);

/*�����������*/
void shuchu(int number, int n, char src, char tmp, char dst);
void zong_shuchu(int number);
void heng_shuchu(int number);

/*��Ϸ���ܺ���*/
void solution_9(int n, char src, char tmp, char dst);
