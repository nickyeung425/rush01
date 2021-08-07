#include <unistd.h>

void ft_print_char(char c)
{
  write(1, &c, 1);
}

void ft_print_str(char *str)
{
  while(*str)
  {
    ft_print_char(*str);
    str++;
  }
}

void ft_print_int_array(int ***no_array)
{
  int i;
  int j;
  int k;

  i = 0;
  j = 0;
  k = 0;
  while (i < 4)
  {
    while (j < 4)
    {
      while (k < 4)
      {
        ft_print_char(no_array[i][j][k]);
        if (k != 3)
        {
          ft_print_char(' ');
        }
      }
    }
    ft_print_char('\n');
  }
}