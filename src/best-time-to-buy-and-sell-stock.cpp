class Solution1 {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 1)
            return 0;
        
        int max = 0;
        for(int i = 0; i < prices.size(); i++){
            if(i == prices.size() - 1)
                exit;
            for(int x = i + 1; x < prices.size(); x++){
                if(prices[x] - prices[i] > max)
                    max = prices[x] - prices[i];
            }
        }
        return max;
    }
};
