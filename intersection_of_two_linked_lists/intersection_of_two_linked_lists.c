/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB){
  struct ListNode *node1 = headA;
  struct ListNode *node2 = headB;
  int len1 = 0;
  int len2 = 0;
  while(node1){
    node1 = node1->next;
    len1++;
  }
  while(node2){
    node2 = node2->next;
    len2++;
  }
  int diff = 0;
  if(len1 > len2){
    diff = len1 - len2;
    node1 = headA;
    node2 = headB;
  }else{
    diff = len2 - len1;
    node1 = headB;
    node2 = headA;
  }
  while(diff){
    node1 = node1->next;
    diff--;
  }
  while(node1 && node2){
    if(node1 == node2){
      return node1;
    }
    node1 = node1->next;
    node2 = node2->next;
  }
  return 0;
}
