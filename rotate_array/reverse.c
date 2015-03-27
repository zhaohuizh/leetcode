void reverse(int nums[], int l, int r) {
  int temp;
  while(l < r) {
    temp = nums[l];
    nums[l++] = nums[r];
    nums[r--] = temp;
  }
}

void rotate(int nums[], int n, int k) {
  if(k == 0) return;
  k %= n;
  reverse(nums, 0, n - 1);
  reverse(nums, 0, k - 1);
  reverse(nums, k, n - 1);
}
