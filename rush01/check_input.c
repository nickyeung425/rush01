#include <unistd.h>

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
    if ((index % 2 == 1 && current_value != ' ') || (index % 2 == 0 && (!('0' <= current_value && current_value <= '4'))))
    {
      result = 1;
      break ;
    }
    index++;
    
  }

  return result;
}