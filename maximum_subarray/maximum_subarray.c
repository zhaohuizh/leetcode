#include <limits.h>
int maxSubArray(int A[], int n) {
  int res = INT_MIN, max = 0;
  int i;
  for(i = 0; i < n; i++){
    max += A[i];
    res = max > res ? max : res;
    if(max <= 0){
      max = 0;
    }
  }
  return res;
}

int main(){
  int A[9] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
  int res = maxSubArray(A, 9);
  return 0;
}
