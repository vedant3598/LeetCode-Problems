class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s == "")
            return true;
        
        int counter = 0;
        string construct = "";
        for(int i = 0; i < t.length(); i++){
            while(i < t.length() && t[i] != s[counter]){
                i++;
            }
            construct += t[i];
            counter++;
        }
        
        if(construct == s )
            return true;
        return false;
    }
};
