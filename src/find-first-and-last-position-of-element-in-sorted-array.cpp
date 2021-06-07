class Solution {
public:
    vector<int> ans;
    
    void searchRangeUtil(const vector<int>& nums, const int &target, int l, int r){
        if(l <= r){
            int mid = l + (r-l)/2;
            
            if(nums[mid] == target){
                int start = mid;
                int end = mid;
                int startIndex = -1;
                int endIndex = -1;
                while(start >= 0 && nums[start] == target){
                    startIndex = start;
                    start--;
                }
                if(startIndex == -1)
                    ans.push_back(mid);
                else
                    ans.push_back(startIndex);
                while(end < nums.size() && nums[end] == target){
                    endIndex = end;
                    end++;
                }
                if(endIndex == -1)
                    ans.push_back(mid);
                else
                    ans.push_back(endIndex);
            }
            else if(nums[l] <= target && target < nums[mid])
                searchRangeUtil(nums, target, l, mid - 1);
            else if(nums[mid] < target && target <= nums[r])
                searchRangeUtil(nums, target, mid + 1, r);
            else{}
        }
        if(ans.size() == 0){
            ans.push_back(-1);
            ans.push_back(-1);
        }
        return;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        searchRangeUtil(nums, target, l, r);
        return ans;
    }
};
