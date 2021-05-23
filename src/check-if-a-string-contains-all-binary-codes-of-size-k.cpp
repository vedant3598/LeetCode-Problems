class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int codes = pow(2, k);
        const int power = 2;
        map<int, int> dict;
        int i = 0;
        int counter = 0;
        

        while(counter < s.length()){
            int sum = 0;
            int current = k;
            i = counter;
            while(current != 0){
                if(s[i] == '1'){
                    sum += pow(2, current-1);
                }
                current--;
                i++;
            }
            if(dict.find(sum) == dict.end()){
                dict[sum] == 0;
                if(dict.size() == codes)
                    return true;
            }
            counter++;
        }
        
        if(dict.size() == codes)
            return true;
        else
            return false;
    }
};
