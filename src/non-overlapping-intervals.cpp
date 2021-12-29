class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int erase = 0;
        sort(intervals.begin(), intervals.end());
        
        int ma = intervals[0][1];
        
        for(int i = 1; i < intervals.size(); i++){
            if(intervals[i][0] < ma){
                erase++;
                ma = min(ma, intervals[i][1]);
            }
            else{
                ma = intervals[i][1];
            }
        }
        
        return erase;
    }
};
