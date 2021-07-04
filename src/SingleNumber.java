class Solution {
    public int singleNumber(int[] nums) {
        Arrays.sort(nums);
        int returnNum = 0;
        
        for(int i = 0; i < nums.length; i++){
            if(i == nums.length - 1){
                returnNum = nums[i];
                break;
            }
            
            if(i % 2 == 0){
                if(nums[i] != nums[i + 1]){
                    returnNum = nums[i];
                    break;
                }
            }
        }
        return returnNum;
    }
}
