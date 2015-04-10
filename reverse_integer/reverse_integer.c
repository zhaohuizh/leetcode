#include <stdio.h>
int reverse(int x) {
  int res = 0;
  while(x){
    int tmp = res * 10 + x % 10;
    if(tmp / 10 != res){
      return 0;
    }
    res = tmp;
    x /= 10;
  }
  return res;
}

int main(){
  int res = reverse(123);
  printf("%d\n", res);
  res = reverse((0 - 123));
  printf("%d\n", res);
}
