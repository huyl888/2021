#include "12-31.h"

void PosPrint(int x, int y, char* pChar)
{
	HANDLE hWindow = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD cr = { x,y };
	SetConsoleCursorPosition(hWindow, cr);
	printf(pChar);
}

bool WriteChar(char * pChar, int nX, int nY, WORD attr)
{
	HANDLE hWindow = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO stc;
	stc.bVisible = FALSE;
	stc.dwSize = 1;
	SetConsoleCursorInfo(hWindow, &stc);
	COORD cr = { 2 * nX,nY };
	SetConsoleCursorPosition(hWindow, cr);
	SetConsoleTextAttribute(hWindow, attr);
	printf(pChar);

	return true;
}

bool SetWindowSize(wchar_t* pTitle, int nWid, int High)
{
	SetConsoleTitle(pTitle);	//console标题
	HANDLE hWindow = GetStdHandle(STD_OUTPUT_HANDLE);
	SMALL_RECT sr = { 0 };
	sr.Bottom = High;
	sr.Left = 0;
	sr.Right = nWid;
	sr.Top = 0;
	SetConsoleWindowInfo(hWindow, true, &sr);
	COORD cd = { nWid + 1,High + 1 };	//console缓冲区设置
	SetConsoleScreenBufferSize(hWindow, cd);

	return true;
}

bool InitMap(int(*p)[40])
{
	for (size_t i = 0; i < 40; i++)
	{
		for(size_t j = 0;j < 40;j++)
			if (i == 0 || j == 0 || i == 39 || j == 39)
			{
				p[i][j] = 1;
			}
	}
	for (size_t i = 0; i < 40; i++)
	{
		for (size_t j = 0; j < 40; j++)
			if (p[i][j])
			{
				WriteChar("■",j,i,FOREGROUND_BLUE);
			}
	}
	return true;
}

void GetMap()
{
	for (int i = 0; i < 40; i++)
	{
		for (int j = 0; j < 40; j++)
		{
			if (TempMap2[i][j] == 1)
			{
				WriteChar("〓", j, i, FOREGROUND_INTENSITY);
			}
			if (TempMap2[i][j] == 2)
			{
				WriteChar("□", j, i, FOREGROUND_RED | FOREGROUND_INTENSITY);
			}
			if (TempMap2[i][j] == 3)
			{
				WriteChar("◇", j, i, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			}
			if (TempMap2[i][j] == 4)
			{
				WriteChar("◎", j, i, FOREGROUND_BLUE | FOREGROUND_INTENSITY | FOREGROUND_INTENSITY);
			}
			if (TempMap2[i][j] == 5)
			{
				WriteChar("○", j, i, FOREGROUND_RED | FOREGROUND_INTENSITY);

			}
			if (TempMap2[i][j] == 6)
			{
				WriteChar("■", j, i, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			}
			if (TempMap2[i][j] == 7)	//AI老巢
			{
				WriteChar("★", j, i, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			}
			if (TempMap2[i][j] == 8)	//player老巢
			{
				WriteChar("★", j, i, FOREGROUND_RED | FOREGROUND_INTENSITY);
			}
			if (TempMap2[i][j] == 9)
			{
				WriteChar("■", j, i, FOREGROUND_INTENSITY);
			}
		}
	}
}

void GetZkMap()
{
	for (int i = 40; i < 50; i++)
	{
		WriteChar("■", i,0, FOREGROUND_INTENSITY);
	}
	for (int i = 40; i < 50; i++)
	{
		WriteChar("■", i,39, FOREGROUND_INTENSITY);
	}
	for (int i = 0; i < 40; i++)
	{
		WriteChar("■", 49, i, FOREGROUND_INTENSITY);
	}
	for (int i = 0; i < 40; i++)
	{
		WriteChar("■", 40, i, FOREGROUND_INTENSITY);
	}
}

void ShowZk()
{
	WriteChar("战况显示", 42, 4, FOREGROUND_BLUE);
	WriteChar("战斗中··", 42, 8, FOREGROUND_BLUE);
	WriteChar("剩余敌军", 42, 12, FOREGROUND_BLUE);
	WriteChar("第 X 关", 42, 16, FOREGROUND_BLUE);
}

void DrawTank(TANKINFO tank)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (nTankType[tank.nDir][i][j])
			{
				WriteChar("■", tank.nX-1+j, tank.nY-1+i, FOREGROUND_BLUE);
			}
			else
			{
				WriteChar("  ", tank.nX - 1 + j, tank.nY - 1 + i, FOREGROUND_BLUE);
			}
		}
	}
}

void ClearTank(TANKINFO tank)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (nTankType[tank.nDir][i][j])
			{
				WriteChar("  ", tank.nX - 1 + j, tank.nY - 1 + i, FOREGROUND_BLUE);
			}
		}
	}
}

bool TankMoveJudge(int nDir, TANKINFO tank)
{
	int x, y;
	switch (nDir)
	{
	case UP:
		x = tank.nX;
		y = tank.nY - 1;
		break;
	case DOWN:
		x = tank.nX;
		y = tank.nY + 1;
		break;
	case LEFT:
		x = tank.nX - 1;
		y = tank.nY;
		break;
	case RIGHT:
		x = tank.nX + 1;
		y = tank.nY;
		break;
	}
	return true;
}
void TankMove(char ch)
{
	switch (ch)
	{
	case 'w':
	case 'W':
		MyTank.nDir = UP;
		if (TankMoveJudge(UP, MyTank))
		{
			MyTank.nY--;
		}
		break;
	case 'a':
	case 'A':
		MyTank.nDir = LEFT;
		if (TankMoveJudge(LEFT, MyTank))
		{
			MyTank.nX--;
		}
		break;
	case 's':
	case 'S':
		MyTank.nDir = DOWN;
		if (TankMoveJudge(DOWN, MyTank))
		{
			MyTank.nY++;
		}
		break;
	case 'd':
	case 'D':
		MyTank.nDir = RIGHT;
		if (TankMoveJudge(RIGHT, MyTank))
		{
			MyTank.nX++;
		}
		break;
	default:
		break;
	}
}

int main()
{
	SetWindowSize(L"坦克大战", 100, 40);

	InitMap(TempMap1);
	GetMap(TempMap2);
	GetZkMap();
	ShowZk();
	DrawTank(MyTank);
	DrawTank(AITank);

	while (true)
	{
		char ch = getch();

		if (_kbhit)
		{
			ClearTank(MyTank);
			if (ch >= '1' && ch <= '9')
			{

			}
			else
			{
				TankMove(ch);
			}
			DrawTank(MyTank);
		}
		DrawTank(MyTank);
	}

	//ClearTank(AITank);

	getchar();
	return 0;
}