/* 信16 2251654 付宝莹 */
#include <iostream>
#include <windows.h>
#include <iomanip>
#include <conio.h>
#include "hanoi.h"
#include "cmd_console_tools.h"
using namespace std;

int top[3] = { 0 };
int column[3][10] = { 0 };
int pace = 0;
int speed;
/* ----------------------------------------------------------------------------------

     本文件功能：
	1、存放被 hanoi_main.cpp 中根据菜单返回值调用的各菜单项对应的执行函数

     本文件要求：
	1、不允许定义外部全局变量（const及#define不在限制范围内）
	2、允许定义静态全局变量（具体需要的数量不要超过文档显示，全局变量的使用准则是：少用、慎用、能不用尽量不用）
	3、静态局部变量的数量不限制，但使用准则也是：少用、慎用、能不用尽量不用
	4、按需加入系统头文件、自定义头文件、命名空间等

   ----------------------------------------------------------------------------------- */
void yanshi(int speed){
    if (speed == 0) {
        while (getchar() != '\n')
            ;
    }
    else{
        Sleep(15 * (6 - speed));
    }
}

void change(char src, char dst){
    int fby = 0;
    fby = column[src - 'A'][--top[src - 'A']];
    column[src - 'A'][top[src - 'A']] = 0;
    column[dst - 'A'][top[dst - 'A']++] = fby;
}

void zhuzi(){
    cct_setcursor(CURSOR_INVISIBLE);
    int x = 1;
    int y = 15;
    int i = 0;
    int j = 0;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 23; j++)
        {
            cct_showch(x, y, ' ', COLOR_HYELLOW, 1);
            x++;
        }
        x = x + 9;
    }

    for (i = 0; i < 12; i++)
    {
        x = 12;
        y--;
        for (j = 0; j < 3; j++)
        {
            cct_showch(x, y, ' ', COLOR_HYELLOW, 1);
            x = x + 32;
            yanshi(5);
        }
    }
}

void move_pan(int n, char src, char dst){
    int i = 0;
    int j = 0;
    int space_src = 12 + 32 * int(src - 'A');
    int x = space_src;
    int space_dst = 12 + 32 * int(dst - 'A');
    int y = 15 - top[src - 'A'];
    int fby = n;
    //上移动画展示
    for (y = 13 - top[src - 'A']; y >= 2; y--){
        cct_showch(x - fby, y + 1, ' ', COLOR_BLACK, 7, fby);
        cct_showch(x, y + 1, ' ', COLOR_HYELLOW, 7, 1);
        cct_showch(x + 1, y + 1, ' ', COLOR_BLACK, 7, fby);
        yanshi(5);
        cct_showch(x - fby, y, ' ', fby, 7, 2 * fby + 1);
        yanshi(5);
    }
    yanshi(5);
    cct_showch(x - fby, y + 1, ' ', COLOR_BLACK, 7, 2 * fby + 1);
    yanshi(5);
    cct_showch(x - fby, y, ' ', fby, 7, 2 * fby + 1);
    yanshi(5);
    //左右移动画展示
    if (int(dst - src) >= 0){
        for (x = space_src; x <= space_dst - 1; x++){
            cct_showch(x - fby, y, ' ', COLOR_BLACK, 7, 2 * fby + 1);
            yanshi(5);
            cct_showch(x - fby + 1, y, ' ', fby, 7, 2 * fby + 1);
            yanshi(5);
        }
    }
    else{
        for (x = space_src; x >= space_dst + 1; x--){
            cct_showch(x - fby, y, ' ', COLOR_BLACK, 7, 2 * fby + 1);
            yanshi(5);
            cct_showch(x - fby - 1, y, ' ', fby, 7, 2 * fby + 1);
            yanshi(5);
        }
    }
    //下移动画展示
    yanshi(5);
    cct_showch(x - fby, y, ' ', COLOR_BLACK, 7, 2 * fby + 1);
    yanshi(5);
    cct_showch(x - fby, y + 1, ' ', fby, 7, 2 * fby + 1);
    yanshi(5);
    y++;
    cct_showch(x - fby, y, ' ', COLOR_BLACK, 7, 2 * fby + 1);
    yanshi(5);
    cct_showch(x - fby, y + 1, ' ', fby, 7, 2 * fby + 1);
    yanshi(5);
    y++;
    for (y = 3; y <= 14 - top[dst - 'A']; y++){
        cct_showch(x - fby, y, ' ', COLOR_BLACK, 7, fby);
        cct_showch(x, y, ' ', COLOR_HYELLOW, 7, 1);
        cct_showch(x + 1, y, ' ', COLOR_BLACK, 7, fby);
        yanshi(5);
        cct_showch(x - fby, y + 1, ' ', fby, 7, 2 * fby + 1);
        yanshi(5);
    }
    cct_setcolor(0, 7);
}

