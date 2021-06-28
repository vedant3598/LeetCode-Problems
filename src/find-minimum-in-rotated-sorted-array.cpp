class Solution1 {
public:
    int findMin(vector<int>& nums) {
        int min = nums[0];
        
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] < min)
                min = nums[i];
        }
        
        return min;
    }
};

class Solution2 {
public:
    int findMin(vector<int>& nums) {
        int min = nums[0];
        
        for(int i = 0; i < nums.size(); i++){
            if(i == nums.size() - 1)
                break;
            else{
                if(nums[i] > nums[i + 1]){
                    min = nums[i+1];
                    break;
                }
            }
        }
        return min;
    }
};
