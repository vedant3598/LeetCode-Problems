class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int counter = 0;
        if(nums.size() == 0)
            return counter;
        
        int* p1 = &nums[0];
        int* p2 = &nums[nums.size() - 1];
        
        while(p1 <= &nums[nums.size() - 1] && p2 >= &nums[0]){
            if(*p1 != val){
                counter++;
            }
            else{
                while(*p2 == val && p2 != p1){
                    p2--;
                }
                if(p2 == p1)
                    break;
                else{
                    *p1 = *p2;
                    *p2 = val;
                    counter++;
                }
            }
            p1++;
        }
        return counter;
    }
};
