class Solution {
public:
    string reverseWords(string s) {
        stack<string> words;
        string reverse = "";
        
        for(int i = 0; i < s.length(); i++){
            string temp = "";
            while(i != s.length() && s[i] != ' '){
                temp += s[i];
                i++;
            }
            if(temp != "")
                words.push(temp);
        }
        
        while(!words.empty()){
            reverse += words.top();
            words.pop();
            if(!words.empty())
                reverse += ' ';
        }
        return reverse;
    }
};
