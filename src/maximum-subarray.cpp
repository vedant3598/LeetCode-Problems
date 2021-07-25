class Solution1 {
public:
    int maxSubArray(vector<int>& nums) {
        int max = INT_MIN;
        int current = 0;
        for(int i = 0; i < nums.size(); i++){
            current = nums[i];
            for(int x = i; x < nums.size(); x++){
                if(i == x)
                    current += 0;
                else
                    current += nums[x];
                
                if(current > max)
                    max = current;
            }
        }
        return max;
    }
};

class Solution2 {
public:
    int maxSubArray(vector<int>& nums) {
        int globalMax = nums[0];
        int currentMax = nums[0];
        
        for(int i = 1; i < nums.size(); i++){
            currentMax = max(nums[i], currentMax + nums[i]);
            if(currentMax > globalMax)
                globalMax = currentMax;
        }
        
        return globalMax;
    }
};
