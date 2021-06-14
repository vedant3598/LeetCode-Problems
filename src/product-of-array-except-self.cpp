class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> forward;
        vector<int> reverse;
        
        int fMult = 1;
        for(int i = 0; i < nums.size(); i++){
            forward.push_back(fMult);
            fMult *= nums[i];
        }
        
        int lMult = 1;
        for(int i = nums.size()-1; i >= 0; i--){
            reverse.push_back(lMult);
            lMult *= nums[i];
        }
        
        int reverseCount = nums.size() - 1;
        for(int i = 0; i < nums.size(); i++){
            nums[i] = forward[i] * reverse[reverseCount];
            reverseCount--;
        }
        
        return nums;
        
    }
};
