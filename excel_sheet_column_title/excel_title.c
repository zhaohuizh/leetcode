char *convertToTitle(int n) {
    int len = 0;
    int n_copy = n;
    while(--n_copy > -1){
        n_copy /= 26;
        len++;
    }
    char * ret = (char *) malloc(sizeof(char) * (len + 1));
    ret[len] = '\0';
    while(--n > -1){
        ret[--len] = n % 26 + 'A';
        n /= 26;
    }
    return ret;
}
