#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<Windows.h>
#include<stdlib.h>
#include<conio.h>


//刚学完c语言的基础内容（就是刚学完指针，新手村小白）
//因为想用c的标准库来写，所以在不调用第三方库的情况下打算用命令行的形式输出
//逐帧输出结果，调用资源可能较大请见谅
char screen[40][100];
char a = '#';
char b = ' ';
int select_number = 0;      //计时器用变量（不能修改）
int line = 0;

void values(int turning)
{

}


//光标移动类
int coor(char instruct, int xx, int yy, int turns)
{
	int* y_c = &yy; int* x_c = &xx;
	switch (instruct)
	{
	case 72://方向向上
		if (turns > 0 && turns < 13) {
			turns = 0;

		}
		else if (turns > 12 && turns < 28)
		{
			if (turns < 25) {
				turns -= 12;
			}
			if (turns > 24) {
				turns = 0;
			}

		}
		else if (turns > 28 && turns < 46)
		{
			if (turns < 43)
			{
				turns -= 16;
			}
			if (turns == 43)
				turns = 26;
			if (turns == 44)
				turns = 27;
			if (turns == 45)
				turns = 28;
		}
		else if (turns > 45 && turns < 61)
		{
			if (turns == 46)
			{
				turns = 29;
			}
			if (turns > 46 && turns < 59)
			{
				turns -= 16;
			}
			if (turns == 59)
			{
				turns = 44;
			}
			if (turns == 60)
			{
				turns = 45;
			}
		}
		else if (turns > 60 && turns < 76)
		{
			if (turns == 61) {
				turns = 46;
			}
			if (turns > 61 && turns < 73) {
				turns -= 14;
			}
			if (turns == 73 || turns == 74)
				turns = 59;
			if (turns == 75)
				turns = 65;
		}
		else if (turns > 75 && turns < 85)
		{
			switch (turns)
			{
			case 76:
				/*case 76:*/
				turns = 61;
				break;
			case 77:
				turns = 61;
				break;
			case 78:
				turns = 62;
				break;
			case 79:
				turns = 64;
				break;
			case 80:
				turns = 66;
				break;
			case 81:
				turns = 72;
				break;
			case 82:
				turns = 73;
				break;
			case 83:
				turns = 73;
				break;
			case 84:
				turns = 73;
				break;

			}
		}
		break;
	case 75://方向向左
		if (turns == 0)
			turns = 12;
		else
		{
			if (turns != 1 && turns != 13 && turns != 29 && turns != 46 && turns != 61 && turns != 76)
			{
				turns -= 1;
			}
		}
		break;
	case 77://方向向右
		if (turns == 12)
			turns = 26;
		if (turns == 0)
			turns = 27;
		else
		{
			if (turns != 0 && turns != 12 && turns != 28 && turns != 45 && turns != 60 && turns != 75 && turns != 84)
				turns += 1;
		}
		break;
	case 80://方向向下
		if (turns >= 0 && turns < 13)
		{
			turns += 13;
		}
		if (turns > 12 && turns < 28)
		{
			if (turns < 27) {
				turns += 16;
			}
			if (turns == 27 || turns == 28)
			{
				turns += 17;
			}
		}
		if (turns > 28 && turns < 46)
		{
			if (turns < 31)
			{
				turns = 46;
			}
			if (turns >= 31 && turns < 43)
			{
				turns += 16;
			}
			if (turns == 43)
			{
				turns = 58;
			}
			if (turns == 59 || turns == 60)
				turns += 15;
		}
		if (turns > 45 && turns < 61)
		{
			if (turns < 48)
			{
				turns = 61;
			}
			if (turns >= 48 && turns < 59)
			{
				turns += 14;
			}
			if (turns > 58)
			{
				turns += 15;
			}

		}
		if (turns > 60 && turns < 76)
		{
			if (turns == 61)
			{
				turns = 76;
			}
			if (turns == 62 || turns == 63)
			{
				turns = 78;
			}
			if (turns == 64)
			{
				turns = 79;
			}
			if (turns > 64 && turns < 71)
			{
				turns = 80;
			}
			if (turns == 72)
			{
				turns = 81;
			}
			if (turns == 73)
				turns = 83;
			if (turns == 74 || turns == 75)
			{
				turns = 84;
			}
		}

		break;
	}
	return turns;
}
void computers()
{
	
	char get1 = 0;
	char get2 = 0;
	int turn = 0;


	int x=92, y=21;
	/*int* x_c = &x;
	int* y_c = &y;*/
	char como[100][115] = { {"__________________________________________________________________________________________________________________"},
							{"\\                                                                                                                /"},
							{" \\                                                                                                              / "},
							{"  \\                                                                                                            /  "},
							{"   \\                                                                                                          /   "},
							{"    \\                                                                                                        /    "},
							{"     \\                                                                                                      /     "},
							{"      \\                                                                                                    /      "},
							{"       \\                                                                                                  /       "},
							{"        \\                                                                                                /        "},
							{"         \\                                                                                              /         "},
							{"          \\                                                                                            /          "},
							{"           \\                                                                                          /           "},
							{"            \\                                                                                        /            "},
							{"             \\                                                                                      /             "},
							{"              \\                                                                                    /              "},
							{"               \\                                                                                  /               "},
							{"                \\                                                                                /                "},
							{"                 \\                                                                              /                 "},
							{"                  \\                                                                            /                  "},
							{"                   \\__________________________________________________________________________/                   "},
							{"                   /____/___/___/___/___/___/_____________________________________________\\___\\                   "},
							{"                  / F1 / F2 / F3 / F4 / F5 / F6 / F7 / F8 / F9 / F10/F11 /F12 /                \\                  "},
							{"                 /____/____/____/____/____/____/____/____/____/____/____/____/__________________\\                 "},
							{"                /    /   /   /   /   /   /   /   /   /   /)  /-  /+  /           /   \\     \\     \\                "},
							{"               /  ` / 1 / 2 / 3 / 4 / 5 / 6 / 7 / 8 / 9 / O /  -/  =/    Back   /     \\ Del \\ Pau \\               "},
							{"              /____/___/___/___/___/___/___/___/___/___/___/___/___/___________/       \\_____\\_____\\	             "},
							{"             /        /   /   /   /   /   /   /   /   /   /   /   /   /|  /   /         \\     \\     \\             "},
							{"            /   Tab  / Q / W / E / R / T / Y / U / I / O / P / [ / ] / \\ /   /           \\ Ins \\Bre  \\            "},
							{"           /________/___/___/___/___/___/___/___/___/___/___/___/___/___/   /             \\_____\\_____\\           "},
							{"          /            /   /   /   /   /   /   /   /   /   /:  /\"  /       /               \\     \\     \\          "},
							{"         /  CapsLocks / A / S / D / F / G / H / J / K / L /  ;/  '/ Enter /                 \\ Prt \\ Sys \\         "},
							{"        /____________/___/___/___/___/___/___/___/___/___/___/___/_______/      _______      \\_____\\_____\\        "},
							{"       /                /   /   /   /   /   /   /   /<  />  /?  /       /       |      |      \\     \\     \\       "},
							{"      /    SHIFT       / Z / X / C / V / B / N / M /  ,/  ./   /Shift  /        |  ↑  |       \\ Hom \\ End \\      "},
							{"     /________________/___/___/___/___/___/___/___/___/___/___/_______/_________|______|________\\_____\\_____\\     "},
							{"    /        /       /       /       /                       /       /   |      |      |      |              \\    "},
							{"   /   Ctrl /  FN   /  Win  /  Alt  /                       /  Ctrl /    |  ←  |  ↓  |  →  |               \\   "},
							{"  /________/_______/_______/_______/_______________________/_______/_____|______|______|______|________________\\  "},
							{" /______________________________________________________________________________________________________________\\ "},
	};
	//第一遍图像绘制
	for (int i = 0; i < 40; i++)
	{
		printf("%s\n", como[i]);
		Sleep(400);
	}
	//como[21][92] = '@';
	system("cls");
	for (int i = 0; i < 40; i++)
	{
		printf("%s\n", como[i]);
		//Sleep(400);
	}



	//键盘控制系统
	while (true)
	{
		
		if (get1 = _getch())
		{
			system("cls");
			get2 = _getch();
			//printf("%d\n", get2);
			turn = coor(get2,x,y,turn);
			//printf("%d\n", turn);
			como[y][x] = '@';


			//图像渲染
			for (int i = 0; i < 40; i++)
			{
				printf("%s\n", como[i]);
				//Sleep(400);
			}
		}
	}


}
void carding() 
{
	int i= 1;
	char card[23] = "[                    ]";
	while (true)
	{
		
		card[i] = '#';
		printf("%s", card);
		
		Sleep(350);
		system("cls");
		i++;
		if (i == 22) {
			break;
		}
	}
}
void one(int left1,int right1)
{
	
	for (int i = left1; i < right1; i++)
	{
		screen[line][i] = a;
		
	}
	line++;
}

