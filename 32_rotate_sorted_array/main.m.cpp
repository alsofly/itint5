#include <iostream>
#include <vector>

using namespace std;

int search_b(vector<int>& arr, int low, int high, int target)
{
    cout << low << ", " << high << endl;
    if ( high < low ) return -1;
    if ( high == low ) return (arr[high] == target ? low : -1);
    
    int mid = (low + high)/2;
    if ( target == arr[mid] ) return mid;
    if ( arr[mid] > arr[high] )
    {
        if ( target > arr[mid] || target <= arr[high] )
        {
            int result = search_b(arr, mid + 1, high, target);
            if ( result > -1 ) return result;
        }
        else
        {
            int result = search_b(arr, low, mid - 1, target);
            if ( result > -1 ) return result;
        }
    }
    else
    {
        cout << "mid < high" << endl;
        if ( target > arr[mid] && target <= arr[high] )
        {
            int result = search_b(arr, mid + 1, high, target);
            if ( result > -1 ) return result;
        }
        else
        {
            int result = search_b(arr, low, mid - 1, target);
            if ( result > -1 ) return result;
        }
    }
    
    return -1;
}

int search(vector<int> &arr, int target) {
    return search_b(arr, 0, arr.size()-1, target);
}

int main()
{
   vector<int> arr;
   arr.push_back(1);
   arr.push_back(2);

   cout << search(arr, 3) << endl;
   return 0;
}
