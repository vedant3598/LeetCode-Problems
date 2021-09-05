class Solution {
public:
    int searchUtil(vector<int>& nums, int target, int min, int max){
        if(max > min){
            int mid = min + (max - min)/2;
                        
            if(nums[mid] == target)
                return mid;
            else if(nums[min] == target)
                return min;
            else if(nums[max] == target)
                return max;
            else if(target > nums[mid] && target <= nums[max])
                return searchUtil(nums, target, mid+1, max);
            else if(target < nums[min] && target <= nums[mid]){
                int num = searchUtil(nums, target, min, mid-1);
                if(num == -1)
                    num = searchUtil(nums, target, mid+1, max);
                return num;
            }
            else if(target < nums[mid] && target >= nums[min])
                return searchUtil(nums, target, min, mid-1);
            else{
                int num = searchUtil(nums, target, mid+1, max);  
                if(num == -1)
                    num = searchUtil(nums, target, min, mid-1);
                return num;
            }
        }
        return -1;
        
    }
    
    int search(vector<int>& nums, int target) {
        int index = -1;
        int min = 0;
        int max = nums.size() - 1;
        if(nums.size() == 1){
            if(nums[0] == target)
                return 0;
            else
                return index;
        }
        else
            return searchUtil(nums, target, min, max);
    }
};
