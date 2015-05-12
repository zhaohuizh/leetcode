#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <stdio.h>

bool isIsomorphic(char* s, char* t) {
  int len = strlen(s);
  int *dis = (int *)malloc(sizeof(int) * 256);
  int *dis2 = (int *)malloc(sizeof(int) * 256);
  int i;
  for(i = 0; i < 256; ++i){
    dis[i] = INT_MIN;
    dis2[i] = INT_MIN;
  }
  for(i = 0; i < len; ++i){
    if(dis[s[i]] == INT_MIN){
      dis[s[i]] = t[i];
    }else if(dis[s[i]] != t[i]){
      return false;
    }
    if(dis2[t[i]] == INT_MIN){
      dis2[t[i]] = s[i];
    }else if(dis2[t[i]] != s[i]){
      return false;
    }
  }
  return true;
}

int main(){
  char *s = "qwertyuiop[]asdfghjkl;'\\zxcvbnm,./";
  char *t = "',.pyfgcrl/=aoeuidhtns-\\;qjkxbmwvz";
  bool res = isIsomorphic(s, t);
  printf("res %d\n", res);
}
