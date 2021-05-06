class Solution {
public:
    bool isPowerOfTwo(int n) {       
        int num = 2;
        int counter = 0;
        long long int curr;
        
        while(true){
            curr = pow(num, counter);
            
            if(curr > n)
                return false;
            else if(curr == n)
                return true;
            else
                counter++;
        }

    }
};
