class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int counter = 0;
        
        int rule = 1;
        if(ruleKey == "color")
            rule = 2;
        else if(ruleKey == "name")
            rule = 3;
        else{}
        
        for(int i = 0; i < items.size(); i++){
            if(rule == 1){
                if(ruleValue == items[i][0])
                    counter++;
            }
            else if(rule == 2){
                if(ruleValue == items[i][1])
                    counter++;
            }
            else if(rule == 3){
                if(ruleValue == items[i][2])
                    counter++;
            }
        }
       
        return counter;
    }
};
