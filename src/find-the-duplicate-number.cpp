class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int duplicate;
        
        for(int i = 0; i < nums.size(); i++){
            int num = nums[i];
            int index = num - 1;
            if(i != index){
                int temp = nums[index];
                if(temp == num){
                    duplicate = temp;
                    break;   
                }
                nums[index] = num;
                nums[i] = temp;
            }
        }
        return duplicate;        
    }
};
