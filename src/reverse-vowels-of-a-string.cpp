class Solution {
public:
    bool isVowel(char c){
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
    
    string reverseVowels(string s) {
        if(s.length() == 1)
            return s;
        
        char* p1 = &s[0];
        char* p2 = &s[s.length() - 1];
        
        while(p1 <= p2){
            if(isVowel(*p1)){
                while(!isVowel(*p2)){
                    p2--;
                }
                char temp = *p2;
                *p2 = *p1;
                *p1 = temp;
            }
            else
                p1++;
        }
        return s;
    }
};
