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
        A = A->next;
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

ListNode* Solution::reorderList(ListNode* A) {
    
    ListNode* head = A;
    
    int n = length(A);
    int sol_factor;
    if(n%2==0){
        sol_factor=n/2;
    }
    else{
        sol_factor=(n/2)+1;
    }
    
    ListNode* curr = A;
    for(int i=0;i<sol_factor;i++){
        curr = curr->next;
    }
    
    ListNode* B = reverse(curr);
    
    ListNode* temp;                
    while(B!=NULL){           // merging the two lists as required
        temp = A->next;
        A->next = B;
        A = temp;
        temp = B->next;
        B->next = A;
        B = temp;
    }
    
    A->next = NULL;
    
    return head;
    
    /******************** a simple solution but time complexity -> O(n^2) *******************/
    
    if(A==NULL){
        return A;
    }
    
    ListNode* temp = A;
    
    while(temp->next!=NULL){
        temp->next = reverse(temp->next);
        temp = temp->next;
    }
    
    return A;
}
