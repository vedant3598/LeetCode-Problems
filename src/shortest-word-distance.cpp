class Solution {
public:
    /**
     * @param words: a list of words
     * @param word1: a string
     * @param word2: a string
     * @return: the shortest distance between word1 and word2 in the list
     */
    int shortestDistance(vector<string> &words, string &word1, string &word2) {
        map<string, vector<int>> ind;

        for(int i = 0; i < words.size(); i++){
            ind[words[i]].push_back(i);
        }

        vector<int> w1 = ind[word1];
        vector<int> w2 = ind[word2];
        int i = 0;
        int j = 0;
        int sol = INT_MAX;
        while(i < w1.size() && j < w2.size()){
            sol = min(sol, abs(w1[i] - w2[j]));
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
