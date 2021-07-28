#include <stack>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        int p = 0; 
        stack<char> paren;
        for(int i = 0; i < s.size(); i++){
            char t = s[i];
            if(t == '{' || t == '[' || t == '('){
                paren.push(s[i]);
                p++;
            }
            else{
                if(t == ')' && !paren.empty() && paren.top() == '('){
                    paren.pop();
                    p--;
                }
                else if(t == ']' && !paren.empty() && paren.top() == '['){
                    paren.pop();
                    p--;
                }
                else if(t == '}' && !paren.empty() && paren.top() == '{'){
                    paren.pop();
                    p--;
                }
                else
                    return false;
            }
        }
        if(p != 0)
            return false;
        else
            return true;
    }
};
