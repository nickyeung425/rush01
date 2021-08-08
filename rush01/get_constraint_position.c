int get_i(int index)
{
  int i;
  if (index < G_SIZE)
    i = 0;
  else if (G_SIZE <= index && index < (G_SIZE * 2))
    i = 3;
  else
    i = index % G_SIZE;
  return (i);
}

int get_j(int index)
{
  int j;
  if (index < G_SIZE * 2)
    j = index % G_SIZE;
  else if (G_SIZE * 2 <= index && index < G_SIZE * 3)
    j = 0;
  else
    j = 3;
  return (j);
}