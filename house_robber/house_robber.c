int max(int a, int b){
  return a > b ? a : b;
}
int rob(int num[], int n) {
  if(n == 0) return 0;
  if(n == 1) return num[0];
  int ret[n + 1];
  ret[0] = 0;
  ret[1] = num[0];
  int i;
  for(i = 2; i <= n; i++){
    ret[i] = max(ret[i - 1], ret[i - 2] + num[i - 1]);
  }
  return ret[n];
}
