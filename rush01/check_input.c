int	check_input(char *input)
{
	int	id;
	int	result;
	int	cv;

	id = 0;
	result = 0;
	while (input[id])
	{
		cv = input[id];
		if ((id % 2 == 1 && cv != ' ') || (id % 2 == 0 && (!('0' < cv && cv <= (g_size + '0')))))
		{
			result = 1;
			break ;
		}
		id++;
	}
	return (result);
}

int	*ft_parse_constraint(char *string)
{
	int	index;
	int	constraint_index;
	int	*constraint;

	index = 0;
	constraint_index = 0;
	constraint = (int *) malloc(sizeof (int) * 16);
	while (string[index])
	{
		if (index % 2 == 0)
		{
			constraint[constraint_index] = convert_char_to_int(string[index]);
			constraint_index++;
		}
		index++;
	}
	return (constraint);
}
