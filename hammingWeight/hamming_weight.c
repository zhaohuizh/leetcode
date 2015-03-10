int hammingWeight(uint32_t n) {
    int ret = 0;
    int i;
    for(i = 0; i < 32; i++){
        ret += (n >> i) & 1;
    }
    return ret;
}
