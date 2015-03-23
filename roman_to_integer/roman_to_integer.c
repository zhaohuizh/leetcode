int value(char c){
    switch(c){
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default: return 0;
    }
}

int romanToInt(char *s) {
    int ret = 0;
    char next = *s;
    while(*s && *(s + 1)){
        int val = value(*s);
        int val_next = value(*(s + 1));
        if(val_next > val){
            ret += (val_next - val);
            s += 2;
        }else{
            ret += val;
            s++;
        }
    }
    if(*s)
        ret += value(*s);
    return ret;
}
