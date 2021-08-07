class Solution {
public:
    bool isHappy(int n) {
        int temp = 0;
        vector<int> numberSeen;

        while(n != 1){
            temp = n;
            vector<int> num;
            while(temp != 0){
                num.push_back(temp % 10);
                temp /= 10;
            }
            
            temp = 0;
            for(int i = 0; i < num.size(); i++){
                int sqr = num[i] * num[i];
                temp += sqr;
            }    
            n = temp;
            
            for(int i = 0; i < numberSeen.size(); i++){
                if(numberSeen[i] == n)
                    return false;
            }
            numberSeen.push_back(n);
        }
        return true;
    }
};
