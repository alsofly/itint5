/*
树结点的定义(请不要在代码中定义该类型)
struct TreeNode {
    int val;
    vector<TreeNode*> children;  //该结点的儿子结点
 };
*/

int max_rec(TreeNode *root, int& maxVal)
{
    if ( root == NULL )  return 0;
    vector<int> maxSum;
    int one(0), two(0);
    for ( int i = 0, len = root->children.size(); i < len; ++i )
    {
        int val = max_rec(root->children[i], maxVal);
        if ( val > one )
        {
            two = one;
            one = val;
        }
        else if ( val > two )
        {
            two = val;
        }
    }
    
    maxVal = max(maxVal, root->val + one + two);
    return root->val + one;
}


int maxTreePathSum(TreeNode *root) {
    if ( root  == NULL ) return 0;
    int maxVal(root->val);
    max_rec(root, maxVal);
    return max(maxVal, 0);
}