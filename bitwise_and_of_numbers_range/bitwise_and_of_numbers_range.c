#include <stdio.h>
int rangeBitwiseAnd(int m, int n) {
  int res = 0;
  int i;
  for(i = 31; i >= 0; i--){
    if(((m >> i) & 1) == ((n >> i) & 1)){
      res = (res << 1) + ((m >> i) & 1);
    }else{
      break;
    }
  }
  return res << (i + 1);
}

int range_bitwise_and(int m, int n){
  int i = 0;
  while (m != n){
    m >>= 1;
    n >>= 1;
    i++;
  }
  return m << i;
}

int main(){
  int m = 3;
  int n = 6;
  int res = rangeBitwiseAnd(m, n);
  printf("res: %d\n", res);
}
