class Solution {
public:
    vector<vector<int>> pascal;
 
    void generateUtil(vector<int> v, int &numRows) {
        if(numRows == 0)
            return;
        
        if(v.size() == 1){
            vector<int> second;
            second.push_back(1);
            second.push_back(1);
            pascal.push_back(second);
            generateUtil(second, --numRows);
        }
        else{
            vector<int> second;
            second.push_back(1);
            int num1 = 0;
            int num2 = 1;
            while(num1 != v.size() - 1){
                int num = v[num1] + v[num2];
                second.push_back(num);
                num1++;
                num2++;
            }
            second.push_back(1);
            pascal.push_back(second);
            generateUtil(second, --numRows);
        }
    }
    
    vector<vector<int>> generate(int numRows) {
        vector<int> first;
        first.push_back(1);
        pascal.push_back(first);
        numRows--;
        generateUtil(first, numRows);
        return pascal;
    }
};
