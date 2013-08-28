bool next_permutation(vector<int> &arr) {
    if ( arr.size() < 2 ) return false;
    
    int pt(arr.size() - 2);
    while ( pt >= 0 && arr[pt] >= arr[pt+1] ) --pt;
    if ( pt < 0 ) return false;
    
    int ptEnd(arr.size() - 1);
    while ( arr[ptEnd] <= arr[pt] ) --ptEnd;
    
    swap(arr[pt], arr[ptEnd]);
    int pt1(pt+1), pt2(arr.size() - 1);
    while ( pt1 < pt2 ) swap(arr[pt1++], arr[pt2--]);
    
    return true;
}