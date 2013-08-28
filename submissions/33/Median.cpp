#include <climits>

int kth(vector<int>& arr1, vector<int>& arr2, int k)
{
    int low(0), high(arr1.size());
    while ( true )
    {
        int i = (low + high)/2;
        int j = k - 1 - i;
        if ( j > arr2.size() ) j = arr2.size();
        else if ( j < 0 ) j = 0;
        i = k - 1 - j;
        
        int Ai   = i == arr1.size() ? INT_MAX : arr1[i];
        int Ai_1 = i == 0 ? INT_MIN : arr1[i-1];
        int Bj   = j == arr2.size() ? INT_MAX : arr2[j];
        int Bj_1 = j == 0 ? INT_MIN : arr2[j-1];
        
        if ( Ai >= Bj_1 && Ai <= Bj ) return Ai;
        if ( Bj >= Ai_1 && Bj <= Ai ) return Bj;
        if ( Ai_1 > Bj ) high = i - 1;
        else low = i + 1;
    }
}

int median(vector<int> &arr1, vector<int> &arr2) {
    int l1 = arr1.size();
    int l2 = arr2.size();
    if ( (l1 + l2)&1 ) return kth(arr1, arr2, (l1+l2+1)/2);
    else return (kth(arr1, arr2, (l1+l2)/2) + kth(arr1, arr2, (l1+l2)/2+1))/2;
}