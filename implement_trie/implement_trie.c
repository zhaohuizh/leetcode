#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct TrieNode {
  bool is_last;
  struct TrieNode **children;
};

/** Initialize your data structure here. */
struct TrieNode* trieCreate() {
  struct TrieNode *head = 
    (struct TrieNode *)malloc(sizeof(struct TrieNode)); 
  head->is_last = false;
  head->children = (struct TrieNode **) malloc(sizeof(struct TrieNode *));
  return head;
}

/** Inserts a word into the trie. */
void insert(struct TrieNode* root, char* word) {
  struct TrieNode *curr = root;
  while(*word){
    int idx = *word - 'a';
    if(curr->children[idx] == 0){
      curr->children[idx] = trieCreate();
    }
    curr = curr->children[idx];
    word++;
  }
  curr->is_last = true;
}

/** Returns if the word is in the trie. */
bool search(struct TrieNode* root, char* word) {
  struct TrieNode *curr = root;
  if(!root) return false;
  while(*word){
    int idx = *word - 'a';
    if(curr->children[idx] == 0){
      return false;
    }
    word++;
    curr = curr->children[idx];
  }
  return curr->is_last;
}

/** Returns if there is any word in the trie 
    that starts with the given prefix. */
bool startsWith(struct TrieNode* root, char* prefix) {
  struct TrieNode *curr = root;
  if(!root) return false;
  while(*prefix){
    int idx = *prefix - 'a';
    if(curr->children[idx] == 0){
      return false;
    }
    prefix++;
    curr = curr->children[idx];
  }
  return true;
}

/** Deallocates memory previously allocated for the TrieNode. */
void trieFree(struct TrieNode* root) {
  if(!root) return;
  int i;
  for(i = 0; i < 26; i++){
    struct TrieNode *child = root->children[i];
    trieFree(child);
  }
  free(root);
}

// Your Trie object will be instantiated and called as such:
// struct TrieNode* node = trieCreate();
// insert(node, "somestring");
// search(node, "key");
// trieFree(node);
//
int main(){
  struct TrieNode *node = trieCreate();
  bool res = search(node, "a");
  printf("res: %d\n", res);
  insert(node, "abc");
  res = search(node, "ab");
  printf("res: %d\n", res);
  res = search(node, "abc");
  printf("res: %d\n", res);
  res = startsWith(node, "ab");
  printf("res: %d\n", res);
  return 0;
}
