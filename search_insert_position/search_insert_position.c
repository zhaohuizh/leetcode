#include <stdio.h>

int searchInsert(int A[], int n, int target) {
  int start = 0;
  int end = n;
  int mid;
  while(start < end){
    mid = (start + end) >> 1;
    if(A[mid] == target){
      return mid;
    }
    if(A[mid] > target){
      end = mid;
    }else{
      start = mid + 1;
    }
  }
  return end;
}

int main(){
  int A[] = {1, 3, 5, 6};
  int res = searchInsert(A, 4, 5);
  printf("%d\n", res);
  res = searchInsert(A, 4, 2);
  printf("%d\n", res);
  res = searchInsert(A, 4, 7);
  printf("%d\n", res);
  res = searchInsert(A, 4, 0);
  printf("%d\n", res);

}
