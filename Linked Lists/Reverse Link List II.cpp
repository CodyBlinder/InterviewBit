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
     while(A!=0){
         count++;
         A = A->next;
     }
     return count;
 }
 
 ListNode* reverseSegment(ListNode* A,int n){
     
     ListNode* curr = A;
     ListNode* prev = NULL;
     ListNode* next;
     
     for(int i=0;i<n;i++){
         next = curr->next;
         curr->next = prev;
         prev = curr;
         curr = next;
     }
     
     return prev;
 }
 
ListNode* Solution::reverseBetween(ListNode* A, int B, int C) {
    
    if(A==NULL){
        return A;
    }
    
    if(C-B+1 == length(A)){
        return reverseSegment(A,length(A));
    }
    
    ListNode* curr = A;
    ListNode* prev = NULL;
    for(int i=0;i<B-1;i++){
        prev = curr;
        curr = curr->next;
    }
    
    ListNode* temp = A;
    for(int i=0;i<C;i++){
        temp = temp->next;
    }
    
    ListNode* rev_head = reverseSegment(curr,C-B+1);
    
    if(B>=2){
        prev->next = rev_head;
        while(prev->next!=NULL){
            prev = prev->next;
        }
        prev->next = temp;
        
        return A;
    }
    else{
        ListNode* var = rev_head;
        while(var->next!=NULL){
            var = var->next;
        }
        var->next = temp;
        
        return rev_head;
    }
}
