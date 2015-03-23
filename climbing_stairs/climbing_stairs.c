int climbStairs(int n) {
    if(n == 0) return 0;
    if(n == 1) return 1;
    int ret[n + 1];
    ret[0] = 1;
    ret[1] = 1;
    int i;
    for(i = 2; i <= n; i++){
        ret[i] = ret[i - 1] + ret[i - 2];
    }
    return ret[n];
}
