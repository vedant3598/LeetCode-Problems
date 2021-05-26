class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = strs[0];
        
        for(int i = 1; i < strs.size(); i++){
            string temp = "";
            int counter = 0;
            while(counter < prefix.length() && counter < strs[i].length()){
                if(prefix[counter] == strs[i][counter]){
                    temp += prefix[counter];
                    counter++;
                }
                else
                    break;
            }
            if(temp == "")
                return "";
            else
                prefix = temp;
        }
        
        return prefix;
    }
};
