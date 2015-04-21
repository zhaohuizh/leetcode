#include <string.h>
#include <stdio.h>

int lengthOfLastWord(char* s) {
  int len = strlen(s);
  int i = len - 1;
  int res = 0;
  while(i >= 0 && *(s + i) == ' '){
    i--;
  }
  while(i >= 0 && *(s + i) != ' '){
    res++;
    i--;
  }
  return res;
}

int main(){
  char *s = "h";
  printf("%d\n", lengthOfLastWord(s));
  printf("%d\n", lengthOfLastWord("hello world  "));
  return 0;
}
