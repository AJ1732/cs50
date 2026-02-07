#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

int SIZE = 3;

int main(void) 
{
  int *x = malloc(SIZE * sizeof(int));
  if (x == NULL)
  {
    return 1;
  }
  x[0] = 72;
  x[1] = 73;
  x[2] = 33;

  for (int i = 0; i < SIZE; i++)
  {
    printf("%i\n", x[i]);
  }
  free(x);
  return 0;
}