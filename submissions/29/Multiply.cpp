//返回a*b的结果
string simple_multi(const string& a, const char b)
{
    string c(a.size(), '0');
    int adv(0);
    int numB(b - '0');
    for ( int i = 0, len = a.size(); i < len; ++i )
    {
        int currNum = adv + numB * (a[len-1-i] - '0');
        c[len-1-i] = currNum%10 + '0';
        adv = currNum/10;
    }
    return adv > 0 ? string(1, adv + '0') + c : c;
}

string add_to(string& a, string& b, int n)
{
    int len = max(b.size() + n, a.size());
    string c(len, '0');
    int adv(0);
    for ( int i = 0; i < n; ++i ) 
    {
        c[c.size() - 1 - i] = i < a.size() ? a[a.size() - 1 - i] : '0'; 
    }
    
    for ( int i = n; i < len; ++i )
    {
        int numA = i >= a.size() ? 0 : a[a.size() - 1 - i] - '0';
        int numB = i - n >= b.size() ? 0 : b[b.size() - 1 - (i - n)] - '0';
        int currNum = adv + numA + numB;
        c[c.size() - 1 - i] = currNum%10 + '0';
        adv = currNum/10;
    }
    
    return adv > 0 ? string(1, adv + '0') + c : c;
}

string multiply(const string& a, const string& b) 
{
    if ( a.size() == 1 && a[0] == '0' || b.size() == 1 && b[0] == '0' ) 
    {
        return "0";
    }
    
    string first, second;
    int sign = ((a[0] == '-') != (b[0] == '-')) ? -1 : 1;
    if ( a[0] == '-' )
    {
        first.assign(a.substr(1));
    }
    else
    {
        first.assign(a);
    }
    
    if ( b[0] == '-' )
    {
        second.assign(b.substr(1));
    }
    else
    {
        second.assign(b);
    }
    
    string rtn("0");
    for ( int i = 0, len = second.size(); i < len; ++i )
    {
        string tempStr = simple_multi(first, second[second.size() - 1 - i]);
        rtn = add_to(rtn, tempStr, i);
    }
    return sign == 1 ? rtn : "-" + rtn;
}