ListNode* reverse(ListNode* A,int n){
    
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
 
ListNode* Solution::reverseList(ListNode* A, int B) {
    
    if(A==NULL){
        return A;
    }
    
    ListNode* newHead;
    
    ListNode* curr = A;
    ListNode* prev = NULL;
    ListNode* next = A;
    
    while(curr!=NULL){
        
        for(int j=0;j<B;j++){
            next = next->next;
        }
        
        if(prev == NULL){
            curr = reverse(curr,B);
            newHead = curr;
        }
        else{
            prev->next = reverse(curr,B);
            curr = prev->next;
        }
        
        while(curr->next != NULL){
            prev = curr;
            curr = curr->next;
        }
        
        curr->next = next;
        prev = curr;
        curr = curr->next;
    }
    
    return newHead;
}
