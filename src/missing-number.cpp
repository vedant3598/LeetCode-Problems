class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int missing;
        int numbers = nums.size();
        map<int, int> dict;
        
        for(int i = 0; i <= nums.size(); i++){
            dict[i] = 0;
        }
        
        for(int i = 0; i < nums.size(); i++){
            dict[nums[i]]++;
        }
        
        for(int i = 0; i <= nums.size(); i++){
            if(dict[i] == 0){
                missing = i;
                break;
            }
        }
       
        return missing;
        
    }
};
