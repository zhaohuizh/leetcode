int numTrees(int n) {
  int res[n + 1];
  res[0] = 1;
  int i, j;
  for(i = 1; i <= n; i++){
    int sum = 0;
    for(j = 0; j < i; j++){
      sum += res[j] * res[i - j - 1];
    }
    res[i] = sum;
  }
  return res[n];
}
