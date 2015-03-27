#include <stdio.h>

int cal_greatest_common_divider(int a, int b){
    int c;
    while(b){
        c = b;
        b = a % b;
        a = c;
    }
    return a; 
}

void rotate(int nums[], int n, int k) {
    if(k <= 0){
        return;
    }
    k = k % n;
    int maxTry = cal_greatest_common_divider(n, k);
    int i;
    int temp;
    for(i = 0; i < maxTry; i++){
        temp = nums[i];
        int j = i;
        do{
            int target = (j + n - k) % n;
            if(target == i){
                nums[j] = temp;
                break;
            }
            nums[j] = nums[target];
            j = target;
        }while(1);
    }
}
