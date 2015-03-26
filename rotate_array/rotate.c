void rotate(int nums[], int n, int k) {
    int tmps[n];
    int i;
    k = k % n;
    for(i = 0; i < n; i++){
        tmps[i] = nums[i];
    }
    for(i = 0; i < n; i++){
        nums[i] = tmps[(i + n - k) % n]; 
    }
}
