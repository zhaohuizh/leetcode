#include <string.h>
#include <stdbool.h>
#include <ctype.h>

bool alphanumeric(char c){
  if(c >= 'a' && c <= 'z'){
    return true;
  }
  if(c >= 'A' && c <= 'Z'){
    return true;
  }
  if(c >= '0' && c <= '9'){
    return true;
  }
  return false;
}

bool is_same(char c, char s){
  return c == s || tolower(c) == tolower(s);
}

bool isPalindrome(char* s) {
  int len = strlen(s);
  int i = 0;
  int j = len - 1;
  while(i < j){
    while(i < j && !alphanumeric(*(s + i))){
      i++;
    }
    while(i < j && !alphanumeric(*(s +j))){
      j--;
    }
    if(i >= j) break;
    if(is_same(*(s + i), *(s + j))){
      i++;
      j--;
    }else{
      return false;
    }
  }
  return true;
}

