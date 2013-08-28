int maxConsSum(const vector<int> &arr) {
    int rtn(0), preEndMax(0);
    for ( int i = 0, len = arr.size(); i < len; ++ i )
    {
        preEndMax = max(0, preEndMax) + arr[i];
        rtn = max(rtn, preEndMax);
    }
    return rtn;
}