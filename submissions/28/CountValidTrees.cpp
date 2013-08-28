int count(vector<int>& preorder, int m, int n,
         vector<int>& postorder, int p, int q)
{
    if ( m == n ) return 1;
    int firstRoot = preorder[m+1];
    int i;
    for ( i = p; i < q; ++i )
    {
        if ( postorder[i] == firstRoot ) break;
    }
    
    if ( i == q - 1 )
    {
        return 2*count(preorder, m+1, n, postorder, p, q-1);
    }
    else
    {
        return count(preorder, m+1, m+1+i-p, postorder, p, i)
             * count(preorder, m+i-p+2, n, postorder, i+1, q-1); 
    }
}

int countValidTrees(vector<int>& preorder, vector<int>& posorder) {
    return count(preorder, 0, preorder.size()-1,
                 posorder, 0, posorder.size()-1);
}