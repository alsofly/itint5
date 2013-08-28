//返回a+b的结果
string add(const string& a, const string& b) {
    int sizeA(a.size()), sizeB(b.size());
    string c(max(sizeA, sizeB), '0');
    int sizeC(c.size());
    
    int adv(0);
    for ( int i = 0, len = c.size(); i < len; ++i )
    {
        int digitA = i >= sizeA ? 0 : a[sizeA - i - 1] - '0';
        int digitB = i >= sizeB ? 0 : b[sizeB - i - 1] - '0';
        int currSum = digitA + digitB + adv;
        c[sizeC - i - 1] = currSum % 10 + '0';
        adv = currSum/10;
    }
    
    return adv > 0 ? "1" + c : c;
}