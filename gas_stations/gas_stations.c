int canCompleteCircuit(int gas[], int cost[], int n) {
  int idx = 0;
  int total = 0, sum = 0;
  for(int i = 0; i < n; i++){
    int diff = gas[i] - cost[i];
    total += diff;
    sum += diff;
    if(sum < 0){
      idx = i + 1;
      sum = 0;
    }
  }
  if(total < 0){
    return -1;
  }
  return idx;
}
