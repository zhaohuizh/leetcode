#include <stdbool.h>
#include <stdio.h>

bool canJump(int A[], int n){
  int max_dis = 0;
  int i;
  for(i = 0; i < n; i++){
    if(i > max_dis){
      return false;
    }
    if(A[i] + i > max_dis){
      max_dis = A[i] + i;
    }
    if(max_dis > n - 1){
      return true;
    }
  }
}

int main(){
  int A[] = {2, 3, 1, 1, 4};
  bool ret = canJump(A, 5);
  printf("%d\n", ret);
  int B[] = {3, 2, 1, 0, 4};
  ret = canJump(B, 5);
  printf("%d\n", ret);

}
