bool validate_recur(
    const string& expr, 
    int pt, 
    int& parenCount,
    bool isNum, 
    char pre)
{
    if ( pt == expr.size() )
    {
        return parenCount == 0 && isNum;
    }
    if ( parenCount < 0 ) return false;
    if ( expr[pt] == '(' )
    {
        if ( pre == ')' || pre == '1' ) return false;
        ++parenCount;
        return validate_recur(expr, pt+1, parenCount, isNum, '(');
    }
    else if ( expr[pt] == ')' )
    {
        if ( pre == '(' || pre == '+' ) return false;
        --parenCount;
        return validate_recur(expr, pt+1, parenCount, isNum, ')');
    }
    else if ( expr[pt] == '+' || expr[pt] == '-' )
    {
        if ( !isNum ) return false;
        return validate_recur(expr, pt+1, parenCount, false, '+');
    }
    else if ( expr[pt] >= '0' && expr[pt] <= '9' )
    {
        if ( isNum ) return false;
        
        int count(0);
        while ( pt != expr.size() 
             && expr[pt] >= '0' && expr[pt] <= '9' )
        {
            ++count;
            ++pt;
        }
        
        if ( count != 1 && expr[pt - count] == '0' ) return false;
        return validate_recur(expr, pt, parenCount, true, '1');
    }
    
    return false;
}

bool validate(const string& expr) {
    int parenCount(0);
    return validate_recur(expr, 0, parenCount, false, '+');
}