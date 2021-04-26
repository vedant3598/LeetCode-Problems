class Solution1 {
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

// Working Solution
class Solution2 {
public:
    bool isPalindrome(string s) {        
        
        stack<char> characters;
        int counter = 0;
        for(int i = 0; i < s.length(); i++){
            //cout << s[counter] << endl;
            if(i == ((s.length() - 1) / 2) && ((s.length() - 1) % 2) == 0){
                counter++;
                break;
            }
            else if(i == ((s.length() - 1) / 2)){
                if(isalnum(s[counter])){
                    characters.push(s[counter]);
                    cout << s[counter] << endl;
                }
                counter++;
                break;
            }
            else{
                if(isalnum(s[counter])){
                    characters.push(s[counter]);
                    cout << s[counter] << endl;
                }
                counter++;
            }
        }
        
        for(; counter < s.length(); counter++){
            if(isalnum(s[counter] && s[counter] == characters.top()))
                characters.pop();
        }
        
        if(characters.size() == 0)
            return true;
        else
            return false;
    }
};
