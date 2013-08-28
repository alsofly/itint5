//使用getLeftChildNode(TreeNode)获得左儿子结点
//使用getRightChildNode(TreeNode)获得右儿子结点
//使用isNullNode(TreeNode)判断结点是否为空

int get_height(TreeNode root)
{
    if ( isNullNode(root) ) return 0;
    return 1 + get_height(getLeftChildNode(root));
}
    

int count_complete_binary_tree_nodes(TreeNode root) {
    if ( isNullNode(root) ) return 0;
    
    int abscent(0);
    int fullCount(1);
    while ( !isNullNode(root) )
    {
        fullCount *= 2;
        TreeNode leftNode = getLeftChildNode(root);
        TreeNode rightNode = getRightChildNode(root);
        int leftH = get_height(leftNode);
        int rightH = get_height(rightNode);
        
        abscent = abscent << 1;
        if ( leftH > rightH ) 
        {
            ++abscent;
            root = leftNode;
        }
        else
        {
            root = rightNode;
        }
    }
    abscent = abscent >> 1;
    
    return fullCount - abscent - 1;
}