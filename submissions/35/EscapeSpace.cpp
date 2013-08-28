void escapeSpace(char *str) {
    if ( str == NULL ) return;
    char *pt = str;
    int count(0);
    while ( *pt != '\0' )
    {
        if ( *pt == ' ' ) 
        {
            ++count;
        }
        ++pt;
    }
    
    char *pt2(pt + 2*count);
    
    while ( pt2 != pt )
    {
        if ( *pt != ' ' )
        {
            *(pt2--) = *(pt--);
        }
        else
        {
            *(pt2--) = '0';
            *(pt2--) = '2';
            *(pt2--) = '%';
            --pt;
        }
    }
}