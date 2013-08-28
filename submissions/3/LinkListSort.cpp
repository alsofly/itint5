ListNode* sortLinkList(ListNode *head) {
    if ( head == NULL || head->next == NULL ) return head;
    
    ListNode *preSlow(NULL);
    ListNode *slow(head);
    ListNode *fast(head);
    while ( fast != NULL )
    {
        preSlow = slow;
        slow = slow->next;
        fast = fast->next;
        if ( fast != NULL ) fast = fast->next;
    }
    
    preSlow->next = NULL;
    ListNode *firstHead = sortLinkList(head);
    ListNode *secondHead = sortLinkList(slow);
    
    ListNode *rtn(NULL);
    ListNode *curr(NULL);
    ListNode *pre(NULL);
    while ( firstHead != NULL && secondHead != NULL )
    {
        if ( firstHead->val < secondHead->val )
        {
            curr = firstHead;
            firstHead = firstHead->next;
        }
        else
        {
            curr = secondHead;
            secondHead = secondHead->next;
        }
        
        if ( rtn == NULL )
        {
            rtn = curr;
            pre = curr;
        }
        else
        {
            pre->next = curr;
            pre = curr;
        }
    }
    
    if ( firstHead != NULL ) pre->next = firstHead;
    else pre->next = secondHead;
    
    return rtn;
}