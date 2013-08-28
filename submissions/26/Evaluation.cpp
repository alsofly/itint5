//返回表达式expr的值

void eval_recur(
    const string& expr, 
    int ptr, 
    int& currSum)
{
    if ( ptr == expr.size() ) return;
    
    int sign(1);
    if ( expr[ptr] == '-' )
    {
        sign = -1;
        ptr++;
    }
    else if ( expr[ptr] == '+' )
    {
        sign = 1;
        ptr++;
    }
    
    int total(1);
    int val(0);
    while ( (expr[ptr] >= '0' && expr[ptr] <='9') 
         || expr[ptr] == '*' )
    {
        if ( (expr[ptr] >= '0' && expr[ptr] <='9') )
        {
            val = val *10 + expr[ptr] - '0';
        }
        else
        {
            total *= val;
            val = 0;
        }
        ptr++;
    }
    total *= val;
    
    currSum += (sign * total);
    eval_recur(expr, ptr, currSum);
}

int evaluate(const string& expr) {
    int sum(0);
    eval_recur(expr, 0, sum);
    return sum;
}