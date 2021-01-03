/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::detectCycle(ListNode* A) {
    set<ListNode*> S;
    ListNode* temp = A;
    while(temp!=NULL){
        
        if(S.find(temp) != S.end()){
            return temp;
        }
        
        S.insert(temp);
        
        temp = temp->next;
    }
    
    return NULL;
}
