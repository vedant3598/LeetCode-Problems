class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> memo;
        // In DP problems, you want to have two elements in a dp or memo vector (or array) before recursing or iterating
        memo.push_back(0);
        memo.push_back(nums[0]);
        
        for(int i = 1; i < nums.size(); i++){
            memo.push_back(max(memo[i], memo[i-1] + nums[i]));
        }
        return memo[nums.size()];
    }
};
