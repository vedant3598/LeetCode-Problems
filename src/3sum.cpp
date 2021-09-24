class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;
        if(nums.size() == 0 || nums.size() == 1)
            return ret;
        
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size() - 2; i++){
            if(i == 0 || (i > 0 && nums[i] != nums[i-1])){
                int sum = 0 - nums[i];
                int* p1 = &nums[i+1];
                int* p2 = &nums[nums.size() - 1];
                while(p1 < p2){
                    vector<int> temp;
                    if(*p1 + *p2 == sum){
                        temp.push_back(nums[i]);
                        temp.push_back(*p1);
                        temp.push_back(*p2);
                        ret.push_back(temp);
                        while(p1 < p2 && *p1 == *(p1+1)){
                            p1++;
                        }
                        p1++;
                        while(p1 < p2 && *p2 == *(p2-1)){
                            p2--;
                        }
                        p2--;
                    }
                    else if(*p1 + *p2 > sum){
                        p2--;
                    }
                    else{
                        p1++;
                    }
                }
            }            
        }
        
        return ret;
    }
};
