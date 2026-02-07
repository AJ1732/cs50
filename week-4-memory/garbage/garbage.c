#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) 
{
  int *x, *y;

  x = malloc(sizeof(int));

  *x = 42;
  y = x;

  *y = 13;
  printf("%p\n", x);
  printf("%i\n", *y);
  
  // x contains the address of the memory block allocated for the int
  // *x dereferences the address x to get the value of the int

  free(x);
  return 0;
}