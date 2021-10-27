class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;
        if(nums.size() < 3)
            return ret;
        
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size() - 2; i++){
            if(i == 0 || i > 0 && nums[i] != nums[i-1]){
                int *p1 = &nums[i+1];
                int *p2 = &nums[nums.size() - 1];
                while(p1 < p2){
                    int sum = *p1 + *p2 + nums[i];
                    if(sum == 0){
                        vector<int> temp;
                        temp.push_back(*p1);
                        temp.push_back(*p2);
                        temp.push_back(nums[i]);
                        ret.push_back(temp);
                        while(p1 < p2 && *p1 == *(p1+1)){
                            p1++;
                        }
                        while(p1 < p2 && *p2 == *(p2-1)){
                            p2--;
                        }
                        p1++;
                        p2--;
                    }
                    else if(sum > 0)
                        p2--;
                    else
                        p1++;
                }
            }
        }
        return ret;
    }
};
