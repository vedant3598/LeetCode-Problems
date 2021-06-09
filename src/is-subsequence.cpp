class Solution {
public:
    bool isSubsequence(string s, string t) {
        int counter = 0;
        for(int i = 0; i < t.length(); i++){
            if(counter < s.length() && t[i] == s[counter])
                counter++;
        }
        
        if(counter == s.length())
            return true;
        return false;
    }
};
