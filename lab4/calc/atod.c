#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>


int atod(const char *number) {
int num=0;
int temp = 1;
int len = strlen(number);
int i;
for(i=len;  i>0; i--)
  {
    num = (int)num+((number[i-1]-'0')*temp);
    temp = temp*10;
  }
  return num;
}