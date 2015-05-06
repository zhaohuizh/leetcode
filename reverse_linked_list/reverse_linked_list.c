/**
 * Definition for singly-linked list.
 */
struct ListNode {
  int val;
  struct ListNode *next;
};
 

// recursive
struct ListNode *reverse(struct ListNode *head) {
  if(head == 0 || head->next == 0) return head;
  struct ListNode *next = head->next;
  struct ListNode *res = reverse(next);
  next->next = head;
  head->next = 0;
  return res;
}

//iteratively
struct ListNode *reverseList(struct ListNode *head){
  struct ListNode *new_head = 0;
  while(head){
    struct ListNode *next = head->next;
    head->next = new_head;
    new_head = head;
    head = next;
  }
  return new_head;
}

