/*积木的定义(请不要在代码中定义该结构)
struct Box {
  int vol, weight;
};*/

struct Comp{
    bool operator() (const Box& a, const Box& b) {
        return a.vol < b.vol;
    }
} comp;

int maxBoxes_recur(
    vector<Box>& boxes,
    vector<int>& max_incl,
    int firstPos)
{
    int currMax(1);
    for ( int i = firstPos + 1, len = boxes.size(); i < len; ++i )
    {
        if ( boxes[i].weight > boxes[firstPos].weight
          && boxes[i].vol > boxes[firstPos].vol )
        {
            if ( max_incl[i] == 0 )
            {
                max_incl[i] = maxBoxes_recur(boxes, max_incl, i);
            }
        
            currMax = max(currMax, 1 + max_incl[i]);
        }
    }
    return currMax;
}

int maxBoxes(vector<Box> &boxes) {
    if ( boxes.size() == 0 ) return 0;
    sort(boxes.begin(), boxes.end(), comp);
    
    vector<int> max_incl(boxes.size(), 0);
    for ( int i = 0, len = boxes.size(); i < len;  ++i )
    {
        if ( max_incl[i] == 0 )
        {
            max_incl[i] = maxBoxes_recur(boxes, max_incl, i);
        }
    }
    
    return *max_element(max_incl.begin(), max_incl.end());
}