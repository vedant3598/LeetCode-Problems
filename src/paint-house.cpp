class Solution {
public:
    /**
     * @param costs: n x 3 cost matrix
     * @return: An integer, the minimum cost to paint all houses
     */
    int minCost(vector<vector<int>> &costs) {
        vector<int> dp = {0, 0, 0};

        for(int i = 0; i < costs.size(); i++){
            int c0 = costs[i][0] + min(dp[1], dp[2]);
            int c1 = costs[i][1] + min(dp[0], dp[2]);
            int c2 = costs[i][2] + min(dp[0], dp[1]);
            dp = {c0, c1, c2};
        }
        return *min_element(dp.begin(), dp.end());
    }
};
