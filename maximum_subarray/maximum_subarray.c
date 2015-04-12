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

/**
 * divide and conquer
 */
int max(int a, int b){
  return a > b ? a : b;
}

int max_cross_sum(int A[], int begin, int end){
  int mid = (begin + end) / 2;
  int sum = 0;
  int max_left = INT_MIN;
  int i;
  for(i = mid; i >= begin; i--){
    sum += A[i];
    max_left = max(sum, max_left);
  }
  int max_right = INT_MIN;
  sum = 0;
  for(i = mid + 1; i <= end; i++){
    sum += A[i];
    max_right = max(sum, max_right);
  }
  return max_left + max_right;
}
int max_subarray_helper(int A[], int begin, int end){
  if(begin == end){
    return A[begin];
  }
  int mid = (begin + end) / 2;
  return max(max_cross_sum(A, begin, end),
             max(max_subarray_helper(A, begin, mid), max_subarray_helper(A, mid + 1, end)));
}

int max_subarray(int A[], int n){
  return max_subarray_helper(A, 0, n - 1);
}

int main(){
  int A[9] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
  int res = maxSubArray(A, 9);
  return 0;
}
