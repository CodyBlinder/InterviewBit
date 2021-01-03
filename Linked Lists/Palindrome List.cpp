/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
int length(ListNode* A){
    int count=0;
    while(A!=NULL){
        count++;
        A= A->next;
    }
    
    return count;
}
 
ListNode* reverse(ListNode* A){
    ListNode* curr = A;
    ListNode* prev = NULL;
    ListNode* next;
    
    while(curr!=NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    
    return prev;
}
 
int Solution::lPalin(ListNode* A) {
    
    if(A == NULL){
        return 0;
    }
    
    int n = length(A);
    if(n==1){
        return 1;
    }
    
    ListNode* curr = A;
    ListNode* prev = NULL;
    
    for(int i=0;i<n/2;i++){
        prev = curr;
        curr = curr->next;
    }
    
    prev->next = reverse(curr);
    prev = prev->next;
    
    for(int i=0;i<n/2;i++){
        if(A->val != prev->val){
            return 0;
        }
        A = A->next;
        prev = prev->next;
    }
    
    return 1;
}
