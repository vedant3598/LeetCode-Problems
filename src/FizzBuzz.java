import java.util.*;

public class FizzBuzz {
	public List<String> fizzBuzz(int n) {
        ArrayList<String> lst = new ArrayList<String>();
        for(int i = 1; i <= n; i++){
            if(i % 15 == 0){
                lst.add("FizzBuzz");
            }
            else if(i % 5 == 0){
                lst.add("Buzz");
            }
            else if(i % 3 == 0){
                lst.add("Fizz");
            }            
            else{
               lst.add(Integer.toString(i)); 
            }    
        }
        return lst;
    }
}
