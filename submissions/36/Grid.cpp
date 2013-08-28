typedef map<int, bool> Memo;
typedef Memo::iterator MemoIt;

bool exists_recur(
    vector<vector<char> >& grid,
    string& pattern,
    Memo& memo,
    int pos,
    int x,
    int y)
{
    if ( pos == pattern.size() ) return true;
    
    int row = grid.size();
    int col = grid[0].size();
    MemoIt it = memo.find(x*col + y);
    if ( it != memo.end() && it->second == true ) return false;
    

    if ( x < 0 || x >= row || y < 0 || y > col ) return false;
    
    if ( grid[x][y] == pattern[pos] )
    {
        if ( it == memo.end() )
        {
            memo.insert(make_pair(x*col + y, true));
        }
        else
        {
            it->second = true;
        }
        
        if ( exists_recur(grid, pattern, memo, pos+1, x+1, y) ) return true;
        if ( exists_recur(grid, pattern, memo, pos+1, x-1, y) ) return true;
        if ( exists_recur(grid, pattern, memo, pos+1, x, y+1) ) return true;
        if ( exists_recur(grid, pattern, memo, pos+1, x, y-1) ) return true;
    
        MemoIt it = memo.find(x*col+y);
        it->second = false;
    }
    
    return false;
}

bool exists(vector<vector<char> > &grid, string pattern) {
    int row = grid.size();
    if ( row == 0 ) return false;
    int col = grid[0].size();
    if ( col == 0 ) return false;
    
    Memo memo;
    for ( int i = 0; i < row; ++i )
        for ( int j = 0; j < col; ++j )
            if ( exists_recur(grid, pattern, memo, 0, i, j) ) return true;
    
    return false;
}