void zong_shuchu(int number){
    int i;
    int x0 = 10;
    int y0;
    if (number == 4)
        y0 = 12;
    else
        y0 = 27;
    cct_gotoxy(x0 - 2, y0);
    cout << "==========================";
    cct_gotoxy(x0, y0 +1 );
    cout << "A         B         C";
    cct_gotoxy(x0, y0);
    int x = x0-1;
    int y = y0;
    for (i = 0; i < 10; i++){
        if (column[0][i] != 0){
            y--;
            cct_gotoxy(x, y);
            cout << setw(2) << column[0][i];
        }
        else{
            y--;
            cct_gotoxy(x, y);
            cout << "  ";
        }
    }
    x = x0 + 9;
    y = y0;
    cct_gotoxy(x, y);
    for (i = 0; i < 10; i++){
        if (column[1][i] != 0){
            y--;
            cct_gotoxy(x, y);
            cout << setw(2) << column[1][i];
        }
        else{
            y--;
            cct_gotoxy(x, y);
            cout << "  ";
        }
    }
    x = x0 + 19;
    y = y0;
    cct_gotoxy(x, y);
    for (i = 0; i < 10; i++){
        if (column[2][i] != 0){
            y--;
            cct_gotoxy(x, y);
            cout << setw(2) << column[2][i];
        }
        else{
            y--;
            cct_gotoxy(x, y);
            cout << "  ";
        }
    }
}

void heng_shuchu(int number)
{
    int i;
    cout << " A:";
    for (i = 0; i < 10; i++)
    {
        if (column[0][i] != 0)
            cout << setw(2) << column[0][i];
        else
            cout << "  ";
    }
    cout << " B:";
    for (i = 0; i < 10; i++)
    {
        if (column[1][i] != 0)
            cout << setw(2) << column[1][i];
        else
            cout << "  ";
    }
    cout << " C:";
    for (i = 0; i < 10; i++)
    {
        if (column[2][i] != 0)
            cout << setw(2) << column[2][i];
        else
            cout << "  ";
    }
    cout << endl;

}

void shuchu(int number, int n, char src, char tmp, char dst)
{
    switch (number) {
        case 1:
            cout << setw(2) << n << "# " << src << "---->" << dst << endl;
            change(src, dst);
            break;
        case 2:
            cout << "第" << setw(4) << pace << " 步(" << setw(2) << n << "#: " << src << "-->" << dst << ")" << endl;
            change(src, dst);
            break;
        case 3:
            cout << "第" << setw(4) << pace << " 步(" << setw(2) << n << "#: " << src << "-->" << dst << ")";
            change(src, dst);
            heng_shuchu(3);
            break;
        case 4:
            change(src, dst);
            zong_shuchu(4);
            cct_gotoxy(0, 17);
            cout << "第" << setw(4) << pace << " 步(" << setw(2) << n << "#: " << src << "-->" << dst << ") ";
            heng_shuchu(4);
            yanshi(speed);
            break;
        case 8:
            change(src, dst);
            zong_shuchu(8);
            cct_gotoxy(0, 32);
            cout << "第" << setw(4) << pace << " 步(" << setw(2) << n << "#: " << src << "-->" << dst << ") ";
            heng_shuchu(8);
            move_pan(n, src, dst);
            yanshi(speed);
            break;
        case 9:
            change(src, dst);
            zong_shuchu(8);
            cct_gotoxy(0, 32);
            cout << "第" << setw(4) << pace << " 步(" << setw(2) << n << "#: " << src << "-->" << dst << ") ";
            heng_shuchu(8);
            move_pan(n, src, dst);
            yanshi(speed);
            break;
    }
}

