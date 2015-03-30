#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int compare(char *n, char *m){
  int len_n = strlen(n);
  int len_m = strlen(m);
  int min_len = len_n < len_m ? len_n : len_m;
  if(min_len == 0){
    return len_n - len_m;
  }
  char *n_copy = n;
  char *m_copy = m;
  while(min_len){
    if(*n_copy > *m_copy){
      return 1;
    }else if(*n_copy < *m_copy){
      return -1;
    }
    n_copy++;
    m_copy++;
    min_len--;
  } if(len_n < len_m){ return compare(n, m_copy);
  }else{
    return compare(n_copy, m);
  }
}

void swap(char **a, char **b){
  char *tmp = *a;
  *a = *b;
  *b = tmp;
}

char *largestNumber(int *num, int n) {
  int i; int j;
  char *array[n];
  int len;
  for(i = 0; i < n; i++){
    char *buffer = malloc(6 * sizeof(char));
    sprintf(buffer, "%d" ,num[i]);
    array[i] = buffer;
    len += strlen(buffer);
  }
  for(i = 0; i < n; i++){
    for(j = 1; j < n - i; j++){
      if(compare(array[j - 1],array[j]) < 0){
        swap(&array[j - 1], &array[j]); 
      }
    }
  }
  char *ret = malloc(sizeof(char) * len);
  if(*array[0] == '0'){
    ret[0] = '0';
    return ret;
  }
  len = 0;
  for(i = 0; i < n; i++){
    strcpy(ret + len, array[i]);
    len += strlen(array[i]);
  }
  return ret;
}

int main(){
  int num[] = {3, 30, 34, 5, 9};
  char *ret = largestNumber(num, 5);
  printf("%s \n", ret);
}
