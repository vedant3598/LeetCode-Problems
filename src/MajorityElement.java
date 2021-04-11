class Solution {
    public int majorityElement(int[] nums) {
        final double num = nums.length / 2;
        double numOfNums = 0;
        int returnNum = 0;
        for(int i = 0; i < nums.length; i++){
            int newNum = nums[i];
            for(int x = 0; x < nums.length; x++){
                if(newNum == nums[x]){
                    numOfNums++; 
                    returnNum = nums[x];
                }                            
            }  
            if(numOfNums > num){
                break;  
            }
            numOfNums = 0;
        }
        return returnNum;
    }
}
