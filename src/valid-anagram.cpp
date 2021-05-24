class Solution {
public:
    bool isAnagram(string s, string t){
        if(s.length() == t.length()){
            map<char, int> s_dict;
            map<char, int> t_dict;
            
            int size = s.length();
            
            for(int i = 0; i < size; i++){
                if(s_dict.find(s[i]) == s_dict.end())
                    s_dict[s[i]] = 1;
                else
                    s_dict[s[i]]++;
            }
                        
            for(int i = 0; i < size; i++){
                if(t_dict.find(t[i]) == t_dict.end())
                    t_dict[t[i]] = 1;
                else
                    t_dict[t[i]]++;
            }
            
            for(int i = 0; i < size; i++){
                if(t_dict.find(t[i]) != t_dict.end() && s_dict.find(t[i]) != s_dict.end()){
                    if(t_dict[t[i]] != s_dict[t[i]])
                        return false;
                }
                else
                    return false;
            }
        }
        else
            return false;
        
        return true;
    }
};
