/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
ListNode* head;

void reverse(ListNode* A){
    
    if(A->next == NULL){
        head = A;
        return;
    }
    
    reverse(A->next);
    
    ListNode* temp = A->next;
    temp->next = A;
    A->next = NULL;
}
 
ListNode* Solution::reverseList(ListNode* A) {
    
    ListNode* temp = A;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    
    reverse(A);
    
    return temp;
}
