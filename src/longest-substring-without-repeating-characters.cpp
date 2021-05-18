class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max = 0;
        int p1 = 0;
        int p2 = 0;
        map<char, int> unique;
        
        while(p2 < s.length()){
            if(unique.find(s[p2]) == unique.end()){
                unique[s[p2]] = 0;
                p2++;
                if(unique.size() > max)
                    max = unique.size();
            }
            else{
                unique.erase(s[p1]);
                p1++;
            }
        }        
        return max;
    }
};
