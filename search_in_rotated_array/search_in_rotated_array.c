int search(int A[], int n, int target) {
  int left = 0;
  int right = n - 1;
  int mid;
  while(left <= right){
    mid = (left + right) >> 1;
    if(A[mid] == target){
      return mid;
    }
    if(A[mid] >= A[left]){
      if(A[mid] > target && A[left] <= target){
        right = mid - 1;
      }else{
        left = mid + 1;
        }
    }else{
      if(A[mid] < target && A[right] >= target){
        left = mid + 1;
      }else{
        right = mid - 1;
      }
    }
  }
  return -1;
}
