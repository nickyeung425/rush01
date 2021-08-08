#include <stdlib.h>

int	***ft_starting_board(void)
{
	int	i;
	int	j;
	int	k;
	int	***board;

	i = 0;
	j = 0;
	k = 0;
	board = (int ***)malloc(sizeof (int **) * g_size);
	while (i < g_size)
	{
		board[i] = (int **)malloc(sizeof (int *) * g_size);
		while (j < g_size)
		{
			board[i][j] = (int *)malloc(sizeof (int) * g_size);
			while (k < g_size)
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

int	**ft_starting_board_solution(void)
{
	int	i;
	int	j;
	int	**board;

	i = 0;
	j = 0;
	board = (int **)malloc(sizeof (int *) * g_size);
	while (i < g_size)
	{
		board[i] = (int *)malloc(sizeof (int) * g_size);
		while (j < g_size)
		{
			board[i][j] = g_size;
			j++;
		}
		j = 0;
		i++;
	}
	return (board);
}
