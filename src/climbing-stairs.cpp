class Solution {
public:
    int climbStairs(int n) {
        vector<int> memo;
        
        memo.push_back(1);
        memo.push_back(2);
        
        if(n == 1)
            return memo[0];
        if (n == 2)
            return memo[1];
        
        for(int i = 2; i < n; i++){
            memo.push_back(memo[i-2] + memo[i-1]);
        }
        return memo[memo.size() - 1];
        
    }
};
