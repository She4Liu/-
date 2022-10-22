#define _CRT_SECURE_NO_WARNINGS 1
#include"head.h"

// 在game.c中编写游戏内容的部分
void game()
{
	// 首先，考虑打印棋盘实际是通过存放二维数组的方式打印棋子
	// 因此定义一个二维数组
	char board[ROW][COL];
	// 通过一个函数实现棋子数据的初始化
	// 因为数组如果不初始化，存放的可能是随机值
	int_board(board, ROW, COL);
	// 而棋盘网格的实现也是有规律可循的
	board_print(board, ROW, COL);
	while (1)
	{
		// 玩家下棋
		player_movie(board, ROW, COL);
		// 判断输赢
		char result;
		result = who(board, ROW, COL);
		who_win(result);
		if (result != 'C')
			break;
		// 电脑下棋
		computer_movie(board, ROW, COL);
		// 判断输赢
		result = who(board, ROW, COL);
		who_win(result);
		if (result != 'C')
			break;
	}
}

// 1.初始化棋子数据
void int_board(char board[ROW][COL], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			// 实现棋盘实际存放内容上（9个格）每个元素都为空
			board[i][j] = ' ';
		}
	}
}

// 2.打印棋盘（实现棋盘大小任意可改，只需改变头文件里的ROW和COL即可）
void board_print(char board[ROW][COL], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		// 第一个双循环实现棋子行的打印
		for (int j = 0; j < col; j++)
		{
			if (j < col - 1)
				printf(" %c |", board[i][j]);
			else
				printf(" %c \n", board[i][j]);
		}
		// 第二个双循环实现分割线行的打印
		// if判断用于避免最后一行也打印分割线，因为最后一行是不封闭的（看图）
		if (i < row - 1)
		{
			for (int j = 0; j < col; j++)
			{
				if (j < col - 1)
					printf("---|");
				else
					printf("---\n");
			}
		}
	}
}

// 玩家下棋操作
void player_movie(char board[ROW][COL], int row, int col)
{
	printf("玩家下棋:\n");
	int x, y;
	while (1)
	{
		printf("请下棋: ");
		scanf("%d %d", &x, &y);
		// 判断坐标是否合法
		if (x >= 1 && x <= ROW + 1, y >= 1 && y <= COL +1)
		{
			// 判断坐标是否已被占用（玩家的选择从1开始）
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("该位置已有棋子！\n");
			}
			printf("坐标位置非法！\n");
		}
	}
	board_print(board, ROW, COL);
}

// 电脑下棋操作
void computer_movie(char board[ROW][COL], int row, int col)
{
	printf("电脑下棋:\n");
	int x, y;
	while (1)
	{
		x = rand() % ROW;
		y = rand() % COL;
		// 不用判断坐标是否合法，因为%ROW或COL生成的数字必然合法
		// 判断坐标是否已被占用（使用%后，电脑的选择从0开始）
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}
	board_print(board, ROW, COL);
}


// 判断输赢函数(使用返回值*、#、n)
char who(char board[ROW][COL], int row, int col)
{
	// 判断行是否有三连子
	for (int i = 0; i < ROW; i++)
	{
		// 注意：c语言不支持连等，因此必须两两比较
		if (board[i][0] == board[i][1] && board[i][0] == board[i][2] && board[i][0] != ' ')
		{
			// 这里就体现出来用*、#作为返回值的好处了
			return board[i][0];
		}
	}
	// 判断列是否有三连子
	for (int j = 0; j < COL; j++)
	{
		if (board[0][j] == board[1][j] && board[0][j] == board[2][j] && board[0][j] != ' ')
		{
			return board[0][j];
		}
	}
	// 判断对角线是否有三连子
	if (board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] != ' ')
		return board[0][0];
	if (board[0][2] == board[1][1] && board[0][2] == board[2][0] && board[0][2] != ' ')
		return board[0][2];
	// 判断是否继续游戏
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			if (board[i][j] == ' ')
				// 如果棋盘未下满
				return 'C';
		}
	}
	// 上面返回条件都为满足，则只可能是平局
	return 'N';
}

void who_win(char c)
{
	if (c == '*')
	{
		printf("玩家胜利！\n\n");
	}
	else if (c == '#')
	{
		printf("电脑胜利！\n\n");
	}
	else if (c == 'N')
		printf("平局！\n\n");
}
