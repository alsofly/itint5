#include <queue>
#include <vector>

/*链表结点的定义(请不要在代码中定义该类型)
struct ListNode {
  int val;
  ListNode *next;
};
*/

struct Comparison
{
    bool operator() (const ListNode *a, const ListNode *b) const
    {
        return a->val > b->val;
    }
};
typedef priority_queue<ListNode *, vector<ListNode *>, Comparison> Pq; 

//lists包含k个链表的头结点,返回合并后链表头结点
ListNode* merge(vector<ListNode*> &lists) {
     Pq pq;
    for ( int i = 0, len = lists.size(); i < len; ++i )
    {
        if ( lists[i] ) pq.push(lists[i]);
    }
    
    ListNode *head(NULL), *pre(NULL), *curr(NULL);
    while ( !pq.empty() )
    {
        curr = pq.top(); 
        pq.pop();
        if ( !head ) head = curr;
        if ( pre ) pre->next = curr;
        if ( curr->next ) pq.push(curr->next);
        pre = curr;
    }
    if ( curr) curr->next = NULL;
    return head;
}