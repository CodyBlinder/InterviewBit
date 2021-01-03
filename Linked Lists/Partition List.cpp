/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::partition(ListNode* A, int B) {
    ListNode* smallerHead = NULL;
    ListNode* smallerTail = NULL;
    ListNode* greaterHead = NULL;
    ListNode* greaterTail = NULL;
    
    while(A!=NULL){
        
        if(A->val < B){
            if(smallerHead == NULL){
                smallerHead = smallerTail = A;
            }
            else{
                smallerTail->next = A;
                smallerTail = A;
            }
        }
        else{
            if(greaterHead == NULL){
                greaterHead = greaterTail = A;
            }
            else{
                greaterTail->next = A;
                greaterTail = A;
            }
        }
        
        A = A->next;
    }
    
    if(greaterTail != NULL){
        greaterTail->next = NULL;
    }
    
    if(smallerHead == NULL){
        return greaterHead;
    }
    
    smallerTail->next = greaterHead;
    return smallerHead;
}
