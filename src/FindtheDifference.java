import java.util.*;
public class FindtheDifference{
	public char findTheDifference(String s, String t) {
   
        ArrayList<Character> t_al = new ArrayList<Character>();
        char[] c1 = s.toCharArray();
        char[] c2 = t.toCharArray();
        
        for(int i = 0; i < c2.length; i++){
            t_al.add(c2[i]);
        }
        
        if(s.equals(""))
            return c2[0];
        
        for(int i = 0; i < c1.length; i++){
            if(t_al.contains(c1[i]))
                t_al.remove(new Character(c1[i]));
        }
        return t_al.get(0);
    }
}
