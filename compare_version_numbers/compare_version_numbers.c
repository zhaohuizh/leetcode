#include <stdio.h>

int compareVersion(char *version1, char *version2){
  int val1 = 0, val2 = 0;
  while(*version1 || *version2){
    while(*version1 && *version1 != '.'){
      val1 = val1 * 10 + *version1 - '0';
      version1++;
    }
    while(*version2 && *version2 != '.'){
      val2 = val2 * 10 + *version2 - '0';
      version2++;
    }
    if(val1 > val2) return 1;
    else if(val1 < val2) return -1;
    if(*version1)
      version1++;
    if(*version2)
      version2++;
    val1 = 0;
    val2 = 0;
  }
  return 0;
}

int main(){
  char *a = "01";
  char *b = "1";
  int res = compareVersion(a, b);
  printf("res: %d\n", res);
}
