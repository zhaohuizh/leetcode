#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * Recursive methods but will exceed time limit
 */
int numDecodings_recur(char *s) {
  if(*s == '\0' || *(s + 1) == '\0'){
    return 1;
  }
  int val = (*s - '0') * 10 + *(s + 1) - '0';
  if(val > 26){
    return numDecodings_recur(s + 1);
  }else{
    return numDecodings_recur(s + 2) + numDecodings_recur(s + 1);
  }
}

int numDecodings(char *s){
  int len = strlen(s);
  if(len == 0){
    return 0;
  }
  int *dp = (int *) malloc(sizeof(int) * (len + 1));
  dp[len] = 1;
  if(*(s + len - 2) == '0'){
    dp[len - 1] = 0;
  }else{
    dp[len - 1] = 1;
  }
  int i;
  for(i = len - 2; i >= 0; i--){
    if(*(s + i) == '0') continue;
    int val = (*(s + i) - '0') * 10 + *(s + i + 1) - '0';
    dp[i] = val > 26 ? dp[i + 1] : dp[i + 1] + dp[i + 2];
  }
  return dp[0];
}

int main(){
  char *s = "00";
  printf("%d\n", strlen(s));
  int res = numDecodings(s);
  printf("%d\n", res);
}
