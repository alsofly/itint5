int maxRectSum(vector<vector<int> > &matrix) {
    int row(matrix.size());
    if ( row == 0 ) return 0;
    int col(matrix[0].size());
    if ( col == 0 ) return 0;
    
    int rtn(0);
    vector<int> sum(col, 0);
    for ( int i = 0; i < row; ++i )
    {
        sum = matrix[i];
        for ( int j = i; j < row; ++j )
        {
            if ( j != i )
            {
                transform(sum.begin(), sum.end(), matrix[j].begin(),
                         sum.begin(), plus<int>());
            }
            
            int tmp(0);
            for ( int k = 0; k < col; ++k )
            {
                tmp = max(0, tmp) + sum[k];
                rtn = max(rtn, tmp);
            }
        }
    }
    
    return rtn;
}