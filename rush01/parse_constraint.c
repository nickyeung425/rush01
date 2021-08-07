#include <stdlib.h>

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