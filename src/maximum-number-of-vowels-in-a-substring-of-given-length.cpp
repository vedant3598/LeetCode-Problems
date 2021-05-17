class Solution1 {
public:
    int maxVowels(string s, int k) {
        int max = 0;
        int currentMax = 0;
        int counter = 0;
        
        for(int i = 0; i < s.length(); i++){
            counter = i;
            while(counter <= i+k-1 && counter < s.length()){
                if(s[counter] == 'a' || s[counter] == 'e' || s[counter] == 'i' || s[counter] == 'o' || s[counter] == 'u')
                    currentMax++;
                counter++;
            }
            if(currentMax > max)
                max = currentMax;
            if(max == k)
                return max;
            currentMax = 0;
        }
        return max;
    }
};
