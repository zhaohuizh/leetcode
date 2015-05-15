/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  struct TreeLinkNode *left, *right, *next;
 * };
 *
 */

//recursive
void connect(struct TreeLinkNode *root) {
  if(root){ 
    if(root->left){
      root->left->next = root->right;
      connect(root->left);
    }
    if(root->right){
      if(root->next){
        root->right->next = root->next->left;
      }
      connect(root->right);
    }
  } 
}

//non-recursive
void connect(struct TreeLinkNode *root){
  if(!root) return;
  while(root->left){
    struct TreeLinkNode *curr = root;
    while(curr){
      curr->left->next = curr->right;
      if(curr->next){
        curr->right->next = curr->next->left;
      }
      curr = curr->next;
    }
    root = root->left;
  }
}
