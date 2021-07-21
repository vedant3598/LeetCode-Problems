class Solution {
public:
    
    int lengthOfLastWord(string s) {
        int length = 0;
        vector<int> all;
        string word = "";
        
        for(int i = 0; i < s.length(); i++){
            while(i < s.length() && s[i] != ' '){
                word += s[i];
                i++;
            }
            if(word.length() > 0)
                all.push_back(word.length());
            word = "";
        }
        
        if(all.size() > 0)
            return all[all.size() - 1];
        else
            return 0;
    }
};
