class Solution {
public:
    int firstUniqChar(string s) {
        map<int, int> dict;
        
        for(int i = 0; i < s.length(); i++){
            dict[s[i]]++;
        }
        
        int index = -1;
        int counter = 0;
        
        while(counter < s.length() && index == -1){
            if(dict[s[counter]] == 1){
                index = counter;
                break;
            }
            counter++;
        }
        return index;
    }
};
