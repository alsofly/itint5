typedef tuple<int, int, int> ABC; //存放a,b,c三元组
//返回所有满足条件的(a,b,c)三元组
vector<ABC> threeSumZero(vector<int> &arr) {
    vector<ABC> rtn;
    if ( arr.size() < 3 ) return rtn; 
    sort(arr.begin(), arr.end());
    for ( int i = 0, len = arr.size(); i < len - 2; ++i )
    {
        if ( i != 0 && arr[i] == arr[i-1] ) continue;
        int j = i + 1;
        int k = len - 1;
        int target = -arr[i];
        while ( j < k )
        {
            while ( arr[j] + arr[k] < target && j < k ) ++j;
            while ( arr[j] + arr[k] > target && j < k ) --k;
            
            if ( j < k && arr[j] + arr[k] == target )
            {
                rtn.push_back(ABC(arr[i], arr[j++], arr[k--]));
                while ( j < k && arr[j-1] == arr[j] ) ++j;
                while ( j < k && arr[k+1] == arr[k] ) --k;
            }
        }
    }
    
    return rtn;
}