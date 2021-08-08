#include <stdlib.h>

int ***ft_starting_board(int size)
{
  int ***board = NULL;
  board = (int ***)malloc(sizeof (int **) * size);

  int i;
  int j;
  int k;
  i = 0;
  j = 0;
  k = 0;

  while (i < size)
  {
    board[i] = (int **)malloc(sizeof (int *) * size);
    while(j < size)
    {
      board[i][j] = (int *)malloc(sizeof (int) * size);
      while(k < size)
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


int **ft_starting_board_solution(int size)
{
  int **board = NULL;
  board = (int **)malloc(sizeof (int *) * size);

  int i;
  int j;
  i = 0;
  j = 0;

  while (i < size)
  {
    board[i] = (int *)malloc(sizeof (int) * size);
    while(j < size)
    {
      board[i][j] = size;
      j++;
    }
    j = 0;
    i++;
  }
  return board;
}