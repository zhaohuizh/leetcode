#include <stdlib.h>
#include <stdio.h>

int *plusOne(int *digits, int len, int *newLen){
  int *res = (int *)malloc(sizeof(int) * (len + 1));
  int carry = 1;
  int i;
  for(i = len - 1; i >= 0; i--){
    if(digits[i] == 9 && carry == 1){
      res[i + 1] = 0;
    }else{
      res[i + 1] = digits[i] + carry;
      carry = 0;
    }
  }
  if(carry == 1){
    res[0] = 1;
    *newLen = len + 1;
    return res;
  }else{
    *newLen = len;
    return res + 1;
  }
}

int main(){
  int *digits = (int *) malloc (sizeof(int) * 2);
  digits[0] = 4;
  int newLen = 0;
  int *res = plusOne(digits, 1, &newLen);
  printf("len: %d\n", newLen);
  printf("num: %d\n", *res);
}
