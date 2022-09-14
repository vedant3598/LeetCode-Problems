class Solution {
public:
    /**
     * @param nestedList: a list of NestedInteger
     * @return: the sum
     */
    int depthSumInverse(vector<NestedInteger> nestedList) {
        deque<vector<NestedInteger>, vector<vector<NestedInteger>>> q;
        q.push(nestedList);
        stack<int> sums;

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

        int sol = 0;
        int level = 1;
        while(!sums.empty()){
            sol += level * sums.top();
            sums.pop();
            level++;
        }
        return sol;
    }
};
