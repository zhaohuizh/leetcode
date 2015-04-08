#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool isLeft(char c){
  return c == '(' || c == '[' || c == '{';
}

bool isRight(char c){
  return c == ')' || c == ']' || c == '}';
}

bool match(char a, char b){
  switch(a){
    case '(':
      return b == ')';
    case '{':
      return b == '}';
    case '[':
      return b == ']';
    default:
      return false;
  }
}

bool isValid(char *s) {
  int len = strlen(s);
  char *stack = malloc(len);
  int idx = 0;
  while(*s){
    if(isLeft(*s)){
      stack[idx++] = *s;
    }else if(isRight(*s) && 
        (match(stack[idx - 1], *s))){
      idx--;
    }else{
      return false;
    }
    s++;
  }
  return idx == 0;
}

int main(){
  char *s = "(()[]){}";
  bool res = isValid(s);
  printf("%d\n", res);
}