void two(int left2, int right2, int left3, int right3)
{
	for (int i = left2; i < right2; i++)
	{
		screen[line][i] = a;
	}
	for (int i = left3; i < right3; i++)
	{
		screen[line][i] = a;
	}
	line++;
}

void three(int left4, int right4, int left5, int right5, int left6, int right6)
{
	for (int i = left4; i < right4; i++)
	{
		screen[line][i] = a;
	}
	for (int i = left5; i < right5; i++)
	{
		screen[line][i] = a;
	}
	for (int i = left6; i < right6; i++)
	{
		screen[line][i] = a;
	}
	line++;
}
void four(int a, int b, int c, int d, int e, int f, int g, int h)
{
	three(a, b, c, d, e, f); line--;
	one(g, h);
	
}
void drawing()
{
	for (int print_high = 0; print_high < 40; print_high++)
	{
		for (int print_width = 0; print_width < 100; print_width++)
		{
			printf("%c", screen[print_high][print_width]);
		}
		printf("\n");
	}
}
void analog_computer()
{

	//这里打算建立一个100×25的屏幕，用 # 作为主要输出框
	//屏幕绘制
	while (true)
	{
		for (int longth = 0; longth < 40; longth++)
		{
			for (int width = 0; width < 100; width++)
			{
				if (longth == 0 || longth == 39)
				{
					screen[longth][width] = a;
				}
				else
				{
					screen[longth][width] = b;
				}
			}
			if (longth != 0 && longth != 39)
			{
				screen[longth][0] = a;
				screen[longth][99] = a;
			}
		}
		//初始化部分↑

		switch (select_number)
		{

		case 1:
			line = 0;
			one(54, 66);
			one(52, 69);
			one(50, 72);
			one(50, 73);
			one(50, 73);
			one(50, 71);
			one(51, 69);
			one(46, 68);
			one(41, 67);
			two(39, 47, 49, 72);
			three(37, 47, 49, 68, 69, 75);
			three(36, 47, 49, 67, 68, 77);
			three(36, 48, 50, 66, 67, 78);
			three(35, 47, 49, 65, 66, 78);
			three(33, 47, 49, 65, 66, 79);
			three(32, 47, 49, 64, 65, 80);
			three(28, 48, 50, 63, 64, 85);
			two(27, 66, 77, 87);
			two(26, 64, 74, 93);
			two(27, 60, 77, 95);
			two(27, 57, 82, 97);
			two(26, 57, 86, 99);
			two(25, 58, 88, 99);
			two(23, 58, 89, 100);
			two(22, 57, 86, 100);
			two(21, 58, 83, 100);
			two(20, 58, 83, 100);
			two(20, 59, 83, 100);
			two(19, 60, 83, 100);
			two(17, 61, 84, 100);
			three(17, 43, 46, 61, 85, 100);
			four(17, 26, 29, 43, 47, 61, 85, 99);
			four(15, 25, 29, 41, 48, 62, 85, 97);
			three(16, 26, 30, 41, 51, 62);
			three(16, 26, 30, 41, 51, 62);
			two(30, 42, 52, 63);
			two(30, 42, 52, 64);
			two(30, 42, 53, 63);
			break;
		case 2:
			line = 0;
			one(41, 60);
			one(39, 62);
			one(38, 62);
			one(38, 62);
			one(38, 61);
			one(39, 60);
			one(39, 58);
			one(40, 57);
			one(35, 61);
			two(33, 37, 40, 62);
			two(30, 38, 40, 62);
			three(29, 38, 41, 61, 62, 67);
			three(28, 38, 41, 60, 63, 68);
			three(27, 39, 42, 60, 62, 69);
			three(26, 40, 42, 59, 61, 70);
			three(24, 41, 42, 59, 62, 70);
			three(23, 40, 41, 58, 61, 70);
			three(23, 40, 43, 58, 60, 71);
			three(21, 40, 42, 58, 60, 70);
			three(20, 40, 43, 57, 59, 71);
			three(19, 39, 42, 58, 67, 71);
			two(18, 57, 61, 70);
			three(18, 28, 29, 59, 62, 72);
			three(17, 27, 29, 59, 64, 74);
			three(16, 26, 29, 59, 65, 75);
			three(15, 25, 28, 59, 67, 76);
			three(15, 24, 30, 60, 69, 79);
			three(14, 23, 31, 62, 70, 80);
			three(15, 22, 32, 63, 72, 79);
			four(15, 21, 32, 45, 46, 65, 73, 80);
			four(15, 21, 33, 45, 48, 66, 73, 80);
			four(15, 21, 34, 46, 49, 67, 72, 80);
			two(34, 46, 50, 80);
			two(34, 46, 52, 81);
			two(35, 46, 54, 82);
			two(82, 46, 56, 83);
			two(33, 44, 57, 83);
			two(32, 43, 59, 82);
			two(31, 42, 59, 81);
			two(30, 42, 58, 80);
			two(29, 41, 56, 79);
			break;
		case 3:
			line = 0;
			one(27, 50);
			one(27, 49);
			one(28, 48);
			one(29, 48);
			one(30, 51);
			one(33, 55);
			two(32, 54, 56, 60);
			two(32, 54, 56, 60);
			three(26, 31, 32, 54, 55, 61);
			three(26, 31, 33, 53, 55, 62);
			three(26, 32, 34, 53, 54, 64);
			three(25, 33, 35, 53, 54, 63);
			three(25, 33, 36, 52, 54, 62);
			three(24, 34, 36, 52, 55, 63);
			three(24, 35, 38, 51, 54, 64);
			three(24, 35, 38, 51, 54, 63);
			two(24, 37, 39, 65);
			two(24, 37, 39, 65);
			two(25, 37, 40, 63);
			one(25, 64);
			one(24, 63);
			one(25, 64);
			one(25, 64);
			one(25, 64);
			two(25, 34, 36, 66);
			two(25, 35, 37, 65);
			three(25, 34, 38, 48, 51, 66);
			three(25, 33, 38, 49, 52, 67);
			three(25, 33, 37, 49, 51, 67);
			three(24, 32, 37, 48, 52, 68);
			three(25, 32, 37, 47, 52, 68);
			two(24, 29, 37, 70);
			two(24, 29, 35, 71);
			two(25, 46, 54, 70);
			two(25, 48, 55, 72);
			two(25, 48, 59, 73);
			two(25, 50, 53, 72);
			two(24, 49, 52, 71);
			two(29, 47, 51, 69);
			two(34, 45, 49, 66);
			break;
		case 4:
			line = 1;
			one(31, 35);
			one(27,41);
			one(25,42);
			one(23,43);
			one(24,43);
			one(24,43);
			one(25,48);
			one(26,53);
			one(28,57);
			one(29,58);
			two(29,48,49,59);
			three(26,28,30,48,50,59);
			three(24,29,31,48,50,60);
			three(24,29,31,48,50,61);
			three(24,30,32,49,50,61);
			two(23, 31, 32, 62);
			two(23, 32, 34, 63);
			two(23, 32, 35, 63);
			two(23, 33, 37, 66);
			two(22, 32, 36, 66);
			two(21, 31, 37, 66);
			two(19, 31, 37, 65);
			two(17, 30, 35, 66);
			two(16, 28, 36, 67);
			two(15, 28, 36, 67);
			two(13, 25, 36, 67);
			two(12, 23, 37, 67);
			two(10, 22, 38, 67);
			two(8, 24, 38, 67);
			two(6, 25, 39, 67);
			three(5, 25, 38, 50, 53, 68);
			three(6, 26, 38, 50, 54, 69);
			three(6, 26, 37, 49, 55, 70);
			three(8, 26, 36, 48, 55, 70);
			three(8, 25, 36, 48, 56, 70);
			three(10, 22, 36, 47, 57, 70);
			two(36, 46, 58, 71);
			two(35, 46, 52, 71);
			two(35, 45, 52, 72);
			two(35, 45, 50, 73);
			break;
		case 5:
			line = 0;
			one(27, 50);
			one(27, 49);
			one(28, 48);
			one(29, 48);
			one(30, 51);
			one(33, 55);
			two(32, 54, 56, 60);
			two(32, 54, 56, 60);
			three(26, 31, 32, 54, 55, 61);
			three(26, 31, 33, 53, 55, 62);
			three(26, 32, 34, 53, 54, 64);
			three(25, 33, 35, 53, 54, 63);
			three(25, 33, 36, 52, 54, 62);
			three(24, 34, 36, 52, 55, 63);
			three(24, 35, 38, 51, 54, 64);
			three(24, 35, 38, 51, 54, 63);
			two(24, 37, 39, 65);
			two(24, 37, 39, 65);
			two(25, 37, 40, 63);
			one(25, 64);
			one(24, 63);
			one(25, 64);
			one(25, 64);
			one(25, 64);
			two(25, 34, 36, 66);
			two(25, 35, 37, 65);
			three(25, 34, 38, 48, 51, 66);
			three(25, 33, 38, 49, 52, 67);
			three(25, 33, 37, 49, 51, 67);
			three(24, 32, 37, 48, 52, 68);
			three(25, 32, 37, 47, 52, 68);
			two(24, 29, 37, 70);
			two(24, 29, 35, 71);
			two(25, 46, 54, 70);
			two(25, 48, 55, 72);
			two(25, 48, 59, 73);
			two(25, 50, 53, 72);
			two(24, 49, 52, 71);
			two(29, 47, 51, 69);
			two(34, 45, 49, 66);
			break;

		case 6:
			line = 0;
			one(41, 60);
			one(39, 62);
			one(38, 62);
			one(38, 62);
			one(38, 61);
			one(39, 60);
			one(39, 58);
			one(40, 57);
			one(35, 61);
			two(33, 37, 40, 62);
			two(30, 38, 40, 62);
			three(29, 38, 41, 61, 62, 67);
			three(28, 38, 41, 60, 63, 68);
			three(27, 39, 42, 60, 62, 69);
			three(26, 40, 42, 59, 61, 70);
			three(24, 41, 42, 59, 62, 70);
			three(23, 40, 41, 58, 61, 70);
			three(23, 40, 43, 58, 60, 71);
			three(21, 40, 42, 58, 60, 70);
			three(20, 40, 43, 57, 59, 71);
			three(19, 39, 42, 58, 67, 71);
			two(18, 57, 61, 70);
			three(18, 28, 29, 59, 62, 72);
			three(17, 27, 29, 59, 64, 74);
			three(16, 26, 29, 59, 65, 75);
			three(15, 25, 28, 59, 67, 76);
			three(15, 24, 30, 60, 69, 79);
			three(14, 23, 31, 62, 70, 80);
			three(15, 22, 32, 63, 72, 79);
			four(15, 21, 32, 45, 46, 65, 73, 80);
			four(15, 21, 33, 45, 48, 66, 73, 80);
			four(15, 21, 34, 46, 49, 67, 72, 80);
			two(34, 46, 50, 80);
			two(34, 46, 52, 81);
			two(35, 46, 54, 82);
			two(82, 46, 56, 83);
			two(33, 44, 57, 83);
			two(32, 43, 59, 82);
			two(31, 42, 59, 81);
			two(30, 42, 58, 80);
			two(29, 41, 56, 79);
			break;
		
		}//打印部分
		drawing();
		

		select_number++;
		Sleep(400);
		system("cls");
		if (select_number == 7) {
			//break;
			select_number = 1;
			
		}
	}
}


int main()
{
	char chaing[20] = {};
	int kuku = 0;
	computers();
	
	
	
	
	
	
	//T:
	//if (kuku > 3) {
	//	printf("您输入的错误指令次数过多，请稍后重试");
	//		Sleep(200);
	//		exit(NULL);
	//	
	//}
	//printf("请输入指令：");
	//scanf("%s", chaing);
	//if (strcmp("cxkngm", chaing) == 0) {
	//	printf("密码正确！即将为你加载......");
	//		Sleep(500);
	//		system("cls");
	//		carding();
	//		analog_computer();
	//}
	//else if (strcmp("computer",chaing) == 0) {
	//	printf("正在启动电脑......\n");
	//	Sleep(200);
	//	/*system("cls");*/
	//	computers();
	//}
	//else
	//{
	//	printf("您输入的指令不正确,您还有"); printf("%d", 3 - kuku); printf("次机会\n"); kuku++; goto T;
	//}
	
	return 0;
}