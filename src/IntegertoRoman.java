public class IntegertoRoman {
	public String intToRoman(int num) {
        int[] nums = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        String[] sym = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        StringBuilder strBuilder = new StringBuilder("");
        
        for(int i = 0; i < nums.length; i++){
            while(num >= nums[i]){
                strBuilder.append(sym[i]);
                num -= nums[i];
            }
        }
        return strBuilder.toString();

    }
}
