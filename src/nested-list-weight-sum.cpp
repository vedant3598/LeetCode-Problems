class Solution {
public:
    /**
     * @param nestedList: a list of NestedInteger
     * @return: the sum
     */
    int depthSum(vector<NestedInteger> nestedList) {
        deque<vector<NestedInteger>, vector<vector<NestedInteger>>> q;
        deque<int, vector<int>> sums;
        q.push(nestedList);

        while(!q.empty()){
            int size = q.size();
            int sum = 0;
            for(int i = 0; i < size; i++){
                vector<NestedInteger> curr = q.front();
                q.pop();
                for(NestedInteger ni : curr){
                    if(ni.isInteger()){
                        sum += ni.getInt();
                    }
                    else{
                        q.push(ni.getList());
                    }
                }
            }
            sums.push(sum);
        }

        int level = 1;
        int sol = 0;
        while(!sums.empty()){
            sol += (sums.front() * level);
            sums.pop();
            level++;
        }
        return sol;
    }
};
