public class StringtoInteger {
	public int myAtoi(String str) {
        StringBuilder sb = new StringBuilder("");
        
        for(int x = 0; x < str.length(); x++){
            char c = str.charAt(x);
            if(Character.isLetter(c) && x == 0)
                return 0;
            else if(Character.isDigit(c)){
                if(x == str.length() - 1)
                    sb.append(c);
                else if(Character.isDigit(str.charAt(x + 1)))
                    sb.append(c);
                else{
                    sb.append(c);
                    break;
                } 
            }
            else if((c == '-' || c == '+')){
                if(x == str.length() - 1)
                    break;
                else if(Character.isDigit(str.charAt(x + 1)))
                    sb.append(c);
                else 
                    break;
            } 
            else if(c == ' ')
                sb.append("");
            else
                break;
        }
        String singleString = sb.toString();
        try{
            int finalNum = Integer.parseInt(singleString);
            return finalNum;
        }catch(NumberFormatException e){
            if(singleString.isEmpty())
                return 0;
            else if(singleString.charAt(0) == '-')
                return Integer.MIN_VALUE;
            else
                return Integer.MAX_VALUE;
        }
    }
}
