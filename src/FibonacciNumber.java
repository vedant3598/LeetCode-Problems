class Solution {
    public int fib(int N) {
        if(N == 0 || N == 1)
            return N;
        
        int fib[] = new int[31];
        fib[0] = 0;
        fib[1] = 1;
        
        for(int f = 2; f < fib.length; f++){
            if(f == N){
                return fib[f-1] + fib[f-2];
            }
            fib[f] = fib[f-1] + fib[f-2];
        }
        return fib[N];
    }
}
