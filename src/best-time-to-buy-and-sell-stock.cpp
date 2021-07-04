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

class Solution2 {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 1)
            return 0;
        int max = INT_MIN;
        int minVal = INT_MAX;
        for(int i = 0; i < prices.size(); i++){
            if(prices[i] < minVal)
                minVal = prices[i];
            if(prices[i] - minVal > max)
                max = prices[i] - minVal;
        }
        if(max < 0)
            return 0;
        return max;
    }
};
