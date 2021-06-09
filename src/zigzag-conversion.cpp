class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1)
            return s;
        
        string zigzag = "";
        int counter = 0;
        int row = 1;
        bool isReverse = false;
        vector<string> strings(numRows);
        
        while(counter != s.length()){
            string temp = strings[row-1] + s[counter];
            string obj(temp);
            strings.at(row - 1) = temp;
            if(!isReverse && row != numRows){
                row++;
            }
            else if(isReverse && row != 1){
                row--;
            }
            else if(row == numRows){
                row--;
                isReverse = true;
            }
            else if(row == 1){
                isReverse = false;
                row++;
            }
            else{}
            counter++;
        }
        
        for(int i = 0; i < strings.size(); i++){
            zigzag += strings[i];
        }
        return zigzag;
    }
};
