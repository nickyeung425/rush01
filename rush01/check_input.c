

int check_input(char *input)
{
  int index;
  int result;
  int current_value;

  index = 0;
  result = 0;
  while(input[index])
  {
    current_value = input[index];
    if ((index % 2 == 1 && current_value != ' ') || (index % 2 == 0 && (!('0' < current_value && current_value <= (SIZE + '0')))))
    {
      result = 1;
      break ;
    }
    index++;
    
  }

  return result;
}

int *ft_parse_constraint(char *string)
{
  int index;
  int constraint_index;
  int *constraint = NULL;

  index = 0;
  constraint_index = 0;
  constraint = (int *)malloc(sizeof (int) * 16);
  while(string[index])
  {
    if (index %2 == 0)
    {
      constraint[constraint_index] = convert_char_to_int(string[index]);
      constraint_index++;
    }
    index++;
  }

  return constraint;
}