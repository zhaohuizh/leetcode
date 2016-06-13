int missingNumber(int* nums, int numsSize) {
  int ret = 0;
  for(int i = 0; i < numsSize; ++i){
    ret += i - nums[i];
  }
  return ret + numsSize;
}
