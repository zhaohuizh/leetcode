#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int countPrimes(int n) {
  int *flag = (int *) malloc(sizeof(int) * n);
  int i;
  for(i= 0; i < n; ++i){
    flag[i] = 1;
  }
  for(i = 2; i < sqrt(n); ++i){
    if(flag[i] == 0){
      continue;
    }
    int j = 2;
    while(j * i < n){
      flag[j * i] = 0;
      j++;
    }
  }

  int res = 0;
  for(i = 2; i < n; ++i){
    if(flag[i] == 1){
      res++;
    }
  }
  return res;
}

int main(){
  int n = 5;
  int res = countPrimes(n);
  printf("res : %d\n", res);
}
