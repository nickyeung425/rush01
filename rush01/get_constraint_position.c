int	get_i(int index)
{
<<<<<<< HEAD
	int	i;

	if (index < g_size)
		i = 0;
	else if (g_size <= index && index < (g_size * 2))
		i = 3;
	else
		i = index % g_size;
	return (i);
=======
  int i;
  if (index < G_SIZE)
    i = 0;
  else if (G_SIZE <= index && index < (G_SIZE * 2))
    i = 3;
  else
    i = index % G_SIZE;
  return (i);
>>>>>>> 1a146ee916b6da9c157f5ad67e2e0142aacd341f
}

int	get_j(int index)
{
<<<<<<< HEAD
	int	j;

	if (index < g_size * 2)
		j = index % g_size;
	else if (g_size * 2 <= index && index < g_size * 3)
		j = 0;
	else
		j = 3;
	return (j);
}
=======
  int j;
  if (index < G_SIZE * 2)
    j = index % G_SIZE;
  else if (G_SIZE * 2 <= index && index < G_SIZE * 3)
    j = 0;
  else
    j = 3;
  return (j);
}
>>>>>>> 1a146ee916b6da9c157f5ad67e2e0142aacd341f
