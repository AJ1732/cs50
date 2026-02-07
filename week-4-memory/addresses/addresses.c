#include <cs50.h>
#include <stdio.h>

int main(void) 
{
  int n = 50;
  int *p = &n;
  printf("%p\n", p);
  printf("%i\n", *p);

  printf("--------------------------------\n");

  string s = "HI!";
  printf("%s\n", s);
  printf("%p\n", s);
  printf("%p\n", &s[0]);
  printf("%p\n", &s[1]);
  printf("%p\n", &s[2]);
  printf("%p\n", &s[3]);

  printf("--------------------------------\n");

  char *s2 = "BYE!";
  printf("%s\n", s2);
  printf("%s\n", s2 + 1);
  printf("%s\n", s2 + 2);
  printf("%s\n", s2 + 3);
  return 0;
}