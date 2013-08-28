int maxConsSum2(const vector<int> &arr) {
    int total(0);
    int minT(0);
    int minC(0);
    int maxT(0);
    int maxC(0);
    
    
    for ( int i = 0, len = arr.size(); i < len; ++i )
    {
        maxC = arr[i] + max(0, maxC);
        maxT = max(maxT, maxC);
        minC = arr[i] + min(0, minC);
        minT = min(minT, minC);
        total += arr[i];
    }
    
    return max(maxT, max(0, total - minT));
}