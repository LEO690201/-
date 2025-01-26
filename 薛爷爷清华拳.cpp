#include<stdio.h>
#include<easyx.h>
#include<time.h>
#include<windows.h>
#include<mmsystem.h>
#include<math.h>
#include <graphics.h>

#undef UNICODE
#undef _UNICODE

#pragma comment(lib,"winmm.lib")
/*winmm.lib 是 Windows Multimedia API（多媒体API）的静态链接库文件。
通过包含这条指令，你可以确保你的程序能够使用 Windows 提供的多媒体功能，
比如音频播放、MIDI、录音等功能。*/
#define Wide 780
#define Hight 500
#define Wide1 780
#define Hight1 286
#define Xue_num 10
#define Player_sleep 10
int Time1 = 0;
int Health = 5;
int sleep = 1;
int Img = 0;
struct Ball
{
	float x = 0;
	int y = 0;
	float r = 0;

};
struct Ball Enemy[Xue_num];
struct Ball Player;
IMAGE img[2];
IMAGE ustcer[58];
IMAGE qinghuaquan[Xue_num];
IMAGE Heal[6];
int a = 0;
//加载图片
//贴图  定义变量  赋值  输出
void Init()
{
	loadimage(&img[0], "background.jpg");
	loadimage(&img[1], "background4.png");
	loadimage(&Heal[5], "five.png.png");
	loadimage(&Heal[4], "four.png.png");
	loadimage(&Heal[3], "three.png.png");
	loadimage(&Heal[2], "two.png.png");
	loadimage(&Heal[1], "one.png.png");
	loadimage(&ustcer[0], "ustc.jpg.jpg", 50, 50);
	loadimage(&ustcer[1], "ustc.jpg.jpg", 50, 50);
	loadimage(&ustcer[2], "ustc.jpg.jpg", 50, 50);
	loadimage(&ustcer[3], "ustc.jpg.jpg", 50, 50);
	loadimage(&ustcer[4], "ustc.jpg.jpg", 50, 50);
	loadimage(&ustcer[5], "ustc.jpg.jpg", 50, 50);
	loadimage(&ustcer[6], "ustc.jpg.jpg", 50, 50);
	loadimage(&ustcer[7], "ustc.jpg.jpg", 50, 50);
	loadimage(&ustcer[8], "ustc.jpg.jpg", 50, 50);
	loadimage(&ustcer[9], "ustc.jpg.jpg", 50, 50);
	loadimage(&ustcer[10], "ustc.jpg.jpg", 50, 50);
	loadimage(&ustcer[11], "ustc.jpg.jpg", 50, 50);
	loadimage(&ustcer[12], "ustc.jpg.jpg", 50, 50);
	loadimage(&ustcer[13], "ustc.jpg.jpg", 50, 50);
	loadimage(&ustcer[14], "ustc.jpg.jpg", 50, 50);
	loadimage(&ustcer[15], "ustc.jpg.jpg", 50, 50);
	loadimage(&ustcer[16], "ustc.jpg.jpg", 50, 50);
	loadimage(&ustcer[17], "ustc.jpg.jpg", 50, 50);
	loadimage(&ustcer[18], "ustc.jpg.jpg", 50, 50);
	loadimage(&ustcer[19], "ustc.jpg.jpg", 50, 50);
	loadimage(&ustcer[20], "ustc.jpg.jpg", 50, 50);
	loadimage(&ustcer[21], "ustc.jpg.jpg", 50, 50);
	loadimage(&ustcer[22], "ustc.jpg.jpg", 50, 50);
	loadimage(&ustcer[23], "ustc.jpg.jpg", 50, 50);
	loadimage(&ustcer[24], "ustc.jpg.jpg", 50, 50);
	loadimage(&ustcer[25], "ustc.jpg.jpg", 50, 50);
	loadimage(&ustcer[26], "ustc.jpg.jpg", 50, 50);
	loadimage(&ustcer[27], "ustc.jpg.jpg", 50, 50);
	loadimage(&ustcer[28], "ustc.jpg.jpg", 50, 50);
	loadimage(&ustcer[29], "ustc.jpg.jpg", 50, 50);
	loadimage(&ustcer[30], "ustc.jpg.jpg", 50, 50);
	loadimage(&ustcer[31], "ustc.jpg.jpg", 50, 50);
	loadimage(&ustcer[32], "ustc.jpg.jpg", 50, 50);
	loadimage(&ustcer[33], "ustc.jpg.jpg", 50, 50);
	loadimage(&ustcer[34], "ustc.jpg.jpg", 50, 50);
	loadimage(&ustcer[35], "ustc.jpg.jpg", 50, 50);
	loadimage(&ustcer[36], "ustc.jpg.jpg", 50, 50);
	loadimage(&ustcer[37], "ustc.jpg.jpg", 50, 50);
	loadimage(&ustcer[38], "ustc.jpg.jpg", 50, 50);
	loadimage(&ustcer[39], "ustc.jpg.jpg", 50, 50);
	loadimage(&ustcer[40], "ustc.jpg.jpg", 50, 50);
	loadimage(&ustcer[41], "ustc.jpg.jpg", 50, 50);
	loadimage(&ustcer[42], "ustc.jpg.jpg", 50, 50);
	loadimage(&ustcer[43], "ustc.jpg.jpg", 50, 50);
	loadimage(&ustcer[44], "ustc.jpg.jpg", 50, 50);
	loadimage(&ustcer[45], "ustc.jpg.jpg", 50, 50);
	loadimage(&ustcer[46], "ustc.jpg.jpg", 50, 50);
	loadimage(&ustcer[47], "ustc.jpg.jpg", 50, 50);
	loadimage(&ustcer[48], "ustc.jpg.jpg", 50, 50);
	loadimage(&ustcer[49], "ustc.jpg.jpg", 50, 50);
	loadimage(&ustcer[50], "ustc.jpg.jpg", 50, 50);
	loadimage(&ustcer[51], "ustc.jpg.jpg", 50, 50);
	loadimage(&ustcer[52], "ustc.jpg.jpg", 50, 50);
	loadimage(&ustcer[53], "ustc.jpg.jpg", 50, 50);
	loadimage(&ustcer[54], "ustc.jpg.jpg", 50, 50);
	loadimage(&ustcer[55], "ustc.jpg.jpg", 50, 50);
	loadimage(&ustcer[56], "ustc.jpg.jpg", 50, 50);
	for (int i = 0; i < Xue_num; i++)
	{
		loadimage(&qinghuaquan[i], "th.jpg.jpg", 36, 36);
	}
}
//初始化薛爷爷的信息
void Itset()
{
	//薛爷爷起始位置
	for (int i = 0; i < Xue_num;i++)
	{
		Enemy[i].x = Wide / 2;
		Enemy[i].y = 10;
		Enemy[i].r = 30;
	}
	//玩家起始位置
	Player.x = Wide / 2;
	Player.r = 10;
	Player.y = Hight - Player.r * 4;
}
void grandpa_Xue_move()//移动
{
	srand((unsigned)time(NULL));
	// 使用当前时间作为随机数种子，确保每次运行程序时生成不同的随机数序列。
	for (int i = 0; i < Xue_num; i++)// 遍历所有敌人（假设敌人数量为 Xue_num）
	{
		int direction = rand() % 8;
		// 生成一个 0 到 7 之间的随机整数，用于决定敌人的移动方向。
		if (direction == 0)
		{
			Enemy[i].y++;
			Enemy[i].x--;
		}
		else if (direction == 1)
		{
			Enemy[i].y++;
			Enemy[i].x++;
		}
		else if (direction == 2)
		{
			Enemy[i].y += 2;
			Enemy[i].x += 2;
		}
		else if (direction == 3)
		{
			Enemy[i].y += 2;
			Enemy[i].x -= 2;
		}
		else if (direction == 4)
		{
			Enemy[i].y += 3;
			Enemy[i].x += 3;
		}
		else if (direction == 5)
		{
			Enemy[i].y += 3;
			Enemy[i].x -= 3;
		}
		else if (direction == 6)
		{
			Enemy[i].y += 4;
			Enemy[i].x -= 4;
		}
		else if (direction == 7)
		{
			Enemy[i].y += 4;
			Enemy[i].x += 4;
		}
		if (Enemy[i].x <0 || Enemy[i].x>Wide || Enemy[i].y > Hight - Player.r * 3)
			// 检查敌人是否超出边界，如果超出则重置其位置和大小
		{
			Enemy[i].x = Wide / 2;
			// 将敌人的 x 坐标重置为窗口宽度的一半
			Enemy[i].y = 10;
			// 将敌人的 y 坐标重置为 10
			Enemy[i].r = 30;
			// 将敌人的半径重置为 30
		}
	}
}
void show()
{
	srand((unsigned)time(NULL));
	cleardevice();//清空屏幕
	putimage(0, 0, &img[Img]);
			//在坐标(0,0)处显示图像img[Img]
	putimage(0, 0, &Heal[Health], SRCAND);
	// 在坐标 (0, 0) 处显示图像 Heal[Health]，使用 SRCAND 模式进行位操作

	for (int i = 0; i < Xue_num; i++) // 循环遍历所有敌人球体
	{
		setfillcolor(WHITE);// 设置填充颜色为白色
		solidcircle(Enemy[i].x, Enemy[i].y, Enemy[i].r);
		// 绘制一个实心圆，圆心为 Enemy[i].x 和 Enemy[i].y，半径为 Enemy[i].r
	}
	putimage(Player.x - 14, Player.y - 14, Wide, Hight, &ustcer[a], 0, 0, SRCAND);
	// 在玩家位置的偏移量 (Player.x - 14, Player.y - 14) 处显示图像 ustcer[a]
	for (int i = 0; i < Xue_num; i++)// 再次循环遍历所有敌人球体
	{
		putimage(Enemy[i].x - 18, Enemy[i].y - 18, Wide, Hight, &qinghuaquan[i], 0, 0, SRCAND);
		// 在敌人球体的偏移量 (Enemy[i].x - 18, Enemy[i].y - 18) 处显示图像 ball[i]
	}
	//settextcolor(RGB(7, 19, 62));
	settextcolor(RED);// 设置文本颜色为红色
	TCHAR buffer[50];// 定义一个字符缓冲区 buffer，用于存储时间字符串
	sprintf_s(buffer, _T("%d"), Time1);// 将 Time1 转换为字符串并存储到 buffer 中
	setbkmode(TRANSPARENT);// 设置背景模式为透明
	settextstyle(25, 0, _T("宋体")); // 设置文本样式为 25 号字体，无特殊样式，字体为宋体
	outtextxy(120, 10, _T("时间:")); // 在坐标 (120, 10) 处输出 "时间:" 字符串
	outtextxy(190, 10, buffer); // 在坐标 (190, 10) 处输出时间值（即 buffer 中的字符串）
}
//距离
int Distance(int x, int y, int x1, int y1)
{
	return sqrt((x - x1) * (x - x1) + (y - y1) * (y - y1));
}
//玩家与球碰撞
void collide()
{
	for (int i = 0; i < Xue_num; i++)
	{
		if (Distance(Player.x, Player.y, Enemy[i].x, Enemy[i].y) < Player.r + Enemy[i].r && Health > 0)
		{
			Health--;
			Enemy[i].x = Wide / 2;
			Enemy[i].y = 10;
			Enemy[i].r = 30;
		}
	}

}
void player_move()
{
	if (GetAsyncKeyState(VK_LEFT) || GetAsyncKeyState(0x41))
		// 如果按下左箭头键或 'A' 键
	{
		if (Player.x > 0)// 如果玩家的 x 坐标大于 0，则向左移动
			Player.x -= Player_sleep;
	}
	if (GetAsyncKeyState(VK_RIGHT) || GetAsyncKeyState(0x44))
		// 如果按下右箭头键或 'D' 键
	{
		// 如果玩家的 x 坐标小于窗口宽度，则向右移动
		if (Player.x < Wide)
			Player.x += Player_sleep;
	}
	// 如果玩家在地面上（y 坐标等于地面高度减去半径的四倍）
	if (Player.y == Hight - Player.r * 4)
	{
		// 如果按下空格键、'W' 键或上箭头键
		if (GetAsyncKeyState(0x20) || GetAsyncKeyState(0x57) || GetAsyncKeyState(VK_UP))
		{
			// 开始批量绘图
			BeginBatchDraw();
			while (Player.y > Hight - Player.r * 4 - 120)
				// 当玩家 y 坐标大于地面高度减去 120 时，执行跳跃动作
			{
				
				Sleep(60);// 暂停 20 毫秒
				Player.y -= 10;// 每次循环 y 坐标减少 10
				player_move();// 递归调用 player_move 函数
				grandpa_Xue_move();
				show();
				collide();// 调用 collide 函数检测碰撞
				FlushBatchDraw();// 刷新批量绘图
			}
		}
		// 如果健康值为零，游戏结束
		if (Health == 0)
		{
			printf("\a");// 发出警告音
			system("pause");// 暂停程序
			exit(0);// 退出程序
		}
	}
}
int main()
{
	Init(); // 初始化游戏设置
	Itset();//设置窗口宽度
	initgraph(Wide, Hight);// 初始化图形窗口并设置缓冲区大小
	BeginBatchDraw();// 开始批量绘图
	int Time = (unsigned)time(NULL);// 获取当前时间戳
	while (1) // 无限循环，保持游戏运行
	{
		Time1 = (unsigned)time(NULL) - Time;// 计算经过的时间
		Sleep(60);// 暂停 20 毫秒
		if (a <= 56)
		{
			a++;
		}
		if (a > 56)
		{
			a = 0;
		}
		if (Player.y < Hight - Player.r * 4)
			// 如果玩家不在地面上
		{
			Player.y += 4;// 玩家 y 坐标增加 4，模拟重力效果
		}
		if (sleep > 0)
		{
			sleep--;
		}
		if (Health == 0)
			Img = 1;
		show();
		FlushBatchDraw();
		grandpa_Xue_move();
		player_move();
		collide();
	}
	closegraph(); // 关闭图形窗口
}








