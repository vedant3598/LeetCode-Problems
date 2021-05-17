class Solution1 {
public:
    bool isVowel(char c){
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
            return true;
        
        return false;
    }
    
    int maxVowels(string s, int k) {
        int max = 0;
        int currentMax = 0;
        int counter = 0;
        int length = s.length();
        for(int i = 0; i < length; i++){
            counter = i;
            if(counter + k < length && (isVowel(s[counter]) || isVowel(s[counter + k - 1]))){
                while(counter <= i+k-1 && counter < length){
                    if(isVowel(s[counter]))
                        currentMax++;
                    counter++;
                }
                if(currentMax > max && counter - i == k)
                    max = currentMax;
                if(max == k)
                    return max;
                currentMax = 0;
            }
        }
        return max;
    }
};
