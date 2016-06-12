#include<string.h>
int is_vowel(char c){
  int k;
  k = c >= 'a' ?  c - 'a' : c - 'A';
  return k == 0 || k == 4 || k == 8
    || k == 14 || k == 20;
}
char* reverse_vowels(char *s){
  int i = 0;
  int j = strlen(s) - 1;
  char c;
  while(i < j){
    if(! is_vowel(s[i])){
      i++;
    }else if(! is_vowel(s[j])){
      j--;
    }else{
      c = s[i];
      s[i++] = s[j];
      s[j--] = c;
    }
  }
  return s;
}
