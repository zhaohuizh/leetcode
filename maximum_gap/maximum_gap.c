#include <limits.h>

int maximumGap(int num[], int n) {
  int min = INT_MAX, max = 0;
  int i;
  for(i = 0; i < n; i++){
    if(num[i] > max){
      max = num[i];
    }else if(num[i] < min){
      min = num[i];
    }
  }
}