void pan_pic(int n, char src)
{
    cct_setcursor(CURSOR_INVISIBLE);
    int space = int(src - 'A') + 12 + 31 * int(src - 'A');
    int x = 1;
    int y = 15;
    int i = 0;
    int fby = n;//展示的色块数
    for (fby = n; fby >= 1; fby--){
        x = space - fby;
        y--;
        for (i = 0; i < (2 * fby + 1); i++){
            cct_showch(x, y, ' ', fby, 2 * fby + 1);
            x++;
        }
        yanshi(5);
    }
}

void clean()
{
    pace = 0;
    int i = 0;
    int j = 0;
    for (i = 0; i < 3; i++) {
        top[i] = 0;
        for (j = 0; j < 10; j++)
            column[i][j] = 0;
    }
}

void hanoi(int number, int n, char src, char tmp, char dst){
    if (n == 1) {
        pace++;
        shuchu(number, n, src, tmp, dst);
    }
    else {
        hanoi(number, n-1, src, dst, tmp);
        pace++;
        shuchu(number,  n, src, tmp, dst);
        hanoi(number, n - 1, tmp, src, dst);
    }
}


void solution_9(int n, char src, char tmp, char dst)
{
    cct_setcursor(CURSOR_VISIBLE_NORMAL);
    char ssrc = 0;
    char sdst = 0;
       while (1){
            //第一个输入判断是否为正确合理值、是否停止
            while (1){
                ssrc = _getch();
                if (ssrc >= 'a' && ssrc <= 'c'){
                    ssrc = ssrc - 32;
                }
                if (ssrc >= 'A' && ssrc <= 'C'){
                    cct_gotoxy(60, 34);
                    cout << src;
                    break;
                }
                if (ssrc == 'q' || ssrc == 'Q'){
                    cct_gotoxy(0, 35);
                    cout << "游戏终止!!!!!";
                    return;
                }
                else;
            }
            while (1){
                sdst = _getch();
                if (sdst >= 'a' && sdst <= 'c')
                    sdst = sdst - 32;
                if (sdst >= 'A' && sdst <= 'C') {
                    cct_gotoxy(60, 34);
                    cout << ssrc << sdst;
                    break;
                }
            }
            if (top[ssrc - 'A'] == 0){
                cct_gotoxy(0, 35);
                cout << "源柱为空!";
                yanshi(-2);
                cct_gotoxy(0, 35);
                for (int i = 0; i < 10; i++)
                    cout << " ";
                cct_gotoxy(60, 34);
                for (int i = 0; i < 30; i++)
                    cout << " ";
                cct_gotoxy(60, 34);
                continue;
            }
            src = ssrc;
            dst = sdst;
          int n0= column[src - 'A'][top[src - 'A'] - 1];
          if(top[dst-'A']!=0)
          {
              if (n0 >= column[dst - 'A'][top[dst - 'A']-1])
              {
                  cct_gotoxy(0, 35);
                  cout << "大盘压小盘，非法移动!";
                  yanshi(1);
                  cct_gotoxy(0, 35);
                  for (int i = 0; i < 30; i++)
                  {
                      cout << " ";
                  }
                  cct_gotoxy(60, 34);
                  for (int i = 0; i < 10; i++)
                  {
                      cout << " ";
                  }
                  cct_gotoxy(60, 34);
                  continue;
              }
          }
            cct_setcolor(0, 7);
            change(src, dst);
            zong_shuchu(8);
            cct_gotoxy(0, 32);
            pace++;
            cout << "第" << setw(4) << pace << " 步(" << setw(2) << n0 << "#: " << src << "-->" << dst << ")";
            heng_shuchu(8);
            move_pan(n0, src, dst);
            cct_gotoxy(60, 34);
            for (int i = 0; i < 10; i++){
                cout << " ";
            }
            if (top[dst - 'A'] == n){
                cct_gotoxy(0, 36);
                cout << "游戏结束";
                break;
            }
        }
       cct_gotoxy(60, 34);
}

