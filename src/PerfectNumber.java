import java.util.*;
public class PerfectNumber {
	public boolean checkPerfectNumber(int num) {
        if(num == 0)
            return false;
        ArrayList<Integer> perfectNum = new ArrayList<Integer>();
        
        for(int x = 1; x <= (num / 2); x++){
            if(num % x == 0)
                perfectNum.add(x);
        }
        
        int sumNum = 0;
        
        for(int i = 0; i < perfectNum.size(); i++){
            sumNum += perfectNum.get(i);
        }
        
        if(sumNum == num)
            return true;
        else return false;
    }
}
