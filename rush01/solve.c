#include <stdlib.h>

int get_i(int index, int size)
{
  int i;
  if (index < size)
    i = 0;
  else if (size <= index && index < (size * 2))
    i = 3;
  else
    i = index % size;
  return i;
}

int get_j(int index, int size)
{
  int j;
  if (index < size * 2)
    j = index % size;
  else if (size * 2 <= index && index < size * 3)
    j = 0;
  else
    j = 3;
  return j;
}
void remove_board_value(int ***board, int **board_solution, int i, int j, int value)
{
  int *new_array = NULL;
  int index;

  new_array = (int *)malloc(sizeof (int) * (board_solution[i][j] - 1));
  index = 0;
  while (index < board_solution[i][j])
  {
    if (board[i][j][index] != value)
    {
      new_array[index] = board[i][j][index];
    }
    index++;
  }
  free(board[i][j]);
  board[i][j]  = new_array;
}

void remove_board_value_row(int ***board, int **board_solution, int i, int j, int value, int size)
{
  int index;

  index = 0;
  while (index < size)
  {
    if (index != i)
    {
      remove_board_value(board, board_solution, index, j, value);
    }
    if (index != j)
    {
      remove_board_value(board, board_solution, index, j ,value);
    }
  }
}

void set_board_value(int ***board, int **board_solution, int i, int j, int value)
{
  free(board[i][j]);
  board[i][j]  = (int *)malloc(sizeof (int));
  board_solution[i][j] = 1;
  board[i][j][0] = value;
}

void update_value_one(int ***board, int **board_solution, int index, int value, int size, int i, int j)
{
  int loop_index;

  loop_index = 0;
  while (loop_index < size)
  {
    if (index < size)
    {
      set_board_value(board, board_solution, i + (1 * loop_index), j, value + loop_index);
    }
    else if  (size <= index && index < size * 2)
    {
      set_board_value(board, board_solution, i + (-1 * loop_index), j, value + loop_index);
    }
    else if  (size <= index * 2 && index < size * 3)
    {
      set_board_value(board, board_solution, i, j + (1 * loop_index), value + loop_index);
    }
    else
    {
      set_board_value(board, board_solution, i, j + (-1 * loop_index), value + loop_index);
    }
    
    loop_index++;
  }
}

void update_board(int ***board, int **board_solution, int index, int value, int size)
{
  int i;
  int j;
  i = get_i(index, size);
  j = get_j(index, size);

  if (value == 1)
  {
    update_value_one(board, board_solution, index, value, size, i, j);
  }
}

void solve_board(int *constraint, int ***board, int **board_solution, int size)
{
  int i;
  i = 0;
  while (i < size * 4)
  {
    update_board(board, board_solution, i, constraint[i], size);
    i++;
  }
}