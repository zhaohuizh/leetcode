/* Return the list of permutation results */

/* *numRows stores the number of permutation arrays */

int **permute(int numbers[], int n, int *numRows) {
    int **ret;
    permute(numbers[], 0, n, ret, numRows);
    return ret;
}



void swap(int numbers[], int i, int j){
    int temp = numbers[i];
    numbers[i] = numbers[j];
    numbers[j] = temp;
}



void permute(int numbers[], int start, 
  int n, int **ret, int *numRows){
    if(start == n - 1){
        memcpy(ret[numRows++], numbers, n);
        return;
    }
    int j;
    for(j = start; j < n, j++){
        swap(numbers, start, j);
        permute(numbers, start + 1, n, ret, numRows);
        swap(numbers, start, j);
    }
}
