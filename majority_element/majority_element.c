int majorityElement(int num[], int n){
  int diff = 0, res;
  for(int i = 0; i < n; i++){
    if(diff == 0) res = num[i];
    if(res == num[i]){
      diff++;
    }else{
      diff--;
    }
  }
  return res;
}
