#include <string.h>
#include <stdio.h>
int titleToNumber(char *s) {
  int res = 0;
  while(*s){
    res = res * 26 + (*s - 'A' + 1);
    s++;
  }
  return res;
}

int main(){
  char *s = "Z";
  int res = titleToNumber(s);
  printf("%d\n", res);
}
