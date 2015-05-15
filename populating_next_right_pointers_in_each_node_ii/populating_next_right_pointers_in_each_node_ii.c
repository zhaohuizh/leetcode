/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  struct TreeLinkNode *left, *right, *next;
 * };
 *
 */

void connect(struct TreeLinkNode *root) {
  while(root){
    struct TreeLinkNode *curr = root;
    while(curr && !curr->left && !curr->right){
      curr = curr->next;
    }
    if(!curr){
      return;
    }
    struct TreeLinkNode *first_child;
    struct TreeLinkNode *prev;
    if(curr->left){
      first_child = curr->left;
      if(curr->right){
        curr->left->next = curr->right;
        prev = curr->right;
      }else{
        prev = curr->left;
      }
    }else{
      first_child = curr->right;
      prev = first_child;
    }
    curr = curr->next;
    while(curr){
      if(curr->left){
        prev->next = curr->left;
        prev = curr->left;
      }
      if(curr->right){
        prev->next = curr->right;
        prev = curr->right;
      }
      curr = curr->next;
    }
    root = first_child;
  }
}
