class Solution {
public:
    bool isVowel(char c){
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
               c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }
    
    string reverseVowels(string s) {
        if(s.length() == 1)
            return s;
        
        char* p1 = &s[0];
        char* p2 = &s[s.length() - 1];
        
        while(p1 <= p2){
            if(isVowel(*p1) && isVowel(*p2)){
                char temp = *p2;
                *p2 = *p1;
                *p1 = temp;
            }
            else if(isVowel(*p1)){
                while(p1 <= p2 && !isVowel(*p2)){
                    p2--;
                }
                if(p1 > p2)
                    break;
                char temp = *p2;
                *p2 = *p1;
                *p1 = temp;
            }
            else if(isVowel(*p2)){
                while(p1 <= p2 && !isVowel(*p1)){
                    p1++;
                }
                if(p1 > p2)
                    break;
                char temp = *p2;
                *p2 = *p1;
                *p1 = temp;
            }
            else {}
            p1++;
            p2--;
        }
        return s;
    }
};
