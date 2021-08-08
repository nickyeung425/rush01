int get_i(int index)
{
  int i;
  if (index < g_size)
    i = 0;
  else if (g_size <= index && index < (g_size * 2))
    i = 3;
  else
    i = index % g_size;
  return i;
}

int get_j(int index)
{
  int j;
  if (index < g_size * 2)
    j = index % g_size;
  else if (g_size * 2 <= index && index < g_size * 3)
    j = 0;
  else
    j = 3;
  return j;
}