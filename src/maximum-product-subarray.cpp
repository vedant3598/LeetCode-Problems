class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max = INT_MIN;
        int current = 0;
        
        for(int i = 0; i < nums.size(); i++){
            current = nums[i];
            for(int x = i; x < nums.size(); x++){
                if(i != x)
                    current *= nums[x];
                
                if(current > max)
                    max = current;
            }
        }
        return max;
    }
};
