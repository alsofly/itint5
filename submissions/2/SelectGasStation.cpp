#include <vector>
using namespace std;

int selectGasStation(const vector<int> &a, const vector<int> &g) {
    int total(a[0] - g[0]);
    int minVal(total);
    int posMin(1%a.size());
    
    for ( int i = 1, len = a.size(); i < len; ++i )
    {
        total += a[i] - g[i];
        if ( total < minVal )
        {
            minVal = total;
            posMin = (i+1)%len;
        }
    }
    
    if ( total < 0 )
    {
        return -1;
    }
    else
    {
        return posMin;
    }    
}