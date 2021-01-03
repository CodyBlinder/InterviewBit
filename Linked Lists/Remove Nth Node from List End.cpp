/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::removeNthFromEnd(ListNode* A, int B) {
    
    if(A == NULL) return NULL;
    
    ListNode* back = A;
    ListNode* front = A;
    for(int i=0;i < B && front != NULL;i++){
        front = front->next;
    }
    
    if(front == NULL) return back->next;
    
    while(front != NULL && front->next != NULL){
        front = front->next;
        back = back->next;
    }
    
    ListNode* temp = back->next;
    back->next = temp->next;
    delete(temp);
    
    return A;
}
