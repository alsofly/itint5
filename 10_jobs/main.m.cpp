#include <map>
#include <stack>
#include <vector>
#include <iostream>
#include <set>

using namespace std;

typedef int JobID;

/*
 * deps[id]表示任务id所依赖的任务
 * 如果存在合法的任务完成序列，返回true，否则返回false
 * 合法的任务序列请存放在参数result中（已经分配空间，不需要push_back）
 */

struct JobIndex {
    int index;
    int lowlink;
    JobIndex(const int i, const int l) : index(i), lowlink(l) {}
};
typedef map<JobID, JobIndex> IndexMap;
typedef IndexMap::iterator IndexMapIt;

IndexMap indexMap;
stack<JobID> st;
set<JobID> st_set;

bool process(
    const JobID id,
    int& index,
    const map<JobID, vector<JobID> > &deps, 
    vector<JobID> &result)
{
    JobIndex jobIndex(index, index);
    indexMap.insert(make_pair(id, jobIndex));
    ++index;
    st.push(id);
    st_set.insert(id);
    
    map<JobID, vector<JobID> >::const_iterator jobIt = deps.find(id);
    if ( jobIt != deps.end() )
    {
        for ( int i = 0, len = jobIt->second.size(); i < len; ++i )
        {
            JobID currId = (jobIt->second)[i];
            IndexMapIt mapIt = indexMap.find(currId);
            if ( mapIt == indexMap.end() )
            {
                if ( !process(currId, index, deps, result) ) return false;
                
            }
            else if ( st_set.find(currId) != st_set.end() )
            {
                return false;
            }
        }
    }
    
    result.push_back(id);
    st.pop();
    st_set.erase(id);
    
    return true;
}

bool jobSchedule(
    const map<JobID, vector<JobID> > &deps, 
    int n,
    vector<JobID> &result) {
   
    int index(0);
    for ( JobID i = static_cast<JobID>(1); i <= n; ++i )
    {
        IndexMapIt it = indexMap.find(i);
        if ( it == indexMap.end() )
        {
            if ( !process(i, index, deps, result) ) return false;
        }
    }

    return true;
}

int main()
{
   map<JobID, vector<JobID> > deps;
   vector<JobID> v1;
   v1.push_back(3); v1.push_back(2);
   vector<JobID> v2;
   v2.push_back(4);
   deps.insert(make_pair(1, v1));
   deps.insert(make_pair(3, v2));
   int n(5);
   vector<JobID> result;

   cout << "Return is [" 
      << (jobSchedule(deps, n, result) ? "TRUE" : "FALSE") 
      << "]"
      << endl;
  
   for ( vector<JobID>::const_iterator it = result.begin(), itE = result.end();
         it != itE; ++it )
   {
      cout << *it << endl;
   }

   return 0;
}

