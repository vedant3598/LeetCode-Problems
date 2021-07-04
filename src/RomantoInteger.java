public class RomantoInteger {
	public int romanToInt(String s) {
int num = 0;
        
        for(int i = 0; i < s.length(); i++){
            if(s.charAt(i) == 'M')
                num += 1000;
            
            else if(s.charAt(i) == 'D')
                num += 500;
            
            else if(s.charAt(i) == 'C'){
                if(i == s.length() - 1)
                    num += 100;
                else if(s.charAt(i + 1) == 'M' || s.charAt(i + 1) == 'D')
                    num -= 100;
                else 
                    num += 100;
            }
            
            else if(s.charAt(i) == 'L')
                num += 50;
            
            else if(s.charAt(i) == 'X'){
                if(i == s.length() - 1)
                    num += 10;
                else if(s.charAt(i + 1) == 'L' || s.charAt(i + 1) == 'C')
                    num -= 10;
                else 
                    num += 10;
            }
            else if(s.charAt(i) == 'V')
                num += 5;
            else if(s.charAt(i) == 'I'){
                if(i == s.length() - 1)
                    num += 1;
                else if(s.charAt(i + 1) == 'V' || s.charAt(i + 1) == 'X')
                    num -= 1;
                else 
                    num += 1;
            }
        }
        return num;
    }
}
