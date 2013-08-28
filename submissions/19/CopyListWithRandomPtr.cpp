/**
链表结点的定义(请不要在代码中定义该类型)
struct ListNode {
    ListNode *next;
    ListNode *random;
};
*/
// 返回复制的新链表头结点
ListNode* copyListWithRandomPtr(ListNode *head) {
    if ( head == NULL ) return NULL;
    
    ListNode *curr = head;
    ListNode *next;
    while ( curr != NULL )
    {
        next = curr->next;
        ListNode *temp = new ListNode();
        curr->next = temp;
        temp->next = next;
        curr = next;
    }
    
    curr = head;
    while ( curr != NULL )
    {
        next = curr->next->next;
        curr->next->random = curr->random->next;
        curr = next;
    }
    
    curr = head;
    ListNode *newHead = curr->next;
    ListNode *newCurr;
    while ( curr != NULL )
    {
        newCurr = curr->next;
        next = newCurr->next;
        curr->next = next;
        newCurr->next = next ? next->next : next;
        curr = next;
    }
    
    return newHead;
}