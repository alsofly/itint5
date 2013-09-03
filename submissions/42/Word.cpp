vector<string> transform(set<string> &dict, string from, string to) {
    map<string, string> visited;
    queue<string> que;
    
    que.push(from);
    visited.insert(make_pair(from, from));
    
    bool flag(false);
    while ( !que.empty() )
    {
        string curr = que.front();
        que.pop();
        
        for ( int i = 0, len = curr.size(); i < len; ++i )
        {
            string tmp(curr);
            for ( char c = 'A'; c <= 'Z'; ++c )
            {
                tmp[i] = c;
               
                map<string, string>::iterator it = visited.find(tmp);
                if ( it == visited.end() ) 
                {
                    if ( dict.find(tmp) != dict.end() )
                    {
                        visited.insert(make_pair(tmp, curr));
                        que.push(tmp);
                    }
                }
                
                if ( tmp == to )
                {
                    flag = true;
                    break;
                }
            }
            
            if ( flag ) break;
        }
        
        if ( flag ) break;
    }
    
    vector<string> rtn;
    if ( !flag ) return rtn;
    map<string, string>::iterator it = visited.find(to);
    while ( it != visited.find(from) )
    {
        rtn.push_back(it->first);
        it = visited.find(it->second);
    }
    rtn.push_back(from);
    reverse(rtn.begin(), rtn.end());
    return rtn;
}