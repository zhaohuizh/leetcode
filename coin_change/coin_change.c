#include <limits.h>

int coinChange(int* coins, int coinsSize, int amount) {
  int changes[amount + 1];
  changes[0] = 0;
  for (int i = 1; i <= amount; ++i){
    int min = INT_MAX, temp;
    for(int j = 0; j < coinsSize; ++j){
      if(i >= coins[j] && (temp = changes[i - coins[j]]) > -1 && min > temp + 1){
        min = temp + 1;
      }
    }
    changes[i] = min == INT_MAX ? -1 : min;
  }
  return changes[amount];
}
