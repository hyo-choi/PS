#include <stdio.h>
#include <string.h>

int flag;
int sudoku[9][9];
int set[10];

void print_sudoku(void)
{
	for (int j = 0; j < 9; j++)
	{
		for (int i = 0; i < 8; i++)
			printf("%d ", sudoku[j][i]);
		printf("%d\n", sudoku[j][8]);
	}
}

void check_sudoku(int j, int i)
{
	memset(set, 0, sizeof(set));
	for (int l = 0; l < 9; l++)
		set[sudoku[j][l]] = 1;
	for (int l = 0; l < 9; l++)
		set[sudoku[l][i]] = 1;
	for (int k = j / 3 * 3; k < (int)(j / 3) * 3 + 3; k++)
		for (int l = i / 3 * 3; l < (int)(i / 3) * 3 + 3; l++)
			set[sudoku[k][l]] = 1;
}

void solve(int j, int i)
{
	if (flag == 1)
		return ;
	if (j == 9)
	{
		if (flag == 0)
		{
			print_sudoku();
			flag = 1;
		}
		return ;
	}
	if (sudoku[j][i] == 0)
	{
		for (int k = 1; k <= 9; k++)
		{
			check_sudoku(j, i);
			if (set[k] == 0)
			{
				sudoku[j][i] = k;
				if (i == 8)
					solve(j + 1, 0);
				else
					solve(j, i + 1);
				sudoku[j][i] = 0;
			}
		}
	}
	else
	{
		if (i == 8)
			solve(j + 1, 0);
		else
			solve(j, i + 1);
	}
}

int main(void)
{
	for (int j = 0; j < 9; j++)
		for (int i = 0; i < 9; i++)
			scanf("%d", &sudoku[j][i]);
	solve(0, 0);
	return (0);
}