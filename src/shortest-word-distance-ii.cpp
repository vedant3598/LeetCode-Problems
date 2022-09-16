class ShortestDistance {
    map<string, vector<int>> ind;
public:
    ShortestDistance(vector<string> &words){
        for(int i = 0; i < words.size(); i++){
            ind[words[i]].push_back(i);
        }
    }

    int shortestDistance(string &word1, string &word2) {
        for(int i = 0; i < words.size(); i++){
            ind[words[i]].push_back(i);
        }

        vector<int> w1 = ind[word1];
        vector<int> w2 = ind[word2];
        int i1 = 0;
        int i2 = 0;
        int sol = words.size();
        while(i1 < w1.size() && i2 < w2.size()){
            sol = min(sol, abs(w2[i2]-w1[i1]));
            if(w1[i] < w2[j]){
                i++;
            }
            else{
                j++;
            }
        }
        return sol;
    }
};
