#include <stdio.h>
#include <stdlib.h>

int main(void) 
{
  // Get Integer
  int n;
  printf("n: ");
  scanf("%i", &n);
  printf("You entered: %i\n", n);

  // Get String
  char *s = malloc(4);
  printf("s: ");
  scanf("%s", s);
  printf("You entered: %s\n", s);
  free(s);
  return 0;
}