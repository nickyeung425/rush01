#include "./utils.c"
#include "./check_input.c"
#include "./starting_board.c"
#include "./solve.c"

int main(int argc, char **argv)
{
  int size = 4;

  if (argc == 2)
  {
    if (check_input(argv[1], size) == 0)
    {
      int *constraint = ft_parse_constraint(argv[1]);
      int ***board = ft_starting_board(size);
      int **board_solution = ft_starting_board_solution(size);

      prepare_board(constraint, board, board_solution, size);

      find_solution_start(constraint, board, board_solution, size);
      // ft_print_int_array(board, board_solution, size);
      free(constraint);
      free(board);
    }
    else
    {
      ft_print_str("Input string parse error, please check whether your string is correct");
    }
  }
  else
  {
    ft_print_str("Invalid number of options passed to function, currently only parameter is needed for this function.\n");
  }

  return (0);
}