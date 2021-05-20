class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int ret = 0;
        if(nums.size() <= 2){
            ret = nums.size();
        }
        else{
            ret = 2;
            for(int i = 2; i < nums.size(); i++){
                if(nums[i] != nums[ret-2]){
                    nums[ret] = nums[i];
                    ret++;
                }    
            }
        }
        
        return ret;
    }
};
