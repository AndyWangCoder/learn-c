#define  _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

void InitBoard(char board[ROWS][COLS], int rows, int cols, char set)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			board[i][j] = set;
		}
	}

}
//有改动 若编译出错 检查下面这段代码
void DisplayBoard(char board[ROWS][COLS],int row,int col )
{
	int i = 0;
	int j = 0;
	for (j = 0; j <= col; j++)
	{
		printf("%d ", j);
	}
	printf("\n");
	for (i=1;i<=row;i++)
	{
		printf("%d ", i);
		for (j=1;j<=col;j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
}
//有改动 若编译出错 检查下面这段代码
void SetMine(char board[ROWS][COLS])
{
	int Mine_Count = EASY_COUNT;
	while (Mine_Count)
	{
		int i = rand() % ROW + 1;
		int j = rand() % COL + 1;
		if (board[i][j] == '0')
		{
			board[i][j] = '1';
			Mine_Count--;
		}
	}
}
int get_mine_count(char board[ROWS][COLS], int i, int j)
{
	return board[i - 1][j - 1] + board[i - 1][j] + board[i - 1][j + 1]
		+ board[i][j - 1] + board[i][j + 1] + board[i + 1][j - 1]
		+ board[i + 1][j] + board[i + 1][j + 1] - 8 * '0';
}
void FindMine(char board1[ROWS][COLS], char board2[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int count = 0;
	while (count < ROW*COL - EASY_COUNT)
	{
		printf("请输入您要排查的位置>:");
		scanf("%d %d", &x, &y);
		if (board1[x][y] == '1')
		{
			printf("很抱歉，您被炸死了！\n");
			DisplayBoard(board1, row, col);
			break;
		}
		else if (board1[x][y] == '0')

		{	 
			board2[x][y] = get_mine_count(board1, x, y) + '0';
			DisplayBoard(board2, row, col);
			count++;
		}
		else if (x>ROW || x<1 || y>COL || y<1)
		{
			printf("您输入的坐标有误，请重新输入！\n");
		}
	}
	if (count == ROW * COL - EASY_COUNT)
	{
		printf("恭喜，您排雷成功！\n");
		DisplayBoard(board2, row, col);

	}
}