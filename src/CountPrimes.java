public class CountPrimes {
	public int countPrimes(int n) {
        int x = 0;
        for(int i = 2; i < n; i++){
            if(findPrimes(i))
                x++;
        }
        return x;
    }
    
    public boolean findPrimes(int n){
        int sqroot = (int) Math.sqrt(n);
        for(int i = 2; i <= sqroot; i++){
            if(n % i == 0)
                return false;
        }
        return true;
    }
}
