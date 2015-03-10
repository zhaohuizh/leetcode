#include<string.h>
#include<stdlib.h>
#include<stdio.h>
/* Return the list of permutation results */

/* *numRows stores the number of permutation arrays */

void swap_number(int numbers[], int i, int j){
    int temp = numbers[i];
    numbers[i] = numbers[j];
    numbers[j] = temp;
}


void permute_recur(int numbers[], int start, 
  int n, int **ret, int *numRows){
    if(start == n - 1){
        int *one = (int *) malloc(sizeof(int) * n);
        memcpy(one, numbers, sizeof(int) * n);
        ret[(*numRows)++] = one;
        return;
    }
    int j = start;
    for(; j < n; j++){
        swap_number(numbers, start, j);
        permute_recur(numbers, start + 1, n, ret, numRows);
        swap_number(numbers, start, j);
    }
}

int factor(int n){ 
  int ret = 1;  
  int i = 1;
  for(i = 1; i <= n; i++){
      ret *= i;
  }   
  return ret;
}

int **permute(int numbers[], int n, int *numRows) {
    int **ret = (int **) malloc(sizeof(int *) * factor(n));
    permute_recur(numbers, 0, n, ret, numRows);
    return ret;
}

int main(){
    int numbers[] = {1, 2, 3};
    int n = 3;
    int rows = 0;
    int **ret = permute(numbers, n, &rows);
    int i = 0;
    for(; i < rows; i++){
        for(int j = 0; j < n; j++)
            printf("%d ", ret[i][j]);
        printf("\n");
    }
    return 0;
} 
