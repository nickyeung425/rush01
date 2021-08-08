#include <stdlib.h>

int get_i(int index)
{
  int i;
  if (index < SIZE)
    i = 0;
  else if (SIZE <= index && index < (SIZE * 2))
    i = 3;
  else
    i = index % SIZE;
  return i;
}

int get_j(int index)
{
  int j;
  if (index < SIZE * 2)
    j = index % SIZE;
  else if (SIZE * 2 <= index && index < SIZE * 3)
    j = 0;
  else
    j = 3;
  return j;
}

int check_value_onboard(int *values, int values_size, int value)
{
  int index;
  index = 0;
  while (index < values_size)
  {
    if (value == values[index])
    {
      return 1;
    }
    index++;
  }
  return 0;
}
void remove_board_value(int ***board, int **board_solution, int i, int j, int value)
{
  int *new_array = NULL;
  int index;
  int new_index;

  if (check_value_onboard(board[i][j], board_solution[i][j], value) == 1)
  {
    new_array = (int *)malloc(sizeof (int) * (board_solution[i][j] - 1));
    index = 0;
    new_index = 0;
    while (index < board_solution[i][j])
    {
      if (board[i][j][index] != value)
      {
        new_array[new_index] = board[i][j][index];
        new_index++;
      }
      index++;
    }
    free(board[i][j]);
    board_solution[i][j] = board_solution[i][j] - 1;
    board[i][j]  = new_array;
  }
}

void remove_board_value_row_col(int ***board, int **board_solution, int i, int j, int value)
{
  int index;

  index = 0;
  while (index < SIZE)
  {
    if (index != i && board_solution[index][j] != 1)
    {
      remove_board_value(board, board_solution, index, j, value);
    }
    if (index != j && board_solution[i][index] != 1)
    {
      remove_board_value(board, board_solution, i, index, value);
    }
    index++;
  }
}

void set_board_value(int ***board, int **board_solution, int i, int j, int value)
{
  free(board[i][j]);
  board[i][j]  = (int *)malloc(sizeof (int));
  board_solution[i][j] = 1;
  board[i][j][0] = value;
  remove_board_value_row_col(board, board_solution, i, j, value);
}

void set_board_value_array(int ***board, int **board_solution, int i, int j, int *value, int value_size)
{
  int index;

  index = 0;
  free(board[i][j]);
  board[i][j]  = value;
  board_solution[i][j] = value_size;
  board[i][j] = value;
}

void update_value_four(int ***board, int **board_solution, int index, int value, int i, int j)
{
  int loop_index;

  loop_index = 0;
  while (loop_index < SIZE)
  {
    if (index < SIZE)
    {
      set_board_value(board, board_solution, i + (1 * loop_index), j, loop_index + 1);
    }
    else if  (SIZE <= index && index < SIZE * 2)
    {
      set_board_value(board, board_solution, i + (-1 * loop_index), j, loop_index + 1);
    }
    else if  (SIZE <= index * 2 && index < SIZE * 3)
    {
      set_board_value(board, board_solution, i, j + (1 * loop_index), loop_index + 1);
    }
    else
    {
      set_board_value(board, board_solution, i, j + (-1 * loop_index), loop_index + 1);
    }
    loop_index++;
  }
}

void update_value_one(int ***board, int **board_solution, int index, int value, int i, int j)
{
  set_board_value(board, board_solution, i, j, value);
}

int get_possible_values_solutions_no(int *current_board_solutions, int current_board_solutions_no, int constraint_value)
{
  int current_board_solutions_index = 0;
  int possible_values_index = 1;
  int possible_solutions_no = 0;
  while (current_board_solutions_index < current_board_solutions_no)
  {
    while (possible_values_index <= (SIZE - constraint_value + 1))
    {
      if (current_board_solutions[current_board_solutions_index] <= (SIZE - constraint_value + 1))
      {
        possible_solutions_no++;
        break;
      }
      possible_values_index++;
    }
    current_board_solutions_index++;
  }
  return possible_solutions_no;
}

void update_value_else(int ***board, int **board_solution, int value, int i, int j)
{
  int possible_solutions_no = get_possible_values_solutions_no(board[i][j], board_solution[i][j], value);
  int *possible_solutions = (int *)malloc(sizeof (int) * possible_solutions_no);
  int current_board_solutions_index = 0;
  int possible_solutions_index = 0;
  while (current_board_solutions_index < board_solution[i][j])
  {
    if (board[i][j][current_board_solutions_index] <= (SIZE - value + 1))
    {
      possible_solutions[possible_solutions_index] = board[i][j][current_board_solutions_index];
      possible_solutions_index++;
    }
    current_board_solutions_index++;
  }
  set_board_value_array(board, board_solution, i, j, possible_solutions, possible_solutions_no);
}

