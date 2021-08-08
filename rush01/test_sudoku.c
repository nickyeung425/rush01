int test_sudoku_row_col(int ***board, int row, int col)
{
  int x;

  x = 0;
  while (x<g_size)
  {
    if (x != row && board[row][col][0] == board[x][col][0])
    {
      return 0;
    }
    if (x != col && board[row][col][0] == board[row][x][0])
    {
      return 0;
    }
    x++;
  }
  return 1;
}

int test_sudoku(int ***board)
{
  int row;
  int col;

  row = 0;
  col = 0;
  while(row < g_size)
  {
    while (col< g_size)
    {
      if (test_sudoku_row_col(board, row, col) == 0)
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
