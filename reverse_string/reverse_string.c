#include<stdlib.h>
#include<string.h>
char* reverseString(char* s) {
  int j = strlen(s) - 1;
  int i = 0;
  char tmp;
  while (i < j){
    tmp = s[i];
    s[i++] = s[j];
    s[j--] = tmp;
  }
  return s;
}
