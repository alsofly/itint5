#include<algorithm>
/*
struct Interval {
    int start;   //区间左端点
    int end;   //区间右端点
};
*/

typedef pair<int, Interval> WithTag;

bool comp(const WithTag& a, const WithTag& b)
{
    if ( a.second.start == b.second.start )
    {
        return a.second.end < b.second.end;
    }
    else return a.second.start < b.second.start;
}

// intervals包含n个区间
// 结果存放到isIntersected中(已分配空间,不需要push_back)
// isIntersected[i]表示第i个区间是否与其它区间相交
void intersected(vector<Interval> &intervals, vector<bool> &isIntersected) {    
    if ( intervals.size() == 0 ) return;
    
    vector<WithTag> withTag;
    for ( int i = 0, len = intervals.size(); i < len; ++i )
    {
        withTag.push_back(make_pair(i, intervals[i]));
    }
    sort(withTag.begin(), withTag.end(), comp);
    
    Interval curr;
    curr.start = withTag[0].second.start;
    curr.end = withTag[0].second.end;
    isIntersected[withTag[0].first] = false;
    for ( int i = 1, len = withTag.size(); i < len; ++i )
    {
        int pos = withTag[i].first;
        isIntersected[pos] = false;
        int currStart = withTag[i].second.start;
        int currEnd = withTag[i].second.end;
        
        if ( currStart <= curr.end )
        {
            curr.end = max(currEnd, curr.end);
            isIntersected[pos] = true;
            isIntersected[withTag[i-1].first] = true;
        }
        else
        {
            curr.start = currStart;
            curr.end = currEnd;
        }
    }
}