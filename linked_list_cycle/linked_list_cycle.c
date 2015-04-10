#include <stdbool.h>
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

bool hasCycle(struct ListNode *head) {
  if(!head) return false;
  struct ListNode *fast = head;
  struct ListNode *slow = head->next;
  while(slow && slow->next){
    if(fast == slow){
      return true;
    }
    fast = fast->next;
    slow = slow->next->next;
  }
  return false;
}
