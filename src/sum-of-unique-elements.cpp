class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        int sum = 0;
        map<int, int> dict;
        
        for(int i = 0; i < nums.size(); i++){
            if(dict.find(nums[i]) == dict.end()){
                dict[nums[i]] = 0;
                sum += nums[i];
            }
            else{
                if(dict[nums[i]] == 0){
                    sum -= nums[i];
                    dict[nums[i]]++;
                }
            }
        }
        return sum;
    }
};
