bool is_interleaving(string& str1, string& str2, string& str3,
                    int p1, int p2, int p3)
{
    if ( p3 == str3.size() ) return true;
    if ( str3[p3] == str1[p1] ) 
    {
        if ( is_interleaving(str1, str2, str3, p1+1, p2, p3+1) )
            return true;
    }
    
    if ( str3[p3] == str2[p2] )
    {
        if ( is_interleaving(str1, str2, str3, p1, p2+1, p3+1) )
            return true;
    }
    
    return false;
}

bool isInterleaving(string &str1, string &str2, string &str3) {
    return is_interleaving(str1, str2, str3, 0, 0, 0);
}