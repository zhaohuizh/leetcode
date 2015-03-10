#include<string.h>

int decoding(char *s, int i, int *num){
    if(num[i]){
        return num[i];
    }
    if(*(s + i) == '\0' || *(s + i + 1) == '\0'){
        num[i] = 1;
        return 1;
    }
    int ret = 0;
    int twoValue = (*(s + i) - '0') * 10 + *(s + i + 1) - '0';
    if(*(s + i) == '0' && twoValue > 26){
        ret = decoding(s, i + 1, num);
    }else{
        ret = decoding(s, i + 1, num) + decoding(s, i + 2, num);
    }
    num[i] = ret;
    return ret;
}

int numDecodings(char *s) {
    if(*s == '\0'){
        return 0;
    }
    size_t len = strlen(s);
    int num[len];
    return decoding(s, 0, num);
}
