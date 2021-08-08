#include <unistd.h>
#include <stdio.h>

void ft_print_char(char c)
{
	write(1, &c, 1);
}

void ft_print_str(char *str)
{
	while (*str)
	{
		ft_print_char(*str);
		str++;
	}
}

void ft_print_number(int n)
{
	ft_print_char(n + '0');
}

void ft_print_int_array(int ***board, int **board_solution)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = 0;
	while (i < G_SIZE)
	{
		while (j < G_SIZE)
		{
			while (k < board_solution[i][j])
			{
				while (k < board_solution[i][j])
				{
					ft_print_number(board[i][j][k]);
					k++;
				}
				ft_print_char(' ');
			}
			k = 0;
			j++;
		}
		ft_print_char('\n');
		j = 0;
		i++;
	}
}

int convert_char_to_int(char c)
{
	{
		if (c == '1')
			return (1);
		else if (c == '2')
			return (2);
		else if (c == '3')
			return (3);
		else if (c == '4')
			return (4);
		else if (c == '5')
			return (5);
		else if (c == '6')
			return (6);
		else if (c == '7')
			return (7);
		else if (c == '8')
			return (8);
		else if (c == '9')
			return (9);
	}
	return (0);
}

void ft_print_int_array_result(int ***board)
{
	int i;
	int j;
	i = 0;
	j = 0;
	while (i < G_SIZE)
	{
		while (j < G_SIZE)
		{
			ft_print_number(board[i][j][0]);
			if (j != G_SIZE - 1)
			{
				ft_print_char(' ');
			}
			j++;
		}
		ft_print_char('\n');
		j = 0;
		i++;
	}
}
