/*
Sort List
=========

Given the head of a linked list, return the list after sorting it in ascending order.

Follow up: Can you sort the linked list in O(n logn) time and O(1) memory (i.e. constant space)?

 
Example 1:
Input: head = [4,2,1,3]
Output: [1,2,3,4]

Example 2:
Input: head = [-1,5,3,4,0]
Output: [-1,0,3,4,5]

Example 3:
Input: head = []
Output: []
 

Constraints:
The number of nodes in the list is in the range [0, 5 * 104].
-105 <= Node.val <= 105
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
  ListNode* merge(ListNode* head1, ListNode* head2){
    ListNode* sorted_new = new ListNode();
    auto curr = sorted_new;
    
    while(head1!=NULL && head2!=NULL){
      if(head1->val < head2->val){
        curr->next = head1;
        head1 = head1->next;
      } else {
         curr->next = head2;
        head2 = head2->next;
      }
      curr = curr->next;
    }
    
    if(head1!=NULL) curr->next = head1;
    if(head2!=NULL) curr->next = head2;
      
    
    return sorted_new->next;
  }
  
public:
    ListNode* sortList(ListNode* head) {
      if(head==NULL || head->next==NULL) return head;
      
      auto temp = head, slow = head, fast = head;
      while(fast && fast->next){
        temp = slow;
        slow = slow->next;
        fast = fast->next->next;
      }
      
      temp->next = NULL;
      auto left = sortList(head);
      auto right = sortList(slow);
      
      return merge(left,right);
      
    }
};

