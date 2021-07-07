class Solution {
public:
    bool detectCapitalUse(string word) {
        int counter = 0;
        
        if(isupper(word[counter])){
            counter++;
            if(word.size() == 1)
                return true;
            else{
                if(isupper(word[counter])){
                    counter++;
                    while(counter != word.length()){
                        if(!isupper(word[counter]))
                            return false;
                        counter++;
                    }
                }
                else{
                    counter++;
                    while(counter != word.length()){
                        if(isupper(word[counter]))
                            return false;
                        counter++;
                    }
                }
            }
        }
        else{
            while(counter != word.length()){
                if(isupper(word[counter]))
                    return false;
                counter++;
            }
        }
        return true;
    }
};
