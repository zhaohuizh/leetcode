void sortColors(int A[], int n) {
  int white = 0;
  int blue = 0;
  int i;
  for(i = 0; i < n; i++){
    if(A[i] == 0){
      A[i] = 2;
      A[blue++] = 1;
      A[white++] = 0;
    }else if(A[i] == 1){
      A[i] = 2;
      A[blue++] = 1;
    }
  }
}
