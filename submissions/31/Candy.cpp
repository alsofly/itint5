#include <numeric>

//返回最少需要的糖果数
long long minimalCandies(vector<int> &ratings) {
    int len = ratings.size();
    vector<long long> candy(len, 1);
    for ( int i = 1; i < len; ++i )
    {
        if ( ratings[i] > ratings[i-1] ) 
        {
            candy[i] = candy[i-1] + 1;
        }
    }
    
    for ( int i = len - 2; i >= 0; --i )
    {
        if ( ratings[i] > ratings[i + 1] )
        {
            candy[i] = max(candy[i], candy[i+1] + 1);
        }
    }
    
    long long init(0);
    return accumulate(candy.begin(), candy.end(), init);
}