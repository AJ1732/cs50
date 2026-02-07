#include <cs50.h>
#include <stdio.h>
#include <string.h>

typedef unsigned char BYTE;

int main(int argc, char *argv[])
{
  FILE *src = fopen(argv[1], "r");
  if (src == NULL)
  {
    return 1;
  }

  FILE *dst = fopen(argv[2], "w");
  if (dst == NULL)
  {
    return 1;
  }
   
  BYTE b;

  while (fread(&b, sizeof(b), 1, src) != 0) {
    fwrite(&b, sizeof(b), 1, dst);
  }

  fclose(src);
  fclose(dst);
  return 0;
}