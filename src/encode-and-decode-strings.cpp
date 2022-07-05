class Solution {
    string delimiter = "*"
public:
    /*
     * @param strs: a list of strings
     * @return: encodes a list of strings to a single string.
     */
    string encode(vector<string> &strs) {
        string sol = "";
        for(string s : strs){
            sol += to_string(s.length()) + delimiter + s;
        }
        return sol;
    }

    /*
     * @param str: A string
     * @return: dcodes a single string to a list of strings
     */
    vector<string> decode(string &str) {
        vector<string> sol;
        for(int i = 0; i < str.length(); i++){
            string tempNum = "";
            while(str[i] != '*'){
                tempNum += str[i++];
            }
            i++;
            int num = stoi(tempNum);
            sol.push_back(str.substr(i, num));
        }
        return sol;
    }
};
