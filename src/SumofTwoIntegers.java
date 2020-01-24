public class SumofTwoIntegers {
	public int getSum(int a, int b) {
        int num = a;
        
        while(b != 0){
            if(b < 0){
                num -= 1;
                b = b + 1;
            }
            else{
                num += 1;
                b = b - 1;
            }
        }
        return num;
            
    }
}
