class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int unique = 0;
        int p1 = 0;
        int p2 = 0;
        
        while(p1 < nums.size()){
            unique++;
            while(p2 < nums.size() && nums[p1] == nums[p2]){
                p2++;
            }
            if(p2 == nums.size())
                break;
            else{
                if(p1 + 1 < p2){
                    nums[p1+1] = nums[p2];
                }
                p1++;  
            }
        }
        return unique;
    }
};
