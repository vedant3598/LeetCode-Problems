public class PalindromeNumber {
	public boolean isPalindrome(int x) {
        String s = Integer.toString(x);
        StringBuilder sb = new StringBuilder("");
        
        for(int i = s.length() - 1; i >= 0; i--){
            sb.append(s.charAt(i));
        }
        String newS = sb.toString();
        if(s.equals(newS))
            return true;
            
        else return false;
    }
}
