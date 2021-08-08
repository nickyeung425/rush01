#include <stdlib.h>

int ***ft_starting_board(void)
{
	int i;
	int j;
	int k;
	int ***board;

	i = 0;
	j = 0;
	k = 0;
	board = (int ***)malloc(sizeof(int **) * G_SIZE);
	while (i < G_SIZE)
	{
		board[i] = (int **)malloc(sizeof(int *) * G_SIZE);
		while (j < G_SIZE)
		{
			board[i][j] = (int *)malloc(sizeof(int) * G_SIZE);
			while (k < G_SIZE)
			{
				board[i][j][k] = k + 1;
				k++;
			}
			k = 0;
			j++;
		}
		j = 0;
		i++;
	}
	return (board);
}

int **ft_starting_board_solution(void)
{
	int i;
	int j;
	int **board;

	i = 0;
	j = 0;
	board = (int **)malloc(sizeof(int *) * G_SIZE);
	while (i < G_SIZE)
	{
		board[i] = (int *)malloc(sizeof(int) * G_SIZE);
		while (j < G_SIZE)
		{
			board[i][j] = G_SIZE;
			j++;
		}
		j = 0;
		i++;
	}
	return (board);
}
