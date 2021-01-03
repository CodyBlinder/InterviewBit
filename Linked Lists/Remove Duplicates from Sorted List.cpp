/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::deleteDuplicates(ListNode* A) {
    
    if(A == NULL || A->next == NULL){
        return A;
    }
    
    ListNode* head = A;
    
    while(A->next!=NULL){
        if(A->val == A->next->val){
            ListNode* temp = A->next;
            A->next = A->next->next;
            delete(temp);
        }
        else{
            A = A->next;
        }
    }
    
    return head;
}
