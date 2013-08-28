void mergeSortedArray(int arr1[], int arr2[], int n, int m) {
    int pt1(n-1), pt2(m-1), pt(n+m-1);
    while ( pt1 >= 0 && pt2 >= 0 )
    {
        int n1 = arr1[pt1];
        int n2 = arr2[pt2];
        if ( n1 > n2 )
        {
            arr1[pt] = n1;
            --pt1;
        }
        else
        {
            arr1[pt] = n2;
            --pt2;
        }
        --pt;
    }
    
    if ( pt1 < 0 )
    {
        while ( pt >= 0 )
        {
            arr1[pt--] = arr2[pt2--]; 
        }
    }
}