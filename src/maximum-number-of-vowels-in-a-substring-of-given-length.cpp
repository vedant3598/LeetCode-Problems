// Run-time: O(n*k), where n is length of input string s
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

// Run-time: O(n), where n is length of input string s
class Solution2 {
public:
    bool isVowel(char c){
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
            return true;
        
        return false;
    }
    
    int maxVowels(string s, int k) {
        int max = 0;
        int current = 0;
        int begin = 0;
        
        for(int i = 0; i < k; i++){
            if(isVowel(s[i]))
                current++;
        }
        max = current;
        
        for(int i = k; i < s.length(); i++){
            if(isVowel(s[begin++]))
                current--;
            
            if(isVowel(s[i]))
                current++;
            
            if(current > max){
                max = current;
                if(max == k)
                    break;
            }
        }
        return max;
    }
};
