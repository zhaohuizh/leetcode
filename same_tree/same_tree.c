/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int isSameTree(struct TreeNode *p, struct TreeNode *q) {
  if(!p && !q){
    return 1;
  }
  if(p && q && p->val == q->val){
    return isSameTree(p->left, q->left) 
        && isSameTree(p->right, q->right);
  }
  return 0;
}
