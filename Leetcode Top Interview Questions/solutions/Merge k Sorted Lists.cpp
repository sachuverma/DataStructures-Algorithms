/*23. Merge k Sorted Lists


You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.

 

Example 1:

Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list:
1->1->2->3->4->4->5->6 */


class Solution {
public:
    
    
     ListNode* merge(ListNode*l1 , ListNode*l2){
       ListNode* tmp = new ListNode(0); 
       ListNode*sort = tmp;
       
       while(l1 && l2){
           if(l1->val > l2->val){
               sort->next= l2;
               l2=l2->next;
           }else {
               sort->next=l1;
               l1= l1->next;
           }
           
           sort = sort->next;
       }
       
       if(l1 != NULL){
           sort->next=l1;
           l1=l1->next;
       }
       
        if(l2 != NULL){
           sort->next=l2;
           l2=l2->next;
       }
       
       return tmp->next;
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0) return NULL; 
        ListNode* head = lists[0]; 
        
        for(int i = 1 ; i < lists.size(); i++){
            head = merge(head, lists[i]); 
        }
        
        return head; 
    }
};