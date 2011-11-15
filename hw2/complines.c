#include <stdio.h>
#include <string.h>

int main(int argc, char *argv)
{
 
  FILE *file_a = fopen("a.txt", "rt");
  if(!file_a)
  {
    printf("Error: could not open file a!\n");
  }

  FILE *file_b = fopen("b.txt", "rt");
  if(!file_a)
  {
    printf("Error: could not open file b!\n");
  }
  int lines=1;
  char aa[80];
  char bb[80];
  fgets(aa, 80, file_a);
  fgets(bb, 80, file_b);
  while(feof(file_a)==0 || feof(file_b)==0)
  {
    if(strcmp(aa,bb)!=0)
    {
      printf("line %d %s",lines,aa);
      printf("line %d %s",lines,bb);
    }
    lines++;
    fgets(aa, 80, file_a);
    fgets(bb, 80, file_b);
  }
  fclose(file_a);
  fclose(file_b);
  return 0;
}

