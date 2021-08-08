#include <unistd.h>
#include <stdlib.h>
#include "./get_constraint_position.c"
#include "./utils.c"
#include "./check_input.c"
#include "./starting_board.c"
#include "./test.c"
#include "./test_sudoku.c"
#include "./solve.c"
#define G_SIZE 4

int	main(int argc, char **argv)
{
	int	*constraint;
	int	***board;
	int	**board_solution;

	if (argc == 2)
	{
		if (check_input(argv[1]) == 0)
		{
			constraint = ft_parse_constraint(argv[1]);
			board = ft_starting_board();
			board_solution = ft_starting_board_solution();
			prepare_board(constraint, board, board_solution);
			find_solution_start(constraint, board, board_solution);
			free(constraint);
			free(board);
		}
		else
			ft_print_str("Input string parse error, please check whether your string is correct");
	}
	else
		ft_print_str("Invalid number of options passed to function, currently only parameter is needed for this function.\n");
	return (0);
}