int basic_judge(int number)
{
    if (number == 5)
    {
         cct_cls();
         zhuzi();
         cct_gotoxy(0, 38);
         cct_setcolor(0, 7);
         cct_setcursor(CURSOR_VISIBLE_NORMAL);
         cout << "按回车键继续";
         while (getchar() != '\n')
             ;
         return 0;
    }
    int n;
    char src, tmp, dst;
    cout << endl << endl;
    while (1)
    {
        cout << "请输入汉诺塔的层数(1-10)" << endl;
        cin >> n;
        cin.clear();
        while (getchar() != '\n')
            ;
        if (cin.good() && (n >= 1) && (n <= 10))
            break;
    }
    cin.clear();
    while (1)
    {
        cout << "请输入起始柱(A-C)" << endl;
        cin >> src;
        cin.clear();
        while (getchar() != '\n')
            ;
        if (cin.good())
        {
            if ((src == 'A') || (src == 'a'))
            {
                src = 'A';
                break;
            }
            else if ((src == 'B') || (src == 'b'))
            {
                src = 'B';
                break;
            }
            else if ((src == 'C') || (src == 'c'))
            {
                src = 'C';
                break;
            }
        }
    }
    while (1)
    {
        cout << "请输入目标柱(A-C)" << endl;
        cin >> dst;
        cin.clear();
        while (getchar() != '\n')
            ;
        if (cin.good())
        {
            if (((dst == 'A') || (dst == 'a')) && (src != 'A'))
            {
                dst = 'A';
                break;
            }
            else if (((dst == 'B') || (dst == 'b')) && (src != 'B'))
            {
                dst = 'B';
                break;
            }
            else if (((dst == 'C') || (dst == 'c')) && (src != 'C'))
            {
                dst = 'C';
                break;
            }
            else if ((dst == src) || (dst == src + 32))
                cout << "目标柱(" << src << ")不能与起始柱(" << src << ")相同" << endl;
        }
    }

    if (((src == 'A') && (dst == 'B')) || ((src == 'B') && (dst == 'A')))
        tmp = 'C';
    else if (((src == 'A') && (dst == 'C')) || ((src == 'C') && (dst == 'A')))
        tmp = 'B';
    else if (((src == 'C') && (dst == 'B')) || ((src == 'B') && (dst == 'C')))
        tmp = 'A';
    if (number == 4||number==8)
    {
        while (1)
        {
            cout << "请输入移动速度(0-5: 0-按回车单步演示 1-延时最长 5-延时最短)";
            cin >> speed;
            cin.clear();
            while (getchar() != '\n')
                ;
            if (cin.good() && (speed >= 0) && (speed <= 5))
                break;
            else
                continue;
        }
    }
    int nb = n;
    for (nb = n; top[src - 'A'] < n;){
        column[src - 'A'][top[src - 'A']++] = nb;
        nb--;
        if (nb <= 0)
            break;
    }
    int i = 0; 
    int j = 0;
    switch (number)
    {
        case 1:
            hanoi(1,n, src, tmp, dst);
            clean();
            cout << endl;
            cout << "按回车键继续";
            while (getchar() != '\n')
                ;
            break;
        case 2:
            hanoi(2,n, src, tmp, dst);
            clean();
            cout << endl;
            cout << "按回车键继续";
            while (getchar() != '\n')
                ;
            break;
        case 3:
            hanoi(3, n, src, tmp, dst);
            clean();
            cout << endl;
            cout << "按回车键继续";
            while (getchar() != '\n')
                ;
            break;
        case 4:
            cct_cls();
            cct_gotoxy(0, 0);
            cout << "从 " << src << " 移动到 " << dst << "，共 " << n << " 层，延时设置为 "<<speed;
            cct_setcursor(CURSOR_INVISIBLE);
            cct_gotoxy(0, 17);
            cout << "初始:  ";
            heng_shuchu(4);
            zong_shuchu(4);
            yanshi(speed);
            hanoi(4, n, src, tmp, dst);
            clean();
            cct_setcursor(CURSOR_VISIBLE_NORMAL);
            cct_gotoxy(0, 38);
            cout << "按回车键继续";
            while (getchar() != '\n')
                ;
            break;
        case 6:
            cct_cls();
            cct_gotoxy(0, 0);
            cout << "从 " << src << " 移动到 " << dst << "，共 " << n << " 层";
            zhuzi();
            pan_pic(n,src);
            clean();
            cct_gotoxy(0, 38);
            cct_setcolor(0, 7);
            cct_setcursor(CURSOR_VISIBLE_NORMAL);
            cout << "按回车键继续";
            while (getchar() != '\n')
                ;
            break;
        case 7:
            cct_cls();
            cct_gotoxy(0, 0);
            cout << "从 " << src << " 移动到 " << dst << "，共 " << n << " 层";
            zhuzi();
            cct_setcolor(0, 7);
            pan_pic(n, src);
            cct_setcolor(0, 7);
            change(src, dst);
            move_pan(1, src, dst);
            clean();
            cct_gotoxy(0, 38);
            cct_setcolor(0, 7);
            cct_setcursor(CURSOR_VISIBLE_NORMAL);
            cout << "按回车键继续";
            while (getchar() != '\n')
                ;
            break;
        case 8:
            cct_cls();
            cct_gotoxy(0, 0);
            cout << "从 " << src << " 移动到 " << dst << "，共 " << n << " 层，延时设置为 " << speed;
            cct_setcursor(CURSOR_INVISIBLE);
            cct_gotoxy(0, 32);
            cout << "初始:  ";
            heng_shuchu(8);
            zong_shuchu(8);
            zhuzi();
            pan_pic(n,src);
            cct_setcolor(0, 7);
            yanshi(speed);
            hanoi(8, n, src, tmp, dst);
            clean();
            cct_gotoxy(0, 38);
            cct_setcolor(0, 7);
            cct_setcursor(CURSOR_VISIBLE_NORMAL);
            cout << "按回车键继续";
            while (getchar() != '\n')
                ;
            break;
        case 9:
            cct_cls();
            cct_gotoxy(0, 0);
            cout << "从 " << src << " 移动到 " << dst << "，共 " << n << " 层";
            zhuzi();
            pan_pic(n, src);
            cct_setcolor(0, 7);
            cct_gotoxy(0, 32);
            cct_setcursor(CURSOR_VISIBLE_NORMAL);
            cout << "初始:  ";
            heng_shuchu(8);
            zong_shuchu(8);
            cct_gotoxy(0, 34);
            cct_setcolor(0, 7);
            cout << "请输入移动的柱号(命令形式：AC=A顶端的盘子移动到C，Q=退出) :";        
            solution_9(n, src, tmp, dst);
            clean();
            cct_gotoxy(0, 38);
            cct_setcolor(0, 7);
            cout << "按回车键继续";
            while (getchar() != '\n')
                ;
            break;
    }

    return 0;
}
