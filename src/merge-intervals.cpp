class Solution2 {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() == 1)
            return intervals;
        
        vector<vector<int>> ret;
        sort(intervals.begin(), intervals.end());
        
        int mi = intervals[0][0];
        int ma = intervals[0][1];
        
        for(int i = 1; i <= intervals.size(); i++){
            if(i < intervals.size() && ma >= intervals[i][0]){
                mi = min(mi, intervals[i][0]);
                ma = max(ma, intervals[i][1]);
            }
            else{
                vector<int> temp;
                temp.push_back(mi);
                temp.push_back(ma);
                ret.push_back(temp);
                if(i < intervals.size()){
                    mi = intervals[i][0];
                    ma = intervals[i][1];
                }
            }
        }
        return ret;
    }
};

class Solution1 {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() == 1)
            return intervals;
        
        vector<vector<int>> ret;
        sort(intervals.begin(), intervals.end());
        
        int mi = intervals[0][0];
        int ma = intervals[0][1];
        
        for(int i = 1; i <= intervals.size(); i++){
            if(i < intervals.size() && ((mi >= intervals[i][0] && mi <= intervals[i][1]) || 
               (ma >= intervals[i][0] && ma <= intervals[i][1]))){
                mi = min(mi, intervals[i][0]);
                ma = max(ma, intervals[i][1]);
            }
            else if(i < intervals.size() && ((intervals[i][0] >= mi && intervals[i][0] <= ma) || 
               (intervals[i][1] >= mi && intervals[i][1] <= ma))){
                mi = min(mi, intervals[i][0]);
                ma = max(ma, intervals[i][1]);
            }
            else{
                vector<int> temp;
                temp.push_back(mi);
                temp.push_back(ma);
                ret.push_back(temp);
                if(i < intervals.size()){
                    mi = intervals[i][0];
                    ma = intervals[i][1];
                }
            }
        }
        
        return ret;
    }
};
