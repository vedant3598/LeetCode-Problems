class Solution {
public:
    int index = -1;
    void searchInsertUtil(const vector<int>& nums, const int& target, int l, int r){
        int mid = l + (r-l)/2;
        if(l <= r){        
            if(nums[mid] == target)
                index = mid;
            else if(nums[l] <= target && target < nums[mid])
                searchInsertUtil(nums, target, l, mid-1);
            else if(nums[mid] < target && target <= nums[r])
                searchInsertUtil(nums, target, mid+1, r);
            else{
                if(target < nums[0])
                    index = 0;
                else if(target > nums[nums.size() - 1])
                    index = nums.size();
                else if(target > nums[r])
                    index = r + 1;
                else if(target < nums[l])
                    index = l;
            }
        }  
        return;
    }
   
    int searchInsert(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        searchInsertUtil(nums, target, l, r);
        return index;
    }
};
