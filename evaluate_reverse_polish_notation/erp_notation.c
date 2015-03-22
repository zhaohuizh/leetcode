#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

int get_result(int v1, int v2, char c){
    switch(c){
        case '+':
            return v1 + v2;
        case '-':
            return v1 - v2;
        case '*':
            return v1 * v2;
        case '/':
            return v1 / v2;
        default:
            assert(0); 
    }
}

int evalRPN(char *tokens[], int n) {
    int result[n];
    int i = 0;
    int j = 0;
    for(; j < n; j++){
        char *c = tokens[j];
        if(!strcmp(c, "+") || !strcmp(c, "-")  || !strcmp(c, "*")|| !strcmp(c, "/")){
            int v2 = result[--i];
            int v1 = result[--i];
            int ret = get_result(v1, v2, *c);
            result[i++] = ret;
        }else{
            result[i++] = atoi(c);
        }
    }
    return result[0];
}

int main(){
    char *tokens[] = {"-78","-33","196","+","-19","-","115","+","-","-99","/","-18","8","*","-86","-","-","16","/","26","-14","-","-","47","-","101","-","163","*","143","-","0","-","171","+","120","*","-60","+","156","/","173","/","-24","11","+","21","/","*","44","*","180","70","-40","-","*","86","132","-84","+","*","-","38","/","/","21","28","/","+","83","/","-31","156","-","+","28","/","95","-","120","+","8","*","90","-","-94","*","-73","/","-62","/","93","*","196","-","-59","+","187","-","143","/","-79","-89","+","-"};
    int ret = evalRPN(tokens, 105);
    printf("result: %d\n", ret);
    return 0;
}
