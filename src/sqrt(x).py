class Solution(object):
    def mySqrt(self, x):
        if x == 0:
            return x;
        if x == 1:
            return x;
        
        num = float (x)
        initial_guess = num / 2
        error = 0.000001
        
        while (initial_guess * initial_guess - num > error):
            initial_guess = (initial_guess + num / initial_guess) / 2
            
        
        
        finalNum = int(initial_guess)
        return finalNum
