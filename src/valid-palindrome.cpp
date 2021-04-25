class Solution {
public:
    bool isPalindrome(string s) {        
        string newS = "";
        for(int i = 0; i < s.length(); i++){
            if(isalnum(s[i])){
                newS += tolower(s[i]);
            }
        }
        
        if(newS.length() == 1)
            return true;
        
        stack<char> characters;
        int counter = 0;
        for(int i = 1; i <= newS.length(); i++){
            cout << newS[counter] << endl;
            if(i * 2 == newS.length()){
                characters.push(newS[counter++]);
                break;
            }
            else if(i * 2 == newS.length() - 1){
                characters.push(newS[counter++]);
                counter++;
                break;
            }
            else{
                characters.push(newS[counter++]);
            }
        }
        
        for(; counter < newS.length(); counter++){
            if(newS[counter] == characters.top())
                characters.pop();
        }
        
        if(characters.size() == 0)
            return true;
        else
            return false;
    }
};