void optimize_board(int ***board, int **board_solution)
{
  int x = 0;
  int y = 0;

  while (x < SIZE)
  {
    while (y < SIZE)
    {
      if (board_solution[x][y] == 1)
      {
        remove_board_value_row_col(board, board_solution, x, y, board[x][y][0]);
      }
      y++;
    }
    y = 0;
    x++;
  }
}
void update_board(int ***board, int **board_solution, int index, int value)
{
  int i;
  int j;
  i = get_i(index);
  j = get_j(index);

  if (value == SIZE)
  {
    update_value_four(board, board_solution, index, value, i, j);
  }
  else if (value == 1)
  {
    update_value_one(board, board_solution, index, SIZE, i, j);
  }
  else 
  {
    update_value_else(board, board_solution, value, i, j);
  }
}

void prepare_board(int *constraint, int ***board, int **board_solution)
{
  int i;
  i = 0;
  while (i < SIZE * 4)
  {
    update_board(board, board_solution, i, constraint[i]);
    i++;
  }

  optimize_board(board, board_solution);
}

int *find_next_coordinates(int **board_solution)
{
  int *coordinates = (int *)malloc(sizeof (int) * 2);
  int i = 0;
  int j = 0;
  while (i < SIZE)
  {
    while (j < SIZE)
    {
      if (board_solution[i][j] != 1)
      {
        coordinates[0] = i;
        coordinates[1] = j;
        return coordinates;
      }
      j++;
    }
    j = 0;
    i++;
  }
  coordinates[0] = 0;
  coordinates[1] = 0;
  return coordinates;
}

int ***copy_board(int ***board, int **board_solution)
{
  int ***new_board;
  new_board = (int ***)malloc(sizeof (int **) * SIZE);
  int row = 0;
  int col = 0;
  int val = 0;

  while(row < SIZE)
  {
    new_board[row] = (int **)malloc(sizeof (int *) * SIZE);
    while (col < SIZE)
    {
      new_board[row][col] = (int *)malloc(sizeof (int) * board_solution[row][col]);
      while (val < board_solution[row][col])
      {
        new_board[row][col][val] = board[row][col][val];
        val++;
      }
      val = 0;
      col++;
    }
    col = 0;
    row++;
  }

  return new_board;
}


int **copy_board_solution(int **board_solution)
{
  int **new_board_solution = NULL;
  new_board_solution = (int **)malloc(sizeof (int *) * SIZE);

  int row;
  int col;
  row = 0;
  col = 0;

  while (row < SIZE)
  {
    new_board_solution[row] = (int *)malloc(sizeof (int) * SIZE);
    while(col < SIZE)
    {
      new_board_solution[row][col] = board_solution[row][col];
      col++;
    }
    col = 0;
    row++;
  }
  return new_board_solution;
}

int find_solution_finished(int **board_solution)
{
  int row = 0;
  int col = 0;
  while (row < SIZE)
  {
    while (col < SIZE)
    {
      if (board_solution[row][col] != 1)
      {
        return 0;
      }
      col++;
    }
    col = 0;
    row++;
  }
  return 1;
}
int find_solution(int ***board, int **board_solution)
{
  int *coordinates = find_next_coordinates(board_solution);
  int no_of_value_left = board_solution[coordinates[0]][coordinates[1]];
  int no_of_value_left_index = 0;
  int ***new_board = NULL;
  int **new_board_solution = NULL;
  if (find_solution_finished(board_solution) == 1)
  {
    // printf("found combination\n");
    // printf("%d %d %d %d\n%d %d %d %d\n%d %d %d %d\n%d %d %d %d\n",
    //   board[0][0][0], board[0][1][0], board[0][2][0], board[0][3][0],
    //   board[1][0][0], board[1][1][0], board[1][2][0], board[1][3][0],
    //   board[2][0][0], board[2][1][0], board[2][2][0], board[2][3][0],
    //   board[3][0][0], board[3][1][0], board[3][2][0], board[3][3][0]
    // );
    ft_print_int_array_result(board);
    return 1;
  }
  else
  {
    while (no_of_value_left_index < no_of_value_left)
    {
      
      new_board = copy_board(board, board_solution);
      
      new_board[coordinates[0]][coordinates[1]][0] =  board[coordinates[0]][coordinates[1]][no_of_value_left_index];
      
      
      new_board_solution = copy_board_solution(board_solution);
      
      new_board_solution[coordinates[0]][coordinates[1]] = 1;
      
      int result = find_solution(new_board, new_board_solution);
      no_of_value_left_index++;
    }
  }
  return 0;
}

void find_solution_start(int *constraint, int ***board, int **board_solution)
{
  // int x = 0;
  // int y = 0;
  int result = find_solution(board, board_solution);
  printf("%d", result);
}
