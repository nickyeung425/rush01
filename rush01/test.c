int	constraint_top_bottom(int constraint_index, int ***board)
{
	int	index;
	int	current_max;
	int	res;
	int	x;
	int	y;

  index = 0;
  current_max = 0;
  x = get_i(constraint_index);
  y = get_j(constraint_index);
  res = 0;
  while (index < g_size)
  {
    if (current_max < board[index][y][0])
    {
      current_max = board[index][y][0];
      res ++;
    }
    index ++;
  }
  return (res);
}

int	constraint_bottom_top(int constraint_index, int ***board)
{
	int	index;
	int	current_max;
	int	res;
	int	x;
	int	y;

  index = g_size - 1;
  current_max = 0;
  x = get_i(constraint_index);
  y = get_j(constraint_index);
  res = 0;
  while (index >= 0)
  {
    if (current_max < board[index][y][0])
    {
      current_max = board[index][y][0];
      res ++;
    }
    index--;
  }
  return (res);
}

int	constraint_left_right(int constraint_index, int ***board)
{
	int	index;
	int	current_max;
	int	res;
	int	x;
	int	y;

  index = 0;
  current_max = 0;
  x = get_i(constraint_index);
  y = get_j(constraint_index);
  res = 0;
  while (index < g_size)
  {
    if (current_max < board[x][index][0])
    {
      current_max = board[x][index][0];
      res ++;
    }
    index ++;
  }
  return (res);
}

int	constraint_right_left(int constraint_index, int ***board)
{
	int	index;
	int	current_max;
	int	res;
	int	x;
	int	y;

  index = g_size - 1;
  current_max = 0;
  x = get_i(constraint_index);
  y = get_j(constraint_index);
  res = 0;
  while (index >= 0)
  {
    if (current_max < board[x][index][0])
    {
      current_max = board[x][index][0];
      res ++;
    }
    index--;
  }
  return (res);
}

int	test_constraint(int ***board, int *constraint)
{
  int constraint_index;
  
  constraint_index = 0;
  while (constraint_index < g_size * 4)
  {
    if (constraint_index / g_size == 0 && constraint_top_bottom(constraint_index, board) != constraint[constraint_index])
    {
      return (0);
    }
    else if (constraint_index / g_size == 1 && constraint_bottom_top(constraint_index, board) != constraint[constraint_index])
    {
      return (0);
    }
    else if (constraint_index / g_size == 2 && constraint_left_right(constraint_index, board) != constraint[constraint_index])
    {
      return (0);
    }
    else if (constraint_index / g_size == 3 && constraint_right_left(constraint_index, board) != constraint[constraint_index])
    {
      return (0);
    }
    constraint_index++;
  }
  return (1);
}
