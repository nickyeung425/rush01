#include <stdlib.h>

int ***ft_starting_board()
{
  int ***board = NULL;
  board = (int ***)malloc(sizeof (int **) * SIZE);

  int i;
  int j;
  int k;
  i = 0;
  j = 0;
  k = 0;

  while (i < SIZE)
  {
    board[i] = (int **)malloc(sizeof (int *) * SIZE);
    while(j < SIZE)
    {
      board[i][j] = (int *)malloc(sizeof (int) * SIZE);
      while(k < SIZE)
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
  return board;
}


int **ft_starting_board_solution()
{
  int **board = NULL;
  board = (int **)malloc(sizeof (int *) * SIZE);

  int i;
  int j;
  i = 0;
  j = 0;

  while (i < SIZE)
  {
    board[i] = (int *)malloc(sizeof (int) * SIZE);
    while(j < SIZE)
    {
      board[i][j] = SIZE;
      j++;
    }
    j = 0;
    i++;
  }
  return board;
}