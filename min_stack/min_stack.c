#include <stdlib.h>
#include <limits.h>
#include <stdio.h>

typedef struct {
  int size;
  int idx;
  int *array;
  int *min_array;
  int min_idx;
} MinStack;

void minStackCreate(MinStack *stack, int maxSize) {
  stack->size = maxSize;
  stack->idx = 0;
  stack->min_idx = 0;
  stack->array = (int *)malloc(sizeof(int) * maxSize);
  stack->min_array = (int *)malloc(sizeof(int) * maxSize);
}

void minStackPush(MinStack *stack, int element) {
  if(stack->idx < stack->size){
    stack->array[stack->idx++] = element;
    if(stack->min_idx == 0 || 
       stack->min_array[stack->min_idx - 1] >= element){
       stack->min_array[stack->min_idx++] = element;
    }
  }
}

void minStackPop(MinStack *stack) {
  if(stack->idx > 0){
    if(stack->array[stack->idx - 1] == 
        stack->min_array[stack->min_idx - 1]){
      stack->min_idx--;
    }
    stack->idx--;
  }
}

int minStackTop(MinStack *stack) {
  if(stack->idx > 0){
    return stack->array[stack->idx - 1];
  }
  return INT_MIN;
}

int minStackGetMin(MinStack *stack) {
  if(stack->min_idx > 0){
    return stack->min_array[stack->min_idx - 1];
  }
  return INT_MIN;
}

void minStackDestroy(MinStack *stack) {
  free(stack->array);
  free(stack->min_array);
  free(stack);
}

int main(){
  MinStack *stack = (MinStack *)malloc(sizeof(MinStack));
  minStackCreate(stack, 5);
  minStackPush(stack, -1);
  printf("size: %d\n", stack->idx);
  printf("top: %d\n", minStackTop(stack));
  printf("min: %d\n", minStackGetMin(stack));
  minStackDestroy(stack);
  return 0;
}
