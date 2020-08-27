class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
     
        int n = intervals.size();
        vector<pair<int,int>> starts;
        
        for(int i=0;i<n;i++)
            starts.push_back({intervals[i][0],i});
        
        sort(starts.begin(),starts.end());
        
        vector<int> result;
        
        for(int i=0;i<n;i++)
        {
            int index = lowerbound(0,n-1,starts,intervals[i][1]);
            if(index == -1)
                result.push_back(-1);
            else
                result.push_back(index);
        }
        return result;
    }
    
    
    int lowerbound(int l,int r,vector<pair<int,int>>& arr , int endinterval){
        if(l>r) return -1;
        //binary search
        int mid = (l+r)>>1;
        
        if(arr[mid].first < endinterval)
            return lowerbound(mid+1,r,arr,endinterval);
        
         else if(!mid || arr[mid-1].first < endinterval)
            return arr[mid].second;
        else
            return lowerbound(l,mid-1,arr,endinterval);
        
    }
};
