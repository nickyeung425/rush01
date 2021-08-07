#include "./utils.c"
#include "./check_input.c"
#include <stdio.h>

int main(int argc, char **argv)
{

  if (argc == 2)
  {
    if (check_input(argv[1]) == 0)
    {
      printf("Correct input: %s\n", argv[1]);
      printf("Testing bit operations: %d\n",  & 2);
      printf("Testing bit operations: %d\n", 6 & 4);
      printf("Testing bit operations: %d\n", 5 & 1);
    }
    else
    {
      ft_print_str("Input string parse error, please check whether your string is correct");
    }
  }
  else
  {
    ft_print_str("Invalid number of options passed to function, currently only parameter is needed for this function.\n");
  }

  return (0);
}