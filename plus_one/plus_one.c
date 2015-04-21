#include <stdlib.h>
#include <stdio.h>

int *plusOne(int *digits, int len, int *newLen){
  int i;
  for(i = len - 1; i >= 0; i--){
    if(digits[i] == 9){
      digits[i] = 0;
    }else{
      digits[i]++;
      break;
    }
  }
  if(digits[0] == 0){
    int *res = (int *)malloc(sizeof(int) * (len + 1));
    for(i = len; i > 0; i--){
      res[i] = digits[i - 1];
    }
    res[0] = 1;
    *newLen = len + 1;
    return res;
  }else{
    *newLen = len;
    return digits;
  }
}

int main(){
  int *digits = (int *) malloc (sizeof(int) * 2);
  digits[0] = 9;
  digits[1] = 9;
  int newLen = 0;
  int *res = plusOne(digits, 2, &newLen);
  printf("len: %d\n", newLen);
  printf("num: %d%d%d\n", res[0], res[1], res[2]);
}
