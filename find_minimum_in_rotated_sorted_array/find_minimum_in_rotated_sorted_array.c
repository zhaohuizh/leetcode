#include <stdio.h>

int find_min(int *nums, int size){
  int begin = 0;
  int end = size - 1;
  int mid;
  while(begin < end){
    if(nums[begin] < nums[end]){
      return nums[begin];
    }
    mid = (begin + end) >> 1;
    if(nums[mid] >= nums[begin]){
      begin = mid + 1;
    }
    if(nums[mid] <= nums[end]){
      end = mid;
    }
  }
  return nums[begin];
}

int main(){
  int nums[] = {1};
  int res = find_min(nums, 1);
  printf("%d\n", res);
  return 0;
}
