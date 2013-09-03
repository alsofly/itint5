int totalPath(vector<vector<bool> > &blocked) {
    int row = blocked.size();
    if ( row == 0 ) return 0;
    int col = blocked[0].size();
    if ( col == 0 ) return 0;
    
    vector<vector<int> > num(row+1, vector<int>(col+1, 0));  
    for ( int i = 1; i < num.size(); ++i )
    {
        for ( int j = 1; j < num[0].size(); ++j )
        {
            if ( i == 1 && j == 1 ) num[i][j] = 1;
            else 
            {
                if ( blocked[i-1][j-1] ) continue;
                num[i][j] = num[i-1][j] + num[i][j-1];
            }
        }
    }
    
    return num[row][col];
}