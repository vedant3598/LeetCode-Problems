class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> counter(nums.size());
        vector<int> disappear;
        
        for(int i = 0; i < nums.size(); i++){
            counter.at(nums[i] - 1) = nums[i];
        }
        
        for(int i = 0; i < counter.size(); i++){
            if(!counter[i])
                disappear.push_back(i+1);
        }
        return disappear;
    }
};
